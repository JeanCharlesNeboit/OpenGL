#include "model.hpp"

Model::Model(std::string path) {
  loadModel(path);
}

void Model::loadModel(std::string path) {
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

  if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
    std::cout << "ERROR:ASSIMP: " << importer.GetErrorString() << std::endl;
    return;
  }
  directory = path.substr(0, path.find_last_of('/'));

  processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene) {
  for(unsigned int i = 0; i < node->mNumMeshes; ++i) {
    aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
    meshes.push_back(processMesh(mesh, scene));
  }

  for(unsigned int i = 0; i < node->mNumChildren; ++i) {
    processNode(node->mChildren[i], scene);
  }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;

  for(unsigned int i = 0; i < mesh->mNumVertices; ++i) {
    Vertex vertex;

    glm::vec3 vector;
    vector.x = mesh->mVertices[i].x;
    vector.y = mesh->mVertices[i].y;
    vector.z = mesh->mVertices[i].z;
    vertex.position = vector;

    vector.x = mesh->mNormals[i].x;
    vector.y = mesh->mNormals[i].y;
    vector.z = mesh->mNormals[i].z;
    vertex.normal = vector;

    if(mesh->mTextureCoords[0]) {
      glm::vec2 vec;
      vec.x = mesh->mTextureCoords[0][i].x;
      vec.y = mesh->mTextureCoords[0][i].y;
      vertex.textureCoordinates = vec;
    }
    else {
      vertex.textureCoordinates = glm::vec2(0.0f, 0.0f);
    }

    vertices.push_back(vertex);
  }

  for(unsigned int i = 0; i < mesh->mNumFaces; ++i) {
    aiFace face = mesh->mFaces[i];
    for(unsigned int j = 0; j < face.mNumIndices; j++) {
      indices.push_back(face.mIndices[j]);
    }
  }

  if(mesh->mMaterialIndex > 0) {
    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
    std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, Texture::Type::diffuse);
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, Texture::Type::specular);
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
  }

  return Mesh(vertices, indices, textures);
}

std::vector<Texture> Model::loadMaterialTextures(aiMaterial* material, aiTextureType aiType, Texture::Type type) {
  std::vector<Texture> textures;
  for(unsigned int i = 0; i < material->GetTextureCount(aiType); ++i) {
    aiString str;
    material->GetTexture(aiType, i, &str);

    bool skip = false;
    for(unsigned int j = 0; j < texturesLoaded.size(); ++j) {
      if(std::strcmp(texturesLoaded[j].path.data(), str.C_Str()) == 0) {
        textures.push_back(texturesLoaded[j]);
        skip = true;
        break;
      }
    }
    if(!skip) {
      Texture texture;
      texture.id = Texture::TextureFromFile(str.C_Str(), directory);
      texture.type = type;
      texture.path = str.C_Str();
      textures.push_back(texture);
      texturesLoaded.push_back(texture);
    }
  }
  return textures;
}

void Model::draw(Shader shader) {
  for(auto mesh : meshes) {
    mesh.draw(shader);
  }
}

#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "mesh.hpp"
#include "stb/stb_image.h"

class Model {
private:
  std::vector<Texture> texturesLoaded;
  std::vector<Mesh> meshes;
  std::string directory;

  void loadModel(std::string);
  void processNode(aiNode*, const aiScene*);
  Mesh processMesh(aiMesh*, const aiScene*);
  std::vector<Texture> loadMaterialTextures(aiMaterial*, aiTextureType, Texture::Type);

public:
  Model(std::string);
  void draw(Shader);
};

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

#endif

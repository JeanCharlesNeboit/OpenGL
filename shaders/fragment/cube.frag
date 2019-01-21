#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// light
uniform vec3 lightColor;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2) * vec4(ambient, 1.0);
}
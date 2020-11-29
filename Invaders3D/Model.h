#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

#include "Shader.h"
#include "Mesh.h"
#include "TextureLoader.h"

class Model
{
public:
	Model() {};
	~Model() {};

	void loadModel(std::string path);
	void draw(Shader& shader);
private:
	std::vector<Mesh> meshes;
	std::string sourceLocation;

	std::vector<Texture> loadMats(aiMaterial* material, aiTextureType type, std::string typeName);
	Mesh convertMesh(aiMesh* mesh, const aiScene* scene);
	void processNode(aiNode* node, const aiScene* scene);

	std::vector<Vertex> processVertices(aiMesh* mesh);
	std::vector<unsigned int> processIndicies(aiMesh* mesh);
	std::vector<Texture> processTextures(aiMesh* mesh, const aiScene* scene);
	unsigned int loadTexture(const char* fileName, const std::string& sourceLocation);
};


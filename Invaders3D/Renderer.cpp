#include "Renderer.h"

//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//"   ourColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor, 1.0f);\n"
//"}\n\0";

Renderer::Renderer()
{
	VAO = 0;
	VBO = 0;
	EBO = 0;
	shaderProgram = 0;
}

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
}

void Renderer::loadDrawingData(float vertices[], int vertSize, unsigned int indices[], int indSize)
{
	shader.setupProgram("shader.vert", "shader.frag");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	// Bind and set vertex buffer data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertSize, vertices, GL_STATIC_DRAW);

	// Set vertex attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Set colour attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Unbind VBO and VAO, not strictly required
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Use the program
	glUseProgram(shaderProgram);

	// Wireframe mode. 
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Renderer::draw()
{
	shader.useProgram();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

unsigned int Renderer::createShader(GLenum shaderType, const char* shaderSource)
{
	//unsigned int shader;

	//shader = glCreateShader(shaderType);
	//glShaderSource(shader, 1, &shaderSource, NULL);
	//glCompileShader(shader);

	//// Check that compilation was successful, if not output errors.
	//int success;
	//char infoLog[512];

	//glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(shader, 512, NULL, infoLog);
	//	std::cout << "ERROR: A shader failed to compile\n" << infoLog << std::endl;

	//	return -1;
	//}

	return 0;
}

unsigned int Renderer::createShaderProgram()
{
	//unsigned int program = 0;
	//unsigned int vertexShader = 0;
	//unsigned int fragmentShader = 0;

	//vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderSource);
	//fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	//program = glCreateProgram();
	//glAttachShader(program, vertexShader);
	//glAttachShader(program, fragmentShader);
	//glLinkProgram(program);

	//// Check that linking was successful, if not output errors.
	//int success;
	//char infoLog[512];

	//glGetProgramiv(program, GL_LINK_STATUS, &success);
	//if (!success)
	//{
	//	glGetProgramInfoLog(program, 512, NULL, infoLog);
	//	std::cout << "ERROR: Program linking failed\n" << infoLog << std::endl;

	//	return -1;
	//}

	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);

	return 0;
}

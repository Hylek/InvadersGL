#include "Shader.h"

Shader::Shader()
{
    shaderProgram = 0;
    vertexShaderSource = nullptr;
    fragmentShaderSource = nullptr;
}

Shader::~Shader()
{
    glDeleteProgram(shaderProgram);
}

unsigned int Shader::getShaderProgram()
{
	return shaderProgram;
}

void Shader::setupProgram(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // Open source files.
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        // Convert stream to string to make it useable.
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR: Could not read shader source file." << std::endl;
    }
    vertexShaderSource = vertexCode.c_str();
    fragmentShaderSource = fragmentCode.c_str();

    // Compile shaders and create program
    shaderProgram = createShaderProgram();
}

void Shader::useProgram()
{
    glUseProgram(shaderProgram);
}

unsigned int Shader::createShader(GLenum shaderType, const char* shaderSource)
{
    unsigned int shader;

    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    // Check that compilation was successful, if not output errors.
    int success;
    char infoLog[1024];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: A shader failed to compile\n" << infoLog << std::endl;

        return -1;
    }

    return shader;
}

unsigned int Shader::createShaderProgram()
{
    unsigned int program = 0;
    unsigned int vertexShader = 0;
    unsigned int fragmentShader = 0;

    vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderSource);
    fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Check that linking was successful, if not output errors.
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR: Program linking failed\n" << infoLog << std::endl;

        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

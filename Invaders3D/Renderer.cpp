#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

bool Renderer::initOpenGL()
{
	return glewInit() == GLEW_OK;
}

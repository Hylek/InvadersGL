#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Game.h"

void processInput(GLFWwindow* window);

int main(void)
{
    Game game;

    if (game.start())
    {
        std::cout << "Game shutting down..." << std::endl;
    }
    else
    {
        std::cout << "ERROR: Game failed to launch correctly!" << std::endl;
        glfwTerminate();

        return -1;
    }

    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

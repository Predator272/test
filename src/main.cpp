#include "glfw/glfw3.h"
#include <iostream>



namespace Engine
{
	class Engine
	{
	public:
		Engine()
		{
			if (!glfwInit())
			{
				throw std::runtime_error("failed init glfw");
			}
		}
		~Engine()
		{
			glfwTerminate();
		}
	};

	class Window
	{
	public:
		GLFWwindow* _Window;
	public:
		Window(const std::string Title, int Width, int Height) : _Window(nullptr)
		{
			if (!(this->_Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr)))
			{
				throw std::runtime_error("failed create window");
			}

			glfwMakeContextCurrent(this->_Window);
		}

		~Window()
		{
			glfwDestroyWindow(this->_Window);
		}

		bool PollEvents()
		{
			glfwSwapBuffers(this->_Window);
			glfwPollEvents();
			return !glfwWindowShouldClose(this->_Window);
		}
	};
}



int main()
{
	try
	{
		Engine::Engine Engine;

		Engine::Window Window("Test", 640, 480);

		while (Window.PollEvents())
		{
		}
	}
	catch (const std::exception& Error)
	{
		std::cerr << "Error: " << Error.what() << '\n';
	}

	return 0;
}

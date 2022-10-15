#pragma once

#include <tsk/util.h>
#include <GLFW/glfw3.h>
#include <string>
#include <cstdint>

namespace tsk
{

	class Window
	{
	public:
		Window(uint16_t width, uint16_t height, const std::string& title);
		Window() = default;
		~Window() = default;

		GLFWwindow* GetWindow() const;

		bool IsOpen() const;
		void SwapBuffers();
		void WaitEvents();
		void MakeContextCurrent();

	private:
		GLFWwindow* m_Window = nullptr;
		uint16_t m_Width = 0, m_Height = 0;
		std::string m_Title = "";
	};

}
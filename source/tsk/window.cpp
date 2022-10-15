#include "window.h"

namespace tsk
{

	Window::Window(uint16_t width, uint16_t height, const std::string& title)
		: m_Width(width), m_Height(height), m_Title(title)
	{
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
		TSK_ASSERT(m_Window);
	}

	GLFWwindow* Window::GetWindow() const
	{
		return m_Window;
	}

	bool Window::IsOpen() const
	{
		return !glfwWindowShouldClose(m_Window);
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::WaitEvents()
	{
		glfwWaitEvents();
	}

	void Window::MakeContextCurrent()
	{
		glfwMakeContextCurrent(m_Window);
	}

}
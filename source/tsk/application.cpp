#include "application.h"

namespace tsk
{

	Application::Application(uint16_t width, uint16_t height, const std::string& title)
	{
		TSK_ASSERT(glfwInit());

		m_Window = std::make_unique<Window>(width, height, title);
	}

	void Application::Run()
	{
		m_Window->MakeContextCurrent();
		Renderer* const renderer = Renderer::Get();
		renderer->SetContext(m_Window->GetWindow());
		renderer->InitImGui();

		while (m_Window->IsOpen())
		{
			renderer->SetClearColor(glm::vec4(0.0f, 0.0f, 0.01f, 1.0f));
			renderer->Clear();

			renderer->DrawImGui();

			m_Window->WaitEvents();
			m_Window->SwapBuffers();
		}
	}

}
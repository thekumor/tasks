#pragma once

#include <tsk/renderer.h>
#include <tsk/window.h>
#include <tsk/util.h>
#include <cstdint>
#include <memory>
#include <string>

namespace tsk
{

	class Application
	{
	public:
		Application(uint16_t width, uint16_t height, const std::string& title);
		Application() = default;
		~Application() = default;

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
	};

}
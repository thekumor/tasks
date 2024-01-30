#pragma once

#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION

#include <tsk/util.h>
#include <tsk/tasksmanager.h>
#include <tsk/buffers.h>
#include <tsk/imgui/imgui.h>
#include <tsk/imgui/imgui_impl_glfw.h>
#include <tsk/imgui/imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

namespace tsk
{

	struct TextureInfo
	{
		GLuint ID = 0;
		glm::vec2 Size = {};
	};

	class Renderer
	{
	public:
		~Renderer();

		static Renderer* Get();

		void SetContext(GLFWwindow* window);
		void Clear();
		void SetClearColor(const glm::vec4& color);
		void InitImGui();
		void DrawImGui();
		//GLuint CreateTexture(const std::string& path);

	protected:
		Renderer();

	private:
		static Renderer* m_Instance;
		glm::vec4 m_ClearColor;
		GLFWwindow* m_Window = nullptr;
		std::vector<TextureInfo> m_Textures = {};
	};

}
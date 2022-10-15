#pragma once

#include <tsk/renderer.h>

namespace tsk
{

	Renderer* Renderer::m_Instance = nullptr;

	Renderer::Renderer()
	{
		TSK_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
	}

	Renderer::~Renderer()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	Renderer* Renderer::Get()
	{
		if (!m_Instance)
		{
			m_Instance = new Renderer; // Loads GLAD as well
		}

		return m_Instance;
	}

	void Renderer::SetContext(GLFWwindow* window)
	{
		m_Window = window;
	}

	void Renderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::SetClearColor(const glm::vec4& color)
	{
		m_ClearColor = color;
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Renderer::InitImGui()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsClassic();
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 330");

		CreateTexture("anime.jpg");
	}

	void Renderer::DrawImGui()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		const TextureInfo& anime = m_Textures[0];

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y));
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::Begin("Workspace");
		ImGui::Image((ImTextureID)anime.ID, ImVec2(anime.Size.x, anime.Size.y));
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	GLuint Renderer::CreateTexture(const std::string& path)
	{
		GLuint textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTextureParameteri(textureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(textureID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri(textureID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTextureParameteri(textureID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 640, 480, false, GL_RGBA, GL_FLOAT, (void*)0);

		int width, height, channels;
		unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		TSK_ASSERT(data);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		stbi_image_free(data);

		TextureInfo info;
		info.ID = textureID;
		info.Size = glm::vec2(width, height);

		m_Textures.emplace_back(info);

		return textureID;
	}

}
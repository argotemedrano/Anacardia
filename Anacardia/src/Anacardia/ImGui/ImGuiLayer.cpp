#include "pch.h"
#include "ImGuiLayer.h"
//#include "imgui.h"
#include "Anacardia/Application.h"

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


// Temp
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Anacardia
{
	void ImGuiLayer::OnAttach()
	{
		// Set up ImGui Context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable keyboard control
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;	// Enable docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;	// Enable viewports (popping out a new window and automatically createa a new context)

		// Set up style
		ImGui::StyleColorsDark();

		// When viewports are enabled, we tweak WindowRounding/WindowBg so platform windows can look identical to regularones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application* app = Application::Get();
		// Set up platform/renderer bindings
		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)app->GetWindow().GetNativeWindow(), true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplGlfw_Shutdown();
		ImGui_ImplOpenGL3_Shutdown();
		ImGui::DestroyContext();
	}

	// Begin a new frame
	void ImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application* app = Application::Get();
		io.DisplaySize = ImVec2(app->GetWindow().GetWidth(), app->GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::OnImGuiRender()
	{
		
		if (m_ShowDemoWindow)
		{
			ImGui::ShowDemoWindow(&m_ShowDemoWindow);
		}
	
	}
}
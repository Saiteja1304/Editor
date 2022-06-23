// IMGUI
#include <cstdlib>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_opengl3_loader.h>

// Editor
#include "PrimaryRenderer.hpp"
#include "Vector2.hpp"
#include <Utils/Debug.hpp>
#include <iostream>
// Editor includes
#include <Editor.hpp>

const char *glsl_version = "#version 130";

Editor &editor = editor.EGetInstance();
EditorUI &editorUI = editorUI.EUIGetInstance();
int main(int, char **) {
    // Editor
    editor.EInit();

    // Imgui Init
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(editor.window.window_handle, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Glad init
    Renderer::Init_Renderer();

    // Set viewport for glad
    Renderer::setViewportSize(iVector2(0, 0), editor.window.WGetWindowSize());

    while (!editor.window.windowCloseFlag) {
        {
            Timer timer;

            // Imgui Frame implementation
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Drawing Editor UI
            editorUI.DrawEditorDetails();
            editorUI.DrawSceneHeirarchy();

            editor.window.WPollEvents();

            // Imgui
            ImGui::Render();

            // Glad Update
            Renderer::update_Renderer();
            

            editor.EUpdate();

            // Render Imgui
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            // Swap window buffers
            editor.window.WSwapBuffers();
        }
    }
    // Imgui Shutdown
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Editor Exit call
    editor.EExit();
    return EXIT_SUCCESS;
}

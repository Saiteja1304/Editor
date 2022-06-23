#include "GLFW/glfw3.h"
#include "imgui.h"
#include <Editor.hpp>
bool b = true;
void EditorUI::DrawEditorDetails() {
    ImGui::ShowDemoWindow(&b);
    if (ImGui::Begin("Editor Details")) {
        ImGui::Text("Editor Version 0.0.1");
        ImGui::Text("Renderer Version 0.0.1");
        ImGui::Text("OpenGL Version 4.6");
        ImGui::End();
    }
}
void EditorUI::DrawSceneHeirarchy() {
    if (ImGui::Begin("Scene heirarchy")) {
        if (ImGui::TreeNode("EmptyScene")) {
            if (ImGui::TreeNode("Empty Group")) {
                ImGui::TreePop();
            }
            ImGui::TreePop();
        }
        ImGui::End();
    }
}

// #include
#include <Components/GameObject.hpp>
void Editor::EInit() {
    window.bindings.windowClosePrimary = GLFW_KEY_LEFT_ALT;
    window.bindings.windowClose = GLFW_KEY_ESCAPE;
    window.WInit();
    window.WCreateWindow();
}

void Editor::EUpdate() { window.WUpdate(); }
void Editor::EExit() { window.WExit(); }
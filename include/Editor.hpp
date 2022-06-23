#ifndef EDITOR_HPP
#define EDITOR_HPP
#include "Window/Window.hpp"
struct Editor_Bindings {};
class Editor {
  public:
    Window &window = window.wGetInstance();
    static Editor &EGetInstance() {
        static Editor EInstance;
        return EInstance;
    }
    void EInit();
    void EUpdate();
    void EExit();

  private:
    Editor() {}
    void operator=(Editor const &);
    Editor(Editor const &);
};

class EditorUI {
  public:
    static EditorUI &EUIGetInstance() {
        static EditorUI EUIInstance;
        return EUIInstance;
    }
    void DrawEditorDetails();
    void DrawSceneHeirarchy();

  private:
    EditorUI() {}
    void operator=(EditorUI const &);
    EditorUI(EditorUI const &);
};

#endif
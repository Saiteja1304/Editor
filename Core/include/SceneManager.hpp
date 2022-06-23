#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
#include "Components/GameObject.hpp"
#include "Container.hpp"
#include <cstring>
struct Scene {
    char Name[16];
    Container<Group> *groups;
    Scene(const char *_name) { strcpy(Name, _name); }
};
class SceneManager {
  public:
    Scene *CurrentScene;
    Container<Scene> *scenes;
    static SceneManager &SMGetInstance() {
        static SceneManager SMInstance;
        return SMInstance;
    }
    int SearchSceneByName(const char *_name) {
        int j = 0;
        for (int i = 0; i < scenes->size; i++) {
            j = (!strcmp(scenes->elements[i].Name, _name)) * i + j * (j != 0);
        }
        return j;
    }
	void setSctiveScene(const char*_name){
		CurrentScene = &scenes->elements[SearchSceneByName(_name)];
	}

  private:
    SceneManager() {
        scenes = new Container<Scene>(1);
        scenes->add(Scene("New Scene"));
    }
    SceneManager(SceneManager const &);
    void operator=(SceneManager const &);
};

#endif
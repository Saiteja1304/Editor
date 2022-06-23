#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Components.hpp"
#include "Container.hpp"
#include <cstring>
enum GameObjectType {
    EMPTY,
    CAMERA_MAIN,
    CAMERA,
    OBJECT_EMPTY,
    OBJECT_3D,
    OBJECT_UI,
    OBJECT_3D_STATIC,
    OBJECT_3D_DYNAMIC,
    LIGHT
};
struct GameObject {
    GameObjectType type;
    Transform transform;
    MeshRenderer meshrenderer;
    GameObject() {}
};
struct State {};

// stores a collection of gameobjects
// has states
struct Group {
    Container<GameObject> g_objects;
    Group() {}
    Group(unsigned short int _size) { g_objects = Container<GameObject>(_size); }
    void resize(unsigned short int _size) { g_objects.resize(_size); }
    ~Group() {}
};
#endif
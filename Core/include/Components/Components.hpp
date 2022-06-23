#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP
#include "Vector2.hpp"
#include "Vector3.hpp"
enum ComponentType { TRANSFORM, MESH, MESHRENDERER };
struct Component {};
struct Transform : Component {
    Vector3 Position = Vector3(0.0);
    Vector3 Rotation = Vector3(0.001);
    Vector3 Scale = Vector3(1.0);
    ComponentType type = TRANSFORM;
};
struct Mesh : Component {
    ComponentType type = MESH;
    float *vertexData;
    int *indexData;
    unsigned short int vertexDataSize, indexDataSize;
    bool isTextCoord, isNormal;
};
struct MeshRenderer : Component {
    ComponentType type = MESHRENDERER;
    unsigned int vertexBuffer, indexBuffer, vertexArrayObject, shaderProgram = 0, matModelView, matProjection;
    unsigned short int indexDataSize;
};
struct Camera : Component {
    float nearPlane, farPlane;
    float fieldOfView;
    iVector2 windowSize;
};

#endif
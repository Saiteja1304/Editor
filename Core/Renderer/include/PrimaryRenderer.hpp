#ifndef PRIMARYRENDERER_HPP
#define PRIMARYRENDERER_HPP
#include "../../Math/include/Vector2.hpp"
namespace Renderer {

// updates background color and clear buffers
void update_Renderer();

// Initializes glad
void Init_Renderer();
void setViewportSize(iVector2 startPos, iVector2 size);
void LoadShaders(const char *vertexShaderSource, const char *fragmentShaderSource, unsigned int shaderProgram);

// Loads mesh data to memory
// requires text coord and normal data
void LoadBufferstn(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                   unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer);
// loads mesh data to memory
// requires only text coord
void LoadBufferst(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                  unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer);
// loads mesh data to memory
// requires only normal
void LoadBuffersn(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                  unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer);
// loads mesh data to memory
// doesnt require text coord or normal
void LoadBuffers(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                 unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer);
// Draws objects
// Requires modelview matrix and projection matrix
void Draw(unsigned int vertexArrayObject, unsigned short int indexDataSize, unsigned int shaderProgram, float *mvmatPtr, float* pmatPtr, unsigned int mvMatLocation,
          unsigned int pMatLocation);

} // namespace Renderer
#endif
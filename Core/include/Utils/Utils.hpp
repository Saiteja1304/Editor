#ifndef UTILS_HPP
#define UTILS_HPP
namespace Utils {
void LoadMesh(const char *meshPath, float *vertexData, int *indexData,
              unsigned short int vertexDataSize,
              unsigned short int indexDataSize, bool isTextCoord,
              bool isNormal);
const char* ReadShaderSource(const char* ShaderFilePath);
} // namespace Utils
#endif
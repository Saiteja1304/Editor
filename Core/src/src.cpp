#include <Utils/Utils.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>
void Utils::LoadMesh(const char *meshPath, float *vertexData, int *indexData,
                     unsigned short vertexDataSize,
                     unsigned short indexDataSize, bool isTextCoord,
                     bool isNormal) {
  std::ifstream input(meshPath, std::ios::binary);
  std::vector<char> bytes((std::istreambuf_iterator<char>(input)),
                          (std::istreambuf_iterator<char>()));
  input.close();

  int vertexSize = 0, indexSize = 0;
  int isvertexcoord = 0;
  int isvertexnormal = 0;

  char sizearray[4];

  sizearray[0] = bytes[0];
  sizearray[1] = bytes[1];
  sizearray[2] = bytes[2];
  sizearray[3] = bytes[3];
  memcpy(&vertexSize, sizearray, 4);
  vertexDataSize = vertexSize;

  sizearray[0] = bytes[4];
  sizearray[1] = bytes[5];
  sizearray[2] = bytes[6];
  sizearray[3] = bytes[7];
  memcpy(&indexSize, sizearray, 4);
  indexDataSize = indexSize;

  sizearray[0] = bytes[8];
  sizearray[1] = bytes[9];
  sizearray[2] = bytes[10];
  sizearray[3] = bytes[11];
  memcpy(&isvertexcoord, sizearray, 4);
  isTextCoord = isvertexcoord;

  sizearray[0] = bytes[12];
  sizearray[1] = bytes[13];
  sizearray[2] = bytes[14];
  sizearray[3] = bytes[15];
  memcpy(&isvertexnormal, sizearray, 4);
  isNormal = isvertexnormal;

  vertexData = new float[int(vertexSize)];
  indexData = new int[indexSize];
  int vertexStartIndex = 16, elementSize = 4;
  for (int i = 0; i < vertexSize; i++) {
    sizearray[0] = bytes[vertexStartIndex + (elementSize * i) + 0];
    sizearray[1] = bytes[vertexStartIndex + (elementSize * i) + 1];
    sizearray[2] = bytes[vertexStartIndex + (elementSize * i) + 2];
    sizearray[3] = bytes[vertexStartIndex + (elementSize * i) + 3];
    memcpy(&vertexData[i], sizearray, 4);
  }
  int indexStartIndex = vertexStartIndex + (vertexSize * elementSize);
  for (int i = 0; i < indexSize; i++) {
    sizearray[0] = bytes[indexStartIndex + (elementSize * i) + 0];
    sizearray[1] = bytes[indexStartIndex + (elementSize * i) + 1];
    sizearray[2] = bytes[indexStartIndex + (elementSize * i) + 2];
    sizearray[3] = bytes[indexStartIndex + (elementSize * i) + 3];
    memcpy(&indexData[i], sizearray, 4);
  }
}
const char *Utils::ReadShaderSource(const char *ShaderFilePath) {
  const char *shaderSource;

  std::ifstream shaderFile;
  shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    shaderFile.open(ShaderFilePath);
    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    shaderSource = shaderStream.str().c_str();
  } catch (std::ifstream::failure e) {
    std::cerr << "[ERROR] [FILEIO][SHADER]\n";
  }
  return shaderSource;
}
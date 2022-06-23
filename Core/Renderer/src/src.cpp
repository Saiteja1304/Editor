#include <PrimaryRenderer.hpp>
#include <glad/glad.h>
#include <iostream>

void Renderer::Init_Renderer() { gladLoadGL(); }
void Renderer::setViewportSize(iVector2 startPos, iVector2 size) { glViewport(startPos.x, startPos.y, size.x, size.y); }
void Renderer::update_Renderer() {
    glClearColor(0.75, 0.75, 0.75, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glEnable(GL_FRONT);
    glEnable(GL_DEPTH_TEST);
}

// draws elements
// requires mvp matrix
void Renderer::Draw(unsigned int vertexArrayObject, unsigned short int indexDataSize, unsigned int shaderProgram, float *mvmatPtr, float* pmatPtr,
                    unsigned int mvMatLocation, unsigned int pMatLocation) {
    glBindVertexArray(vertexArrayObject);
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(mvMatLocation, 1, GL_FALSE, mvmatPtr);
    glUniformMatrix4fv(pMatLocation, 1, GL_FALSE, pmatPtr);
    glDrawElements(GL_TRIANGLES, indexDataSize, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

// laods buffers
void Renderer::LoadBufferstn(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                             unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer) {
#ifdef EVALUATION_ENABLED
    if ((indexDataSize == 0) || (vertexDataSize == 0)) {
        std::cerr << "[ERROR] [BUFFERS] [MESH] \n";
    }
#endif
    // Generating and binding vao
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // Generating and bind vbo
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize * sizeof(float), &vertexData[0], GL_STATIC_DRAW);

    // enabling vertex data position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // enabling vertex text coordinate data layout and configuring data
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // enabling normal data layout and configuring data
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Generating and binding index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexDataSize, &indexData[0], GL_STATIC_DRAW);

    // Unbinding vertex array object
    glBindVertexArray(0);
}
// laods buffers
void Renderer::LoadBufferst(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                            unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer) {
#ifdef EVALUATION_ENABLED
    if ((indexDataSize == 0) || (vertexDataSize == 0)) {
        std::cerr << "[ERROR] [BUFFERS] [MESH] \n";
    }
#endif
    // Generating and binding vao
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // Generating and bind vbo
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize * sizeof(float), &vertexData[0], GL_STATIC_DRAW);

    // enabling vertex data position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // enabling vertex text coordinate data layout and configuring data
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Generating and binding index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexDataSize, &indexData[0], GL_STATIC_DRAW);

    // Unbinding vertex array object
    glBindVertexArray(0);
}
// laods buffers
void Renderer::LoadBuffersn(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                            unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer) {
#ifdef EVALUATION_ENABLED
    if ((indexDataSize == 0) || (vertexDataSize == 0)) {
        std::cerr << "[ERROR] [BUFFERS] [MESH] \n";
    }
#endif
    // Generating and binding vao
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // Generating and bind vbo
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize * sizeof(float), &vertexData[0], GL_STATIC_DRAW);

    // enabling vertex data position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // enabling normal data layout and configuring data
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Generating and binding index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexDataSize, &indexData[0], GL_STATIC_DRAW);

    // Unbinding vertex array object
    glBindVertexArray(0);
}
// laods buffers
void Renderer::LoadBuffers(unsigned short int vertexDataSize, unsigned short int indexDataSize, float *vertexData, int *indexData,
                           unsigned int vertexArrayObject, unsigned int vertexBuffer, unsigned int indexBuffer) {
#ifdef EVALUATION_ENABLED
    if ((indexDataSize == 0) || (vertexDataSize == 0)) {
        std::cerr << "[ERROR] [BUFFERS] [MESH] \n";
    }
#endif
    // Generating and binding vao
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // Generating and bind vbo
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize * sizeof(float), &vertexData[0], GL_STATIC_DRAW);

    // enabling vertex data position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Generating and binding index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexDataSize, &indexData[0], GL_STATIC_DRAW);

    // Unbinding vertex array object
    glBindVertexArray(0);
}
void Renderer::LoadShaders(const char *vertexShaderSource, const char *fragmentShaderSource, unsigned int shaderProgram) {
    unsigned int vertexShader, fragmentShader;

    // loading vertex Shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

#ifdef EVALUATION_ENABLED
    int success;
    char LOG[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, LOG);
        std::cerr << "[ERROR] [SHADER] [VERTEX] " << LOG << "\n";
    }
#endif

    // loading fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

#ifdef EVALUATION_ENABLED
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, LOG);
        std::cerr << "[ERROR] [SHADER] [FRAGMENT] " << LOG << "\n";
    }
#endif

    // loading ShaderProgram shader
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

#ifdef EVALUATION_ENABLED
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, LOG);
        std::cerr << "[ERROR] [SHADER] [PROGRAM] " << LOG << "\n";
    }
#endif
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
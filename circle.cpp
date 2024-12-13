#include "circle.h"

#include <GL/glew.h>
#include <cmath>

void Circle::Initialize(){
    const int vertices = 32;
    GLfloat kVertices[vertices * 4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat kColors[vertices * 4] = { 0.2f, 0.1f, 0.1f, 1.0f };

    const float radius = 0.5f;
    for (int i = 0; i < vertices; ++i){
        const float angle = 2.0f * M_PI * i / vertices;
        kVertices[i * 4 + 0] = radius * cos(angle);
        kVertices[i * 4 + 1] = radius * sin(angle);
        kVertices[i * 4 + 2] = 0.0f;
        kVertices[i * 4 + 3] = 1.0f;

        kColors[i * 4 + 0] = kColors[0];
        kColors[i * 4 + 1] = kColors[1];
        kColors[i * 4 + 2] = kColors[2];
        kColors[i * 4 + 3] = kColors[3];
    }


    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kVertices), kVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &color_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kColors), kColors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

Circle::~Circle(){
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteBuffers(1, &color_buffer_);
    glDeleteBuffers(1, &vertex_buffer_);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vao_);
}

void Circle::Draw(const Program &program){

    glUseProgram(program);
    glBindVertexArray(vao_);

    glDrawArrays(GL_LINE_LOOP, 0, 64);

    glBindVertexArray(0);
    glUseProgram(0);


}

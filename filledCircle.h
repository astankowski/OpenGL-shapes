#ifndef FILLEDCIRCLE_H
#define FILLEDCIRCLE_H

#include <GL/glew.h>

#include "program.h"

class FilledCircle{
 public:
    void Initialize();
    ~FilledCircle();
    void Draw(const Program & program);
 private:
    GLuint vao_;
    GLuint vertex_buffer_;
    GLuint color_buffer_;
};

#endif // FILLEDCIRCLE_H

#ifndef FILLEDSTAR_H
#define FILLEDSTAR_H

#include <GL/glew.h>

#include "program.h"

class FilledStar{
 public:
    void Initialize();
    ~FilledStar();
    void Draw(const Program & program);
 private:
    GLuint vao_;
    GLuint vertex_buffer_;
    GLuint color_buffer_;
};

#endif // FILLEDSTAR_H

# OpenGL-shapes
 
```bash
    $ make run
    g++ -c -Wall -DDEBUG -g3 -fpermissive -std=c++11 -MMD main.cpp -o main.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
    g++ circle.o filledCircle.o filledStar.o glerror.o main.o program.o star.o triangle.o window.o -o triangle  -lX11 -lglfw -lGL -lGLU -lGLEW -lm
```

![image](https://github.com/user-attachments/assets/6296ea2f-03ef-452c-8dc3-c481f8b76007)

```bash
    $ make clean 
    rm -f triangle circle.o filledCircle.o filledStar.o glerror.o main.o program.o star.o triangle.o window.o
    rm -f circle.d filledCircle.d filledStar.d glerror.d main.d program.d star.d triangle.d window.d
```

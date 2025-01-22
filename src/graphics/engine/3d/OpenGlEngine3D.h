//
// Created by osklot12 on 1/17/25.
//

#ifndef REASONATE_CLI_OPENGLENGINE_H
#define REASONATE_CLI_OPENGLENGINE_H

#include <glad/glad.h>
#include <vector>
#include <memory>

#include "../shader/ShaderProgram.h"
#include "../camera/Camera.h"
#include "../../input/InputManagerOpenGl.h"

import Graphics.Engine3D;
import Graphics.OpenGlEngine;
import Graphics.OpenGlStatus;
import Graphics.Object;

namespace Graphics {
    // a 3d graphics engine implementation using opengl
    class OpenGlEngine3D : public OpenGlEngine, public Engine3D {
    public:
        OpenGlEngine3D();

        ~OpenGlEngine3D() override;

        // runs the engine
        void run() override;

        // adds graphical object
        void addObject(Object& obj);

    private:
        // initializes the graphics engine
        void initEngine();

        // creates a shader program
        static ShaderProgram createShaderProgram();

        void setShaderProgram(ShaderProgram &shader);

        // initializes the vertex array objects needed
        void initVao();

        // initializes the vertex buffer object
        void initVbo();

        // adds a vertex attribute
        void addVertexAttribute(int index, int size, GLenum type, bool normalized, int stride, const void *ptr);

        // clears all vertex attributes
        void clearVertexAttributes();

        // initializes vertex arrays needed
        void initVertexArrays();

        Input::InputManagerOpenGl createInputManager();

        // shader program
        std::unique_ptr<ShaderProgram> shaderProgram;

        // vertex buffer object and vertex array object
        unsigned int vbo, vao;

        // camera
        Camera camera;

        // delta time
        float deltaTime;

        // last frame
        float lastFrame;

        // input manager
        Input::InputManagerOpenGl inputManager;

        // default screen dimensions
        static constexpr unsigned int SCR_WIDTH = 800;
        static constexpr unsigned int SCR_HEIGHT = 600;

        std::vector<Object> objects;
    };
}

#endif //REASONATE_CLI_OPENGLENGINE_H

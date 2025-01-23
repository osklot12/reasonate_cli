//
// Created by osklot12 on 1/17/25.
//

#ifndef REASONATE_CLI_OPENGLENGINE_H
#define REASONATE_CLI_OPENGLENGINE_H

#include "../../../../libs/glad/include/glad/glad.h"
#include <vector>
#include <array>
#include <memory>

#include "Engine2D.h"
#include "../../shader/ShaderProgram.h"
#include "../../input/InputManagerOpenGl.h"
#include "../camera/Cam2DOpenGl.h"
#include "../base/OpenGlEngine.h"
#include "../../object/2d/Object2D.h"

namespace Graphics {
    class Object2D;

    // a 2d graphics engine implementation using opengl
    class OpenGlEngine2D : public OpenGlEngine, public Engine2D {
    public:
        // constructor
        OpenGlEngine2D();

        // destructor
        ~OpenGlEngine2D() override;

        // runs the engine
        void run() override;

        // adds graphical object
        void addObject(Object2D& obj);

        // draws a line
        void drawLine(const std::array<float, 2>& from, const std::array<float, 2>& to, const std::array<float, 4>& color);

        // getter for camera
        Camera2D& getCamera() override;

        // getter for input manager
        Input::InputManager& getInputManager() override;

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

        void drawObject(const Object2D& obj, const unsigned int vbo, const unsigned int vao);

        // shader program
        std::unique_ptr<ShaderProgram> shaderProgram;

        // vertex buffer object and vertex array object
        unsigned int vbo, vao;

        // delta time
        float deltaTime;

        // last frame
        float lastFrame;

        // camera
        Cam2DOpenGl camera;

        // input manager
        Input::InputManagerOpenGl inputManager;

        // default screen dimensions
        static constexpr unsigned int SCR_WIDTH = 800;
        static constexpr unsigned int SCR_HEIGHT = 600;

        // graphics objects active
        std::vector<Object2D> objects;

        glm::mat4 projectionMatrix;
    };
}

#endif //REASONATE_CLI_OPENGLENGINE_H

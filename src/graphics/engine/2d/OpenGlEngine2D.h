//
// Created by osklot12 on 1/17/25.
//

#ifndef REASONATE_CLI_OPENGLENGINE_H
#define REASONATE_CLI_OPENGLENGINE_H

#include "../../../../libs/glad/include/glad/glad.h"
#include <vector>
#include <memory>

#include "Engine2D.h"
#include "../../shader/ShaderProgram.h"
#include "../camera/Cam2DOpenGl.h"
#include "../base/OpenGlEngine.h"
#include "../../object/2d/Object2D.h"

namespace Graphics {
    // 2d graphics engine implementation using opengl
    class OpenGlEngine2D final : public OpenGlEngine, public Engine2D {
    public:
        // constructor
        OpenGlEngine2D();

        // destructor
        ~OpenGlEngine2D() override;

        // runs the engine
        void run() override;

        // adds a graphical object
        void addObject(Object2D &obj) override;

        // provides access to the camera
        std::shared_ptr<Camera2D> getCamera() override;

        // provides access to the input manager
        std::shared_ptr<Input::InputManager> getInputManager() override;

    private:
        // initializes the graphics engine
        void initEngine();

        // initializes the framebuffer size callback
        void initFramebufferCallback();

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

        // configures the input manager
        void configInputManager();

        // draws a graphical object
        void drawObject(const Object2D &obj, unsigned int vbo, unsigned int vao);

        // shader program
        std::unique_ptr<ShaderProgram> shaderProgram;

        // vertex buffer object and vertex array object
        unsigned int vbo, vao;

        // camera
        std::shared_ptr<Cam2DOpenGl> camera;

        // input manager
        std::shared_ptr<Input::InputManagerOpenGl> inputManager;

        // default screen dimensions
        static constexpr unsigned int SCR_WIDTH = 800;
        static constexpr unsigned int SCR_HEIGHT = 600;

        // graphical objects
        std::vector<Object2D> objects;

        glm::mat4 projectionMatrix;

        // shader sources
        static constexpr auto V_SHADER_SOURCE = "../src/graphics/shader/shader_src/2d/shader.vs";
        static constexpr auto F_SHADER_SOURCE = "../src/graphics/shader/shader_src/2d/shader.fs";
    };
}

#endif //REASONATE_CLI_OPENGLENGINE_H

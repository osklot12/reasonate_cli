//
// Created by osklot12 on 1/21/25.
//

#ifndef CAM2DOPENGL_H
#define CAM2DOPENGL_H

#include <array>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/detail/type_vec2.hpp>

#include "Camera2D.h"

namespace Graphics {
    // a 2d camera for opengl
    class Cam2DOpenGl : public Camera2D {
    public:
        // constructor
        Cam2DOpenGl();

        // move functions
        void moveVertical(float amount) override;

        void moveHorizontal(float amount) override;

        // rotation function
        void rotate(float angle) override;

        // zoom function
        void adjustZoom(float amount) override;

        // getters
        const std::array<float, 2> getPos() const override;

        float getRotation() const override;

        float getZoom() const override;

        [[nodiscard]] glm::mat4 getViewMatrix() const;

        // setters
        void setPos(float x, float y) override;

        void setRotation(float angle) override;

        void setZoom(float zoom_) override;
    private:
        // normalizes a rotation angle
        static float normalizeRotation(const float angle);

        // counterclockwise rotation
        float rotation;

        // zoom (scale)
        float zoom;

        // camera vectors
        glm::vec2 posVec;

        glm::vec2 dirVec;

        glm::vec2 upVec;

        glm::vec2 rightVec;

        // world vector
        glm::vec2 worldUpVec;

        // view matrix
        glm::mat4 viewMatrix;

        [[nodiscard]] glm::mat4 genViewMatrix() const;
    };
}

#endif //CAM2DOPENGL_H

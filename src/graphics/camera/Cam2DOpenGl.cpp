//
// Created by osklot12 on 1/21/25.
//

#include <array>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_vec2.hpp>
#include <cmath>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Cam2DOpenGl.h"

// defaults
constexpr float INIT_ROTATION = 0;
constexpr float INIT_ZOOM = 1;

constexpr auto INIT_POS = glm::vec2(.0f, .0f);
constexpr auto INIT_DIR = glm::vec2(.0f, -1.0f);
constexpr auto INIT_UP = glm::vec2(0.0f, 1.0f);
constexpr auto INIT_RIGHT = glm::vec2(1.0f, 0.0f);
constexpr auto INIT_WORLD_UP = glm::vec2(0.0f, 1.0f);

namespace Graphics {
    Cam2DOpenGl::Cam2DOpenGl() : rotation(INIT_ROTATION), zoom(INIT_ZOOM), posVec(INIT_POS), dirVec(INIT_DIR),
                                 upVec(INIT_UP), rightVec(INIT_RIGHT), worldUpVec(INIT_WORLD_UP) {
    }

    void Cam2DOpenGl::moveVertical(const float amount) {
        posVec.y += amount;
        viewMatrix = genViewMatrix();
    }

    void Cam2DOpenGl::moveHorizontal(const float amount) {
        posVec.x += amount;
        viewMatrix = genViewMatrix();
    }

    void Cam2DOpenGl::rotate(const float angle) {
        rotation = normalizeRotation(rotation + angle);
        viewMatrix = genViewMatrix();
    }

    void Cam2DOpenGl::adjustZoom(const float amount) {
        zoom += amount;
        viewMatrix = genViewMatrix();
    }

    const std::array<float, 2> Cam2DOpenGl::getPos() const {
        return std::array{posVec.x, posVec.y};
    }

    float Cam2DOpenGl::getRotation() const {
        return rotation;
    }

    float Cam2DOpenGl::getZoom() const {
        return zoom;
    }

    void Cam2DOpenGl::setPos(const float x, const float y) {
        posVec.x = x;
        posVec.y = y;
        viewMatrix = genViewMatrix();
    }

    void Cam2DOpenGl::setRotation(const float angle) {
        rotation = normalizeRotation(angle);
        viewMatrix = genViewMatrix();
    }

    void Cam2DOpenGl::setZoom(const float zoom_) {
        zoom = zoom_;
        viewMatrix = genViewMatrix();
    }

    float Cam2DOpenGl::normalizeRotation(const float angle) {
        float normAngle = std::fmod(angle, 360.0f);
        if (normAngle < 0.0f) {
            normAngle += 360.0f;
        }
        return normAngle;
    }

    glm::mat4 Cam2DOpenGl::getViewMatrix() const {
        return viewMatrix;
    }

    glm::mat4 Cam2DOpenGl::genViewMatrix() const {
        auto viewMatrix = glm::mat4(1.0f);

        // translation
        viewMatrix = glm::translate(viewMatrix, glm::vec3(-posVec, 0.0f));

        // rotation
        const float radians = glm::radians(-rotation);
        viewMatrix = glm::rotate(viewMatrix, radians, glm::vec3(0.0f, 0.0f, 1.0f));

        // scaling
        viewMatrix = glm::scale(viewMatrix, glm::vec3(1.0f / zoom, 1.0f / zoom, 1.0f));

        return viewMatrix;
    }

}

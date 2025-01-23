//
// Created by osklot12 on 12/31/24.
//

#ifndef REASONATE_CLI_CAMERA_H
#define REASONATE_CLI_CAMERA_H

#include "glm/vec3.hpp"
#include "glm/detail/type_mat.hpp"

// default camera values
constexpr glm::vec3 CAMERA_POS = glm::vec3(0.0f, 0.0f, 3.0f);
constexpr glm::vec3 CAMERA_DIR = glm::vec3(0.0f, 0.0f, -1.0f);
constexpr glm::vec3 WORLD_UP = glm::vec3(0.0f, 1.0f, 0.0f);

// default euler angles
constexpr float YAW = -90.0f;
constexpr float PITCH = 0.0f;

// default zoom value
constexpr float ZOOM = 45.0f;
constexpr float MIN_ZOOM = 1.0f;
constexpr float MAX_ZOOM = 45.0f;

// default extreme values
constexpr float MIN_PITCH = -89.0f;
constexpr float MAX_PITCH = 89.0f;

// an abstraction of a camera
class Camera {
public:
    // constructor
    explicit Camera(glm::vec3 pos = CAMERA_POS, glm::vec3 up = WORLD_UP,
           float yaw_ = YAW, float pitch_ = PITCH);

    // getters
    float getYaw() const;
    float getPitch() const;
    const glm::vec3 &getPosition() const;
    const glm::vec3 &getDirection() const;
    const glm::vec3 &getUp() const;
    const glm::vec3 &getWorldUp() const;
    float getZoom() const;

    // move functions
    void moveForward(float amount);
    void moveRight(float amount);
    void moveBackward(float amount);
    void moveLeft(float amount);

    // rotation functions
    void adjustPitch(float amount);
    void adjustYaw(float amount);

    // zoom functions
    void adjustZoom(float amount);

    // vector setters
    void setCameraPos(glm::vec3 pos);
    void setCameraDir(glm::vec3 dir);

    // getting the view matrix
    glm::mat4 getViewMatrix() const;
private:
    // zoom
    float zoom;

    // euler angles
    float yaw;
    float pitch;

    // camera vectors
    glm::vec3 posVec;
    glm::vec3 dirVec;
    glm::vec3 upVec;
    glm::vec3 rightVec;

    // world vector
    glm::vec3 worldUpVec;

    // indicates if mouse has been moved
    bool firstMouse;

    // last mouse x and y pos
    float lastX, lastY;

    // configuring camera vectors
    void updateDirVecFromAngles();
    void updateRightVec();
    void updateUpVec();
    void updateCameraVectors();
};


#endif //REASONATE_CLI_CAMERA_H

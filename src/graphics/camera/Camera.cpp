//
// Created by osklot12 on 12/31/24.
//

#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>
#include <algorithm>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw_, float pitch_) : posVec(position),
                                                                             worldUpVec(glm::normalize(up)),
                                                                             yaw(yaw_), pitch(pitch_),
                                                                             zoom(ZOOM) {
    updateCameraVectors();
}

float Camera::getYaw() const {
    return yaw;
}

float Camera::getPitch() const {
    return pitch;
}

const glm::vec3 &Camera::getPosition() const {
    return posVec;
}

const glm::vec3 &Camera::getDirection() const {
    return dirVec;
}

const glm::vec3 &Camera::getUp() const {
    return upVec;
}

const glm::vec3 &Camera::getWorldUp() const {
    return worldUpVec;
}

float Camera::getZoom() const {
    return zoom;
}

void Camera::moveForward(float amount) {
    posVec += dirVec * amount;
}

void Camera::moveRight(float amount) {
    posVec += glm::normalize(glm::cross(dirVec, upVec)) * amount;
}

void Camera::moveBackward(float amount) {
    posVec -= dirVec * amount;
}

void Camera::moveLeft(float amount) {
    posVec -= glm::normalize(glm::cross(dirVec, upVec)) * amount;
}

void Camera::adjustPitch(float amount) {
    pitch += amount;
    pitch = std::clamp(pitch, MIN_PITCH, MAX_PITCH);
    updateCameraVectors();
}

void Camera::adjustYaw(float amount) {
    yaw += amount;
    updateCameraVectors();
}

void Camera::adjustZoom(float amount) {
    zoom += amount;
    zoom = std::clamp(zoom, MIN_ZOOM, MAX_ZOOM);
}

void Camera::setCameraPos(glm::vec3 pos) {
    posVec = pos;
}

void Camera::setCameraDir(glm::vec3 dir) {
    if (dir == glm::vec3(0.0f)) {
        throw std::invalid_argument("The direction vector cannot be the null vector.");
    }
    dirVec = glm::normalize(dir);

    pitch = glm::degrees(asin(dirVec.y));
    yaw = glm::degrees(atan2(-dirVec.z, dirVec.x));

    updateRightVec();
    updateUpVec();
}

void Camera::updateDirVecFromAngles() {
    glm::vec3 dir;
    dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    dir.y = sin(glm::radians(pitch));
    dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    dirVec = glm::normalize(dir);
}

void Camera::updateRightVec() {
    rightVec = glm::normalize(glm::cross(dirVec, worldUpVec));
}

void Camera::updateUpVec() {
    upVec = glm::normalize(glm::cross(rightVec, dirVec));
}

void Camera::updateCameraVectors() {
    updateDirVecFromAngles();
    updateRightVec();
    updateUpVec();
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(posVec, posVec + dirVec, upVec);
}
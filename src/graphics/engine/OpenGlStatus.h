//
// Created by osklot12 on 1/22/25.
//

#ifndef OPENGLSTATUS_H
#define OPENGLSTATUS_H

class OpenGlStatus {
public:
    // static method to get the singleton instance
    static OpenGlStatus& instance() {
        static OpenGlStatus instance;
        return instance;
    }

    // mark opengl as configured
    void setConfigured(bool status) {
        isConfigured = status;
    }

    // check if opengl is configured
    bool getConfigured() const {
        return isConfigured;
    }
private:
    // tracks opengl status
    bool isConfigured;

    OpenGlStatus() : isConfigured(false) {};

    // delete copy constructor and assignment operator
    OpenGlStatus(const OpenGlStatus&) = delete;
    OpenGlStatus& operator=(const OpenGlStatus&) = delete;
};

#endif //OPENGLSTATUS_H

//
// Created by osklot12 on 1/23/25.
//

#include "Epsilon.h"

#include <vector>

#include "../object/2d/Object2D.h"
#include "../../input/InputManager.h"
#include "../camera/Camera2D.h"

namespace Graphics {
    Epsilon::Epsilon(std::unique_ptr<Engine2D> engine_) {
        if (!engine_) {
            throw std::invalid_argument("Engine is null");
        }
        engine = std::move(engine_);
        init();
    }

    void Epsilon::run() {
        engine->run();
    }


    void Epsilon::init() {
        const std::vector<float> vertices{
            -200.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
            200.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
        };

        Object2D line{vertices};
        engine->addObject(line);

        const std::shared_ptr<Input::InputManager> inputManager = engine->getInputManager();
        const std::shared_ptr<Camera2D> cam = engine->getCamera();
        inputManager->registerKeyCallback(Input::KeyBinding::W, [cam](const float deltaTime) {
            cam->moveVertical(100.0f * deltaTime);
        });
    }
}

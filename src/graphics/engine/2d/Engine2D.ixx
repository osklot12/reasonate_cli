//
// Created by osklot12 on 1/19/25.
//

export module Graphics.Engine2D;

import Graphics.Engine;
import Graphics.Camera2D;
import Input.InputManager;

export namespace Graphics {
    // a graphics engine providing two dimensions
    class Engine2D : public Engine {
    public:
        // destructor
        ~Engine2D() override = default;

        // getter for camera
        virtual Camera2D& getCamera() = 0;
    };
}
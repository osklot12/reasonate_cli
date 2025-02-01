//
// Created by osklot12 on 2/1/25.
//

#ifndef FRAMETIME_H
#define FRAMETIME_H

namespace Graphics {
    // data used for frame timing calculations
    struct FrameTime {
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;
    };
}

#endif //FRAMETIME_H

//
// Created by osklot12 on 1/22/25.
//

#ifndef KEYBINDINGS_H
#define KEYBINDINGS_H
#include <GLFW/glfw3.h>

namespace Input {
    // available key bindings
    enum class KeyBinding {
        Q, W, E, R, T, Y, U, I, O, P,
        A, S, D, F, G, H, J, K, L,
        Z, X, C, V, B, N, M,
        ArrowUp, ArrowDown, ArrowLeft, ArrowRight,
        Space, Escape, Enter, Shift, LeftCtrl, LeftAlt
    };

    // maps key binding to implementation key code
    class KeyMapper {
    public:
        // maps key bindings to glfw key codes
        static int mapKeyBindingToGLFWKey(const KeyBinding key) {
            switch (key) {
                case KeyBinding::Q: return GLFW_KEY_Q;
                case KeyBinding::W: return GLFW_KEY_W;
                case KeyBinding::E: return GLFW_KEY_E;
                case KeyBinding::R: return GLFW_KEY_R;
                case KeyBinding::T: return GLFW_KEY_T;
                case KeyBinding::Y: return GLFW_KEY_Y;
                case KeyBinding::U: return GLFW_KEY_U;
                case KeyBinding::I: return GLFW_KEY_I;
                case KeyBinding::O: return GLFW_KEY_O;
                case KeyBinding::P: return GLFW_KEY_P;
                case KeyBinding::A: return GLFW_KEY_A;
                case KeyBinding::S: return GLFW_KEY_S;
                case KeyBinding::D: return GLFW_KEY_D;
                case KeyBinding::F: return GLFW_KEY_F;
                case KeyBinding::G: return GLFW_KEY_G;
                case KeyBinding::H: return GLFW_KEY_H;
                case KeyBinding::J: return GLFW_KEY_J;
                case KeyBinding::K: return GLFW_KEY_K;
                case KeyBinding::L: return GLFW_KEY_L;
                case KeyBinding::Z: return GLFW_KEY_Z;
                case KeyBinding::X: return GLFW_KEY_X;
                case KeyBinding::C: return GLFW_KEY_C;
                case KeyBinding::V: return GLFW_KEY_V;
                case KeyBinding::B: return GLFW_KEY_B;
                case KeyBinding::N: return GLFW_KEY_N;
                case KeyBinding::M: return GLFW_KEY_M;

                case KeyBinding::ArrowUp: return GLFW_KEY_UP;
                case KeyBinding::ArrowDown: return GLFW_KEY_DOWN;
                case KeyBinding::ArrowLeft: return GLFW_KEY_LEFT;
                case KeyBinding::ArrowRight: return GLFW_KEY_RIGHT;

                case KeyBinding::Space: return GLFW_KEY_SPACE;
                case KeyBinding::Escape: return GLFW_KEY_ESCAPE;
                case KeyBinding::Enter: return GLFW_KEY_ENTER;
                case KeyBinding::LeftCtrl: return GLFW_KEY_LEFT_CONTROL;
                case KeyBinding::LeftAlt: return GLFW_KEY_LEFT_SHIFT;

                default: return -1;
            }
        }
    };
}

#endif //KEYBINDINGS_H

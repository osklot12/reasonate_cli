#version 330 core

// input from the vertex shader
in vec3 vColor;
in float vOpacity;

// output color to the framebuffer
out vec4 fragColor;

void main() {
    // output the interpolated color with full opacity
    fragColor = vec4(vColor, vOpacity);
}
#version 330 core

// input attributes from the vertex buffer
layout(location = 0) in vec2 aPosition;
layout(location = 1) in vec4 aColor;

// output attributes passed to the fragment shader
out vec3 vColor;
out float vOpacity;

// uniforms
uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

void main() {
    // transform the vertex position and pass it to the pipeline
    gl_Position = uProjection * uView * uModel * vec4(aPosition, 0.0, 1.0);

    // pass the vertex color to the fragment shader
    vColor = aColor.rgb;
    vOpacity = aColor.a;
}
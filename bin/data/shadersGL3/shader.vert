#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float time;
uniform vec2 resolution;

void main()
{
    vec4 pos = position;
    
    gl_Position = modelViewProjectionMatrix * pos;
}


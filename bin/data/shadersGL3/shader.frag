#version 150

out vec4 outputColor;
uniform float time;
uniform vec2 resolution;

float sdSphere(vec3 p, float s) {
    return length(p) - s;
}

float map(vec3 p) {
    p.y += cos(length(p.zx) * .1 - time) * 5.0;
    p -= vec3(p.z * -.5, p.z * .5, 0);
    p.zx = mod(p.zx, 2.) - 2.;
    return sdSphere(p, 1.);
}

void main( void ) {
    vec2 uv = (gl_FragCoord.xy * 2. - resolution) / resolution.y;
    vec3 rd = normalize(vec3(0, 0, 1));
    vec3 ro = vec3(uv * 100., -100.);
    
    vec3 color = vec3(255);
    float dist = 0.;
    
    
    
    for (int i = 0; i < 50; i++) {
        vec3 p = ro + rd * dist;
        float d = map(p);
        
        if (d < .01) {
            color = vec3(1, 0, 1) * 5.0 / cos(float(i));
            break;
        }
        
        dist += d;
        if (dist > 400.) break;
    }
    
    outputColor = vec4(sin(color.x), sin(color.y), cos(color.z), 1);
}

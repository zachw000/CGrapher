vec2 complex_mult(vec2 a, vec2 b) {
    return vec2(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

float vec_mag(vec2 vector) {
    return sqrt(vector.x*vector.x+vector.y*vector.y);
}

vec3 mandelbrot_math(vec2 c_num, vec2 coord, int max_iter) {
    int iterations;
    for (iterations = 0; iterations < max_iter; iterations++) {
        c_num = complex_mult(c_num, c_num);
        c_num += coord;
        if (vec_mag(c_num) > 2.5) {
            c_num = vec2(0.0, 0.0);
            break;
        }
    }
    
    return vec3(c_num, iterations);
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float scale = 3.0;
    // Normalized pixel coordinates (from 0 to 1)
    //vec2 uv = (scale * fragCoord/iResolution.xy - vec2(scale/2.0, scale/2.0));
    vec2 uv = ((fragCoord * 2.0 - iResolution.xy) / iResolution.y);
    vec2 mi = scale * iMouse.xy/iResolution.xy - vec2(scale/2.0, scale/2.0);

    // Time varying pixel color
    vec3 col = 0.5 + 0.5*cos(mi.xyx+uv.xyx+vec3(0,3,4));
    vec3 mandelset = mandelbrot_math(uv, uv, 1000);
    mandelset.z = sin(mandelset.z / 100.0);
    mandelset.xy /= 6.25;
    
    mandelset.x *= sin(mandelset.z / 100.0);
    mandelset.y *= sin(mandelset.z / 100.0);

    // Output to screen
    fragColor = vec4(mandelset,0.50);
}
/////////////////////////////////////////////////////////////////////////////////////////////
vec2 complex_mult(vec2 a, vec2 b) {
    return vec2(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}

float vec_mag(vec2 vector) {
    return sqrt(vector.x*vector.x+vector.y*vector.y);
}

vec3 mandelbrot_math(vec2 c_num, vec2 coord, int max_iter) {
    int iterations;
    for (iterations = 0; iterations < max_iter; iterations++) {
        c_num = complex_mult(c_num, c_num);
        c_num += coord;
        if (vec_mag(c_num) > 2.5) {
            //c_num = vec2(0.0, 0.0);
            c_num.x = 0.5 * cos(c_num.x / 6.282 + float(iterations) / 5.0) + 0.5;
            c_num.y = 0.5 * sin(c_num.y / 6.282 + float(iterations) / 5.0) + 0.5;
            //break;
            return vec3(c_num, 0.0);
        }
    }
    
    return vec3(c_num, iterations);
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    float scale = 3.0;
    float e = 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449920695517027618386062613313845830007520449338265602976067371132007093287091274437470472306969772093101416928368190255151086574637727052709886283999344114499350782227987009277152807317679077071572134447306057007334924369311383504931631284042512192565179806941135280131470130478164378851853437350275900906412606611523451408;
    vec2 point = vec2(0.0);
    // Normalized pixel coordinates (from 0 to 1)
    //vec2 uv = (scale * fragCoord/iResolution.xy - vec2(scale/2.0, scale/2.0));
    vec2 uv = ((fragCoord * 2.0 - iResolution.xy) / iResolution.y) / pow(2.0, 0.0 * (0.5 * sin(iTime / 1.0) + 0.5)) + point;
    vec2 mi = scale * iMouse.xy/iResolution.xy - vec2(scale/2.0, scale/2.0);
    // Time varying pixel color
    vec3 col = 0.5 + 0.5*cos(mi.xyx+uv.xyx+vec3(0,3,4));
    vec3 mandelset = mandelbrot_math(uv, mi, 1000);
    float iterations = mandelset.z;
    mandelset.z = sin((mandelset.z - 50.0 * 3.14159265358979323846) / 100.0 + iTime / 5.0)*0.5 + 0.5;
    
    mandelset = mod(mandelset, 1.0);

    // Output to screen
    fragColor = vec4(mandelset,0.50);
}
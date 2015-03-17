GLSL Shaders
============
```
NOTICE: The "of.frag" and "of.vert" files MUST be moved to /bin/data of your
OpenFrameworks app, this demo will NOT work without those files in place!
```

GLSL shaders are a hugely powerful tool to render pixels on the graphics card.
The algorithm to generate the colours is placed in a special file, which is
compiled by OpenGL when the shader is loaded for the first time.

There are different types of shaders: in this tutorial we focus only on 
`fragment` shaders, which affect colour. 

The fragment shader used in this demo is `of.frag`, it sets all pixels to a
single colour. The colour changes over time, as in the OF code we write to the
`time` variable, as defined in the fragment shader as `uniform float time`.

Inspiration
-----------
As OpenGL has a web runtime called WebGL, it is possible to run shaders in a 
web browser. Checkout the [http://glslsandbox.com](http://glslsandbox.com) site,
they have some nice examples, and the code can be edited in the window:
[http://glslsandbox.com/e#22728.0](http://glslsandbox.com/e#22728.0)
[http://glslsandbox.com/e#23607.0](http://glslsandbox.com/e#23607.0).

The shaders from GlslSandbox cannot be copy-pasted into OF and expected to work.
This is due to the fact that the shaders depend on the `time` and `resolution`
GLSL variables. These are written into the GLSL code by the web-page.


Uniform Variables
-----------------
Uniform variables can be concidered as variables "shared" between GLSL and OF.
Openframeworks can write values to these variables, and GLSL will use the new
values.

The most common uniforms are `float`, `vec2` and `vec3`. A `float` value is
useful for communicating a scalar value : time for example. A `vec2` is generally
used as a X,Y co-ordinate, while `vec3` often contains RGB data.

Each uniform is declared in the `shaderName.frag` file, and the variable name itself
is used by OF to write it.

A short example, in the fragment shader we have a time variable like so:
```
uniform float time;
```
to write to it in OF, we do this:
```
shaderName.setUniform1f( "time", 0.5 );
```

The documentation on writing a single `float` is available: [http://openframeworks.cc/documentation/gl/ofShader.html#show_setUniform1f](http://openframeworks.cc/documentation/gl/ofShader.html#show_setUniform1f)
while a `vec2` (vector of floats, of size 2) can be written like so [http://openframeworks.cc/documentation/gl/ofShader.html#show_setUniform2f](http://openframeworks.cc/documentation/gl/ofShader.html#show_setUniform2f).



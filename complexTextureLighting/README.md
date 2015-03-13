Complex Texture Lighting
========================

This OF App demonstrates lighting and texture usage with 3D objects.
Note that this example is taken almost verbatim from the OpenFrameworks
examples/gl/multiLightExample project.

This code (`main.cpp`, `ofApp.cpp` and `ofApp.h`) needs to be put into a
generated OF app for your platform of choice, and then compiled.

Textures
--------
```
http://openframeworks.cc/documentation/gl/ofTexture.html
```
Textures are image data, that is drawn to the surface of a 3D shape. In
`ofApp.cpp : line 70` we load a `.png` image into a texture. Lines `99` and `121`
bind() and unbind() the texture respectively - this makes the texture get drawn.

Note: `ofDisableArbTex()` on line 68 is needed to map textures correctly - see
the note in the source code.

Lighting
--------
```
http://openframeworks.cc/documentation/gl/ofLight.html
```
Lighting in OpenGL is similar to stage lighting - various different types exist,
`point`, `spot` and `directional` are three common ones. Each light can emit
different colours - not just the 'main' colour, but the `specular` and `diffuse`
colours can be set individually.

`ofApp.cpp : line 25` does `pointLight.setDiffuseColor( ofColor(0.f, 255.f, 0.f));`
This sets the diffuse colour of the light to 100% green - run the application,
and notice the green point light, and how it affects the scene.

Conclusion
----------
Textures and lighting can add a lot to depth and intricacy to a scene. As the
lighting is calculated per-pixel (when `ofSetSmoothLighting( true )` is called),
it can provide a very pleasing polished aesthetic.

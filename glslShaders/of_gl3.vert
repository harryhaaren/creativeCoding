
// taken from from OF examples/gl/shaderExample

attribute vec4 a_Position;     // Per-vertex position information we will pass in.
attribute vec4 a_Color;        // Per-vertex color information we will pass in.
attribute vec3 a_Normal;       // Per-vertex normal information we will pass in.
 
varying vec3 v_Position;       // This will be passed into the fragment shader.
varying vec4 v_Color;          // This will be passed into the fragment shader.
varying vec3 v_Normal;         // This will be passed into the fragment shader.
 
// The entry point for our vertex shader.
void main()
{
  // gl_Position is a special variable used to store the final position.
  // Multiply the vertex by the matrix to get the final point in normalized screen coordinates.
  gl_Position = a_Position;
}


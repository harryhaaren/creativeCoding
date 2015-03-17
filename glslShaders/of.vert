
// this shader *changes* the location of a vertex
// this code just leaves everything as is.
// The of.frag shader a faster way to get cool FX

void main()
{
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

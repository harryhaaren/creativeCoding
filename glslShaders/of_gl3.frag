#version 150

uniform vec2 resolution;
uniform float time;

// output RGBA data
out vec4 fragColor;

void main( void )
{
  vec2 position = ( gl_FragCoord.xy / resolution.xy );
  vec3 color=vec3((sin(time)+1./2.), position.x, position.y);
  fragColor = vec4( color , 1.0 );
}

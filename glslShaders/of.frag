//precision highp float;

uniform vec2 resolution;
uniform float time;

void main( void ) {
	vec2 position = ( gl_FragCoord.xy / resolution.xy );
	vec3 color=vec3((sin(time)+1./2.), position.x, position.y);

	gl_FragColor = vec4( color , 1.0 );

}

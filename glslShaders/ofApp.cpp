#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackground( 33,33,33 );
  
  // load the "of.frag" and "of.vert" shader
  shader.load("of");
  
  // add vertexs
  float s = 20;
  mesh.addVertex( ofVec3f(-s, s,0) );
  mesh.addVertex( ofVec3f( s, s,0) );
  mesh.addVertex( ofVec3f( s,-s,0) );
  mesh.addVertex( ofVec3f(-s,-s,0) );
  
  // set the mesh into the VBO, a VertexBufferObject. It stores
  // the mesh, and allows for faster drawing.
  vbo.setMesh( mesh, GL_STATIC_DRAW );
  
  ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  cam.begin();
  ofPushMatrix();
  
  // move whole view to approx center
  ofTranslate( -50*5, 50*5, 0 );
  
    // start the shader
    shader.begin();
      // write to the "time" variable in the GLSL code. Note that the shader
      // must have .begin() called before writing uniforms
      shader.setUniform1f( "time", ofGetSystemTimeMicros() / 1000000.f );
      
      // change the width / height and GLSL will resize its render - keeping
      // per pixel lighting, so it "scales" just like vector graphics, no edges
      shader.setUniform2f( "resolution", ofGetWidth(), ofGetHeight() );
      
      // draw a grid, 10 by 20 in size, using ofPushMatrix() and ofPopMatrix()
      // to reset the translation after each "row" of squares, and after drawing
      // the whole grid
      ofPushMatrix();
      for(int j = 0; j < 10; j++)
      {
        ofPushMatrix();
        for(int i = 0; i < 20; i++ )
        {
          // draw the contents of the VBO
          vbo.draw( GL_QUADS, 0, 4 );
          
          // move to new location
          ofTranslate( 50, 0, 0 );
        }
        ofPopMatrix();
        ofTranslate( 0, -50, 0 );
      }
      ofPopMatrix();
    shader.end();
    
    ofTranslate( -50, 50, 0 );
    // no colour from shader - uses white/grey default
    vbo.draw( GL_QUADS, 0, 4 );
  
  
  ofPopMatrix();
  cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

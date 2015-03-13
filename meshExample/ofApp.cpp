#include "ofApp.h"

void ofApp::changeColors()
{
  // for each mesh
  for( int m = 0; m < meshes.size(); m++ )
  {
    // for each vertex
    for(int i = 0; i < meshes.at(m).getVertices().size(); i++ )
    {
      // change the color to a random one
      float r = ofRandomuf();
      float g = ofRandomuf();
      float b = ofRandomuf();
      meshes.at(m).setColor( i, ofFloatColor( r, g, b ) );
    }
  }
}

//--------------------------------------------------------------
void ofApp::setup()
{
  // set background
  ofBackground(0);
  glEnable(GL_DEPTH_TEST);
  
  // set default values for variables in the header file
  mode = 0;
  drawing = 0;
  
  // add meshes to the vector
  meshes.push_back( ofMesh::cone(100.0, 200.0)     );
  meshes.push_back( ofMesh::cylinder(100.0, 200.0) );
  meshes.push_back( ofMesh::icosphere( 130, 2)     );
  meshes.push_back( ofMesh::box( 170, 170, 0)      );
  
  // set initial colour values
  for( int m = 0; m < meshes.size(); m++ )
  {
    for(int i = 0; i < meshes.at(m).getVertices().size(); i++ )
    {
      float r = ofRandomuf();
      float g = ofRandomuf();
      float b = ofRandomuf();
      meshes.at(m).addColor( ofFloatColor( r, g, b ) );
    }
  }
  
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
  
  camera.begin();
  
  
  /// note that ofPushMatrix() saves the current "view"
  ofPushMatrix();
    /// move 200 to the left, and draw a wireframe
    ofTranslate( -200, 0, 0 );
    meshes.at(0).drawWireframe();
  /// restore the previous view
  ofPopMatrix();
  
  
  /// push a new "view", rotate, draw it, and pop the view
  ofPushMatrix();
    
    ofRotate( 360 * ofGetMouseY() / (float(ofGetHeight())), 1, 0, 0 );
    
    ofTranslate( 200, 0, 0 );
    
    if( mode == 0 )
    {
      meshes.at(drawing).drawFaces();
    }
    else if( mode == 1 )
    {
      meshes.at(drawing).drawVertices();
    }
    else if(  mode == 2 )
    {
      meshes.at(drawing).drawWireframe();
    }
    else
    {
      meshes.at(drawing).draw();
    }
  
  ofPopMatrix();
  
  camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  // space changes colour
  if( key == ' ' )
  {
    changeColors();
  }
  // m changes the mode
  else if( key == 'm' )
  {
    mode++;
    mode = mode % 4 ;
  }
  else
  {
    // any other key changes the mesh to be drawn
    drawing += 1;
    drawing = drawing % 4;
  }
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

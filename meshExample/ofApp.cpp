#include "ofApp.h"

void ofApp::changeColors()
{
  for( int m = 0; m < meshes.size(); m++ )
  {
    for(int i = 0; i < meshes.at(m).getVertices().size(); i++ )
    {
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
  drawing = 0;
  
  meshes.push_back( ofMesh::cone(100.0, 200.0)     );
  meshes.push_back( ofMesh::cylinder(300.0, 200.0) );
  meshes.push_back( ofMesh::icosphere( 130, 2)     );
  meshes.push_back( ofMesh::box( 170, 170, 0)      );
  
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
  
  
  ofBackground(0);
  glEnable(GL_DEPTH_TEST);
  
}

//--------------------------------------------------------------
void ofApp::update()
{
  
  /*
  
  for(int i = 0; i < meshes.at(drawing).getVertices().size(); i++ )
  {
    float r = ofRandomuf();
    float g = ofRandomuf();
    float b = ofRandomuf();
    meshes.at(drawing).addColor( i, ofFloatColor( r, g, b ) );
    
    //float n = 1.234;
    //n = ofNoise( n );
    //meshes.at(drawing).setColor( i, ofFloatColor( n, 1-n, n*n ) );
  }
  */
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  
  camera.begin();
  
  int frame = ofGetFrameNum() % 400;
  
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
  
  camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if( key == ' ' )
    changeColors();
  else if( key == 'm' )
    mode = (++mode) % 4 ;
  else
    drawing += 1;
    drawing = drawing % 4;
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

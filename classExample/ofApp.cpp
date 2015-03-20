#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  ofBackground(22);
}

//--------------------------------------------------------------
void ofApp::update()
{
  
}

//--------------------------------------------------------------
void ofApp::draw()
{
  cam.begin();
    mesh.draw();
  cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  mesh.randomize();
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

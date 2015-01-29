
#include "ofMain.h"
#include "ofApp.h"

int main( )
{
  // setup the graphical window
  ofSetupOpenGL(720,360, OF_WINDOW);
  
  // create our App, and run it
  ofRunApp( new ofApp() );
  
  return 0;
}

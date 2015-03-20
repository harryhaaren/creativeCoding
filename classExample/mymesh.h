#pragma once

// An example "MyMesh" class, with a position, rotation and mesh

class MyMesh
{
  public:
    /// Constructor, called when creating a new instance.
    /// Used to set default values for the class
    MyMesh()
    {
      position = ofVec3f( 0, 0, 0 );
      rotation = ofVec3f( 0, 0, 0 );
      
      /// add 10 random vertexs to mesh by default
      for(int i = 0; i < 12; i++)
      {
        float x = ofRandom(-100,100);
        float y = ofRandom(-100,100);
        float z = ofRandom(-100,100);
        ofVec3f pos = ofVec3f( x, y, z );
        mesh.addVertex( pos );
        mesh.addColor( ofColor( 255, 81, 0 ) );
      }
    }
    
    /// Translates to the position, applies rotation, draws mesh
    /// note that the ofPushMatrix() ofPopMatrix() pair restore POV 
    void draw()
    {
      ofPushMatrix(); // save POV
        ofTranslate( position.x, position.y, position.z );
        ofRotate   ( 30, rotation.x, rotation.y, rotation.z );
        mesh.draw();
      ofPopMatrix(); // restore POV
    }
    
    /// 
    void randomize()
    {
      position = ofVec3f( ofRandom(-100,100),
                          ofRandom(-100,100),
                          ofRandom(-100,100));

      rotation = ofVec3f( ofRandom( 0,360),
                          ofRandom( 0,360),
                          ofRandom( 0,360));
    }
  
    ofVec3f position;
    ofVec3f rotation;
    ofMesh  mesh;
};

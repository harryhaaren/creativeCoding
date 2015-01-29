/*
 * Author: Harry van Haaren 2015
 *         harryhaaren@gmail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

/// This is a hack: it allows OpenFrameworks code to compile without having
/// the OpenFrameworks library present. It declares the most basic functions,
/// and provides stubbed versions instead. This is useful for presenting code
/// in a lecture-learning environment on computers where OFX is not present.

#ifndef OPENFRAMEWORKS_STUBS
#define OPENFRAMEWORKS_STUBS

#include <stdio.h>
#include <unistd.h>

#define OF_WINDOW     0
#define OF_FULLSCREEN 1

class ofDragInfo
{
  public:
    ofDragInfo(){}
};

class ofMessage
{
  public:
    ofMessage(){}
};

class ofBaseApp
{
  public:
    ofBaseApp(){}
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual void keyPressed(int key){}
    virtual void keyReleased(int key){}
    virtual void mouseMoved(int x, int y){}
    virtual void mouseDragged(int x, int y, int button){}
    virtual void mousePressed(int x, int y, int button){}
    virtual void mouseReleased(int x, int y, int button){}
    virtual void windowResized(int w, int h){}
    virtual void dragEvent(ofDragInfo dragInfo){}
    virtual void gotMessage(ofMessage msg){}
};

static void ofSetupOpenGL( int w, int h, int fullscreen )
{
  printf("ofSetupOpenGL() called, width = %i, height %i, fullscreen : %s\n",
      w, h, fullscreen ? "yes" : "no" );
}

static int ofRunApp( ofBaseApp* app )
{
  app->setup();
  
  while( true )
  {
    app->update();
    
    app->draw();
    
    sleep(1);
  }
  
  return 0;
}

#endif // OPENFRAMEWORKS_STUBS

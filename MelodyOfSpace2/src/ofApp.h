#pragma once

#include "ofMain.h"
#include "ofxFFTLive.h" //this allows us to do FFT *in*
#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxFFTLive fftLive;

		ofImage stars;

		Planet planet;

//		ofMesh ball;
//		int circle_x;
//		int circle_y;
//		int circle_dx;
//		int circle_dy;
//
//        ofFbo fbo;
//        int fboSize = 1024;
//
//        ofImage blur;
//        ofImage swirl_thing;
//        int r=0;
//        int g=0;
//        int b=0;

        int highest=0;
        int highest_loc=0;
        int num_zeroes_since_last_note=0;
        int set_color=-1;
        //if highest was 0 more than 6 times, this is probably a new note

};

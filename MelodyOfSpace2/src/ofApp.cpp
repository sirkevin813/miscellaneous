#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    ofSetFrameRate(60);
    ofDisableArbTex();

    planet= Planet();

    fftLive.setMirrorData(false);
    fftLive.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    float * audioData = new float[512];
    fftLive.getFftPeakData(audioData,512);

    highest=-1;
    highest_loc=-1;
    for (int i=0; i<180; i++){
        //TODO: check through audio data by stepping through and find the
        //index of the highest frequency
        //By testing, I find that up to and including 180
        //there tends to be some value in the box.
        //From 180 on, it's 0. Here's the test I ran:
        //for (int i=0; i<512; i++){
        //if (audioData[i]==0 && i<200) printf("box %i is 0\n",i);}
        if (audioData[i]>highest && audioData[i]>.95){
            highest=audioData[i];
            highest_loc=i;
        }

    }



    if (num_zeroes_since_last_note > 10){
        set_color=ofMap(highest_loc,0,180,0,254,true);
        if (highest_loc==-1) set_color=-1;
        printf("Set color changed! \n");
    }


    if (highest==-1){
        num_zeroes_since_last_note++;
    }
    else{
        num_zeroes_since_last_note=0;
    }

    printf("highest loc: %i\n",highest_loc);

    //TODO: map highest loc to a certain part of the spectrum

    fftLive.update();

    delete[] audioData;

    planet.updatePlanet(set_color);

}

//--------------------------------------------------------------
void ofApp::draw(){
    fftLive.draw();

    ofBackground(ofColor::black);

    planet.drawPlanet();

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
    planet.pushback();

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

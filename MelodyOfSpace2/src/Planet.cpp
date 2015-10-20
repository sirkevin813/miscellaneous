#include "Planet.h"

Planet::Planet()
{
    ball = ofMesh::sphere(200);
    circle_dx=5;
    circle_dy=1;

    blur.loadImage("blur.png");

    fbo.allocate(fboSize, fboSize, GL_RGBA);
    fbo.begin();
    //clear with white color at 100% transparent
    ofClear(0,0,0, 255);
    fbo.end();
}

void Planet::updatePlanet(float set_color){
    if (!orbiting){
        bool draw_double=false;
        circle_x = (circle_x + circle_dx) % 512;
        if (abs(circle_x-512)<blur.width/2){
           draw_double=true;
        }
        circle_y = (circle_y + circle_dy +(int)ofRandom(-10,10)) % 512;

        fbo.begin();
        ofDisableDepthTest();
        ofEnableAlphaBlending();
    //    ofClear(255,255,255, 0);
        ofPushMatrix();
        ofTranslate(circle_x, circle_y, 0);
        if (set_color==-1) ofSetColor(0,0,0,0);
        else ofSetColor(ofColor::fromHsb(set_color,255,255));//ofSetColor(r,g,b);
        blur.draw(circle_x, circle_y);
        ofPopMatrix();

        if (draw_double){
            ofPushMatrix();
            ofTranslate(circle_x-512, circle_y, 0);
            //ofSetColor(ofColor::red);
            blur.draw(circle_x-512, circle_y);
        ofPopMatrix();
            draw_double=false;
        }


        ofDisableAlphaBlending();
        ofEnableDepthTest();
        fbo.end();
    }

    else{
         theta+=delta_theta;
    }
}

void Planet::drawPlanet(){
    ofPushMatrix();
    if (!orbiting){
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2, z);
        if (pushing_into_orbit){
            if (z<= -radius){
                pushing_into_orbit=false;
                orbiting = true;
            }
            else{
                z-=4;
            }

        }
    }
    else{
        int _x= radius*sin(ofDegToRad(theta));
        int _z= radius*cos(ofDegToRad(theta));
        ofTranslate(ofGetWidth()/2+_x, ofGetHeight()/2, _z);
    }
    ofRotate(ofGetFrameNum()/* *speed factor */ , 0, 1, 0);
    ofSetColor(ofColor::white);
    fbo.getTextureReference().bind();
    ball.draw();
    fbo.getTextureReference().unbind();
    ofPopMatrix();
}

void Planet::pushback(){
    pushing_into_orbit =true;
}

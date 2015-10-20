
#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED

#pragma once

#include "ofMain.h"
class Planet{
    int x;
    int y;
    int z=0;

    ofMesh ball;

    int circle_x;
    int circle_y;
    int circle_dx;
    int circle_dy;

    ofFbo fbo;
    int fboSize = 1024;

    ofImage blur;

    bool orbiting=false;
    int radius = 1000;
    float theta = 180;
    float delta_theta=.3;

    bool pushing_into_orbit = false;

public:
    Planet();
    void updatePlanet(float set_color);
    void drawPlanet();
    void orbit();
    void pushback();

};
#endif // PLANET_H_INCLUDED

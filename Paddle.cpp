//
//  Paddle.cpp
//  firstSketch
//
//  Created by Ron Guglielmone on 11/1/16.
//
//

#include "Paddle.h"

Paddle::Paddle(){
}

void Paddle::setup(float _x, float _y, float _width,  float _height){
    x = _x;
    y = _y;
    height = _height;
    width = _width;
    
    color.set(178,186,192);
}


void Paddle::update(float _x){
    x = _x;
}

void Paddle::draw(){
    ofSetColor(color);
    ofDrawRectangle(x, y, width, height);
}

// Allows the main program to know
// where the paddle is.  Returns the
// left side of the paddle.
float Paddle::getX(){
    return x;
}

float Paddle::getWidth(){
    return width;
}

// Returns true if the points are inside
// the rectangle.
bool Paddle::isWithin(float _x, float _y){
    if( (_x > x) &&
        (_x < x + width) &&
        (_y > y) &&
       (_y < y + height)){
        return true;
    }
    else{
        return false;
    }
}

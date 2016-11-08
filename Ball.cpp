//
//  Ball.cpp
//  firstSketch
//
//  Created by Ron Guglielmone on 10/31/16.
//
//

#include "Ball.h"

Ball::Ball(){
}

void Ball::setup(float _x, float _y, int _dim, int R, int G, int B){
    x = _x;
    y = _y;
    dim = _dim;
    
    speedX = BALL_SPEED;
    speedY = 0;
    color.set(R, G, B);
}

// Updates the ball graphic.  Handles the
// "bouncing" logic.
void Ball::update(float paddleLeftX, float paddleRightX){
    
    if(x < paddleLeftX ){
        x = paddleLeftX;
        speedX *= -1;
        isBouncing = true;
    } else if(x > paddleRightX){
        x = paddleRightX;
        speedX *= -1;
        isBouncing = true;
    }
    else {
    x+=speedX;
    y+=speedY;
    isBouncing = false;
    }
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
}

// Returns the x-position of the ball:
float Ball::getX(){
    return x;
}

// Returns the radius of the ball:
float Ball::getR(){
    float radius = (float)dim;
    return radius;
}

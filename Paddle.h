//
//  Paddle.hpp
//  firstSketch
//
//  Created by Ron Guglielmone on 11/1/16.
//
//

#ifndef Paddle_h
#define Paddle_h

#include <stdio.h>
#include "ofMain.h"

class Paddle {
    
public:
    
    // setup takes in an x position, y position,
    // width and height
    void setup(float _x, float _y, float _width, float _height);
    void update(float _x);
    void draw();
    float getX(); // returns the x position
    float getWidth(); // returns the width
    bool isWithin(float _x, float _y); 
    
    // variables
    float x;        // position
    float y;
    float width;
    float height;
    ofColor color;
    
    Paddle();  // constructor
    
private:
    
    
};

#endif /* Paddle_hpp */

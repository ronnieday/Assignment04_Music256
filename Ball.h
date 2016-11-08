//
//  Ball.h
//  firstSketch
//
//  Created by Ron Guglielmone on 10/31/16.
//
//

#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "ofMain.h"
#define BALL_SPEED 6;

class Ball {
    
public:
    
    // setup takes in an x position, y position, dimension,
    // and RGB color values.
    void setup(float _x, float _y, int _dim, int R, int G, int B);
    void update(float paddleLeftX, float paddleRightX); 
    void draw();    // draw method, this where you'll do the object's drawing
    float getX(); // returns x cordinate of the ball
    float getR(); // returns the radius
    
    // variables
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    ofColor color;  // color using ofColor type
    bool isBouncing; // true at moment of impact
    
    Ball();  // constructor
    
private:
    
    
}; 


#endif /* Ball_hpp */

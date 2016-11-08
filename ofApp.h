#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Paddle.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyReleased(int key);
    void keyPressed(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float 	counter;
    
    // pauses the app
    bool	pausePlay;
    
    // true when we're dragging a paddle
    bool    draggingPaddleOneLeft;
    bool    draggingPaddleOneRight;
    bool    draggingPaddleTwoLeft;
    bool    draggingPaddleTwoRight;
    bool    draggingPaddleThreeLeft;
    bool    draggingPaddleThreeRight;
    bool    draggingPaddleFourLeft;
    bool    draggingPaddleFourRight;
    
    // object dimensions:
    int paddleWidth = 30;
    int paddleHeight = 160;
    
    // Graphic objects:
    
    // First unit:
    Ball ballOne;
    Paddle paddleOneLeft;
    Paddle paddleOneRight;
    // Second unit:
    Ball ballTwo;
    Paddle paddleTwoLeft;
    Paddle paddleTwoRight;
    // Third unit:
    Ball ballThree;
    Paddle paddleThreeLeft;
    Paddle paddleThreeRight;
    // Fourth unit:
    Ball ballFour;
    Paddle paddleFourLeft;
    Paddle paddleFourRight;
    
    // Audio objects:
    ofSoundPlayer  voiceOne;
    ofSoundPlayer voiceTwo;
    ofSoundPlayer voiceThree;
    ofSoundPlayer voiceFour;
};

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    counter = 0;
    ofSetCircleResolution(50);
    ofBackground(35,54,80); // Deep Blue
    pausePlay = false;
    ofSetWindowTitle("Bumper Beats");
    
    ofSetFrameRate(60); // framerate at 60fps.
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    // Set up our graphics objects:
    paddleOneLeft.setup(((width/8)*2) - paddleWidth,30,paddleWidth,paddleHeight);
    paddleOneRight.setup(((width/8)*6),30,paddleWidth,paddleHeight);
    ballOne.setup((width/2),110,30, 252, 200, 80);
    // Second ball and paddle:
    paddleTwoLeft.setup(((width/8)*2) - paddleWidth,240,paddleWidth,paddleHeight);
    paddleTwoRight.setup(((width/8)*6),240,paddleWidth,paddleHeight);
    ballTwo.setup((width/2),310,30, 252, 200, 80);
    // Third ball and paddle:
    paddleThreeLeft.setup(((width/8)*2) - paddleWidth,450,paddleWidth,paddleHeight);
    paddleThreeRight.setup(((width/8)*6),450,paddleWidth,paddleHeight);
    ballThree.setup((width/2),530,30, 252, 200, 80);
    // Fourth ball and paddle:
    paddleFourLeft.setup(((width/8)*2) - paddleWidth,660,paddleWidth,paddleHeight);
    paddleFourRight.setup(((width/8)*6),660,paddleWidth,paddleHeight);
    ballFour.setup((width/2),740,30, 252, 200, 80);
    
    // Set up our audio objects:
    voiceOne.load("sounds/C2.wav");
    voiceOne.setVolume(0.75f);
    voiceOne.setMultiPlay(true);
    // Second object:
    voiceTwo.load("sounds/E2.wav");
    voiceTwo.setVolume(0.75f);
    voiceTwo.setMultiPlay(true);
    // Third object:
    voiceThree.load("sounds/G2.wav");
    voiceThree.setVolume(0.75f);
    voiceThree.setMultiPlay(true);
    // Fourth object:
    voiceFour.load("sounds/C3.wav");
    voiceFour.setVolume(0.75f);
    voiceFour.setMultiPlay(true);
}




//--------------------------------------------------------------
void ofApp::update(){
    
    if(!pausePlay){
        
        counter = counter + 0.033f;
        
        // get x positions of paddles:
        float _leftX = paddleOneLeft.getX();
        float _rightX = paddleOneRight.getX();
        // get width of paddle to add to left
        // padde bounce point
        float leftWidth = paddleOneLeft.getWidth();
        // get ball radius to subtract:
        float radius = ballOne.getR();
        // calculate actual bounce location:
        float leftX = _leftX + leftWidth + radius;
        float rightX = _rightX - radius;
        
        // Play the bouncing sound
        // (Must be done before ball
        //  is updated or isBouncing
        //  will always be 0).
        if (ballOne.isBouncing) {
            voiceOne.play();
        }
        
        // Update the ball, pass in its boundaries:
        ballOne.update(leftX,rightX);
        
        // Update the paddles
        paddleOneLeft.update(paddleOneLeft.getX());
        paddleOneRight.update(paddleOneRight.getX());
        
        
        
        // Second object:
        float _leftXTwo = paddleTwoLeft.getX();
        float _rightXTwo = paddleTwoRight.getX();
        float leftWidthTwo = paddleTwoLeft.getWidth();
        float radiusTwo = ballTwo.getR();
        float leftXTwo = _leftXTwo + leftWidthTwo + radiusTwo;
        float rightXTwo = _rightXTwo - radiusTwo;
        if (ballTwo.isBouncing) {
            voiceTwo.play();
        }
        ballTwo.update(leftXTwo,rightXTwo);
        paddleTwoLeft.update(paddleTwoLeft.getX());
        paddleTwoRight.update(paddleTwoRight.getX());
        
        
        // Third Object:
        float _leftXThree = paddleThreeLeft.getX();
        float _rightXThree = paddleThreeRight.getX();
        float leftWidthThree = paddleThreeLeft.getWidth();
        float radiusThree = ballThree.getR();
        float leftXThree = _leftXThree + leftWidthThree + radiusThree;
        float rightXThree = _rightXThree - radiusThree;
        if (ballThree.isBouncing) {
            voiceThree.play();
        }
        ballThree.update(leftXThree,rightXThree);
        paddleThreeLeft.update(paddleThreeLeft.getX());
        paddleThreeRight.update(paddleThreeRight.getX());
        
        
        // Fourth object:
        float _leftXFour = paddleFourLeft.getX();
        float _rightXFour = paddleFourRight.getX();
        float leftWidthFour = paddleFourLeft.getWidth();
        float radiusFour = ballFour.getR();
        float leftXFour = _leftXFour + leftWidthFour + radiusFour;
        float rightXFour = _rightXFour - radiusFour;
        if (ballFour.isBouncing) {
            voiceFour.play();
        }
        ballFour.update(leftXFour,rightXFour);
        paddleFourLeft.update(paddleFourLeft.getX());
        paddleFourRight.update(paddleFourRight.getX());
        
        
        // Update the sound playing system:
        ofSoundUpdate();
        
    }
    
}





//--------------------------------------------------------------
void ofApp::draw(){
    // Draw lines:
    int width = ofGetWidth();
    int bottom = ofGetHeight();
    int sixteenth = width/16;
    
    // Instructions:
    ofEnableAlphaBlending();
    ofSetColor(10, 10, 10, 60);
    ofDrawRectangle(5, 5, sixteenth*2 - 10, 40);
    ofSetColor(120,120,150);
    ofDrawBitmapString("space : play/pause", 10,20);
    ofDrawBitmapString("r key : reset balls", 10, 40);
    
    // Center Line:
    ofSetHexColor(0x000000);
    ofDrawLine(width/2, 0, width/2, bottom);
    // 16th Lines:
    ofSetColor(45,45,55);
    ofDrawLine(sixteenth*7, 0, sixteenth*7, bottom);
    ofDrawLine(sixteenth*9, 0, sixteenth*9, bottom);
    // 8thth Lines:
    ofSetColor(25,25,35);
    ofDrawLine(sixteenth*6, 0, sixteenth*6, bottom);
    ofDrawLine(sixteenth*10, 0, sixteenth*10, bottom);
    // 16th Lines:
    ofSetColor(45,45,55);
    ofDrawLine(sixteenth*5, 0, sixteenth*5, bottom);
    ofDrawLine(sixteenth*11, 0, sixteenth*11, bottom);
    // 8thth Lines:
    ofSetColor(25,25,35);
    ofDrawLine(sixteenth*4, 0, sixteenth*4, bottom);
    ofDrawLine(sixteenth*12, 0, sixteenth*12, bottom);
    // 16th Lines:
    ofSetColor(45,45,55);
    ofDrawLine(sixteenth*3, 0, sixteenth*3, bottom);
    ofDrawLine(sixteenth*13, 0, sixteenth*13, bottom);
    // 8thth Lines:
    ofSetColor(25,25,35);
    ofDrawLine(sixteenth*2, 0, sixteenth*2, bottom);
    ofDrawLine(sixteenth*14, 0, sixteenth*14, bottom);
    // 16th Lines:
    ofSetColor(45,45,55);
    ofDrawLine(sixteenth, 0, sixteenth, bottom);
    ofDrawLine(sixteenth*15, 0, sixteenth*15, bottom);
    
    // Draw paddles and balls:
    paddleOneLeft.draw();
    paddleOneRight.draw();
    ballOne.draw();
    // Two:
    paddleTwoLeft.draw();
    paddleTwoRight.draw();
    ballTwo.draw();
    // Three:
    paddleThreeLeft.draw();
    paddleThreeRight.draw();
    ballThree.draw();
    // Four:
    paddleFourLeft.draw();
    paddleFourRight.draw();
    ballFour.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    if (key == 32){
        pausePlay = !pausePlay;
    }
    if (key == 'r'){
        int width = ofGetWidth();
        ballOne.setup((width/2),110,30, 252, 200, 80);
        ballTwo.setup((width/2),310,30, 252, 200, 80);
        ballThree.setup((width/2),530,30, 252, 200, 80);
        ballFour.setup((width/2),740,30, 252, 200, 80);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    int width = ofGetWidth();
    
    // Execute the drag:
    if(draggingPaddleOneLeft){
        paddleOneLeft.update(x);
        paddleOneRight.update(width - x - paddleWidth);
    }
    else if(draggingPaddleOneRight){
        paddleOneRight.update(x);
        paddleOneLeft.update(width - x - paddleWidth);
    }
    // Paddle Two:
    if(draggingPaddleTwoLeft){
        paddleTwoLeft.update(x);
        paddleTwoRight.update(width - x - paddleWidth);
    }
    else if(draggingPaddleTwoRight){
        paddleTwoRight.update(x);
        paddleTwoLeft.update(width - x - paddleWidth);
    }
    // Paddle Three:
    if(draggingPaddleThreeLeft){
        paddleThreeLeft.update(x);
        paddleThreeRight.update(width - x - paddleWidth);
    }
    else if(draggingPaddleThreeRight){
        paddleThreeRight.update(x);
        paddleThreeLeft.update(width - x - paddleWidth);
    }
    // Paddle Four:
    if(draggingPaddleFourLeft){
        paddleFourLeft.update(x);
        paddleFourRight.update(width - x - paddleWidth);
    }
    else if(draggingPaddleFourRight){
        paddleFourRight.update(x);
        paddleFourLeft.update(width - x - paddleWidth);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // Start the drag:
    if(paddleOneLeft.isWithin(x,y)){
        draggingPaddleOneLeft = true;
    }
    else if(paddleOneRight.isWithin(x,y)){
        draggingPaddleOneRight = true;
    }
    if(paddleTwoLeft.isWithin(x,y)){
        draggingPaddleTwoLeft = true;
    }
    else if(paddleTwoRight.isWithin(x,y)){
        draggingPaddleTwoRight = true;
    }
    if(paddleThreeLeft.isWithin(x,y)){
        draggingPaddleThreeLeft = true;
    }
    else if(paddleThreeRight.isWithin(x,y)){
        draggingPaddleThreeRight = true;
    }
    if(paddleFourLeft.isWithin(x,y)){
        draggingPaddleFourLeft = true;
    }
    else if(paddleFourRight.isWithin(x,y)){
        draggingPaddleFourRight = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // Finish the drag:
    if(draggingPaddleOneLeft){
        draggingPaddleOneLeft = false;
    }
    else if(draggingPaddleOneRight){
        draggingPaddleOneRight = false;
    }
    if(draggingPaddleTwoLeft){
        draggingPaddleTwoLeft = false;
    }
    else if(draggingPaddleTwoRight){
        draggingPaddleTwoRight = false;
    }
    if(draggingPaddleThreeLeft){
        draggingPaddleThreeLeft = false;
    }
    else if(draggingPaddleThreeRight){
        draggingPaddleThreeRight = false;
    }
    if(draggingPaddleFourLeft){
        draggingPaddleFourLeft = false;
    }
    else if(draggingPaddleFourRight){
        draggingPaddleFourRight = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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

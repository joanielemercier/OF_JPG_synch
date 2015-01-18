#include "testApp.h"

void testApp::setup(){
    ofSetFrameRate(120.0);
    ofSetVerticalSync(true);
    
    sender.setup(HOST, PORT);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    currFrame = 0;
    totalFrames = 300;
    lastFrameTimestamp = 0;
    isPlaying = true;
}


void testApp::update(){
    if(isPlaying) {
        if (ofGetElapsedTimeMillis() - lastFrameTimestamp > 1000/30) {
            lastFrameTimestamp = ofGetElapsedTimeMillis();
            currFrame++;
            if (currFrame > totalFrames) {
                currFrame = 0;
            }
        }
    }
    
    ofxOscMessage m;
    m.setAddress("/f");
    m.addIntArg(currFrame);
    sender.sendMessage(m, false);
}


void testApp::draw(){
    int pos = (float)currFrame / totalFrames * ofGetWidth();
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofDrawLine(pos, 0, pos, ofGetHeight());
    ofPopStyle();
}


void testApp::keyPressed(int key){
    switch (key) {
        case ' ':
            currFrame = 0;
        default:
            break;
    }
}


void testApp::mouseDragged(int x, int y, int button){
    isPlaying = false;
    currFrame = (float)x / ofGetWidth() * totalFrames;
}


void testApp::mouseReleased(int x, int y, int button){
    isPlaying = true;
}
#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(120.0);
    ofSetVerticalSync(true);
    
    sender.setup(HOST, PORT);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    currFrame = 0;
    totalFrames = 300;
    lastFrameTimestamp = 0;
    playbackFrameRate = 30;
    isPlaying = true;
}


void ofApp::update(){
    if(isPlaying) {
        if (ofGetElapsedTimeMillis() - lastFrameTimestamp > 1000/playbackFrameRate) {
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
    sender.sendMessage(m);
}


void ofApp::draw(){
    int pos = (float)currFrame / totalFrames * ofGetWidth();
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofLine(pos, 0, pos, ofGetHeight());
    ofPopStyle();
}


void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            currFrame = 0;
        default:
            break;
    }
}


void ofApp::mouseDragged(int x, int y, int button){
    isPlaying = false;
    currFrame = (float)x / ofGetWidth() * totalFrames;
}


void ofApp::mouseReleased(int x, int y, int button){
    isPlaying = true;
}
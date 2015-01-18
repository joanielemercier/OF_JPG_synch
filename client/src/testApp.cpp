#include "testApp.h"


void testApp::setup(){
    ofSetFrameRate(30.0);
    ofSetVerticalSync(true);
    
    mySequence.loadSequence("sequence",30.0f);
    ofSetWindowShape(mySequence.getSequence().getWidth(), mySequence.getSequence().getHeight());
    
    receiver.setup(PORT);
}


void testApp::update(){
    mySequence.update();
    
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if(m.getAddress() == "/f"){
            int frameIndex = m.getArgAsInt32(0);
            mySequence.setCurrentFrameIndex(frameIndex);
        }
    }
}


void testApp::draw(){
    mySequence.draw();
    
    int pos = (float)mySequence.getCurrentFrameIndex() / mySequence.getTotalFrames() * ofGetWidth();
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofDrawLine(pos, 0, pos, ofGetHeight());
    ofPopStyle();
}
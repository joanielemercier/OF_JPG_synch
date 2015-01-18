#pragma once

#include "ofMain.h"
#include "ofxImageSequencePlayback.h"
#include "ofxOsc.h"

#define PORT 12345

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofxImageSequencePlayback mySequence;
    
    ofxOscReceiver receiver;
};

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "192.168.1.255"
#define PORT 12345

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    ofxOscSender sender;
    
    int currFrame;
    int totalFrames;
    int lastFrameTimestamp;
    bool isPlaying;
    
    int playbackFrameRate;
};

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxKinect.h"
//#include "ofxSecondWindow.h"
#include "ofxKinectProjectorToolkit.h"
#include "ofxGui.h"


using namespace ofxCv;
using namespace cv;


class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void drawSecondWindow(ofEventArgs &args);
    void keyPressed(int key);
    shared_ptr<ofAppBaseWindow> secondWindow;
    
//    ofxSecondWindow             projector;
    
    ofxPanel                    gui;
    ofColor                     blobColors[12];
    
    ofxCv::ContourFinder        contourFinder;
    ofxKinectProjectorToolkit   kpt;
    ofxKinect                   kinect;
    
    ofxCvGrayscaleImage         bgImage;
    ofxCvGrayscaleImage         grayImage;
    ofxCvGrayscaleImage         grayThreshNear;
    ofxCvGrayscaleImage         grayThreshFar;
    
    ofParameter<float>          nearThreshold;
    ofParameter<float>          farThreshold;
    ofParameter<float>          minArea;
    ofParameter<float>          maxArea;
    ofParameter<float>          threshold;
    ofParameter<float>          persistence;
    ofParameter<float>          maxDistance;
};

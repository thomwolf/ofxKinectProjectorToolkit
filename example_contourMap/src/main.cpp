#include "ofMain.h"
#include "ofApp.h"

// this must match the display resolution of your projector
#define PROJECTOR_RESOLUTION_X 800
#define PROJECTOR_RESOLUTION_Y 600

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    
    settings.width = 800;
    settings.height = 600;
    settings.setPosition(ofVec2f(100, 100));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 800;//PROJECTOR_RESOLUTION_X;
    settings.height = 600;//PROJECTOR_RESOLUTION_Y;
    settings.setPosition(ofVec2f(ofGetScreenWidth(), 0));
    settings.resizable = false;
    settings.decorated = false;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> secondWindow = ofCreateWindow(settings);
    secondWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    ofAddListener(secondWindow->events().draw, mainApp.get(), &ofApp::drawSecondWindow);
    mainApp->secondWindow = secondWindow;
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}

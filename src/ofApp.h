#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxNanoVG.h"
#include "ofxGui.h"

static const int NUM = 5; //色数

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setColor();
    
    ofImage myImage;
    ofxSVG svg;
    vector<ofPolyline> outlines;
    int svgSize;
    ofColor bgColor, stColor;
    ofColor colors[NUM];
    bool bCset;
    int cs;
    
    ofxNanoVG::Canvas canvas;
    
    //gui
    ofxPanel gui;
    ofxToggle randomFill;
    ofxToggle randomStroke;
    ofxIntSlider lWidth;
    ofxIntSlider colorScheme;
    bool bHide;
};

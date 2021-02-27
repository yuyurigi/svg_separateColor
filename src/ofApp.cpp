#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(2);
    
    svg.load("LSNOT.svg");
    for (ofPath p: svg.getPaths()){
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        const vector<ofPolyline>& lines = p.getOutline();
        for(const ofPolyline & line: lines){
            outlines.push_back(line.getResampledBySpacing(1));
        }
    }
    
    svgSize = 750;
    
    canvas.allocate(ofGetWidth(), ofGetHeight());
    
    //gui
    gui.setup();
    gui.add(randomFill.setup("random fill color" , true));
    gui.add(randomStroke.setup("random stroke color", false));
    gui.add(lWidth.setup("line width", 7, 1, 10)); //線の太さ
    gui.add(colorScheme.setup("color scheme", 0, 0, 2)); //配色
    bHide = false;
    
    bCset = true;
    cs = colorScheme;
    
}
//--------------------------------------------------------------
void ofApp::setColor(){
    if(colorScheme == 0){
    bgColor = ofColor::fromHex(0xffffff); //白
    stColor = ofColor::fromHex(0xf6eced); //うすいピンク
        colors[0] = (ofColor::fromHex(0xc2d9ff)); //水色
        colors[1] = (ofColor::fromHex(0xffa7be));
        colors[2] = (ofColor::fromHex(0xff5c90));
        colors[3] = (ofColor::fromHex(0xfe7ab4));
        colors[4] = (ofColor::fromHex(0xffc6e9));
    }
     
    if(colorScheme == 1) {
    bgColor = ofColor::fromHex(0x36405b); //紺
    stColor = ofColor::fromHex(0x36405b); //紺
        colors[0] = (ofColor::fromHex(0xf6eced)); //うすいピンク
        colors[1] = (ofColor::fromHex(0xff4082)); //濃いピンク
        colors[2] = (ofColor::fromHex(0xffa7be)); //ピンク
        colors[3] = (ofColor::fromHex(0xfe7ab4)); //ピンク
        colors[4] = (ofColor::fromHex(0x608dec)); //青
    }
    
    if(colorScheme == 2){
    bgColor = ofColor::fromHex(0xf6eced); //うすいピンク
    stColor = ofColor::fromHex(0xf6eced); //うすいピンク
        colors[0] = (ofColor::fromHex(0xbce2bf)); //黄緑
        colors[1] = (ofColor::fromHex(0xfdb759)); //オレンジ
        colors[2] = (ofColor::fromHex(0xffa7be)); //ピンク
        colors[3] = (ofColor::fromHex(0xff5c90)); //濃いピンク
        colors[4] = (ofColor::fromHex(0xffea46)); //黄色
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (cs != colorScheme){
        bCset = true;
        cs = colorScheme;
    }
    if (bCset) {
        setColor();
        bCset = false;
    }
    ofBackground(bgColor);
    
    ofxNanoVG::Canvas& c = canvas;
    c.begin();
    
    c.lineCap(ofxNanoVG::LineCap::ROUND);
    c.lineJoin(ofxNanoVG::LineCap::ROUND);
    c.lineWidth(lWidth);
    
    c.translate(ofGetWidth()/2, ofGetHeight()/2);
    c.translate(-(svg.getWidth()*0.001*svgSize)/2, -(svg.getHeight()*0.001*svgSize)/2);
    c.scale(.001 * svgSize, .001 * svgSize);
    
    //fill
    if (!randomFill) c.fillColor(bgColor);
    
    for (ofPolyline & line: outlines){
        int num = line.size();
        
        if (randomFill) {
            
            int r = (int)ofRandom(NUM);
                
            c.fillColor(colors[r]);
        }
        
        c.beginPath();
        for (int j = 0; j < num; j++){
            float x = line[j].x;
            float y = line[j].y;
            if(j == 0) c.moveTo(x,y);
            else c.lineTo(x, y);
        }
        c.fillPath();
        
    }
    
    if(!randomStroke) c.strokeColor(stColor);
    
    for (ofPolyline & line: outlines){
        int num = line.size();
        
        if(randomStroke){
            
            int r = (int)ofRandom(NUM);
            c.strokeColor(colors[r]);
        }
        
        c.beginPath();
        for (int j = 0; j < num; j++){
            float x = line[j].x;
            float y = line[j].y;
            if(j == 0) c.moveTo(x,y);
            else c.lineTo(x, y);
        }
        c.strokePath();
        
    }
    
    c.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    canvas.draw(0, 0);
    
    if(!bHide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'H' || key == 'h'){
        bHide = !bHide;
    }
    if (key == 'S' || key == 's') {
            myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
        }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    shader.load("shadersGL3/shader");
    
    float planeScale = 0.75;
    int planeWidth = ofGetWidth() * planeScale;
    int planeHeight = ofGetHeight() * planeScale;
    int planeGridSize = 10;
    int planeColumns = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    
    plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
}

void ofApp::draw(){
    shader.begin();
    
    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;
    
    float mx = mouseX - cx;
    float my = mouseY - cy;
    
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("resolution", plane.getWidth(), plane.getHeight());
    
    ofTranslate(cx, cy);
    
    plane.draw();
    
    shader.end();
}

void ofApp::keyPressed(int key){
    if(key == 'x'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
}

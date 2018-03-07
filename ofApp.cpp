#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float size = 100;

	for (int i = 60; i > 0; i--) {

		float deg = ofNoise(i * 0.005 + ofGetFrameNum() * 0.005) * 720;
		float x = (i * 5) * cos(deg * DEG_TO_RAD);
		float y = (i * 5) * sin(deg * DEG_TO_RAD);
		ofPoint point = ofPoint(x, y);

		ofPushMatrix();
		ofTranslate(point);
		ofRotate(deg);

		ofFill();
		ofSetColor(239);
		ofDrawRectangle(ofPoint(0, 0), size, size);

		ofNoFill();
		ofSetColor(39);
		ofDrawRectangle(ofPoint(0, 0), size, size);

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
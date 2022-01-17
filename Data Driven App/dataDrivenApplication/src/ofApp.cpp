#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//loads images declared in header, with image assets from src folder of this project
	testImg.load("ned.jpg");

	// loads fonts, same as the image above but for fonts (styles, sizes)
	smallTxt.load("Dongle-Light.ttf", 23);
	medTxt.load("Dongle-Regular.ttf", 25);
	bigTxt.load("RobotoCondensed-Regular.ttf", 29);
	btnTxt.load("Dongle-Bold.ttf", 32);
	uiHeader.load("Dongle-Bold.ttf", 55); 

	//button setting
	btn1.set(10, 70, 350, 60); // 10 and 50 as x and y coordinates, 350 and 60 as length and width
	btn2.set(10, 140, 350, 60); // same except the y value is incremented by 70 to arrange in a column
	btn3.set(10, 210, 350, 60);
	btn4.set(10, 280, 350, 60);
	btn5.set(10, 350, 350, 60);
	btn6.set(10, 420, 350, 60);
	btn7.set(10, 490, 350, 60);
	btn8.set(10, 560, 350, 60);
	btn9.set(10, 630, 350, 60);
	btn10.set(10, 700, 350, 60);

	queWindow.set(0, 60, 370, 760); // num are as follows, XYLW 
	resWindow.set(390, 20, 615, 725);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(108, 184, 235); // sets color to lightish blue
	//(108, 184, 235);
	

	ofSetColor(228, 241, 255); // sets color to offwhite
	ofDrawRectangle(queWindow);

	ofSetColor(101, 119, 134); // sets color to gray
	ofDrawRectangle(resWindow); // draws resWindow as a rectangle

	ofDrawRectangle(btn1); 
	ofDrawRectangle(btn2);
	ofDrawRectangle(btn3);
	ofDrawRectangle(btn4);
	ofDrawRectangle(btn5);
	ofDrawRectangle(btn6);
	ofDrawRectangle(btn7);
	ofDrawRectangle(btn8);
	ofDrawRectangle(btn9);
	ofDrawRectangle(btn10);

	ofSetColor(255, 255, 255);
	uiHeader.drawString("Tweet Search", 30, 45); // uses uiHeader object for drawString function, Tweet Search string, 30 x and 45 y added as values
	btnTxt.drawString("Count Tweets", 85, 110);  // same but with adjusted string, x and y values to fill in the btn entities drawn 
	btnTxt.drawString("Count Tweets w/ 'money'", 25, 180);
	btnTxt.drawString("Count Tweets w/ 'politics'", 21, 250);
	btnTxt.drawString("Print Tweets w/ 'Paris'", 45, 320);
	btnTxt.drawString("Print Tweets w/ 'DreamWorks'", 10, 390);
	btnTxt.drawString("Print Tweets w/ 'Uber'", 35, 460);
	btnTxt.drawString("7) Count Tweets", 35, 530);
	btnTxt.drawString("8) Count Tweets", 35, 600);
	btnTxt.drawString("9) Count Tweets", 35, 670);
	btnTxt.drawString("10) Count Tweets", 35, 740);
	

	//testImg.draw(600, 500, 212, 212);
}

//--------------------------------------------------------------
void ofApp::loadData() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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

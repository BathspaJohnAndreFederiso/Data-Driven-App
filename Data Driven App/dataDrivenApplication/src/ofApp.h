#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void loadData();
		void processData();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		vector <string> tweets, processTweet1, processTweet2, tweetDate;
		string dateOfTweet, b, tweetContent;
		string ofApp::wrapString(string text, int width); // wrapString function declared

		ifstream data; // declares ifstream data for file handling the twitter csv file
		ofImage testImg; // declares ofImage testImg for testing images
		ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, queWindow, resWindow; // declares ofRectangle objects btn1-10 and resWindow
		ofTrueTypeFont smallTxt, medTxt, bigTxt, boldTxt, uiHeader, btnTxt; // declares four ofTrueTypeFont
};

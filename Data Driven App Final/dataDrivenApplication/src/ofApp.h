#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void loadData(); // declares functions for running the UI
		void processDataSingle(string srchTerm); 
		void processData(string srchTerm, string srchTerm2);  // declares processData functions for processing the data in the csv file
		
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
		
		vector <string> tweets, processTweet1, processTweet2, tweetDate;
		string dateOfTweet, b, tweetContent;
		int tweetCount = 0; // declares vectors, strings and int to be used in data processing and display
		bool displayTweetCount = false; // sets bool displayTweetCount with a default value of false
		int prs; // declares prs for use in presenting vector elements
		bool upPress, downPress; // declares bools upPress and downPress for tweet navigation
		string ofApp::wrapString(string text, int width); // wrapString function declared

		ifstream data; // declares ifstream data for file handling the twitter csv file
		ofImage testImg; // declares ofImage testImg for testing images
		ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, queWindow, resWindow, nxtBtn; // declares ofRectangle objects btn1-10 and resWindow
		ofTrueTypeFont smallTxt, medTxt, bigTxt, boldTxt, uiHeader, btnTxt; // declares six ofTrueTypeFont objects
};

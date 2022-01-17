#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//loads images declared in header, with image assets from src folder of this project
	testImg.load("ned.jpg");

	// loads fonts, same as the image above but for fonts (styles, sizes)
	smallTxt.load("Dongle-Light.ttf", 13);
	medTxt.load("Dongle-Regular.ttf", 17);
	bigTxt.load("RobotoCondensed-Regular.ttf", 17);
	btnTxt.load("Dongle-Bold.ttf", 26);
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

	queWindow.set(0, 60, 370, 760); // num are as follows, Xposition, Yposition, Length, Width 
	resWindow.set(390, 20, 615, 925); // original width value is 725

	loadData(); //function to load the data is summoned
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(108, 184, 235); // sets color to lightish blue
	
	

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
	ofDrawRectangle(btn10); // draws the btn entities on the screen using ofDrawRectangle

	ofSetColor(255, 255, 255);
	uiHeader.drawString("Tweet Search", 30, 45); // uses uiHeader object for drawString function, Tweet Search string, 30 x and 45 y added as values
	btnTxt.drawString("Count Tweets", 105, 110);  // same but with adjusted string, x and y values to put text in the btn entities drawn 
	btnTxt.drawString("Count Tweets w/ 'money'", 50, 180);
	btnTxt.drawString("Count Tweets w/ 'politics'", 48, 250);
	btnTxt.drawString("Print Tweets w/ 'Paris'", 65, 320);
	btnTxt.drawString("Print Tweets w/ 'DreamWorks'", 27, 390);
	btnTxt.drawString("Print Tweets w/ 'Uber'", 65, 460);
	btnTxt.drawString("Print Tweets w/ 'Trump'", 60, 530);
	btnTxt.drawString("Count Tweets w/ 'Pizza'", 60, 600);
	btnTxt.drawString("Count Tweets w/ 'Tokyo'", 60, 670);
	btnTxt.drawString("Print Tweets w/ 'America'", 55, 740);


	int yPos = 50;
	for (int q = 0; q < tweets.size(); q++) {

		bigTxt.drawString(tweetDate[q], 395, yPos);

		string formattedTxt = wrapString(tweets[q], 610);
		medTxt.drawString(formattedTxt, 400, (yPos + 20));

		yPos += 110;
	}


	//testImg.draw(600, 500, 212, 212);
}

//--------------------------------------------------------------
void ofApp::loadData() {
	data.open(ofToDataPath("sampleTweets.csv"));
	if (data.is_open()) {
		while (!data.eof()) {

			getline(data, dateOfTweet, ','); // gets the first part of a row in the csv file into dateOfTweet string
			getline(data, b, 'b'); // gets the b in the row to b string
			getline(data, tweetContent); // gets the remaining parts to tweetContent

			processTweet1.push_back(dateOfTweet);
			processTweet2.push_back(tweetContent); // pushes the values back into their appropriate vectors
		}
		processTweet1.erase(processTweet1.begin()); // erases the first element in tweet1 which is a row with irrelevant information
		data.close(); //close file
	}
	else {
		cout << "Error: File is not found." << endl; // outputs error message
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (btn4.inside(x, y)) { // runs if btn1 is in the cursor when pressed
		std::cout << "Clicked button 1" << std::endl;

		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement
		for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

			string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
			if (srch.find("Paris") != string::npos) { // nested if statement that runs if srch has any value equal to "Paris" 
				tweets.push_back(processTweet2[a]); // pushes the value of tweet2 into tweets vector
				tweetDate.push_back(processTweet1[a]);
			}

		}
	}
	else if (btn4.inside(x, y)) { // runs if btn1 is in the cursor when pressed
		std::cout << "Clicked button 4" << std::endl;

		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement
		for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

			string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
			if (srch.find("Paris") != string::npos) { // nested if statement that runs if srch has any value equal to "Paris" 
				tweets.push_back(processTweet2[a]); // pushes the value of tweet2 into tweets vector
				tweetDate.push_back(processTweet1[a]);
			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
// --------------------------------------------------------------
string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

	for (int i = 0; i < words.size(); i++) { //run through vector
		string wrd = words[i]; //get current word in vector

		// if we aren't on the first word, add a space
		if (i > 0) {
			tempString += " ";
		}
		tempString += wrd; //add current word to temp string

		int stringwidth = medTxt.stringWidth(tempString); //set string width to length of line

		if (stringwidth >= width) {//check string with to add either space or new line before current word
			typeWrapped += "\n"; //if line is now longer than desired width add a new line
			tempString = wrd; // make sure we're including the extra word on the next line
		}
		else if (i > 0) {
			typeWrapped += " "; // if we aren't on the first word, add a space
		}
		typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
	}

	return typeWrapped;

}


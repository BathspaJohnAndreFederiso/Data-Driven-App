#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	


	// loads fonts, same as the image above but for fonts (styles, sizes)
	smallTxt.load("Dongle-Light.ttf", 19);
	medTxt.load("Dongle-Regular.ttf", 17);
	bigTxt.load("RobotoCondensed-Regular.ttf", 19);
	btnTxt.load("Dongle-Bold.ttf", 26);
	uiHeader.load("Dongle-Bold.ttf", 55); 

	//button setting
	btn1.set(10, 70, 350, 60); // 10 and 70 as x and y coordinates, 350 and 60 as length and width
	btn2.set(10, 140, 350, 60); // same except the y value is incremented by 70 to arrange in a column
	btn3.set(10, 210, 350, 60);
	btn4.set(10, 280, 350, 60);
	btn5.set(10, 350, 350, 60);
	btn6.set(10, 420, 350, 60);
	btn7.set(10, 490, 350, 60);
	btn8.set(10, 560, 350, 60);
	btn9.set(10, 630, 350, 60);
	btn10.set(10, 700, 350, 60);
	nxtBtn.set(850, 80, 150, 50);

	queWindow.set(0, 60, 370, 760); // entered values are as follows, X position, Y position, Length, Width 
	resWindow.set(390, 70, 615, 295); // original width value is 725
	
	tweets.push_back("Select buttons on the left to begin displaying.");
	tweetDate.push_back("No Tweets Yet!"); // pushes back initial values to display to the screen when the user has not clicked on any buttons yet
	
	loadData(); //function to load the data is summoned

	prs = 0; // sets prs to 0
}

//--------------------------------------------------------------
void ofApp::update(){
	 // left empty no need for update
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(108, 184, 235); // sets color to lightish blue
	
	

	ofSetColor(228, 241, 255); // sets color to offwhite
	ofDrawRectangle(queWindow);


	ofSetColor(101, 119, 134); // sets color to gray
	ofDrawRectRounded(resWindow, 20); // draws resWindow as a rectangle
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
	ofDrawRectRounded(nxtBtn, 20);
	ofSetColor(101, 119, 134);
	btnTxt.drawString("Next Page", 870, 110);

	ofSetColor(255, 255, 255);
	uiHeader.drawString("Tweet Finder", 30, 45); // uses uiHeader object for drawString function, Tweet Search string, 30 x and 45 y added as values
	btnTxt.drawString("Count Tweets", 105, 110);  // same but with adjusted string, x and y position values to put text in the btn entities drawn 
	btnTxt.drawString("Count Tweets w/ 'money'", 50, 180);
	btnTxt.drawString("Count Tweets w/ 'politics'", 48, 250);
	btnTxt.drawString("Print Tweets w/ 'Paris'", 65, 320);
	btnTxt.drawString("Print Tweets w/ 'DreamWorks'", 27, 390);
	btnTxt.drawString("Print Tweets w/ 'Uber'", 65, 460);
	btnTxt.drawString("Count Tweets w/ 'Biden'", 60, 530);
	btnTxt.drawString("Count Tweets w/ 'Pizza'", 60, 600);
	btnTxt.drawString("Print Tweets w/ 'Tokyo'", 60, 670);
	btnTxt.drawString("Print Tweets w/ 'America'", 55, 740);
	 



		if (prs < tweets.size()) { // if statement that runs if prs is less than the size of tweets
			bigTxt.drawString(tweetDate[prs], 405, 100); // draws the value of the current element of TweetDate with 405 and 100 as x and y position values
			string formattedTxt = wrapString(tweets[prs], 500); // declares new string formattedTxt, which is equal to the wrapString function with the current element of tweets and value 580 passed in
			smallTxt.drawString(formattedTxt, 415, 160); //  using smallTxt, calls drawString with formattedTxt, 400 (x position) and 160 (y position)
			if (displayTweetCount == true) { // if code that runs if displayTweetCount is equal to true and q's value is equal to the second to last element

				uiHeader.drawString("Tweet " + ofToString((prs) + 1) + " out of " + ofToString(tweetCount), 390, 55); // draws the value of tweetCount using ofToString and btnTxt.drawString

			}
		}
		else { // else statement that runs if the above did not run
			bigTxt.drawString("No more tweets are available.", 415, 140); // draws appropriate message to screen
		}
			
	
}

//--------------------------------------------------------------
void ofApp::loadData() {
	data.open(ofToDataPath("sampleTweets.csv")); // uses data to open sampleTweets.csv (itself accessed via ofToDataPath as the file is located in bin/src
	if (data.is_open()) { // if statement that runs as long as data is open
		while (!data.eof()) { // while loop that runs as long as its not the end of data file

			getline(data, dateOfTweet, ','); // gets the first part of a row in the csv file into dateOfTweet string, ends at ,
			getline(data, b, 'b'); // gets the b in the row to b string, ends at itself
			getline(data, tweetContent); // gets the remaining parts to tweetContent

			processTweet1.push_back(dateOfTweet);
			processTweet2.push_back(tweetContent); // pushes the values back into their appropriate vectors
		}
		processTweet1.erase(processTweet1.begin()); // erases the first element in tweet1 which is a row with irrelevant information
		data.close(); //close file
	}
	else { // else statement that runs if anything else happens, usually failure to find the csv
		cout << "Error: File not found." << endl; // outputs error message
	}
}



//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (btn1.inside(x, y)) { // runs if btn2 is in the cursor when pressed
		prs = 0; // resets prs back to 0
		displayTweetCount = false; // returns displayTweetCount to false, removing any previous displayed count of tweets
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement
		std::cout << "Clicked button 1" << std::endl; // displays appropriate message to console
		

		for (int b = 0; b < 63691; b++) { // for loop that runs as long as b is less than 63591, which is almost all of the text lines in the csv

			tweets.push_back(processTweet2[b]);
			tweetDate.push_back(processTweet1[b]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors

		}
		
		
		
		displayTweetCount = true; // resets displayTweetCount to true to make it count its own number of tweets

		int tweetNum = 0; // declares int tweetNum for counting the actual number of the vetor
		for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of processTweet2, displaying all the tweets
			tweetNum++;
			//std::cout << processTweet1[a] << " " << processTweet2[a] << std::endl;
		}
		std::cout << "The total amount of tweets in sampleTweets.csv is " << tweetNum << std::endl; // displays every tweet in the csv file to console using cout 
		tweetCount = tweetNum; // sets tweetCount to the value of tweetNum
	}
	else if (btn2.inside(x, y)) { // runs if btn2 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 2" << std::endl; // displays appropriate message to console
		displayTweetCount = false; 
		tweets.clear();
		tweetDate.clear(); 

		processData("money", "Money"); // summons processData function with "money" and "Money" passed in as parameter
		
		displayTweetCount = true;
	}
	else if (btn3.inside(x, y)) { // runs if btn3 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 3" << std::endl;
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement

		processData("Politics", "politics"); // the following btn elses' 
		                                     // content will be mostly the same but with different string values passed in
		
		displayTweetCount = true; 
	}
	else if (btn4.inside(x, y)) { // runs if btn4 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 4" << std::endl; 
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear(); 

		processData("Paris", "paris");
	}
	else if (btn5.inside(x, y)) { // runs if btn5 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 5" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("DreamWorks"); // summons processDataSingle function with Dreamworks passed in 
	}
	else if (btn6.inside(x, y)) { // runs if btn6 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 6" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("Uber");  // summons processDataSingle function with Uber  passed in 
	}
	else if (btn7.inside(x, y)) { // runs if btn7 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 7" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("Biden");
		displayTweetCount = true; // sets displayTweetCount to true
		
	}
	else if (btn8.inside(x, y)) { // runs if btn8 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 8" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("pizza", "Pizza");
		displayTweetCount = true; // sets displayTweetCount to true
		
	}
	else if (btn9.inside(x, y)) { // runs if btn9 is in the cursor when pressed
		prs = 0;
		std::cout << "Clicked button 9" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("Tokyo", "tokyo");
		
	}
	else if (btn10.inside(x, y)) { // runs if btn10 is in the cursor when pressed
	    prs = 0;
		std::cout << "Clicked button 10" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("America", "america");
	}
	else if (nxtBtn.inside(x, y)) {
	  std::cout << "Pressed up button" << std::endl;
	  upPress = true;
	  prs++;
    }
	
}


void ofApp::processData(string srchTerm, string srchTerm2) {

	for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

		string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
		if (srch.find(srchTerm) != string::npos || srch.find(srchTerm2) != string::npos) { // nested if statement that runs if srchTerm or srchTerm2 has any value equal to the passed in string element 
			tweets.push_back(processTweet2[a]); 
			tweetDate.push_back(processTweet1[a]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors
		}

	}
	tweetCount = tweets.size(); // assigns to tweetCount the value of the size of tweets vector

}

//--------------------------------------------------------------
void ofApp::processDataSingle(string srchTerm) {
	
	for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

		string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
		if (srch.find(srchTerm) != string::npos) { // nested if statement that runs if srchTerm has any value equal to the passed in string element 
			tweets.push_back(processTweet2[a]); 
			tweetDate.push_back(processTweet1[a]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors
		}

	}
	tweetCount = tweets.size(); // assigns to tweetCount the value of the size of tweets vector
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

		int stringwidth = smallTxt.stringWidth(tempString); //set string width to length of line, with smallTxt passed in as the font value

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
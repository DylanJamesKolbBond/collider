//input.cpp

#include <iostream>
#include "primer.h"
#include "move.h"
#include "input.h"
#include "display.h"
#include "legal.h"
#include "board.h"
#include <unistd.h>
#include "debug.h"
#include "search.h"

//FUE
/* Takes input from the user and checks it for input error */
bool userEntry(){	
	std::string input;
	thinkFlag = false;

	//Display side to move
	if( board.side == WHITE ){
		std::cout << "White to move.\n";
	}
	else if( board.side == BLACK ){
		std::cout << "Black to move.\n";
	}
	else { std::cout << "Nothing!" << std::endl; }; //This should never occur

	//Prompt and take the users input.
	std::cout << "Enter your move!\n";
	getline( std::cin, input );
	
	//Allows quitting of program
	if( input == "exit" || input == "quit" || input == "stop" ){
		stop = true;
		return false;
	}

	//Undo input command	
	if( input == "undo" || input == "u" ){
		if( undo.size() < 1 ){
			std::cout << "Can't undo anymore!\n";
			return false;
		}
		changeSide();
		unmakeMove();
		return false;
	}

	//Increase and decrease depth
	if( input == "id" ){
		grandDepth++;
	}
	else if( input == "dd" ){
		grandDepth--;
	}

	//Flip board command
	if( input == "flip" ){
		flipFlag = (flipFlag) ? false: true;
		return false;
	}

	if( input == "think" || input == "t" ){
		thinkFlag = true;
		engine();
		return false;
	}

	//Slow down display speed
	if( input == "slow" ){
		slowFlag = (slowFlag) ? false: true;
		return false;
	}

	//Restart command
	if( input == "restart" || input == "r" ){
		for( int i = undo.size(); i > 0; i--){
			std::cout << "Undo size is: " << undo.size() << "\n";
			changeSide();
			unmakeMove();
		}
		return false;
	}

	//Set castling
	if( input == "o-o" || input == "o-o-o" || input == "0-0" || input == "0-0-0" ){
		board.castling = true;
		board.newfrSq = ((board.side - 1) * 70) + 25;
		std::cout << "The kingSq is: " << board.newfrSq << "\n";
		//Set the toSq	
		if( input == "o-o" || input == "0-0" ){
			board.newtoSq = board.newfrSq + 1;
		}
		else{
			board.newtoSq = board.newfrSq - 1;
		}
		std::cout << "The toSq is: " << board.newtoSq << "\n";

		life++;
		return true;
	}

	//Error check for too many spaces.
	// (Will change later for input leniency)
	else{
		board.castling = false;
		if ((int)input.size()!=5){      	
			std::cout << "Invalid input.\n";
			return false;
		}
		
		//Error check for invalid ranks and files
		if ( (int)input[0] > 105 || (int)input[0] < 97 || (int)input[3] > 105 || (int)input[3] < 97 ){ 	
			std::cout << "Invalid input.\n";
			return false;
		}

		if(( (int)input[1] < 49) ||( (int)input[1] > 57) ||( (int)input[4] < 49) ||( (int)input[4] > 57) ){
			std::cout << "Invalid input.\n";
			return false;
		}
	}
	nl(9);

	/* Converts the ASCI value of the input into file and rank */	
	board.newfrSq = FR2SQ(((int)input[0] - 97), ((int)input[1] - 49));
	board.newtoSq = FR2SQ(((int)input[3] - 97), ((int)input[4] - 49));	

	return true;
	life++;
}

/* Search code (FUI) */
/* Container function which gets input and checks it for legality.
   Basically takes input, checks it, and sets the official to and fr squares */
void userInput(){
	getInput();
	if( stop ) return;
	while( !checkLegal() || moveCheck() ){
		displayAll();
		std::cout << "TEST 4\n";
		getInput();
		if( stop ) return;
	}	
	board.frSq = board.newfrSq;
	board.toSq = board.newtoSq;	
}	

/* Container function to check userEntry and repeatedly run until it returns true */
void getInput(){
	while( !userEntry() ){
		if( stop ) return;
		displayAll();
	}
	return;
}

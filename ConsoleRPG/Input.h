#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <iostream>
#include <conio.h>
#include <thread>

#endif

using namespace std;

enum ARROW_KEY{
	RIGHT = -1,
	UP = -2,
	LEFT = -3,
	DOWN = -4
};

namespace Input{

	///<summary>
	///Stores the last keypress taken in by the inputThread as an int.
	///</summary>
	static int KeyPress;

	///<summary>
	///The storage for the input thread that runs to grab input.
	///</summary>
	static thread InputThread;

	///<summary>
	///Called when the program exits safely.
	///</summary>
	void cleanup(){ InputThread.join();}

	///<summary>
	///The function that becomes the thread to handle input.
	///</summary>
	static void thread_HandleInput(){
		// Default keyPress to 0 so we know if _getch() hasn't detected a keypress yet.
		KeyPress = 0;
		// _getch() waits for you to press a key, and then when you do returns the int for that key.
		KeyPress = _getch();
	}

	///<summary>
	///Initializes the Input Library to prevent crashes on exit.
	///</summary>
	static void InitializeInput(){
		atexit(cleanup);
		InputThread = thread(thread_HandleInput);
	}

	///<summary>
	///Gets you the current key input.  0 means no input has occured.
	///-5 is an error code that means you should see Luna.
	///</summary>
	static int GetKey(){
		int currentInput;

		if ((currentInput = KeyPress) != 0){ // If it's changed the thread is dead so we need to start it again to catch the next time.

			// If currentInput is 224 that means we've hit a special case, so I need to getch again to move in the buffer
			if (currentInput == 224){
				switch (_getch()){
				case 77:
					currentInput = ARROW_KEY::RIGHT;
					break;
				case 72:
					currentInput = ARROW_KEY::UP;
					break;
				case 75:
					currentInput = ARROW_KEY::LEFT;
					break;
				case 80:
					currentInput = ARROW_KEY::DOWN;
					break;
				default:
					currentInput = -5;
					break;
				}
			}

			InputThread.join();
			InputThread = thread(thread_HandleInput);
		}

		return currentInput;
	}

	



}
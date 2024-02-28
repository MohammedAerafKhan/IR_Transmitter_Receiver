// Functions.cpp: function declaration for main file

#include "main.h"
#include "Keypad.h"
#include <cstdio>

Keypad kpad(PTA6, PTA4, PTA26, PTA27, PTA1, PTA9, PTA8, PTA7);
PwmOut led(PTC8); // set LED

PwmOut statusReady(PTB19); // set LED
PwmOut statusBusy(PTB18); // set LED

std::string getPressedNumbers() {
    std::string numbers = "";
    char key;
    int released = 1;

    while(1) {
        key = kpad.ReadKey();

        if(key == '\0')
            released = 1;

        if((key != '\0') && (released == 1)) {
            if (key == '#') {
                return numbers; // return accumulated numbers when '#' is pressed
            } else {
                numbers += key; // accumulate numbers in the string
                released = 0;
            }
        }
    }
}

std::string convertToWord(const std::string& numbers) {
    std::map<char, std::string> num_to_char = {
        {'1', "1"},
        {'2', "2abc"},
        {'3', "3def"},
        {'4', "4ghi"},
        {'5', "5jkl"},
        {'6', "6mno"},
        {'7', "7pqrs"},
        {'8', "8tuv"},
        {'9', "9wxyz"},
        {'0', " 0"}
    };

    std::string word = "";
    char prev_num = '\0';
    int count = 0;

    for (char num : numbers) {
        if (num == '*') {
            word += "";
            prev_num = '\0';
        } else if (num == prev_num) {
            count = (count + 1) % num_to_char[num].size();
            word.pop_back(); // remove the previous character
            word += num_to_char[num][count];
        } else {
            prev_num = num;
            count = 0;
            word += num_to_char[num][count];
        }
    }
    return word;
}

void delayShort() {
    wait_us(500000);
}

void delayLong() {
    wait_us(1000000);
}

void setStatusReady() {
    statusReady = 0;
    statusBusy = 1;
}

void setStatusBusy() {
    statusReady = 1;
    statusBusy = 0;
}

void IR_LED_ON() {
    led = 1;
}

void IR_LED_OFF() {
    led = 0;
}

void stringToMorse(const std::string& str) {
    setStatusBusy();
    printf("String is: %s\n", str.c_str());
    for (char character : str) {
        printf("Blinking %c\n", character);
        charToMorse(character);
        // Additional delay between characters if needed
    }
    setStatusReady();
}

void charToMorse(char character){
    switch (character) {
        case 'a':	// .-
            IR_LED_ON();
            delayShort();	// .
            IR_LED_OFF();

            delayShort();

            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'b':	// -...
        	IR_LED_ON();
        	delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'c':	 // -.-.
            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'd':	// -..
            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayShort();

            IR_LED_ON();
            delayShort();	// .
            IR_LED_OFF();

            delayShort();

            IR_LED_ON();
            delayShort();	//.
            IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'e':	// .
            IR_LED_ON();
            delayShort(); // .
            IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'f':	// ..-.
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayShort();

            IR_LED_ON();
            delayShort();	// .
            IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'g':	// --.
            IR_LED_ON();
            delayLong();	// -
            IR_LED_OFF();

            delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
            delayShort();	// .
            IR_LED_OFF();

            delayLong();	// a bit of a delay after every letter
            break;
        case 'h':	// ....
        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'i':	// ....
        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'j':	// .---
        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'k':	// -.-
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'l':	// .-..
        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayShort();

        	IR_LED_ON();
        	delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'm':	// --
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'n':	// -.
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'o':	// ---
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'p':	// .--.
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'q':	// --.-
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 'r':	// .-.
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 's':	// ...
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
        case 't':	// -
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
            break;
		case 'u':	// ..-
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;
		case 'v':	// ...-
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;
		case 'w':	// .--
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;
		case 'x':	// -..-
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;
		case 'y':	// -.--
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;
		case 'z':	// --..
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();	// a bit of a delay after every letter
			break;

		case '1':		// .----
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();
			break;

		case '2':           // ..---
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();
			break;

		case '3':           // ...__
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();
			break;

		case '4':           // ...._
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayLong();
			break;

		case '5':           // .....
			IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();
			break;

		case '6':           // _....
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();
			break;

		case '7':           // __...
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();
			break;

		case '8':           // ___..
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();

			delayLong();
			break;

		case '9':          // ____.
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayShort();	// .
			IR_LED_OFF();
  
			delayLong();
			break;

		case '0':           // _____
			IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// -
			IR_LED_OFF();

			delayShort();

            IR_LED_ON();
			delayLong();	// _
			IR_LED_OFF();
			
			delayLong();
			break;

        case ' ':
        	delayLong();
        	break;

        default:
            printf("Invalid character ");
    }
}

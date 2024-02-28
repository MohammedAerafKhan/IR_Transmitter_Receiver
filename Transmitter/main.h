// main.h: function definition for main

#ifndef _MAIN_H_
#define _MAIN_H_

#include <string>
#include <map>

std::string getPressedNumbers();
std::string convertToWord(const std::string& numbers);
void delayShort();
void delayLong();
void setStatusReady();
void setStatusBusy();
void IR_LED_ON();
void IR_LED_OFF();
void charToMorse(char character);
void stringToMorse(const std::string& str);


#endif
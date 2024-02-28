// main.cpp: mine file

#include "mbed.h"
#include "main.h"
#include <cstdio>

int main() {
    while(1) {
        setStatusReady();
        string numbers = getPressedNumbers();
        wait_us(100000);
        string word = convertToWord(numbers);
        wait_us(100000);
        printf("Characters: %s\n", word.c_str());
        wait_us(100000); // Adjust the delay time as needed
        printf("Arriving at stringToMorse\n");
        stringToMorse(word);
    }
}

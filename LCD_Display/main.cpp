#include "mbed.h"
#include "LCDi2c.h"

I2C i2c(PTC11, PTC10); // Adjust with your actual I2C pins
LCDi2c lcd(PTC11, PTC10, LCD20x4); // Initialize your LCD. 20x4 is my LCD you may replace 20x4 with 16x2

/**
 * Displays a text string on the LCD, automatically managing line breaks.
 * 
 * @param text The text string to display.
 */
void displayOnLCD(const char* text) {
    const int lineLength = 20; // Maximum characters per line for a 20x4 LCD
    lcd.cls(); // Clear the screen before displaying new text

    int line = 0;
    while (*text && line < 4) {
        lcd.locate(0, line); // Move cursor to the start of the current line
        
        // Calculate the length of the next substring to fit in the line
        int len = strlen(text);
        if (len > lineLength) {
            len = lineLength;
        }

        // Look for a newline character in the current line segment
        const char* newline = strchr(text, '\n');
        if (newline && newline - text < len) {
            len = newline - text;
        }

        // Print the substring that fits on the current line
        char buffer[lineLength + 1]; // Temporary buffer to hold the current line segment
        strncpy(buffer, text, len);
        buffer[len] = '\0'; // Ensure null-termination
        lcd.printf("%s", buffer);
        
        text += len; // Advance the text pointer past the current line segment
        if (*text == '\n') {
            text++; // Skip newline character
        }

        line++; // Move to the next line
    }
}

int main() {
    // Example usage of displayOnLCD function
    displayOnLCD("The quick brown fox jumps over the lazy dog!");

    ThisThread::sleep_for(2s); // Display for 2 seconds before the loop

    while(true) {
        ThisThread::sleep_for(1s); // Keep the program running
    }
}


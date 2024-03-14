


// #include "mbed.h"
// #include "LCDi2c.h"

// // Assuming LCD 16x2 or 20x4 with an I2C address of 0x27
// // You should replace I2C_SDA and I2C_SCL with the correct pins for your board
// // lcd_t type should be adjusted according to your LCD, e.g., LCD16x2, LCD20x4
// I2C i2c(PTC11, PTC10); // replace with I2C pins

// LCDi2c lcd(PTC11, PTC10, LCD20x4);


// int main() {
//     // // Initialize the LCD
//     //lcd.init();

//     // Clear the screen
//     lcd.cls();

//     //Set cursor to the beginning of the first row
//      lcd.locate(0, 0);
//     // // Display "Hello, World!" on the first row
//     lcd.printf("01234567890123456789\n");


//     //Set cursor to the beginning of the second row
//      lcd.locate(0, 1);
//     // // Display "LCDi2c Demo" on the second row
//     lcd.printf("ABCDEFGHIJKLMNOPQRST\n");

//         // Print on the third row
//     lcd.locate(0, 2); // Set cursor to the beginning of the third row
//     lcd.printf("01234567890123456789");

//     // Print on the fourth row
//     lcd.locate(0, 3); // Set cursor to the beginning of the fourth row
//     lcd.printf("UVWXYZABCDEFGHIJKLMN");

//     //=============================================
//     // lab 5 sample code
//     // lcd.cls();
//     // lcd.locate(0, 0);
//     // lcd.printf("AB!\n");
//     // lcd.character(0, 1, 0);
//     // lcd.character(3, 1, 1);
//     // lcd.character(5, 1, 2);
//     // lcd.character(7, 1, 3);

//     ThisThread::sleep_for(2s);
//     // Loop forever
//     while(true) {
//         ThisThread::sleep_for(1s);
//     }

// }




// #include "mbed.h"
// #include "LCDi2c.h"

// // Initialize LCD
// I2C i2c(PTC11, PTC10); // Adjust for your board
// LCDi2c lcd(PTC11, PTC10, LCD20x4); // Assuming LCD20x4 is a valid constructor argument

// // Setup serial connection
// BufferedSerial pc(PTC4, PTC3); // Use default USB serial pins
// char buffer[80]; // Buffer to store input string from serial

// int main() {
//     pc.set_baud(9600); // Set baud rate for serial communication
//     lcd.cls(); // Clear the LCD

//     while (true) {
//         if (uint32_t num = pc.read(buffer, sizeof(buffer) - 1)) {
//             buffer[num] = '\0'; // Null-terminate the string

//             lcd.cls(); // Clear the LCD
//             lcd.locate(0, 0); // Set cursor to the beginning
//             lcd.printf("You typed:");
//             lcd.locate(0, 1); // Move to the next line
//             lcd.printf("%s", buffer);

//             // Clear the buffer to receive new input
//             memset(buffer, 0, sizeof(buffer));
//         }

//         ThisThread::sleep_for(100ms); // Add a small delay to debounce input
//     }
// }






// I2C i2c(PTC11, PTC10); // replace with I2C pins

// LCDi2c lcd(PTC11, PTC10, LCD20x4);


// int main() {


//     // Clear the screen
//     lcd.cls();

//     //Set cursor to the beginning of the first row
//      lcd.locate(0, 0);
//     // // Display "Hello, World!" on the first row
//     lcd.printf("01234567890123456789\n");


//     //Set cursor to the beginning of the second row
//      lcd.locate(0, 1);
//     // // Display "LCDi2c Demo" on the second row
//     lcd.printf("ABCDEFGHIJKLMNOPQRST\n");

//         // Print on the third row
//     lcd.locate(0, 2); // Set cursor to the beginning of the third row
//     lcd.printf("01234567890123456789");

//     // Print on the fourth row
//     lcd.locate(0, 3); // Set cursor to the beginning of the fourth row
//     lcd.printf("UVWXYZABCDEFGHIJKLMN");


//     ThisThread::sleep_for(2s);
//     // Loop forever
//     while(true) {
//         ThisThread::sleep_for(1s);
//     }

// }

#include "mbed.h"
#include "LCDi2c.h"

I2C i2c(PTC11, PTC10); // Adjust with your actual I2C pins
LCDi2c lcd(PTC11, PTC10, LCD20x4); // Initialize your LCD

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


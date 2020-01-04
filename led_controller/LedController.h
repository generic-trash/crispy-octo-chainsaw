#include <Entropy.h>
extern "C" {
  // function prototypes
  void transferState(uint16_t data);  //Send state to 74hc595
  byte mode;                          //Animation
  void setup();                       //Setup
  void beginSerial();                 // Initialize Serial
  void beginEntropy();                // Initialize Entropy
  void delay250();                    //Delay function
}
// Animations
const uint16_t oscillating[] = {
  0B1010101010101010,
  0B0101010101010101  
};

const uint16_t flasher[] = {
  0B1111111111111111,
  0B0000000000000000  
};

const uint16_t bouncer[] = {
  0B0000000000000001,
  0B0000000000000010,
  0B0000000000000100,
  0B0000000000001000,
  0B0000000000010000,
  0B0000000000100000,
  0B0000000001000000,
  0B0000000010000000,
  0B0000000100000000,
  0B0000001000000000,
  0B0000010000000000,
  0B0000100000000000,
  0B0001000000000000,
  0B0010000000000000,
  0B0100000000000000,
  0B1000000000000000,
  0B0100000000000000,
  0B0010000000000000,
  0B0001000000000000,
  0B0000100000000000,
  0B0000010000000000,
  0B0000001000000000,
  0B0000000100000000,
  0B0000000010000000,
  0B0000000001000000,
  0B0000000000100000,
  0B0000000000010000,
  0B0000000000001000,
  0B0000000000000100,
  0B0000000000000010 
};

const uint16_t train[] = {
  0B0000000000000000,
  0B0000000000000001,
  0B0000000000000011,
  0B0000000000000111,
  0B0000000000001111,
  0B0000000000011111,
  0B0000000000111111,
  0B0000000001111111,
  0B0000000011111111,
  0B0000000111111110,
  0B0000001111111100,
  0B0000011111111000,
  0B0000111111110000,
  0B0001111111100000,
  0B0011111111000000,
  0B0111111110000000,
  0B1111111100000000,
  0B1111111000000000,
  0B1111110000000000,
  0B1111100000000000,
  0B1111000000000000,
  0B1110000000000000,
  0B1100000000000000,
  0B1000000000000000
};
char serread;                         // For animation logic
uint16_t data;                        // For animation logic
uint8_t counter;                      //For animation

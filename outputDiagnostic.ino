int latchPin = 5;      // Latch pin of the first 74HC595 is connected to Digital pin 5
int clockPin = 6;      // Clock pin of the first 74HC595 is connected to Digital pin 6
int dataPin = 4;       // Data pin of the first 74HC595 is connected to Digital pin 4

int latchPin1 = 8;     // Latch pin of the second 74HC595 is connected to Digital pin 8
int clockPin1 = 9;     // Clock pin of the second 74HC595 is connected to Digital pin 9
int dataPin1 = 7;      // Data pin of the second 74HC595 is connected to Digital pin 7

byte leds = 0;         // Variable to hold the pattern of which LEDs are currently turned on or off

void setup()
{
  // Set all the pins of both 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
}

void loop()
{
  // Turn on LEDs on the first shift register from the 1st LED to the 8th LED
  for (int i = 0; i < 8; i++)  
  {
    bitSet(leds, i);          // Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(500);
  }

  // Turn on LEDs on the second shift register in a waterfall effect
  for (int i = 0; i < 8; i++)  
  {
    bitSet(leds, i);          // Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister1();
    delay(500);
    bitClear(leds, i);        // Clear the bit to turn off the LED before shifting to the next LED
  }

  // Turn off LEDs on the first shift register
  leds = 0;                  
  updateShiftRegister();
  delay(500);

  // Turn off LEDs on the second shift register
  leds = 0;                  
  updateShiftRegister1();
  delay(500);
}

void updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void updateShiftRegister1()
{
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin1, clockPin1, LSBFIRST, leds);
  digitalWrite(latchPin1, HIGH);
}

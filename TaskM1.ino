// C++ code
// Global variables
const uint16_t timer_compare = 31249;  
volatile uint8_t blueTimer = 6;  
// Variables for LED
volatile byte red, green, blue, pRed, pGreen, pBlue = 0;
volatile bool bRed, bGreen, bBlue = false;
void setup(){
  	// Setup ports and other code
	DDRB |= 0b00000111;
    Serial.begin(9600); 
    PCICR |= B00000100;
    PCMSK2 |= B00001100;
  	
  	// For setting up timer
  	noInterrupts();
    TCCR1A = 0;
  	TCCR1B = 0;
    TCNT1 = 0;
    OCR1A = timer_compare;
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1 << OCIE1A);
    interrupts();
}

void loop() {
// Nothing happens in loop
}

// This updates non timer based LED
void updateLED() {
  PORTB = (PORTB & 0b11111000)         
         | (bRed   ? (1 << PB0) : 0)       
         | (bGreen ? (1 << PB1) : 0)
         | (bBlue ? (1 << PB2) : 0);     
}

// Timer interrupt
ISR(TIMER1_COMPA_vect)
{
  //If blue timer is more than 0
  if (blueTimer > 0)
  {
    blueTimer--;
    // If blue time is 0
    if (blueTimer == 0)
    {
      // Make state of light opposite of what it is
      bBlue = !bBlue;
      // Reset timer for next toggle
      blueTimer = 6;  
      Serial.print("LED toggled: ");
    }
  }
  updateLED();
}

// PCI interrupt
ISR(PCINT2_vect){
  // Get current red & green LED status
  red = PIND & B00001000;
  green = PIND & B0000100;
  
  // If it's changed, swap what LED should be
  if(green && !pGreen)
  {
    bGreen = !bGreen;
    Serial.print("Green sensor triggered. New bGreen state: ");
    Serial.println(bGreen);
  }
  if(red && !pRed)
  {
    bRed = !bRed;
    Serial.print("Red sensor triggered. New bRed state: ");
    Serial.println(bRed);
  }
  
  // Adjust previous values
  pRed = red;
  pGreen = green;
  
  // Update LED
  updateLED();
}
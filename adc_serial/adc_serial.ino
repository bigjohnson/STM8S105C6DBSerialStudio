/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define ONEBIT 0.0048828125
#define MEDIA 10

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial_begin(576000);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  Serial_print_c('[');
  //unsigned int pippo = analogRead(0);
  unsigned int pippo;
  float pluto;
  //unsigned int lettura = 0;
  for (unsigned char canale = 0; canale < 10; canale ++) {
    pippo = 0;
    for ( unsigned char x = 0; x < MEDIA; x++) {
      //lettura = analogRead(0);
      pippo += analogRead(canale);
    }
    pluto = (( pippo * ONEBIT ) / MEDIA) + ONEBIT;
    Serial_print_f(pluto);
    if ( canale < 9 ) {
      Serial_print_c(',');
    }
  }
  Serial_print_c(']');
}

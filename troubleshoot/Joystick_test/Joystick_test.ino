


const uint8_t x_pin = 34 ,y_pin = 35, switch_1 = 33, switch_2 =25;        //INPUT pins


bool sw1 = 0, sw2 = 0;
int X = 0, Y = 0;



void setup() {
  // declare the INPUT:
  pinMode(switch_1, INPUT_PULLUP);
  pinMode(switch_2, INPUT_PULLUP);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);

  Serial.begin(115200);
}



void loop() {
  // read the value from the joysticks:
  X = analogRead(x_pin);
  Y = analogRead(y_pin);
  
  sw1 = digitalRead(switch_1);
  sw2 = digitalRead(switch_2);



  X = map(X, 4095, 0, 7, -7);
  Y = map(Y, 4095, 0, 7, -7);

  Serial.printf("Value of X = %d  Y = %d, sw1= %d, sw2= %d \n  ", X, Y, sw1, sw2);

  
  delay(100);
  
}
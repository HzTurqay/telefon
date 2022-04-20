bool lastDigitstate = 0;
uint8_t digitCounter = 0;
bool digitState = 0;
bool dialState = 0;
uint8_t dialCounter = 0;
bool lastDialState = 0;

uint8_t myDigits[12];
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(2 , INPUT_PULLUP);
pinMode(3 , INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
digitState = digitalRead(2);
dialState = digitalRead(3);

if(dialState != lastDialState)
{
  if(dialState == HIGH)

  {
    dialCounter++;
  }

  delay(5);
}

lastDialState = dialState;

if(digitState != lastDigitstate)
{
  if(digitState == HIGH)
  {
    myDigits[dialCounter - 1] = dialCounter; 
    digitCounter++;
    dialCounter = 0;
  }
  delay(10);
}
lastDigitstate = digitState;
}

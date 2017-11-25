//still try to clean it up :(
//hard to understand
//change extension into .ino from .c
int in2 = 8;
int in1 = 9;
int pin10 =10;
char val; 
int ledPin1 = 3;
int ledPin2 = 4;
int ledPin3 = 5;
int ledPin4 = 6;
int ledPin5 = 7;
int ledPin0 = 2;
int ledPin12 = 12;

int i;

void setup() {
	Serial.begin(9600);
	// the array elements are numbered from 0 to (pinCount - 1).
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	pinMode(ledPin4, OUTPUT);
	pinMode(ledPin5, OUTPUT);
	pinMode(ledPin12, OUTPUT);
	pinMode(pin10, OUTPUT);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(pin10, HIGH);
	fa();
	delay(800);
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(pin10, LOW);
  
}

void loop() {
	if (Serial.available()) 
	{ // If data is available to read,
	 val = Serial.read(); // read it and store it in val
	}

	switch (val) {
		case 'Z':
			fz();
			break;
		case 'C':
			ff();
			break;
		case 'K':
			fk();
			break;
		case 'L':
			fl();
			break;
		case 'P':
			fp();
			fj();
			break;
		case 'R':
			fa();
                     four_pin_high(ledPin4, in1, in2, pin10);
			fa();
			delay(800);
                     three_pin_low(in1, in2, pin10);
			fa();
                     four_pin_high(ledPin4, in1, in2, pin10);
			fa();
			delay(800);
                     three_pin_low(in1, in2, pin10);
			fa();
			break;
		case 'H':
			digitalWrite(ledPin4, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(1800);
			digitalWrite(pin10, LOW);
			fa();
			digitalWrite(pin10, HIGH);
			fa();
			delay(1800);
			digitalWrite(pin10, LOW);
			fa();
			break;
		   
		case 'J':
                     four_pin_high(ledPin4, in1, in2, pin10);
			fa();
			delay(3800);  //?? why?
                     three_pin_low(in1, in2, pin10);
			fa();
			break;
		case 'Y':
			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(3800);  //?? whats that?
			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
			fa();
			break;
		case 'X':
			fk();
			fl();
                     four_pin_high(ledPin4, in1, in2, pin10);
			fa();
			delay(3800);  //?? really need this?
                     three_pin_low(in1, in2, pin10);
			fa();
			break;
		case 'A':
			fn();
			break;
		case 'S':
			fs();
			break;
	        default: 
			delay(10);
			break;
	}
	//val = "0";  //is it needed?
}

void blink01(int pinHigh, int pinLow, int timeDelay)
{
  digitalWrite(pinHigh, HIGH);
  digitalWrite(pinLow, LOW);
  delay(timeDelay); 
}

void four_pin_high(int pin1, int pin2, int pin3, int pin4)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH); 
}

void three_pin_low(int pin1, int pin2, int pin3)
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW);
}

void three_pin_high(int pin1, int pin2, int pin3)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH); 
  digitalWrite(pin3, HIGH);
}


void fk()
{
	digitalWrite(ledPin4, HIGH);
	digitalWrite(in2, HIGH);
	// set speed to 200 out of possible range 0~255
	// turn on motor B
	delay(3500);
	// now change motor directions
	digitalWrite(in2, LOW);	
	digitalWrite(ledPin1, LOW);
	delay(5);

  blink01(ledPin3, ledPin2, 225);
  blink01(ledPin4, ledPin3, 225);
  blink01(ledPin5, ledPin4, 215);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);

};

void fl()
{
	digitalWrite(ledPin4, HIGH);
	digitalWrite(in1, HIGH);

	// set speed to 200 out of possible range 0~255
	// turn on motor B
	delay(1500);
	// now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(ledPin1, LOW);
	delay(5);
  blink01(ledPin3, ledPin2, 215);
  blink01(ledPin4, ledPin3, 115);
  blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
};

void fs()
{
	digitalWrite(ledPin4, HIGH);
	digitalWrite(in1, HIGH);
	// set speed to 200 out of possible range 0~255
	// turn on motor B
	delay(25000);    //wait for 25 seconds!!??
	// now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 215);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
};

  


void fn()
{
	digitalWrite(ledPin4, HIGH);
	// now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 315);
      blink01(ledPin5, ledPin4, 315);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
};


void fp()
{
  digitalWrite(pin10, HIGH);
  delay(2500);
  digitalWrite(pin10, LOW);
};



void fz()
{
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, LOW);
};


void ff()
{
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin0, HIGH);
      four_pin_high(ledPin4, in1, in2, pin10);
	fa();
	delay(1000);
      three_pin_low(in1, in2, pin10);
      three_pin_high(ledPin2, ledPin1, ledPin12);
};

void fg()
{
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin12, HIGH);   
	delay(100);
};
  
void fh()
{
    digitalWrite(ledPin3, HIGH);
};

  void fi()
{
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin5, HIGH);
};

  void fj()
{
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 115); 
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 115);

	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 115);

	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin5, LOW);
};

void fa()
{
        digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(15);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 215);
      blink01(ledPin5, ledPin4, 15);

	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(215);
	digitalWrite(ledPin1, LOW);
	delay(215);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 151);
	digitalWrite(ledPin5, LOW);
	delay(215);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 215);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, HIGH);
};

void fx()
{
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
      blink01(ledPin3, ledPin2, 115);
      blink01(ledPin4, ledPin3, 115);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 15);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 15);
      blink01(ledPin4, ledPin3, 15);
      blink01(ledPin5, ledPin4, 115);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
      blink01(ledPin3, ledPin2, 125);
      blink01(ledPin4, ledPin3, 115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin5, LOW);
};


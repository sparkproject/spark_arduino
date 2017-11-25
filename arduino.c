#include <AccelStepper.h>
#define HALFSTEP 8
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
			digitalWrite(ledPin4, HIGH);
			digitalWrite(in1, HIGH);
			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(800);
			digitalWrite(in1, LOW);
			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
			fa();
			digitalWrite(ledPin4, HIGH);
			digitalWrite(in1, HIGH);
			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(800);
			digitalWrite(in1, LOW);
			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
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
			digitalWrite(ledPin4, HIGH);
			digitalWrite(in1, HIGH);
			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(3800);
			digitalWrite(in1, LOW);
			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
			fa();
			break;
		case 'Y':

			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(3800);

			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
			fa();
			break;
		case 'X':
			fk();
			fl();
			digitalWrite(ledPin4, HIGH);
			digitalWrite(in1, HIGH);
			digitalWrite(in2, HIGH);
			digitalWrite(pin10, HIGH);
			fa();
			delay(3800);
			digitalWrite(in1, LOW);
			digitalWrite(in2, LOW);
			digitalWrite(pin10, LOW);
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
	val = "0";
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(225); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(215);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(215);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH); 

	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin3, HIGH);
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(215); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);


	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin3, HIGH);
};

void fs()
{
	digitalWrite(ledPin4, HIGH);
	digitalWrite(in1, HIGH);
	// set speed to 200 out of possible range 0~255
	// turn on motor B
	delay(25000);
	// now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(ledPin1, LOW);
	delay(5);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(215); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);

	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin3, HIGH);
};

  


void fn()
{
	digitalWrite(ledPin4, HIGH);
	// now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

	digitalWrite(ledPin1, LOW);
	delay(5);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(315);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(315);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);

	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin3, HIGH);
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
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin3, LOW);
};


void ff()
{
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin0, HIGH);

	digitalWrite(ledPin4, HIGH);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(pin10, HIGH);
	fa();
	delay(1000);
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(pin10, LOW);
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin12, HIGH);
};

void fg()
{
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin12, HIGH);   
	delay(100);
	//digitalWrite(ledPin2, LOW);
	//digitalWrite(ledPin1, LOW);
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
	//digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(125);
	digitalWrite(ledPin1, LOW);
	delay(5);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);

	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);

	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);

	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);

	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
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
	{digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(15);
	digitalWrite(ledPin1, LOW);
	delay(5);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(215);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(215);
	digitalWrite(ledPin1, LOW);
	delay(215);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(151);
	digitalWrite(ledPin5, LOW);
	delay(215);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(215);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
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
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(115); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	delay(115);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(15);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(15); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(15);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin4, LOW);
	delay(115);

	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin5, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin2, LOW);
	delay(125); 
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin3, LOW);
	delay(115);
	digitalWrite(ledPin5, HIGH);
	digitalWrite(ledPin1, LOW);
	delay(115);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin4, LOW);
	delay(115);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin5, LOW);
};


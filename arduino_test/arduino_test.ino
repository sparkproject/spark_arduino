
//connect RGB led to pwm pins; {R, G, B}
int rgbArray[3] = {5, 3, 6};

double actualTime = millis();

void setup(void)
{
  for (int j=0; j<=2; j++)
    pinMode(rgbArray[j], OUTPUT); 
}

void loop(void)
{
  /*if ((millis() - actualTime) > 250)
  {
    rgb_random();
    actualTime = millis();
  }*/
  
  rgb_rainbow(2);
}


void rgb_random(void)
{
  for (int j=0; j<=2; j++)
    analogWrite(rgbArray[j], random(256)); 
}

void rgb_rainbow(int speed)
{
  int b = 0;  
  for (int j=0; j<=2; j++)
  {
    for (int value=0; value<=256; value++)
    {
     analogWrite(rgbArray[j], value);     
     delay(speed);
    } 
  }
  
}



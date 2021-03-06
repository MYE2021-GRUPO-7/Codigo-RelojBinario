int ledPinsSec[] = {2, 3, 4, 5, 6, 7};
int ledPinsMin[] = {8, 9, 10, 11, 12, 13};
int ledPinsHr[] = {14, 15, 16, 17, 18, 19};
int secSize =sizeof(ledPinsSec) / sizeof(int);
  int minSize = sizeof(ledPinsMin) / sizeof(int);
  int hourSize = sizeof(ledPinsHr) / sizeof(int);
int seconds = 30;
int minutes = 30;
int hours = 15;
void setup() 
{
  Serial.begin(9600);
  //Obtiene el número de elementos de un arreglo
  Serial.println(sizeof(ledPinsSec));
  for(int i = 0; i< secSize;i++)
  {
    pinMode(ledPinsSec[i], OUTPUT);
  }
  for(int i = 0; i< minSize;i++)
  {
    pinMode(ledPinsMin[i], OUTPUT);
  }
  for(int i = 0; i< hourSize;i++)
  {
    pinMode(ledPinsHr[i], OUTPUT);
  }
}
void loop() 
{
    seconds++;
    if(seconds > 59)
    {
      seconds = 0;
      minutes++;
      if(minutes > 59)
      {
        minutes = 0;
        hours++;
        if(hours > 23)
        {
          hours = 0;
        }
      }
    }
    //Serial.println((char) seconds);
    Serial.print("Hours: ");
    Serial.print(hours);
    Serial.print(" Minutes: ");
    Serial.print(minutes);
    Serial.print(" Seconds: ");
    Serial.println(seconds);
    DisplaySeconds();
    DisplayMinutes();
    DisplayHours();
    delay(1000);
/*
    DisplaySeconds();
    DisplayMinutes();
    DisplayHours();*/
}
void DisplaySeconds()
{     
  for(int i = secSize - 1; i>= 0; i--)
  {
    int currentSecond = bitRead(seconds, i);
    digitalWrite(ledPinsSec[i], currentSecond); 
  }  
}
void DisplayMinutes()
{     
  for(int i = minSize - 1; i>= 0; i--)
  {
    int currentMinute = bitRead(minutes, i);
    digitalWrite(ledPinsMin[i], currentMinute); 
  }  
}
void DisplayHours()
{     
  for(int i = hourSize - 1; i>= 0; i--)
  {
    int currentHour = bitRead(hours, i);
    digitalWrite(ledPinsHr[i], currentHour); 
  }  
}

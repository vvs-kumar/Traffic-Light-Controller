int time1;
int time2;
int count=0;
int click01;
int R1=2;
int O1=3;
int G1=4;
int R2=5;
int O2=6;
int G2=7;
int R3=8;
int O3=9;
int G3=10;
int R4=11;
 int O4=12;
 int G4=13;
void setup() 
{
  //Lane 1
  pinMode(R1,OUTPUT);//R
  pinMode(O1,OUTPUT);//O
  pinMode(G1,OUTPUT);//G
  //Lane 2
  pinMode(R2,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(G2,OUTPUT);
  //Lane 3
  pinMode(R3,OUTPUT);
  pinMode(O3,OUTPUT);
  pinMode(G3,OUTPUT);
  //Lane 4
  pinMode(R4,OUTPUT);
  pinMode(O4,OUTPUT);
  pinMode(G4,OUTPUT);

  pinMode(A0,INPUT);
  Serial.begin(9600);
digitalWrite(R1,LOW);
digitalWrite(R2,LOW);
digitalWrite(R3,LOW);
digitalWrite(R4,LOW);
digitalWrite(O1,LOW);
digitalWrite(O2,LOW);
digitalWrite(O3,LOW);

digitalWrite(O4,LOW);
digitalWrite(G4,LOW);
digitalWrite(G3,LOW);
digitalWrite(G2,LOW);
digitalWrite(G1,LOW);
digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  delay(2000);
  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
}

void loop()
{
  
  click01=digitalRead(A1);
  if(click01==HIGH)
  {
    delay(100);
    if(click01==LOW)
    {
      count=count+1;
    }
    
  }
  switch(count)
  {
    case 1:
      Serial.println("Set the Time ");
      time2=analogRead(A0);
      time1=(time2*10);
      time1=5000;
      Serial.print("Time set for ");
      Serial.print(time1/1000);
      Serial.println("Seconds");
      
      delay(1000);
      lane1();
      lane2();
      lane3();
      lane4();
      delay(10);
     case 2:
      Serial.println("Slow_Orange_Blink");
      blinkO();
  }
  
  
  
}

void lane1()
{
  {digitalWrite(O4,HIGH);
  digitalWrite(O1,HIGH);
  }
  delay(3000);
  {
  digitalWrite(O4,LOW);
  digitalWrite(O1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R1,LOW);
  digitalWrite(G1,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  }
  delay(time1);
  digitalWrite(G1,LOW);
  Serial.println("Lane 01");
 }
 void lane2()
{
  
  
  digitalWrite(O1,HIGH);
  digitalWrite(O2,HIGH);
  delay(3000);
  digitalWrite(O1,LOW);
  digitalWrite(O2,LOW);
  digitalWrite(R1,HIGH);
  digitalWrite(R3,HIGH);
  
  digitalWrite(G2,HIGH);
  digitalWrite(R2,LOW);
  digitalWrite(R4,HIGH);
  Serial.println("Lane 02");
  delay(time1);
  digitalWrite(G2,LOW);
  
 }
 void lane3()
{
  digitalWrite(O2,HIGH);
  digitalWrite(O3,HIGH);
  delay(3000);
  digitalWrite(O2,LOW);
  digitalWrite(O3,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);
  digitalWrite(G3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R1,HIGH);
  Serial.println("Lane 03");
  delay(time1);
  digitalWrite(G3,LOW);
 }
 void lane4()
{
 digitalWrite(O3,HIGH);
  digitalWrite(O4,HIGH);
  delay(3000);
  digitalWrite(O3,LOW);
  digitalWrite(O4,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,LOW);
  digitalWrite(G4,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  Serial.println("Lane 04");
  delay(time1);
  digitalWrite(G4,LOW);
 }


 void blinkO()
 {
  digitalWrite(O3,HIGH);
  digitalWrite(O4,HIGH);
  digitalWrite(O2,HIGH);
  digitalWrite(O1,HIGH);
  delay(2000);
  digitalWrite(O3,LOW);
  digitalWrite(O4,LOW);
  digitalWrite(O2,LOW);
  digitalWrite(O1,LOW);
  delay(2000);
 }

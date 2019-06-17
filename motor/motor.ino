#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6d352150f478472d9726e76460969aa2";
SoftwareSerial SerialBLE(2, 3); // RX, TX

const int SagArkaMotor1 = 9;     // Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int SagArkaMotor2 = 8;     
const int SagOnMotor3 =  9;
const int SagOnMotor4 =  8;

const int a =  5;//a ve c 2
const int b =  6;//b ve d birleştirip 6  
const int c =  5;
const int d =  6;

const int BluetoothIleri =  7;
const int BluetoothSag =  13;
const int OtomatikMode =  4;

const int echo = 10;
const int trig = 11; 
long duration;
int distance;

void setup() 
{

 // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
  
pinMode(SagArkaMotor1, OUTPUT);  //Tüm pinlerden güç çıkışı olacağı için OUTPUT olarak ayarladık.
pinMode(SagArkaMotor2, OUTPUT);  
pinMode(SagOnMotor3, OUTPUT);
pinMode(SagOnMotor4, OUTPUT);

pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(BluetoothIleri,INPUT);
pinMode(BluetoothSag,INPUT);


pinMode(trig, OUTPUT); 
pinMode(echo, INPUT);

Dur();
Serial.begin(9600);
}
void Dur(){
  
  
  digitalWrite(SagArkaMotor1, LOW);
      digitalWrite(SagArkaMotor2,  LOW);  
      // motor 2
      digitalWrite(SagOnMotor3, LOW);
      digitalWrite(SagOnMotor4,  LOW);
      //motor 3
      digitalWrite(a, LOW);
      digitalWrite(b,  LOW);
      //motor 4
      digitalWrite(c, LOW);
      digitalWrite(d,  LOW);
  }
void IleriGit(){
// motor 1
      digitalWrite(SagArkaMotor1, HIGH);
      digitalWrite(SagArkaMotor2,  LOW);  
      // motor 2
      digitalWrite(SagOnMotor3, HIGH);
      digitalWrite(SagOnMotor4,  LOW);
      //motor 3
      digitalWrite(a, LOW);
      digitalWrite(b,  HIGH);
      //motor 4
      digitalWrite(c, LOW);
      digitalWrite(d,  HIGH);

  }
  void GeriGit(){
    // motor 1
      digitalWrite(SagArkaMotor1, HIGH);
      digitalWrite(SagArkaMotor2,  LOW);  
      // motor 2
      digitalWrite(SagOnMotor3, HIGH);
      digitalWrite(SagOnMotor4,  LOW);
      //motor 3
      digitalWrite(a, LOW);
      digitalWrite(b,  HIGH);
      //motor 4
      digitalWrite(c, LOW);
      digitalWrite(d,  HIGH);
  }
  void SagGit(){
    // motor 1
      digitalWrite(SagArkaMotor1, LOW);
      digitalWrite(SagArkaMotor2,  HIGH);  
      // motor 2
      digitalWrite(SagOnMotor3, LOW);
      digitalWrite(SagOnMotor4,  HIGH);
      //motor 3
      digitalWrite(a, LOW);
      digitalWrite(b,  HIGH);
      //motor 4
      digitalWrite(c, LOW);
      digitalWrite(d,  HIGH);
  }
  void SolGit(){
    // motor 1
      digitalWrite(SagArkaMotor1, HIGH);
      digitalWrite(SagArkaMotor2,  LOW);  
      // motor 2
      digitalWrite(SagOnMotor3, HIGH);
      digitalWrite(SagOnMotor4,  LOW);
      //motor 3
      digitalWrite(a, HIGH);
      digitalWrite(b,  LOW);
      //motor 4
      digitalWrite(c, HIGH);
      digitalWrite(d,  LOW);
  }
void loop() 
{
  Dur();
  Blynk.run();
  if(digitalRead(OtomatikMode)== true){
    IleriGit();
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance= duration*0.034/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    if(distance <= 35){
      Dur();
      delay(200);
      SagGit();
      delay(200);
      }
    }
      else if(digitalRead(BluetoothIleri) == true){IleriGit();}
      else if(digitalRead(BluetoothSag) == true){SagGit();}
    }

const int SagArkaMotor1 = 9;     // Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int SagArkaMotor2 = 8;     
const int SagOnMotor3 =  9;
const int SagOnMotor4 =  8;

const int a =  5;//a ve c 2
const int b =  6;//b ve d birleştirip 6  
const int c =  5;
const int d =  6;

const int BluetoothIleri =  4;
const int BluetoothGeri =  12;
const int BluetoothSag =  13;
const int BluetoothSol =  7;

const int OtomatikMode =  3;

const int echo = 10;
const int trig = 11; 
long duration;
int distance;

void setup() 
{
pinMode(SagArkaMotor1, OUTPUT);  //Tüm pinlerden güç çıkışı olacağı için OUTPUT olarak ayarladık.
pinMode(SagArkaMotor2, OUTPUT);  
pinMode(SagOnMotor3, OUTPUT);
pinMode(SagOnMotor4, OUTPUT);

pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(BluetoothIleri,INPUT);
pinMode(BluetoothGeri,INPUT);
pinMode(BluetoothSag,INPUT);
pinMode(BluetoothSol,INPUT);
pinMode(OtomatikMode,INPUT);

pinMode(trig, OUTPUT); 
pinMode(echo, INPUT);
Serial.begin(9600);
}
void Dur(){
  digitalWrite(SagArkaMotor1, HIGH);
      digitalWrite(SagArkaMotor2,  HIGH);  
      // motor 2
      digitalWrite(SagOnMotor3, HIGH);
      digitalWrite(SagOnMotor4,  HIGH);
      //motor 3
      digitalWrite(a, HIGH);
      digitalWrite(b,  HIGH);
      //motor 4
      digitalWrite(c, HIGH);
      digitalWrite(d,  HIGH);
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
      digitalWrite(SagArkaMotor1, LOW);
      digitalWrite(SagArkaMotor2,  HIGH);  
      // motor 2
      digitalWrite(SagOnMotor3, LOW);
      digitalWrite(SagOnMotor4,  HIGH);
      //motor 3
      digitalWrite(a, HIGH);
      digitalWrite(b,  LOW);
      //motor 4
      digitalWrite(c, HIGH);
      digitalWrite(d,  LOW);
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
  
  if(digitalRead(OtomatikMode)== true){
    IleriGit();
      //otomatik mod çalışır.
      // Clears the trigPin
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echo, HIGH);
      // Calculating the distance
      distance= duration*0.034/2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
      if(distance <= 20){
          Dur();
          delay(200);
          SagGit();
          delay(200);
          
        } 
      
    }
  else{
    if(digitalRead(BluetoothIleri) == true){
      IleriGit();
    }
     else if(digitalRead(BluetoothGeri) == true){
      GeriGit();
    }
    else if(digitalRead(BluetoothSag) == true){
      SagGit();
    }
    else if(digitalRead(BluetoothSol) == true){
      SolGit();
    }else{
       Dur();
    }
    }
  

}

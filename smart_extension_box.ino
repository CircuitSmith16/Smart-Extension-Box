int Relay = 2;
int CurrentSensor = A1;
int Buzzer = 4;
int PushButton = 5;

float ZeroVal;
float CurrentDraw;
float Power;
float SetLimit = 70;
float PercentLimit;

int Relayflag = 1; //default ON 1

void setup() {
   Serial.begin(9600);
   pinMode(Relay,OUTPUT);
   pinMode(PushButton,INPUT_PULLUP);
   pinMode(Buzzer,OUTPUT);
  
  float sum = 0;
  Serial.println("Setting up the Current Sensor, Do not Plug Loads");
  Serial.print("Setting Up");
  for(int i = 0; i<200; i++){
    sum += analogRead(CurrentSensor);
    Serial.print(".");
    delay(10);
  }
  float avg = sum/200;
  ZeroVal = avg * (5.0/1024.0);

  Serial.println("Extension cord ready for use!");
  digitalWrite(Relay,LOW);
  Relayflag = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  float AnalogCurrent;
  float sumSq = 0;
  for(int i = 0;i<200;i++){
    float adc = analogRead(CurrentSensor);
    float voltage = adc * (5.0/1024.0);
    float instCurrent = (voltage - ZeroVal)/0.185;
    sumSq += instCurrent * instCurrent;
    
  }
  CurrentDraw = sqrt(sumSq/200);
  Power = 230 * CurrentDraw;
  
  PercentLimit = (Power/SetLimit)*100;

  if(Relayflag == 1){
    Serial.print("Current Drawn : ");
   Serial.println(CurrentDraw);
   Serial.print("Percentage of Limit used : ");
   Serial.print(PercentLimit);
   Serial.println("%");
   Serial.println(digitalRead(Relay));
   Serial.println("---------------");
  }

  if(Relayflag == 1 && Power>SetLimit){
     Serial.println("Relay tripped! Overload detected!");
     Serial.println("Remove high loads and press the reset button!");
     digitalWrite(Relay, HIGH);
     Relayflag = 0;
    for(int i = 0; i<6; i++){
      digitalWrite(Buzzer,HIGH);
      delay(500);
      digitalWrite(Buzzer,LOW);
      delay(500);
    }
    
  }

  if(digitalRead(PushButton) == 0 && Relayflag == 0){

    digitalWrite(Buzzer,HIGH);
    delay(500);
    digitalWrite(Buzzer,LOW);
    digitalWrite(Relay,LOW);
    Relayflag = 1;
  }

delay(1000); 

}

/*//////////
 * program lampu otomtis kamar mandi
 * 
 *//////////

 const int sensor1 = 3;
 const int sensor2 = 4;
 const int sensor3 = 5;
 
 const byte relay1 = 7;
 const byte relay2 = 10;
 
 //const byte tombol_manual_1 = 2;
 const byte tombol_manual_2 = 9;
 const byte sensor_tekan = 6;
 
 byte indikator1 = 8;
 byte indikator2 = 12;
 byte indikator3 = 11 ;


void setup() {
    Serial.begin(9600);
   digitalWrite(relay1,HIGH);
   digitalWrite(relay2,HIGH);
    
    pinMode(sensor1,INPUT_PULLUP);
    pinMode(sensor2,INPUT_PULLUP);
    pinMode(sensor3,INPUT_PULLUP);
    
    pinMode(relay1,OUTPUT);
    pinMode(relay2,OUTPUT);
    
    pinMode(sensor_tekan,INPUT_PULLUP);
    //pinMode(tombol_manual_1,OUTPUT);
    pinMode(tombol_manual_2,OUTPUT);
    
    pinMode(indikator1,OUTPUT);
    pinMode(indikator2,OUTPUT);
    pinMode(indikator3,OUTPUT);

    attachInterrupt(digitalPinToInterrupt(2),modeTombol,LOW);
}

void modeTombol(){
delay(50);
digitalWrite(relay1,LOW);
//Serial.println("interrup on");  
}

void loop() {
   logika();
   //saklar();
   //Serial.println("interrup off");
   
   //tampil();
 //delay(500);
}

void logika(){

  
  int nilaiSensor1 = digitalRead(sensor1);
   int nilaiSensor2 = digitalRead(sensor2);
   int nilaiSensor3 = digitalRead(sensor3);
   

   if(nilaiSensor1==HIGH && nilaiSensor2==LOW && nilaiSensor3==LOW){
       delay(50);
       digitalWrite(relay1,HIGH);  //MATI
       digitalWrite(indikator1,LOW);
   }
    //
   else if(nilaiSensor1==LOW && nilaiSensor2==HIGH && nilaiSensor3==LOW){
       delay(50);
       digitalWrite(relay1,HIGH);  //MATI
       digitalWrite(indikator1,LOW);
   }
    //
    else if(nilaiSensor1==LOW && nilaiSensor2==LOW && nilaiSensor3==HIGH){
       delay(50);
       digitalWrite(relay1,HIGH);  //MATI
       digitalWrite(indikator1,LOW);
    }

     else if(nilaiSensor1==LOW && nilaiSensor2==LOW && nilaiSensor3==LOW){
       delay(50);
       digitalWrite(relay1,HIGH);  //MATI
       digitalWrite(indikator1,LOW);
    }
    
   /////////////////////////////  NYALA
   else if(nilaiSensor1==HIGH && nilaiSensor2==HIGH && nilaiSensor3==LOW){
       delay(50);
       digitalWrite(relay1,LOW); //NYALA
       digitalWrite(indikator1,HIGH);
   }
    //
   else if(nilaiSensor1==LOW && nilaiSensor2==HIGH && nilaiSensor3==HIGH){
       delay(50);
       digitalWrite(relay1,LOW); //NYALA
       digitalWrite(indikator1,HIGH);
   }
    //
    else if(nilaiSensor1==HIGH && nilaiSensor2==LOW && nilaiSensor3==HIGH){
       delay(50);
       digitalWrite(relay1,LOW); //NYLA
       digitalWrite(indikator1,HIGH);
   }
//
    else if(nilaiSensor1==LOW && nilaiSensor2==LOW && nilaiSensor3==LOW){
       delay(50);
       digitalWrite(relay1,HIGH); //MATI
       digitalWrite(indikator1,LOW);
   }
//
   else if(nilaiSensor1==HIGH && nilaiSensor2==HIGH && nilaiSensor3==HIGH){
       delay(50);
       digitalWrite(relay1,LOW); //NYALA
       digitalWrite(indikator1,HIGH);
   }

  
}


void saklar(){
 
 // byte nilaiSaklar1 = digitalRead(tombol_manual_1);
  byte nilaiSaklar2 = digitalRead(tombol_manual_2);

  //fungsi untuk saklar manual lampu kamar mandi
//  if(nilaiSaklar1 == HIGH){
//   
//    digitalWrite(relay1,LOW);
//    digitalWrite(indikator2,HIGH);
//    
//  }
//  else if(nilaiSaklar1 == LOW){
//    digitalWrite(relay1,HIGH);
//    digitalWrite(indikator2,LOW);}

  //fungsi untuk saklar manual lampu dapur
  if(nilaiSaklar2 == HIGH ){
    //nyalakan lampu
    digitalWrite(relay2,LOW);
    digitalWrite(indikator3,HIGH);
  }
  else{
    //matikan lampu
    digitalWrite(relay2,HIGH);
    digitalWrite(indikator3,LOW);
  }

  
}



void tampil(){
   int nilaiSensor1 = digitalRead(sensor1);
   int nilaiSensor2 = digitalRead(sensor2);
   int nilaiSensor3 = digitalRead(sensor3);

   if(nilaiSensor1==HIGH){
    Serial.println("sensor1 high");
   }
   if(nilaiSensor2==HIGH){
    Serial.println("sensor2 high");
   }
   if(nilaiSensor3==HIGH){
    Serial.println("sensor3 high");
   }
   if(nilaiSensor1==LOW){
    Serial.println("sensor1 low");
   }
   if(nilaiSensor2==LOW){
    Serial.println("sensor2 low");
   }
   if(nilaiSensor3==LOW){
    Serial.println("sensor3 low");
   }

}

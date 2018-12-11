#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

#define motorEsquerdoFrente 2;
#define motorDireitoFrente 4;
#define motorEsquerdoReverso 3;
#define motorDireitoReverso 5;

int mensagemRecebida[1] = {000};

RF24 radio(9, 10);

const uint64_t pipe = 0xE6E6E6E6E6E6;

void setup() {

  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  radio.setDataRate(RF24_2MBPS);
  radio.setPALevel(RF24_PA_MAX);

  pinMode(motorEsquerdoFrente, OUTPUT);
  pinMode(motorDireitoFrente, OUTPUT);
  pinMode(motorEsquerdoReverso, OUTPUT);
  pinMode(motorEsquerdoReverso, OUTPUT);

  digitalWrite(motorEsquerdoFrente, HIGH);
  digitalWrite(motorDireitoFrente, HIGH);
  digitalWrite(motorEsquerdoReverso, HIGH);
  digitalWrite(motorDireitoReverso, HIGH);
  
}

void loop() {

  while(radio.available()){

    radio.read(mensagemRecebida, 1);

    if(mensagemRecebida[0] == 111){

      digitalWrite(motorEsquerdoFrente, LOW);
      digitalWrite(motorDireitoFrente, LOW);
      digitalWrite(motorEsquerdoReverso, HIGH);
      digitalWrite(motorDireitoReverso, HIGH);
      
    }

    if(mensagemRecebida[0] == 222){

      digitalWrite(motorEsquerdoFrente, HIGH);
      digitalWrite(motorDireitoFrente, HIGH);
      digitalWrite(motorEsquerdoReverso, LOW);
      digitalWrite(motorDireitoReverso, LOW);
      
    }

     if(mensagemRecebida[0] == 100){

      digitalWrite(motorEsquerdoFrente, LOW);
      digitalWrite(motorDireitoFrente, HIGH);
      digitalWrite(motorEsquerdoReverso, HIGH);
      digitalWrite(motorDireitoReverso, LOW);
      
    }

     if(mensagemRecebida[0] == 110){

      digitalWrite(motorEsquerdoFrente, HIGH);
      digitalWrite(motorDireitoFrente, LOW);
      digitalWrite(motorEsquerdoReverso, LOW);
      digitalWrite(motorDireitoReverso, HIGH);
      
    }

     if(mensagemRecebida[0] == 000){

      digitalWrite(motorEsquerdoFrente, HIGH);
      digitalWrite(motorDireitoFrente, HIGH);
      digitalWrite(motorEsquerdoReverso, HIGH);
      digitalWrite(motorDireitoReverso, HIGH);
      
    }
    
  }
  
}

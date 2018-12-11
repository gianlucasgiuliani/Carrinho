#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

int mensagemEnviada[1] = {000}; //Guarda o valor da mensagem a ser enviada

RF24 radio(9, 10); //Pinos SPI do NRF

const uint64_t pipe = 0xE6E6E6E6E6E6; //Pipe para comunicação entre os dois

//Botões que controlam os motores
int frente = 2;
int reverso = 3;
int direita = 4;
int esquerda = 5;

void setup() {
  radio.begin(); //Inicia o NRF
  radio.openWritingPipe(pipe); //Abre o pipe para escrever
  radio.setDataRate(RF24_2MBPS);

  //Define os botões como INPUT
  pinMode(frente, INPUT);
  pinMode(reverso, INPUT);

}

void loop() {
  int frenteVal, reversoVal, direitaVal, esquerdoVal;
  //Atribui valores aos botões
  if(digitalRead(frente) == HIGH){

    frenteVal = 1;
        
  }else{

    frenteVal = 0;
    
  }

  if(digitalRead(reverso) == HIGH){

    reversoVal = 1;
        
  }else{

    reversoVal = 0;
    
  }

  if(digitalRead(direita) == HIGH){

    direitaVal = 1;
        
  }else{

    direitaVal = 0;
    
  }

  if(digitalRead(esquerda) == HIGH){

    esquerdoVal = 1;
        
  }else{

    esquerdoVal = 0;
    
  }

  //Manda sinal para o carrinho ir para frente

  if(frenteVal == 1 && reversoVal == 0 && direitaVal == 0 && esquerdoVal == 0){

    mensagemEnviada[0] = 111;
    radio.writeFast(mensagemEnviada, 1);
     
  }
  
  //Manda sinal para o carrinho ir para trás

  if(frenteVal == 0 && reversoVal == 1 && direitaVal == 0 && esquerdoVal == 0){

    mensagemEnviada[0] = 222;
    radio.writeFast(mensagemEnviada, 1);
     
  }

  //Manda sinal para o carrinho ir para direita

  if(frenteVal == 0 && reversoVal == 0 && direitaVal == 1 && esquerdoVal == 0){

    mensagemEnviada[0] = 100;
    radio.writeFast(mensagemEnviada, 1);
     
  }

  //Manda sinal para o carrinho ir para esquerda

  if(frenteVal == 0 && reversoVal == 0 && direitaVal == 0 && esquerdoVal == 1){

    mensagemEnviada[0] = 110;
    radio.writeFast(mensagemEnviada, 1);
     
  }

  //Nenhum botão pressionado, manda o valor 0

  if(frenteVal == 0 && reversoVal == 0 && direitaVal == 0 && esquerdoVal == 0){

    mensagemEnviada[0] = 000;
    radio.writeFast(mensagemEnviada, 1);
     
  }

}

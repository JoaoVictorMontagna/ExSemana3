//Define os Leds 

int ledVermelho=2;
int ledAmarelo=5;
int ledVerde=6;
int ledAzul=11;


//Define os Botoes 
int botaoV=3; 
int botaoA=4; 
int botaoVe=8; 
int botaoAz=12;
int botaoReset=10;

int nivelBotaoV;
int nivelBotaoA;
int nivelBotaoVe;
int nivelBotaoAz;
int nivelBotaoReset;


int Acerto[4]={1,2,3,4};

int a=Acerto[0];
int b=Acerto[1];
int c=Acerto[2];
int d=Acerto[3];

int resp[4];
int posicao=0;
int nmr=0;

void definirPins(){
    Serial.begin(9600); //
 	  pinMode(botaoV, OUTPUT); //Define o botao de saida
    pinMode(botaoA, OUTPUT); //Define o botao de saida
   	pinMode(botaoVe, OUTPUT); //Define o botao de saida
  	pinMode(botaoVe, OUTPUT); //Define o botao de saida
     pinMode(botaoReset, OUTPUT); //Define o botao de saida

    pinMode(LED_BUILTIN,OUTPUT);
	  pinMode(ledVermelho, OUTPUT); //Define o Led de saida
  	pinMode(ledAmarelo, OUTPUT); //Define o Led de saida
  	pinMode(ledAzul, OUTPUT); //Define o Led de saida
    pinMode(ledVerde, OUTPUT); //Define o Led de saida
}

void resetarCores(){



 
  
  digitalWrite(ledVermelho,HIGH);
  delay(500);
  digitalWrite(ledVermelho,LOW);
  
  digitalWrite(ledAmarelo,HIGH);
  delay(500);
  digitalWrite(ledAmarelo,LOW);
  
  digitalWrite(ledVerde,HIGH);
  delay(500);
  digitalWrite(ledVerde,LOW);

  digitalWrite(ledAzul,HIGH);
  delay(500);
  digitalWrite(ledAzul,LOW);
  delay(1000);
     for (int i = 0; i < 4; i++) {
    if (Acerto[i]==1){
        digitalWrite(ledVermelho,HIGH);
        delay(500);
        digitalWrite(ledVermelho,LOW);
    }else if(Acerto[i]==2){
        digitalWrite(ledAmarelo,HIGH);
        delay(500);
        digitalWrite(ledAmarelo,LOW);
    }else if(Acerto[i]==3){
        digitalWrite(ledVerde,HIGH);
        delay(500);
        digitalWrite(ledVerde,LOW);

    }else if(Acerto[i]==4){
        digitalWrite(ledAzul,HIGH);
        delay(500);
        digitalWrite(ledAzul,LOW);


    }
  }
}

void resetar(){
   resp[0]=0;
    resp[1]=0;
    resp[2]=0;
    resp[3]=0;
    posicao=0;
}


void simonGame(){
  	nivelBotaoV=digitalRead(botaoV);
    nivelBotaoA=digitalRead(botaoA);
    nivelBotaoVe=digitalRead(botaoVe);
     nivelBotaoAz=digitalRead(botaoAz);
    nivelBotaoReset=digitalRead(botaoReset);
  
  if (nivelBotaoV==1){
    nmr=1;
  	digitalWrite(ledVermelho,HIGH);
    delay(200);
    digitalWrite(ledVermelho,LOW);
    resp[posicao]=nmr;
    posicao=posicao+1;
  }
  
    if (nivelBotaoA==1){
      nmr=2;
  	  digitalWrite(ledAmarelo,HIGH);
      delay(200);
      digitalWrite(ledAmarelo,LOW);
      resp[posicao]=nmr;
      posicao=posicao+1;
   }

  
    if (nivelBotaoVe==1){
      nmr=3;
  	  digitalWrite(ledVerde,HIGH);
      delay(200);
      digitalWrite(ledVerde,LOW);
     resp[posicao]=nmr;
      posicao=posicao+1;

   }

     
    if (nivelBotaoAz==1){
      nmr=4;
  	  digitalWrite(ledAzul,HIGH);
      delay(200);
      digitalWrite(ledAzul,LOW);
     resp[posicao]=nmr;
      posicao=posicao+1;

   }
  	
  if (resp[0]==a && resp[1]==b && resp[2]==c && resp[3]==d){
    Serial.println("Acertou");
 	  resetar();

   
  }else if(resp[0]!=0 && resp[1]!=0 && resp[2]!=0 && resp[3]!=0) {

    Serial.println("Nao acertou");
 	  resetar();

  }
  
   if (nivelBotaoReset==1){
      Serial.println("Okk, vamos recomeçar !");
      resetar();
      resetarCores();


   }
}


void setup(){
  
  definirPins();
  resetarCores();

 
}


void loop(){

  simonGame();

  delay(100);
  
}
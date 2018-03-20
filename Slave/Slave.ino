//Programa : Integração do Aplicativo "Bluetooth Spp Pro" com o Modulo bluetooth HC-06
//Autor : Jackson Terceiro
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define GREEN 3
#define YELLOW 4
#define RED 5

char buf;

void desligaLeds(){
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, HIGH);
}

 
void setup()
{
  //Define os pinos dos leds como saida
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(38400);

  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, HIGH);

  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop(){


  
  //Limpa a tela
  //lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("SERIAL BLUETOOTH");
  lcd.setCursor(0, 1);
  lcd.print("VALUE:");

  while(Serial.available() > 0){
    
    buf = Serial.read();

    lcd.setCursor(7, 1);
    lcd.print(buf);

    if (buf == 'G'){
      desligaLeds();
      digitalWrite(GREEN, LOW);
      Serial.println("LED Verde ligado !");
      //delay(1000);
      //digitalWrite(GREEN, HIGH);
    }
    
    else if (buf == 'Y'){
      desligaLeds();
      digitalWrite(YELLOW, LOW);
      Serial.println("LED Amarelo ligado !");
      //delay(1000);
      //digitalWrite(YELLOW, HIGH);
    }
    
   else if (buf == 'R'){
      desligaLeds();
      digitalWrite(RED, LOW);
      Serial.println("LED RED ligado !");
     // delay(1000);
     //digitalWrite(RED, HIGH);
    }

    else if (buf == 'N'){
      desligaLeds();
    }

 

  }
  //desligaLeds();
}





#include <SoftwareSerial.h>
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

//------------ DECLARAÇÃO LCD ------------
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//------------ DECLARAÇÃO ULTRA ------------
#define Frente_Trig 8
#define Frente_Echo 9
Ultrasonic Frente(Frente_Trig, Frente_Echo);
float Frente_val = 0;
long microsecF = 0;

//------------ DECLARAÇÃO BLUETOOTH ------------
SoftwareSerial BTSerial(10, 11);

int state = 0;
int buttonState = 1;


void setup() {
  BTSerial.begin(38400);

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
  //delay(5000);
  
  if(BTSerial.available() > 0){ 
     // Checks whether data is comming from the serial port
      state = BTSerial.read(); // Reads the data from the serial port
  }


  microsecF = Frente.timing(); /* Leitura do sensor FRENTE */
  Frente_val = Frente.convert(microsecF, Ultrasonic::CM); /* Leitura do sensor FRENTE */

  lcd.setCursor(11,1);
  lcd.print(Frente_val, 4);
  delay(100);
  
  if(Frente_val <= 30){
    lcd.setCursor(7, 1);
    lcd.print("R");
    BTSerial.write("R");
  }
  
  else if(Frente_val <= 50){
    lcd.setCursor(7, 1);
    lcd.print("Y");
    BTSerial.write("Y");
  }
  
  else if(Frente_val <= 80){
    lcd.setCursor(7, 1);
    lcd.print("G");
    BTSerial.write("G");
  }

  else{
    lcd.setCursor(7, 1);
    lcd.print("N");
    BTSerial.write("N");
  }
  
  
}

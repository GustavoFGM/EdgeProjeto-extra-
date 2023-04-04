
#include <LiquidCrystal.h>

int seconds = 0;
int fotoresistorValue = 0; // Variável para armazenar o valor lido do fotoresistor

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(A3, OUTPUT);// led verde
  pinMode(A2, OUTPUT);// led amarelo
  pinMode(A1, OUTPUT);// led vermelho
  pinMode(A4, OUTPUT);// PIezo
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  pinMode(A0, INPUT); // Definir o pino A0 como entrada
  lcd_1.print("Valor Fotorresistor:");// Print a message to the LCD.
}

void loop()
{
  fotoresistorValue = analogRead(A0); // Ler o valor analógico do pino A0
  lcd_1.setCursor(0, 1); // Definir o cursor na linha 2, coluna 1
  lcd_1.print(fotoresistorValue); // Exibir o valor do fotoresistor no display
  delay(1000); // Esperar por 1 segundo
  seconds += 1;
  {
  if (fotoresistorValue < 100){ //definindo as saidas do led e do piezo
    digitalWrite(A3, 1);
    digitalWrite(A2, 0);
    digitalWrite(A1, 0);
    digitalWrite(A4, 0);
  }
     
  if (fotoresistorValue > 100 && fotoresistorValue < 130){
    digitalWrite(A3, 0);
    digitalWrite(A2, 1);
    digitalWrite(A1, 0);
    digitalWrite(A4, 0);
 }
     if (fotoresistorValue > 130){
    digitalWrite(A3, 0);
    digitalWrite(A2, 0);
    digitalWrite(A1, 1);
    digitalWrite(A4, 1);
  }
}
}
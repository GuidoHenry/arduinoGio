
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial bluetooth(10,11); // RX, TX
LiquidCrystal_I2C lcd(0x27,20,4);

String str ;
bool quieroMostrarTexto=false;
bool desconectado=true;

void setup()
{
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("Goodnight moon!");

  bluetooth.begin(9600);
  bluetooth.println("Hello, world?");
  
  lcd.init();
  lcd.backlight();
}
      
void loop() // run over and over
{
  if(desconectado==true){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Bluetooth");
    lcd.setCursor(3,2);
    lcd.print("Desconectado!");
    delay(800);
    }
  if (bluetooth.available())
  {
    str = bluetooth.readString();
    quieroMostrarTexto = true;
    if(str=="Desconectar"){desconectado=true; quieroMostrarTexto=false;}
    if(str=="Conectar"){desconectado=false;quieroMostrarTexto=false;}
    if(str.length()<21 && quieroMostrarTexto==true)
        {
          lcd.clear();
          lcd.print(str);
        }
    if(str.length()>20 && str.length()<41 && quieroMostrarTexto==true)
        {
          lcd.clear();
          String primer_renglon = str.substring(0,20);
          String segundo_renglon = str.substring(20,str.length());
          lcd.setCursor(0,0);
          lcd.print(primer_renglon);
          lcd.setCursor(0,1);
          lcd.print(segundo_renglon);
        }
    if(str.length()>40 && str.length()<61 && quieroMostrarTexto==true)
        {
          lcd.clear();
          String primer_renglon = str.substring(0,20);
          String segundo_renglon = str.substring(20,40);
          String tercer_renglon = str.substring(40,str.length());
          lcd.setCursor(0,0);
          lcd.print(primer_renglon);
          lcd.setCursor(0,1);
          lcd.print(segundo_renglon);
          lcd.setCursor(0,2);
          lcd.print(tercer_renglon);
        }
    if(str.length()>60 && str.length()<81 && quieroMostrarTexto==true)
        {
          lcd.clear();
          String primer_renglon = str.substring(0,20);
          String segundo_renglon = str.substring(20,40);
          String tercer_renglon = str.substring(40,60);
          String cuarto_renglon = str.substring(60,str.length());
          lcd.setCursor(0,0);
          lcd.print(primer_renglon);
          lcd.setCursor(0,1);
          lcd.print(segundo_renglon);
          lcd.setCursor(0,2);
          lcd.print(tercer_renglon);
          lcd.setCursor(0,3);
          lcd.print(cuarto_renglon);
        }
    if(str.length()>80)
      {
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("El texto ingresado");
        lcd.setCursor(4,2);
        lcd.print("es muy largo");
      }
  }
    if(quieroMostrarTexto==false && desconectado==false)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Esperando texto");
      delay(700);
      lcd.setCursor(15,0);
      lcd.print(".");
      delay(700);
      lcd.setCursor(16,0);
      lcd.print(".");
      delay(700);
      lcd.setCursor(17,0);
      lcd.print(".");
      delay(700);
      lcd.clear();
    }
    
}

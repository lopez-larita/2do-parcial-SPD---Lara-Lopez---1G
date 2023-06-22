// Lara Belen Lopez - 1G

#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Servo.h>

#define codigo_on 0xFF00BF00
#define codigo_stop 0xFD02BF00

#define PINMOT 9

Servo servomotor;

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

int receptor = 11;
int led1= 13; 
int led2= 12;

int temperaturaLeida = 0;
float temperatura = 0;

void calcularEstacionDelAnio();
void encenderApagarSistema();
void encenderAlarmaIncendio();


void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(receptor, DISABLE_LED_FEEDBACK);//inicia la recepcion
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  servomotor.attach(PINMOT);
  
  lcd.begin(16, 2);  //(columna, fila)
}

void loop()
{
  //Leer temperatura
  temperaturaLeida = analogRead(A0);
  temperatura = map(temperaturaLeida, 20, 358, -40, 125);
  
  //Recibir senial IR
  if (IrReceiver.decode()){
    //muestra el vaor HEX de la señal recibida
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
	
    //espera la proxima señal
    IrReceiver.resume();
  }
  
   
  encenderApagarSistema(); 
}

  
void calcularEstacionDelAnio(int temperatura){
  if (temperatura < 10){
    lcd.clear();
    lcd.print("Invierno:");
    lcd.print(temperatura);
  	lcd.print("°C");
  } else if (temperatura < 20){
    lcd.clear();
    lcd.print("Otonio:");
    lcd.print(temperatura);
  	lcd.print("°C");
  } else if (temperatura < 27){
    lcd.clear();
    lcd.print("Primavera:");
    lcd.print(temperatura);
  	lcd.print("°C");
  } else if (temperatura < 60){
    lcd.clear();
    lcd.print("Verano:");
    lcd.print(temperatura);
  	lcd.print("°C");
  }
 
  delay(1000);
}

void encenderApagarSistema(){
  
  if (IrReceiver.decodedIRData.decodedRawData == codigo_on){
    
    digitalWrite(led2, HIGH);
    
    calcularEstacionDelAnio(temperatura);
    
    encenderAlarmaIncendio(temperatura);
    
  }else if (IrReceiver.decodedIRData.decodedRawData == codigo_stop){
    
    lcd.clear();
    digitalWrite(led2, LOW);
    
  }
}

void encenderAlarmaIncendio (int temperatura){
  if (temperatura > 60){
    lcd.clear();
    lcd.print("INCENDIO!!");
    lcd.print(temperatura);
  	lcd.print("°C");
   
    servomotor.write(0);
  	digitalWrite (led1,HIGH);
  	delay(1500);
  	servomotor.write(180);
    digitalWrite (led1,LOW);
 	delay(1500);
    
  }
}
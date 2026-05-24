// 20 vagas no estacionamento
#include <Servo.h>
#include <LiquidCrystal.h>
// MEUS PINOS: RS = 12  E = 11  DB4 = 10  DB5 = 9  DB6 = 7  DB7 = 8  
// PINOS VÍDEO: RS = 12 E = 11 DB4 = 5  DB5 = 4  DB6 = 3  DB7 = 2
#define capacidadeTotal 20

// DEFINIR PINOS LED
LiquidCrystal lcd(12, 11, 10, 9, 7, 8);

// PIN LEDs
int LEDvermelho = 5;
int LEDverde = 6;

// PIN Botões
int botao1 = 2; // botão para entrada do veículo
int botao2 = 3; // botão para saída do veículo

// PIN Servo
Servo meuServo;

// Estado Botões
bool estadobotao1 = false;
bool estadoAnteriorBotao1 = false;
bool estadobotao2 = false;
bool estadoAnteriorBotao2 = false;

int vagasDisponiveis = capacidadeTotal;
int vagasOcupadas = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("SISTEMA INICIADO | Capacidade: 20 vagas");
  
  // leds
  pinMode(LEDvermelho, OUTPUT);
  pinMode(LEDverde, OUTPUT);
  digitalWrite(LEDvermelho, HIGH);
  
  // botões
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  
  // Servo
  meuServo.attach(4);
  
  // LED LCD
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FECHADO");
  lcd.setCursor(0,1);
  lcd.print("Vagas: ");
  lcd.print(vagasDisponiveis);
  //
}

void abrirCatraca(){
  vagasDisponiveis--;
  vagasOcupadas++;
  
  digitalWrite(LEDverde, HIGH);
  digitalWrite(LEDvermelho, LOW);
  
  meuServo.write(0); 
  
  //lcd
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ABERTO :D");
  
  lcd.setCursor(0,1);
  lcd.print("Vagas: ");
  lcd.print(vagasDisponiveis);
  //lcd
  
  Serial.print("'ENTRADA registrada | Vagas ocupadas: ");
  Serial.print(vagasOcupadas);
  Serial.print("| Vagas disponíveis: ");
  Serial.println(vagasDisponiveis);
}
       
void fecharCatraca(){
  digitalWrite(LEDverde, LOW);
  digitalWrite(LEDvermelho,HIGH);
  
  meuServo.write(90); 
  
  //lcd
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("FECHADO");
  lcd.setCursor(0,1);
  lcd.print("Vagas: ");
  lcd.print(vagasDisponiveis);
  //
  
  Serial.println("'CANCELA FECHADA'");
} 
       
void piscarLotado() {
  for(int i=0; i<3; i++){
    digitalWrite(LEDvermelho, LOW);
    delay(100);
    digitalWrite(LEDvermelho, HIGH);
    delay(100);
  }
}
  
  
void loop(){
  
  estadobotao1 = digitalRead(botao1);
  estadobotao2 = digitalRead(botao2);
  
  if(vagasDisponiveis == 0){
    piscarLotado();
  }
    
  if(estadobotao1 == HIGH && estadoAnteriorBotao1 == LOW && digitalRead(LEDverde) == LOW){
    delay(50);
    
    if(vagasDisponiveis >0){
      abrirCatraca();
      
      if(vagasDisponiveis == 0){
        digitalWrite(LEDverde, LOW);
        digitalWrite(LEDvermelho, HIGH);
        Serial.println("ESTACIONAMENTO LOTADO!");
      }
    } else{
     Serial.println("'ESTACIONAMENTO LOTADO — entrada bloqueada | Vagas:0/20'");
     piscarLotado();
    }
  }
  if(estadobotao2 == HIGH && estadoAnteriorBotao2 == LOW){
    delay(50);
    
    if(vagasOcupadas > 0){
      fecharCatraca();
    }
  }
  
  estadoAnteriorBotao1 = estadobotao1;
  estadoAnteriorBotao2 = estadobotao2;
}

  

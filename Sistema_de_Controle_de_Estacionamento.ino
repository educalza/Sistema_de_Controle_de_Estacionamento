// 20 vagas no estacionamento

#define capacidadeTotal 20
int LEDvermelho = 9;
int LEDverde = 10;
int botao1 = 2; // botão para entrada do veículo
int botao2 = 3; // botão para saída do veículo

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
}

void abrirCatraca(){
  vagasDisponiveis--;
  vagasOcupadas++;
  
  digitalWrite(LEDverde, HIGH);
  digitalWrite(LEDvermelho, LOW);
  
  Serial.print("'ENTRADA registrada | Vagas ocupadas: ");
  Serial.print(vagasOcupadas);
  Serial.print("| Vagas disponíveis: ");
  Serial.println(vagasDisponiveis);
}
       
void fecharCatraca(){
  digitalWrite(LEDverde, LOW);
  digitalWrite(LEDvermelho,HIGH);
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
    
  if(estadobotao1 == HIGH && estadoAnteriorBotao1 == LOW){
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
    }S
  }
  
  estadoAnteriorBotao1 = estadobotao1;
  estadoAnteriorBotao2 = estadobotao2;
}

  

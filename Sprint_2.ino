int PontosHerois = 0;
int PontosViloes = 0;
int Heroi1, Heroi2, Vilao1, Vilao2;
int NUMERO_DE_PARTIDAS = 5;
int partida = 0;
int GanhadorH = 0;
int GanhadorV = 0;

bool botaoPressionado1 = false;
bool botaoPressionado2 = false;
bool botaoPressionado3 = false;
bool botaoPressionado4 = false;
//declarando os botões
#define BotaoHeroi1 6
#define BotaoHeroi2 8
#define BotaoVilao1 7
#define BotaoVilao2 9
//declarando os leds
#define ledVerde 3
#define ledVermelho 4
//declarando a buzzer
#define Buzzer 2
//declarando as variaveis para limpar os estados dos botoes 
int contH1 = 0;
int contH2 = 0;
int contV1 = 0;
int contV2 = 0;


void setup() {
  Serial.begin(9600);

  pinMode(BotaoHeroi1, INPUT);
  pinMode(BotaoVilao1, INPUT);
  pinMode(BotaoHeroi2, INPUT);
  pinMode(BotaoVilao2, INPUT);
  pinMode(ledVerde, INPUT);
  pinMode(ledVermelho, INPUT);
  pinMode(Buzzer, OUTPUT);
  delay(1000);

}

void limparEstado() {
  // Limpa o estado das variáveis para zero
  Heroi1 = 0;
  Heroi2 = 0;
  Vilao1 = 0;
  Vilao2 = 0;
  PontosHerois = 0;
  PontosViloes = 0;
  contH1 = 0;
  contH2 = 0;
  contV1 = 0;
  contV2 = 0;
}

void limparEstadoBotao() {
  //Limpar o estado dos botoes
  botaoPressionado1 = false;
  botaoPressionado2 = false;
  botaoPressionado3 = false;
  botaoPressionado4 = false;
}


void loop() {
  String partida1 = "";
  String partida2 = "";
  String partida3 = "";
  String partida4 = "";
  String partida5 = "";

  for (byte partida = 0; partida < NUMERO_DE_PARTIDAS;) {
    if (!botaoPressionado1 && digitalRead(BotaoHeroi1) == 1) {
      Heroi1 = random(1, 7);
      Serial.print("Pontos do Heroi1: ");
      Serial.println(Heroi1);
      delay(1000);
      botaoPressionado1 = true;
      contH1 += 1;
    }

    if (!botaoPressionado2 && digitalRead(BotaoHeroi2) == 1) {
      Heroi2 = random(1, 7);
      Serial.print("Pontos do Heroi2: ");
      Serial.println(Heroi2);
      delay(1000);
      botaoPressionado2 = true;
      contH2 += 1;
    }

    if (!botaoPressionado3 && digitalRead(BotaoVilao1) == 1) {
      Vilao1 = random(1, 7);
      Serial.print("Pontos do Vilao1: ");
      Serial.println(Vilao1);
      delay(1000);
      botaoPressionado3 = true;
      contV1 += 1;
    }

    if (!botaoPressionado4 && digitalRead(BotaoVilao2) == 1) {
      Vilao2 = random(1, 7);
      Serial.print("Pontos do Vilao2: ");
      Serial.println(Vilao2);
      delay(1000);
      botaoPressionado4 = true;
      contV2 += 1;
    }
    if (contH1 >= 2) {
      Serial.println("Erro, voce clicou mais de uma vez no seu botao em uma unica partida");
    }

    PontosHerois = Heroi1 + Heroi2;
    PontosViloes = Vilao1 + Vilao2;
    if (PontosHerois > 0 && PontosViloes > 0 && (Heroi1 != 0 && Heroi2 != 0 && Vilao1 != 0 && Vilao2 != 0)) {
      if (PontosHerois > PontosViloes) {
        Serial.print("Os herois venceram a partida!!!");
        limparEstado();
        limparEstadoBotao();
        delay(500);
        digitalWrite(Buzzer, HIGH);
        tone(Buzzer, 500);  // Frequência de 500Hz por 0.5 segundo caso os heróis ganh
        digitalWrite(ledVermelho, LOW);
        //delay(1000);  // Mantém o LED verde ligado por 0.5 segundo
        digitalWrite(ledVerde, HIGH);
        delay(2000);
        digitalWrite(ledVerde, LOW);
        noTone(Buzzer);
        partida1 = "herois";
        GanhadorH += 1;
        partida2 = "herois";
        GanhadorH += 1;
        partida3 = "herois";
        GanhadorH += 1;
        partida4 = "herois";
        GanhadorH += 1;
        partida5 = "herois";
        GanhadorH += 1;
      } 
      else if (PontosViloes > PontosHerois) {
        Serial.println("Os viloes venceram a partida!!!");
        limparEstado();
        limparEstadoBotao();
        delay(500);
        tone(Buzzer, 1000);  // Frequência de 500Hz por 0.5 segundo caso os heróis ganh
        digitalWrite(ledVerde, LOW);
        //delay(1000);  // Mantém o LED verde ligado por 0.5 segundo
        digitalWrite(ledVermelho, HIGH);
        delay(2000);
        digitalWrite(ledVermelho, LOW);
        noTone(Buzzer);
        partida1 = "viloes";
        GanhadorV += 1;
        partida2 = "viloes";
        GanhadorV += 1;
        partida3 = "viloes";
        GanhadorV += 1;
        partida4 = "viloes";
        GanhadorV += 1;
        partida5 = "viloes";
        GanhadorV += 1;
      } else {
        Serial.println("Empate!!!");
        limparEstado();
        limparEstadoBotao();
        tone(Buzzer, 750, 5000);  // Frequência de 750Hz por 5 segundo em caso de empate
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, LOW);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, LOW);
        delay(100);
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, LOW);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, LOW);
        delay(100);
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, LOW);
        delay(100);
        digitalWrite(ledVerde, HIGH);
        delay(100);
        digitalWrite(ledVermelho, HIGH);
        delay(100);
        digitalWrite(ledVerde, LOW);
        delay(100);
        digitalWrite(ledVermelho, LOW);
        delay(100);
        noTone(Buzzer);
      }
      partida += 1;
      Serial.print("Partida ");
      Serial.println(partida);
    }


    if (partida == 5) {
      if (GanhadorH > GanhadorV) {
        Serial.println("Os herois venceram o jogo"); 
        for (byte i = 0; i < 10; i++){
          tone(Buzzer, 500);
          digitalWrite(ledVerde, HIGH);
          delay(50);
          noTone(Buzzer);
          digitalWrite(ledVerde, LOW);
          delay(100);
        }    
      }

      if (GanhadorV > GanhadorH) {
        Serial.println("Os viloes venceram o jogo");
        for (byte i2 = 0; i2 < 10; i2++){
          tone(Buzzer, 1000);
          digitalWrite(ledVermelho, HIGH);
          delay(50);
          noTone(Buzzer);
          digitalWrite(ledVermelho, LOW);
          delay(100);
        }    
      }
      Serial.println("Fim de jogo");
    }
  }
}

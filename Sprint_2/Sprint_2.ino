int PontosHerois = 0;
int PontosViloes = 0;
int Heroi1, Heroi2, Vilao1, Vilao2;
int NUMERO_DE_PARTIDAS = 5;
int partida = 0;
int GanhadorH = 0;
int GanhadorV = 0;
int Vitoria = 7;

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

// Definição das notas musicais
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

// Define a estrutura da melodia
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_C4,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_C4
};

// Define a duração de cada nota
int noteDurations[] = {
  4, 4, 4, 4, 4, 2, 4,
  4, 4, 4, 4, 2,
  4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 2, 4,
  4, 4, 4, 4, 2,
  4, 4, 4
};


void setup() {
  Serial.begin(9600);

  Serial.println(R"(
 ==============================
|     Bem-vindo ao jogo,       |
|  Escolham seus personagens   |
|      para o inicio da        |
|         partida!!!           |
 ==============================
)");

  pinMode(BotaoHeroi1, INPUT);
  pinMode(BotaoVilao1, INPUT);
  pinMode(BotaoHeroi2, INPUT);
  pinMode(BotaoVilao2, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
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
}

void limparEstadoBotao() {
  //Limpar o estado dos botoes
  botaoPressionado1 = false;
  botaoPressionado2 = false;
  botaoPressionado3 = false;
  botaoPressionado4 = false;
}


void loop() {
  //quem ganhou da partida
  String partida1 = "";
  String partida2 = "";
  String partida3 = "";
  String partida4 = "";
  String partida5 = "";

  for (byte partida = 0; partida < NUMERO_DE_PARTIDAS;) {//limitar as partidas
    //lançamento de dados 
    if (!botaoPressionado1 && digitalRead(BotaoHeroi1) == 1) {
      Heroi1 = random(1, 7);
      Serial.print("Pontos do Heroi1: ");
      Serial.println(Heroi1);
      delay(1000);
      botaoPressionado1 = true;
    }

    if (!botaoPressionado2 && digitalRead(BotaoHeroi2) == 1) {
      Heroi2 = random(1, 7);
      Serial.print("Pontos do Heroi2: ");
      Serial.println(Heroi2);
      delay(1000);
      botaoPressionado2 = true;
    }

    if (!botaoPressionado3 && digitalRead(BotaoVilao1) == 1) {
      Vilao1 = random(1, 7);
      Serial.print("Pontos do Vilao1: ");
      Serial.println(Vilao1);
      delay(1000);
      botaoPressionado3 = true;
    }

    if (!botaoPressionado4 && digitalRead(BotaoVilao2) == 1) {
      Vilao2 = random(1, 7);
      Serial.print("Pontos do Vilao2: ");
      Serial.println(Vilao2);
      delay(1000);
      botaoPressionado4 = true;
    }

    PontosHerois = Heroi1 + Heroi2;
    PontosViloes = Vilao1 + Vilao2;
    if (PontosHerois > 0 && PontosViloes > 0 && (Heroi1 != 0 && Heroi2 != 0 && Vilao1 != 0 && Vilao2 != 0 && partida < 5)) {
      if (PontosHerois > PontosViloes && partida < 5) {
        Serial.println("Os herois venceram a partida!!!");
        limparEstado();
        limparEstadoBotao();
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledVerde, HIGH);
        tone(Buzzer, 663);
        delay(400);
        tone(Buzzer, 701);
        delay(250);
        tone(Buzzer, 589);
        delay(400);
        tone(Buzzer, 663);
        delay(250);
        tone(Buzzer, 526);
        delay(400);
        tone(Buzzer, 589);
        delay(250);
        tone(Buzzer, 440);
        delay(1000);
        noTone(Buzzer);
        delay(1000);
        digitalWrite(ledVerde, LOW);
        noTone(Buzzer);
        delay(1000);
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
      } else if (PontosViloes > PontosHerois && partida < 5) {
        Serial.println("Os viloes venceram a partida!!!");
        limparEstado();
        limparEstadoBotao();
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledVermelho, HIGH);
        tone(Buzzer, 392);
        delay(500);
        tone(Buzzer, 440);
        delay(250);
        tone(Buzzer, 468);
        delay(400);
        tone(Buzzer, 589);
        delay(400);
        tone(Buzzer, 468);
        delay(400);
        tone(Buzzer, 440);
        delay(250);
        tone(Buzzer, 392);
        delay(1000);
        noTone(Buzzer);
        digitalWrite(ledVermelho, LOW);
        delay(1000);
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
        for (byte i = 0; i < Vitoria; i++) {
          tone(Buzzer, 750, 5000);  // Frequência de 750Hz por 5 segundo em caso de empate
          digitalWrite(ledVermelho, HIGH);
          delay(100);
          digitalWrite(ledVerde, HIGH);
          noTone(Buzzer);
          delay(250);
          tone(Buzzer, 750);
          digitalWrite(ledVermelho, LOW);
          delay(100);
          digitalWrite(ledVerde, LOW);
          noTone(Buzzer);
          delay(250);
        }
      }
      partida += 1;
      Serial.print("Partida ");
      Serial.println(partida);
    }


    if (partida == 5) {
      if (GanhadorH > GanhadorV) {
        Serial.println("Os herois venceram o jogo");
        // Reproduz a melodia
        for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
          int duration = 1000 / noteDurations[i];
          digitalWrite(ledVerde, HIGH);
          tone(Buzzer, melody[i], duration);
          delay(duration + 50);  // Adiciona um pequeno atraso entre cada nota
          digitalWrite(ledVerde, LOW);
        }
      }

      if (GanhadorV > GanhadorH) {
        Serial.println("Os viloes venceram o jogo");
        // Reproduz a melodia
        for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
          int duration = 1000 / noteDurations[i];
          digitalWrite(ledVermelho, HIGH);
          tone(Buzzer, melody[i], duration);
          delay(duration + 50);
          digitalWrite(ledVermelho, LOW);
          
        }
      }

      else if (GanhadorV == GanhadorH) {
        Serial.println("O JOGO TERMINOU EMPATADO!!!");
      }
      Serial.println("Fim de jogo");
    }
  }
}

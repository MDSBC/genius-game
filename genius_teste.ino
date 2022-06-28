int botoes[4] = {
  7,
  6,
  5,
  4
};

int pinos[4] = {
  13,
  12,
  11,
  10
};

int numeroSorteado[] = {};
int cont_estados = 0;

int cont_botoes = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) 
  {
    pinMode(botoes[i], INPUT_PULLUP);
    pinMode(pinos[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  static byte botaoPressionado;
  numeroSorteado[cont_estados] = random(4);
  for (int i = 0; i <= cont_estados; i++) 
  {
    digitalWrite(pinos[i], HIGH);
    delay(500);
    digitalWrite(pinos[i], LOW);
    delay(500);
  }
  while (1)
  {
    for (int i = 0; i <= cont_estados; i++) 
    {
      while (1) 
      {
        for (int x = 0; x < 4; x++) 
        {
          if ((digitalRead(botoes[x]) == false) && (digitalRead(botoes[i]) == false)) 
          {
            break;
          } else if(digitalRead(botoes[x]) == false) {
            while (1) {
              digitalWrite(pinos[0], HIGH);
              delay(250);
              digitalWrite(pinos[0], LOW);
              delay(250);
            }
          }
        }
      }
    }
  }
  cont_estados ++;
  /*if(botaoPressionado == numeroSorteado) {
    cont_estados ++;
    Serial.println("É isso ae.");
    }*/
}

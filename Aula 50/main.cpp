#include <Arduino.h>

// PROTOTIPOS DAS FUNÇÕES

//! define as funções (nomes, tipos e parâmetros)

//* tipo   nome              parâmetros
    void   ligaLed           (int);
    void   desligaLed        (int);
    void   piscaLed          (int, unsigned long);
    int    somaDeDoisNumeros (int, int);

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  piscaLed(2, 100); //* executa a função
  Serial.println(somaDeDoisNumeros(4, 8)); //* imprime o resultado da função
}
            //* define o nome da variavel dentro do parâmetro da função
void ligaLed(int pin)
{
  digitalWrite(2, HIGH);
}

void desligaLed(int pin)
{
  digitalWrite(2, LOW);
}

void piscaLed(int pin, unsigned long tempo)
{
  //* executa todas as funções
  ligaLed(pin);
  delay(tempo);
  desligaLed(pin);
  delay(tempo);
}

int somaDeDoisNumeros(int numeroA, int numeroB)
{
  return (numeroA + numeroB); //* retorna o resultado
}
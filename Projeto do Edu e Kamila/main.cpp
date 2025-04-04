#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinLedPerigo 2
#define pinLedTiro 4
#define pinButtonBoneco 18
#define pinButtonNave 19

byte bonecoParado[] = {
    B01110,
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B01010,
    B01010};

byte bonecoAndando01[] = {
    B01110,
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B01010,
    B00010};

byte bonecoAndando02[] = {
    B01110,
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B01010,
    B01000};

byte bonecoEspantado[] = {
    B01110,
    B01110,
    B01110,
    B10101,
    B01110,
    B00100,
    B01010,
    B01010};

byte bonecoPulando[] = {

    B01110,
    B01110,
    B01110,
    B10101,
    B01110,
    B00100,
    B11011,
    B00000};

    byte espanto_pernas_meio_abertas[] = {
      B01110,
      B01110,
      B01110,
      B10101,
      B01110,
      B00100,
      B01010,
      B10001
    };

    byte nave[] = {
      B00000,
      B00100,
      B01110,
      B11111,
      B01110,
      B00000,
      B00000,
      B00000
    };
void setup()
{
  pinMode(pinLedPerigo, OUTPUT);
  pinMode(pinLedTiro, OUTPUT);
  pinMode(pinButtonBoneco, INPUT_PULLUP);
  pinMode(pinButtonNave, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, bonecoParado);
  lcd.createChar(1, bonecoAndando01);
  lcd.createChar(2, bonecoAndando02);
  lcd.createChar(3, bonecoEspantado);
  lcd.createChar(4, espanto_pernas_meio_abertas);
  lcd.createChar(5, bonecoPulando);
  lcd.createChar(6, nave);

  lcd.setCursor(19, 3);
  lcd.write(0);

}

void loop()
{
  bool buttonStateAtual = digitalRead(pinButtonBoneco);
  bool buttonState2Atual = digitalRead(pinButtonNave);

  static bool buttonStateAnterior = 1;
  static bool ledState = 0;

  static unsigned long tempoMudanca = 0;
  unsigned long tempoAtual = millis();
  const unsigned long tempoFiltro = 50;
  static bool ultimaAcao = 1;
  static bool atualizacao = 0;

  static int posicaoPacMan = 0;
  static bool posicaoExplosao = 0;
  static bool posicaoBoneco = 0;

  if (buttonStateAtual != buttonStateAnterior)

    tempoMudanca = tempoAtual;

  if (tempoAtual - tempoMudanca > tempoFiltro)
  {

    if (buttonStateAtual != ultimaAcao)
    {

      ultimaAcao = buttonStateAtual;

      if (!buttonStateAtual)
      {
        

        atualizacao = 1;
      }
    }
  }

  buttonStateAnterior = buttonStateAtual;
}
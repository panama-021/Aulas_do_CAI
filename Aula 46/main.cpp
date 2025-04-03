#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinLed 2
#define pinButton 19
#define pinButton2 18

byte pacMan[] = {
    B01110,
    B11101,
    B11111,
    B11100,
    B11000,
    B11000,
    B11111,
    B01110};

byte fantasma[] = {
    B01110,
    B11111,
    B10101,
    B11111,
    B11111,
    B11111,
    B11111,
    B10101};

byte pontinho[] = {
    B00000,
    B00000,
    B00000,
    B00100,
    B00000,
    B00000,
    B00000,
    B00000};

byte pacMan2[] = {
    B01110,
    B11101,
    B11111,
    B11111,
    B11111,
    B11111,
    B01110,
    B00000};

byte boneco[] = {
    B01110,
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B01010,
    B01010};

byte bonecoSalve[] = {
    B01110,
    B01110,
    B01110,
    B10101,
    B01110,
    B00100,
    B01010,
    B01010};

byte coracao[] = {
    B00000,
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000};

byte coracaoInvertido[] = {
    B11111,
    B11111,
    B10101,
    B00000,
    B00000,
    B10001,
    B11011,
    B11111};

void setup()
{
  lcd.init();
  lcd.createChar(0, pacMan);
  lcd.createChar(1, fantasma);
  lcd.createChar(2, pontinho);
  lcd.createChar(3, pacMan2);
  lcd.createChar(4, boneco);
  lcd.createChar(5, bonecoSalve);
  lcd.createChar(6, coracao);
  lcd.createChar(7, coracaoInvertido);

  lcd.backlight();
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);

  //* Pac Man
  lcd.setCursor(0, 1);
  lcd.write(0);

  //* Pontinhos
  lcd.setCursor(1, 1);
  lcd.write(2);
  lcd.setCursor(3, 1);
  lcd.write(2);
  lcd.setCursor(5, 1);
  lcd.write(2);
  lcd.setCursor(7, 1);
  lcd.write(2);

  //* Fantasma
  lcd.setCursor(9, 1);
  lcd.write(1);

  //* Boneco
  lcd.setCursor(16, 3);
  lcd.write(4);
}

void loop()
{
  bool buttonStateAtual = digitalRead(pinButton);
  bool buttonState2Atual = digitalRead(pinButton2);
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
        ledState = !ledState;
        posicaoPacMan++;

        atualizacao = 1;
      }
    }
  }

  buttonStateAnterior = buttonStateAtual;

  if (atualizacao)
  {

    //* código para o Pac Man andar
    switch (posicaoPacMan)
    {
    case 1:
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(1, 1);
      lcd.write(3);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 2:
      lcd.setCursor(0, 1);
      lcd.print("  ");
      lcd.setCursor(2, 1);
      lcd.write(0);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 3:
      lcd.setCursor(0, 1);
      lcd.print("   ");
      lcd.setCursor(3, 1);
      lcd.write(3);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 4:
      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(4, 1);
      lcd.write(0);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 5:
      lcd.setCursor(0, 1);
      lcd.print("     ");
      lcd.setCursor(5, 1);
      lcd.write(3);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 6:
      lcd.setCursor(0, 1);
      lcd.print("      ");
      lcd.setCursor(6, 1);
      lcd.write(0);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 7:
      lcd.setCursor(0, 1);
      lcd.print("       ");
      lcd.setCursor(7, 1);
      lcd.write(3);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 8:
      lcd.setCursor(0, 1);
      lcd.print("        ");
      lcd.setCursor(8, 1);
      lcd.write(0);
      lcd.setCursor(9, 1);
      lcd.write(1);
      break;

    case 9:
      lcd.setCursor(0, 1);
      lcd.print("         ");
      lcd.setCursor(9, 1);
      lcd.write(3);

      posicaoExplosao = 1;
      break;

    default:
      break;
    }

    //* código da explosão de corações
    if (posicaoExplosao)
    {

      lcd.setCursor(16, 3);
      lcd.write(5);
      delay(100);
      lcd.setCursor(16, 1);
      lcd.write(6);
      delay(100);

      lcd.setCursor(16, 0);
      lcd.write(7);
      delay(100);
      lcd.setCursor(16, 2);
      lcd.write(7);
      delay(100);

      lcd.setCursor(15, 2);
      lcd.write(6);
      delay(100);
      lcd.setCursor(15, 1);
      lcd.write(7);
      delay(100);
      lcd.setCursor(15, 0);
      lcd.write(6);
      delay(100);

      lcd.setCursor(14, 2);
      lcd.write(7);
      delay(100);
      lcd.setCursor(14, 1);
      lcd.write(6);
      delay(100);
      lcd.setCursor(14, 0);
      lcd.write(7);
      delay(100);

      lcd.setCursor(17, 2);
      lcd.write(6);
      delay(100);
      lcd.setCursor(17, 1);
      lcd.write(7);
      delay(100);
      lcd.setCursor(17, 0);
      lcd.write(6);
      delay(100);

      lcd.setCursor(18, 2);
      lcd.write(7);
      delay(100);
      lcd.setCursor(18, 1);
      lcd.write(6);
      delay(100);
      lcd.setCursor(18, 0);
      lcd.write(7);
      delay(100);

      lcd.setCursor(0, 3);
      lcd.print("TE AMO MAMAE!!!");
      delay(500);

      lcd.setCursor(0, 0);
      lcd.print("Panama_021");
    }
  }

  digitalWrite(pinLed, ledState);

  atualizacao = 0;
}

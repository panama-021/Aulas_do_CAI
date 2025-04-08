//* Eu fiz até a etapa 10

#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#define ledRed 15
#define ledYellow 2
#define ledGreen 4
#define ledWhite 5
#define pinButton01 18
#define pinButton02 19
#define pinButton03 23

LiquidCrystal_I2C lcd(0x27, 20, 4);

//* Instancias
Bounce buttonA = Bounce();
Bounce buttonB = Bounce();
Bounce buttonC = Bounce();

void botaoSeta();

bool atualizacao = 0;
bool modoSelecao = 1;
int buttonContador = 0;

void setup()
{
  Serial.begin(9600);
  // LCD
  lcd.init();
  lcd.backlight();

  // Led's e Botões
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledWhite, OUTPUT);
  pinMode(pinButton01, INPUT_PULLUP);
  pinMode(pinButton01, INPUT_PULLUP);
  pinMode(pinButton02, INPUT_PULLUP);
  pinMode(pinButton03, INPUT_PULLUP);

  // Bounce
  buttonA.attach(pinButton01, INPUT_PULLUP);
  buttonB.attach(pinButton02, INPUT_PULLUP);
  buttonC.attach(pinButton03, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(1, 0);
  lcd.print("Led Red");
  lcd.setCursor(1, 1);
  lcd.print("Led Yellow");
  lcd.setCursor(1, 2);
  lcd.print("Led Green");
  lcd.setCursor(1, 3);
  lcd.print("Led White");

  lcd.setCursor(12, 0);
  lcd.print("0%");
  lcd.setCursor(12, 1);
  lcd.print("0%");
  lcd.setCursor(12, 2);
  lcd.print("0%");
  lcd.setCursor(12, 3);
  lcd.print("0%");
}

void loop()
{
  botaoSeta();
}

void botaoSeta()
{
  buttonA.update();
  buttonB.update();
  buttonC.update();

  static int brilhoRed = 0;
  static int brilhoYellow = 0;
  static int brilhoGreen = 0;
  static int brilhoWhite = 0;

  if (buttonA.fell())
  {
    if (modoSelecao)
    {
      buttonContador++;
      atualizacao = 1;
      if (buttonContador > 3)
        buttonContador = 0;
    }
    else
    {
      switch (buttonContador)
      {
      case 0:
        brilhoRed += 10;

        if (brilhoRed > 100)
          brilhoRed = 100;
        Serial.println(brilhoRed);
        break;

      case 1:
        brilhoYellow += 10;

        if (brilhoYellow > 100)
          brilhoYellow = 100;
        Serial.println(brilhoYellow);
        break;

      case 2:
        brilhoGreen += 10;

        if (brilhoGreen > 100)
          brilhoGreen = 100;
        Serial.println(brilhoGreen);
        break;

      case 3:
        brilhoWhite += 10;

        if (brilhoWhite > 100)
          brilhoWhite = 100;
        Serial.println(brilhoWhite);
        break;
      }
    }
  }

  else if (buttonB.fell())
  {
    if (modoSelecao)
    {
      buttonContador--;
      atualizacao = 1;
      if (buttonContador < 0)
        buttonContador = 3;
    }
    else
    {
      switch (buttonContador)
      {
      case 0:
        brilhoRed -= 10;

        if (brilhoRed < 0)
          brilhoRed = 0;
        Serial.println(brilhoRed);
        break;

      case 1:
        brilhoYellow -= 10;

        if (brilhoYellow < 0)
          brilhoYellow = 0;
        Serial.println(brilhoYellow);
        break;

      case 2:
        brilhoGreen -= 10;

        if (brilhoGreen < 0)
          brilhoGreen = 0;
        Serial.println(brilhoGreen);
        break;

      case 3:
        brilhoWhite -= 10;

        if (brilhoWhite < 0)
          brilhoWhite = 0;
        Serial.println(brilhoWhite);
        break;
      }
    }
  }

  else if (buttonC.fell())
  {
    atualizacao = 1;
    modoSelecao = !modoSelecao;
  }

  if (atualizacao)
  {
    switch (buttonContador)
    {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print(">");
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 2);
      lcd.print(" ");
      lcd.setCursor(0, 3);
      lcd.print(" ");
      break;

    case 1:
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(">");
      lcd.setCursor(0, 2);
      lcd.print(" ");
      lcd.setCursor(0, 3);
      lcd.print(" ");
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 2);
      lcd.print(">");
      lcd.setCursor(0, 3);
      lcd.print(" ");
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 2);
      lcd.print(" ");
      lcd.setCursor(0, 3);
      lcd.print(">");
      break;
    }
  }

  atualizacao = 0;
}

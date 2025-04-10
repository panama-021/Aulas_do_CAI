#include <Arduino.h>

// -------AULA SOBRE STRING'S-------

//* FORMAS DE ESCREVER PALAVRAS EM C

char palavra[10] = "OLA MUNDO";
char palavra2[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};

String palavra3 = "HOJE EH QUINTA";

void setup()
{
  Serial.begin(9600);

  Serial.println(palavra);
  Serial.println(palavra2);

  strcpy(palavra, "SENAI"); //! substitui o que esta no vetor

  if (!strcmp(palavra, "SENAI")) // SE FOR IGUAL RETORNA ZERO
    Serial.println("SAO IGUAIS");

  if (!strncmp(palavra2, "OLA", 3)) //! PARA COMPARAR APENAS 3 LETRAS DA PALAVRA retorna 0 se for igual
    Serial.println("As primeiras letras da palavra eh OLA");

  if (strstr(palavra2, "MUNDO")) //! ENCONTRAR UMA PALAVRA EM UMA FRASE
    Serial.println("palavra MUNDO detectada");


  //*-----------------------------------------------------------------------------
    Serial.println(palavra3.length());          //retorna o numero de letras do objeto da classe string
    Serial.println(palavra3.charAt(10));        //retorna a letra que esta na posicao do parenteses
    Serial.println(palavra3.substring(10, 13)); //retorna da 10 posicao ate a 13
    Serial.println(palavra3.indexOf('U'));      //retorna a posicao que a primeira letra "u" esta
    Serial.println(palavra3.lastIndexOf('E'));  //retorna a posicao que a ultima letra "e" esta
  
    if (palavra3.equals("HOJE EH QUINTA") == 1) //retorna verdadeiro se forem iguais
      Serial.println("sao iguais");
  
    if (palavra3.equalsIgnoreCase("HOJE EH QUINTA") == 1) //retorna verdadeiro se forem iguais  ignorando letras maiusculas
      Serial.println("sao iguais");
  
    if (palavra3.startsWith("HOJE") == 1) //retorna verdadeiro se comacar com determinado texto
      Serial.println("comeca HOJE");
  
    if (palavra3.endsWith("inta") == 1) //retorna verdadeiro se a palavra terminar com determinado texto
      Serial.println("termina com inta");

  String valor = "123";
  int valorNumerico = valor.toInt();

  String valor2 = "10.5";
  float valorNumerico2 = valor2.toFloat();

  //* EXEMPLO: transforme o numero do texto em valor numerico tipo inteiro

  String mensagem = "Valor = 50";

  int tamanho = mensagem.length(); // MEDIR O TAMANHO DO TEXTO

  String extracao = mensagem.substring(8, tamanho); // EXTRAIR O NUMEOR INICIADO EM UMA POSICAO CONHECIDA ATÉ O FIM DO TEXTO

  int numero = extracao.toInt(); // TRANSFORME O CONTEÚDO EXTRAIDO EM UM NUMERO INTEIRO

  Serial.println(numero * 2); // UTILIZE O NUMERO SEM MODERAÇÃO... HAHAHAHAHA

  //! CONTINUANDO
  
  palavra3.toLowerCase(); // Altera todas as letras para minúsculas
  Serial.println(palavra3);
  palavra3.toUpperCase(); //Altera todas para maiúsculas
 Serial.println(palavra3);
  

  String textoLed = "Led = ON";
  Serial.println(textoLed);
  textoLed.replace("ON" , "OFF");
  Serial.println(textoLed);

  String novaFrase = "Texto    ";
  novaFrase.trim(); //Remove os espaços do fim do texto

  novaFrase.concat(" adicionado"); //Adiciona um texto a string
  Serial.println(novaFrase);
}

void loop()
{
}

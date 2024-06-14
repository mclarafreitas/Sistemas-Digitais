#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char s = 0; // Variável para controlar o estado do sistema
unsigned char reset_flag = 0; // Flag para indicar o reset do sistema

void setup() {
  DDRA = 0b11111111; // Configura o PORTA como saída
  PORTA = 0b01111110; // Configura o estado inicial dos pinos do PORTA
  DDRD &= 0b11111100; // Configura o PD1 e PD0 (20 e 21) como entrada

}

void loop() {
  // Verifica se o botão de reset foi pressionado
  if ((PIND & (0b00000001))) {
    s = 0; // Reinicia a variável de controle de estado
    PORTA = 0b01111110; // Configura o PORTA para o estado inicial
  }

  // Máquina de estados para controlar as saídas do PORTA com base no estado atual (s)
  switch (s) {
    case 0:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 1; // Altera o estado para 1
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 1:
      // Configura o PORTA para um padrão específico
      PORTA = 0b00101000; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 2; // Altera o estado para 2
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 2:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 3; // Altera o estado para 3
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 3:
      // Configura o PORTA para um padrão específico
      PORTA = 0b01011011; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 4; // Altera o estado para 4
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 4:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 5; // Altera o estado para 5
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 5:
      // Configura o PORTA para um padrão específico
      PORTA = 0b01101011; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 6; // Altera o estado para 6
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 6:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 7; // Altera o estado para 7
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 7:
      // Configura o PORTA para um padrão específico
      PORTA = 0b00101101; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 8; // Altera o estado para 8
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 8:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 9; // Altera o estado para 9
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 9:
      // Configura o PORTA para um padrão específico
      PORTA = 0b01100111; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 10; // Altera o estado para 10
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 10:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 11; // Altera o estado para 11
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 11:
      // Configura o PORTA para um padrão específico
      PORTA = 0b01110111; 
      // Verifica se o botão foi solto para avançar para o próximo estado
      if (!(PIND & (0b00000010))) {
        s = 12; // Altera o estado para 12
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 12:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 13; // Altera o estado para 13
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 13:
      // Configura o PORTA para um padrão específico
      PORTA = 0b00101010; 
      // Verifica se o botão de reset foi pressionado para voltar ao estado inicial (0)
      if ((PIND & (0b00000001))) {
        s = 0; // Volta ao estado inicial
        PORTA = 0b01111110; // Configura o PORTA para o estado inicial
      } else {
        // Verifica se o botão foi solto para avançar para o próximo estado
        if (!(PIND & (0b00000010))) {
          s = 14; // Altera o estado para 14
          delay(3); // Aguarda um curto período de tempo
        }
      }
      break;
    case 14:
      // Verifica se o botão foi pressionado para avançar para o próximo estado
      if (PIND & (0b00000010)) {
        s = 15; // Altera o estado para 15
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    case 15:
      // Configura o PORTA para o estado inicial
      PORTA = 0b01111110; 
      // Verifica se o botão foi solto para voltar ao estado inicial (0)
      if (!(PIND & (0b00000010))) {
        s = 0; // Volta ao estado inicial
        delay(3); // Aguarda um curto período de tempo
      }
      break;
    default:
      // Verifica se o botão de reset foi pressionado para voltar ao estado inicial (0)
      if (PIND & (0b00000001)) {
        PORTA = 0b01111110; // Configura o PORTA para o estado inicial
        s = 0; // Volta ao estado inicial
        delay(3); // Aguarda um curto período de tempo
      }
  }
}

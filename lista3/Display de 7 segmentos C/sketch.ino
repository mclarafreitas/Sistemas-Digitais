#include <avr/io.h>
#include <util/delay.h>

#define pushButtom PB7 // Definição do pino do botão

int main() {
  int vector_values[8] = 
  {
    0b0111111, // 0
    0b0000110, // 1
    0b1011011, // 2
    0b1001111, // 3
    0b1100110, // 4
    0b1101101, // 5
    0b1111101, // 6
    0b0000111  // 7
  };

 
  DDRC = 0xFF; // Define todos os pinos de C como saída


  DDRB &= ~(1 << pushButtom); // Define o pino do botão como entrada

  int cont = 0; // Variável para controlar o índice do vetor

  while(1){

 
    if(PINB & (1 << pushButtom)){ // Verifica se o botão foi pressionado


      PORTC = vector_values[cont]; // Mostra o valor do vetor na porta C

      _delay_ms(1000); // Aguarda 1 segundo


      while(PINB & (1 << pushButtom)); // Aguarda o botão ser solto


      cont = (cont == 7) ? 0 : cont + 1; // Incrementa o índice do vetor ou retorna ao início se for 7

    }
  }
  return 0;
}

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char s = 0; // Variável de estado

void setup() {
  DDRA = 0b11111111;   // Define todas as portas do registrador A como saída
  PORTA = 0b01111110;  // Define o valor inicial das portas do registrador A
  EIMSK |= 0b00000011; // Habilita interrupções externas INT0 e INT1
  EICRA |= 0b00001111; // Configura interrupção para borda de subida e descida em INT0 e INT1
  sei();               // Habilita interrupções globalmente
}

ISR(INT0_vect) {
  if ((PIND & (0b00000010))) { // Verifica se a borda de subida ocorreu no pino PD1
    s = 0;                     // Reinicia a sequência
    PORTA = 0b01111110;        // Define a sequência inicial
  }
}

ISR(INT1_vect) {
  switch (s) {
    case 0:
      if (PIND & (0b00000001)) { // Verifica se a borda de subida ocorreu no pino PD0
        s = 1;                   // Avança para o próximo passo da sequência
        _delay_ms(3);            // Pequeno atraso para evitar debouncing
      }
      break; // Fim do caso 0
    case 1:
      PORTA = 0b00101000; // Exibe o número 1 no display
      if (!(PIND & (0b00000001))) {
        s = 2;
        _delay_ms(3);
      }
      break; // Fim do caso 1
    case 2:
      if (PIND & (0b00000001)) {
        s = 3;
        _delay_ms(3);
      }
      break; // Fim do caso 2
    case 3:
      PORTA = 0b01011011; // Exibe o número 2 no display
      if (!(PIND & (0b00000001))) {
        s = 4;
        _delay_ms(3);
      }
      break; // Fim do caso 3
    case 4:
      if (PIND & (0b00000001)) {
        s = 5;
        _delay_ms(3);
      }
      break; // Fim do caso 4
    case 5:
      PORTA = 0b01101011; // Exibe o número 3 no display
      if (!(PIND & (0b00000001))) {
        s = 6;
        _delay_ms(3);
      }
      break; // Fim do caso 5
    case 6:
      if (PIND & (0b00000001)) {
        s = 7;
        _delay_ms(3);
      }
      break; // Fim do caso 6
    case 7:
      PORTA = 0b00101101; // Exibe o número 4 no display
      if (!(PIND & (0b00000001))) {
        s = 8;
        _delay_ms(3);
      }
      break; // Fim do caso 7
    case 8:
      if (PIND & (0b00000001)) {
        s = 9;
        _delay_ms(3);
      }
      break; // Fim do caso 8
    case 9:
      PORTA = 0b01100111; // Exibe o número 5 no display
      if (!(PIND & (0b00000001))) {
        s = 10;
        _delay_ms(3);
      }
      break; // Fim do caso 9
    case 10:
      if (PIND & (0b00000001)) {
        s = 11;
        _delay_ms(3);
      }
      break; // Fim do caso 10
    case 11:
      PORTA = 0b01110111; // Exibe o número 6 no display
      if (!(PIND & (0b00000001))) {
        s = 12;
        _delay_ms(3);
      }
      break; // Fim do caso 11
    case 12:
      if (PIND & (0b00000001)) {
        s = 13;
        _delay_ms(3);
      }
      break; // Fim do caso 12
    case 13:
      PORTA = 0b00101010; // Exibe o número 7 no display
      if (!(PIND & (0b00000001))) {
        s = 14;
        _delay_ms(3);
      }
      break; // Fim do caso 13
    case 14:
      if (PIND & (0b00000001)) {
        s = 15;
        _delay_ms(3);
      }
      break; // Fim do caso 14
    case 15:
      PORTA = 0b01111110; // Exibe o número 8 no display
      if (!(PIND & (0b00000001))) {
        s = 0;
        _delay_ms(3);
      }
      break; // Fim do caso 15
  }
}

void loop() {
  // O loop está vazio, pois as ações são realizadas nas interrupções
}


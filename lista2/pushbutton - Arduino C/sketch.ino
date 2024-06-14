#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define buttonPin 7 // Define buttonPin no pino digital 7
#define ledPin 10   // Define ledPin no pino digital 10

void setup() {
  DDRB |= (1 << PB4);  // Define o pino 10 (PB4) como saída
  DDRH &= ~(1 << PH4); // Define o pino 7 (PH4) como entrada
}

void loop() {
  if (PINH & (1 << PH4)) { // Verifica o estado do botão (PH4)
    PORTB |= (1 << PB4); // Liga o LED (PB4)
    _delay_ms(100);         // Aguarda 100 milissegundos
  } else {
    PORTB &= ~(1 << PB4); // Desliga o LED (PB4)
  }
}



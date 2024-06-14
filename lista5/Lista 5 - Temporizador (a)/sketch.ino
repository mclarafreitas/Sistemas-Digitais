#include <avr/io.h>

#define LED_PIN 13  // O LED está conectado ao pino digital 13

void setup() {
    // Configura o pino LED como saída
    DDRB |= (1 << PORTB7);  // Configura o pino 13 (PORTB7) como saída
    
    // Configura o temporizador no modo CTC
    // Temporizador 1 - Timer1
    TCCR1A = 0; // Limpa o registrador de controle A do Timer1
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // Modo CTC (WGM12) e prescaler de 1024 (CS12 e CS10)
    
    // Configura o valor de comparação para 1 segundo
    OCR1A = 15624; // Valor calculado para um segundo com prescaler de 1024 (16MHz / 1024 = 15625 Hz)
}

void loop() {
    // Verifica se houve um evento de comparação
    if (TIFR1 & (1 << OCF1A)) {
        // Limpa a flag de comparação
        TIFR1 |= (1 << OCF1A);
        
        // Alterna o estado do LED
        PORTB ^= (1 << PORTB7);  // Alterna o pino 13 (PORTB7) do Arduino
    }
}



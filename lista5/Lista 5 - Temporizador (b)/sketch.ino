#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN 13  // O LED está conectado ao pino digital 13

void setup() {
    // Configura o pino LED como saída
    pinMode(LED_PIN, OUTPUT);
    
    // Configura o temporizador no modo CTC
    // Temporizador 1 - Timer1
    TCCR1A = 0; // Limpa o registrador de controle A do Timer1
    TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // Modo CTC (WGM12) e prescaler de 1024 (CS12 e CS10)
    
    // Configurar o valor de comparação para 1 segundo
    OCR1A = 15624; // Valor calculado para um segundo com prescaler de 1024 (16MHz / 1024 = 15625 Hz)
    
    // Habilitar a interrupção de comparação A
    TIMSK1 = (1 << OCIE1A);
    
    // Habilitar interrupções globais
    sei();
}

void loop() {
    // O loop está vazio porque tudo está sendo controlado pela interrupção
}

// Rotina de serviço de interrupção para o evento de comparação do Timer1
ISR(TIMER1_COMPA_vect) {
    // Alterna o estado do LED
    PORTB ^= (1 << PORTB7); // Alternar o pino 13 (PORTB7) do Arduino
}

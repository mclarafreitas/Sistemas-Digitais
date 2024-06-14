#include <avr/io.h> 
#include <util/delay.h> 

#define LED_PIN PB7 // Define o pino PB7 como o pino onde o LED está conectado.

void initPWM() {
    // Configura o Timer/Counter0:
    // COM0A1: Define o modo de saída para PWM rápido com non-inverting mode (saída de comparação).
    // WGM00 e WGM01: Configura o temporizador para modo PWM rápido.
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    
    // Configura o prescaler para 1 (CS00) para não dividir a frequência do clock.
    TCCR0B |= (1 << CS00); // Prescaler = 1
    
    // Configura o pino do LED como saída.
    DDRB |= (1 << LED_PIN);
}

void setPWM(float duty) {
    // Calcula o valor do registrador de comparação com base no ciclo de trabalho desejado (duty).
    // duty * 256 dá um valor na escala de 0 a 255 para o duty cycle.
    OCR0A = (int)(duty * 256) - 1;
}

int main() {
    // Inicializa o PWM
    initPWM();
    
    while (1) {
        // Define o ciclo de trabalho para 1% e aguarda 300 ms.
        setPWM(0.01);
        _delay_ms(300);
        
        // Define o ciclo de trabalho para 25% e aguarda 200 ms.
        setPWM(0.25);
        _delay_ms(200);
        
        // Define o ciclo de trabalho para 50% e aguarda 200 ms.
        setPWM(0.5);
        _delay_ms(200);
        
        // Define o ciclo de trabalho para 75% e aguarda 200 ms.
        setPWM(0.75);
        _delay_ms(200);
        
        // Define o ciclo de trabalho para 100% (LED sempre aceso) e aguarda 200 ms.
        setPWM(1.0);
        _delay_ms(200);
    }
    
    return 0;
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);  // acende o LED vermelho
  digitalWrite(12, LOW);   // garante que o LED amarelo esteja apagado
  digitalWrite(11, LOW);   // garante que o LED verde esteja apagado
  delay(5000);             // aguarda 5 segundos

  // Sinal de atenção (amarelo) por 2 segundos
  digitalWrite(13, LOW);   // garante que o LED vermelho esteja apagado
  digitalWrite(12, HIGH);  // acende o LED amarelo
  digitalWrite(11, LOW);   // garante que o LED verde esteja apagado
  delay(2000);             // aguarda 2 segundos

  // Sinal aberto (verde) por 5 segundos
  digitalWrite(13, LOW);   // garante que o LED vermelho esteja apagado
  digitalWrite(12, LOW);   // garante que o LED amarelo esteja apagado
  digitalWrite(11, HIGH);  // acende o LED verde
  delay(5000);
}

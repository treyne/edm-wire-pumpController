const byte INPUT_PIN = A1;
const byte MODE = A6;

const byte HIGH_PINS[] = {A2, A3};
const byte LOW_PINS[]  = {A4, A5};

const unsigned long PULSE_TIME = 200; // мс

bool lastState = LOW;

void pulsePins(const byte pins[], byte count)
{
  for (byte i = 0; i < count; i++)
    digitalWrite(pins[i], HIGH);

  delay(PULSE_TIME);

  for (byte i = 0; i < count; i++)
    digitalWrite(pins[i], LOW);
}

void setup()
{
  pinMode(INPUT_PIN, INPUT_PULLUP);
  pinMode(MODE, INPUT_PULLUP);

  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);

  lastState = digitalRead(INPUT_PIN);
}

void loop()
{
  bool currentState = digitalRead(INPUT_PIN);

  // Переход LOW -> HIGH
  if (!lastState && currentState)
  {
    pulsePins(HIGH_PINS, 2);
  }

  // Переход HIGH -> LOW
  if (lastState && !currentState)
  {
    pulsePins(LOW_PINS, 2);
  }

  lastState = currentState;
}

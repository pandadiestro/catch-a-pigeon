void
setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(19, OUTPUT);
}

void
loop()
{
    for (int i = 0; i <= 15; i++) {
        digitalWrite(21, (i & 0x01));
        digitalWrite(22, ((i & 0x02) >> 1));
        digitalWrite(23, ((i & 0x04) >> 2));
        digitalWrite(19, ((i & 0x08) >> 3));
        delay(1000);
    }
}

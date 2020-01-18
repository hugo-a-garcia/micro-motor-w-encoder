char receivedChar;
boolean newData = false;
long number = -1;

void setup()
{
    Serial.begin(115200);
    Serial.setTimeout(20);
    Serial.println("<Arduino is ready>");
}

void loop()
{
    if (Serial.available() > 0)
    {
        //receivedChar = Serial.read();
        number = Serial.parseInt();
        newData = true;
    }
    if (newData == true)
    {
        Serial.println(number);
        newData = false;
    }
}

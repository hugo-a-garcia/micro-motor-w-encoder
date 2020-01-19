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

        switch (number)
        {
        case 1:
            Serial.println("ONE");
            break;
        case 2:
            Serial.println("TWO");
            break;
        case 3:
            Serial.println("THREE");
            break;
        case 4:
            Serial.println("FOUR");
            break;
        default:
            Serial.println("DEFAULT");
        }
    }
}


SimpleDHT22 dht22(23);

void temp_DHT()
{

    int err = SimpleDHTErrSuccess;

    if ((err = dht22.read2(&temperatura, &humidade, NULL)) != SimpleDHTErrSuccess)
    {
        Serial.print("Read DHT22 failed, err=");
        Serial.println(err);
    }
    Serial.print(temperatura);
    Serial.print(" *C, ");
    Serial.print(humidade);
    Serial.println(" RH%");
}
void task_timers()
{
    TimerHandle_t xControleLoRaTimer;
    BaseType_t xTimer1Started;

    xControleLoRaTimer = xTimerCreate("Controle_LoRa",
                                      mainControleLoRa_PERIOD,
                                      pdTRUE,
                                      30,
                                      checarControle);

    if (xControleLoRaTimer != NULL)
    {

        xTimer1Started = xTimerStart(xControleLoRaTimer, 0);

        if (xTimer1Started == pdPASS)
        {
            Serial.println("Timers criados e iniciados");
        }
    }
}

void task_sensor(void *pvParameter)
{

    for (;;)
    {
        temp_DHT();
        medicaoPotencia();
        msgSensores = String(temperatura) + "!" + String(humidade) + "!" + String(Irms) + "!" + String(potencia) + "!" + String(kwhTotal_Acc, 5);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

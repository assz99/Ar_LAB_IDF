void task_timers()
{
    TimerHandle_t xLoRaTimer, xSensorTimer;
    BaseType_t xTimer1Started, xTimer2Started;

    /*xLoRaTimer = xTimerCreate("envio_Lora",
                              mainLoRa_PERIOD,
                              pdTRUE,
                              30,
                              prvLoRaCallback);*/

    xSensorTimer = xTimerCreate("Sensortimer",
                                mainSensor_PERIOD,
                                pdTRUE,
                                0,
                                prvSensorCallback);

    if ((xSensorTimer != NULL) /*&& ( xAutoReloadTimer != NULL )*/)
    {

        xTimer1Started = xTimerStart(xSensorTimer, 0);
        //xTimer2Started = xTimerStart( xAutoReloadTimer, 0 );

        if ((xTimer1Started == pdPASS) /*&& ( xTimer2Started == pdPASS )*/)
        {
            Serial.println("Timers criados e iniciados");
        }
    }
}

static void prvSensorCallback(TimerHandle_t xTimer)
{

    temp_DHT();
    medicaoPotencia();
}

void task_sensor(void *pvParameter)
{

    for (;;)
    {
        temp_DHT();
        medicaoPotencia();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

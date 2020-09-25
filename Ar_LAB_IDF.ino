#include "includes/headers.h"

void setup()
{
    Serial.begin(115200);
    oledInit();
    SCT013.current(pinSCT, 5.4);

    ////////////////////////////////////////
    // Convertendo o MAC para MAC byte
    ////////////////////////////////////////
    String MAC_LOCAL = WiFi.macAddress();
    char ChMacLocal[18];
    String(MAC_LOCAL).toCharArray(ChMacLocal, 18);
    char *InfoMacLocal[6];
    InfoMacLocal[0] = strtok(ChMacLocal, ":");
    InfoMacLocal[1] = strtok(NULL, ":");
    InfoMacLocal[2] = strtok(NULL, ":");
    InfoMacLocal[3] = strtok(NULL, ":");
    InfoMacLocal[4] = strtok(NULL, ":");
    InfoMacLocal[5] = strtok(NULL, ":");
    String Mac_Local_Full;
    for (int s = 0; s < 6; s++)
    {
        Mac_Local_Full += InfoMacLocal[s];
    }
    localAddress = Mac_Local_Full;

    oledLimpar();
    oledEscrever(0, 0, "" + String(MAC_LOCAL));
    oledEscrever(0, 16, "Novo: " + String(Mac_Local_Full));
    oledEscrever(0, 32, "[ESP - AR COND]");
    ////////////////////////////////////////
    // Convertendo o MAC para MAC byte
    ////////////////////////////////////////

    blueInit();

    if ((xTaskCreate(task_sensor, "task_sensor", 4048, NULL, 5, NULL)) != pdTRUE)
    {
        ESP_LOGI(TAG, "error - nao foi possivel alocar task_sensor.\n");
        return;
    }
    else
    {
        Serial.println("Task criada com sucesso");
    }
}

void loop(){

};

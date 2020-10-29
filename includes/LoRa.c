//Função Que vai estar nas tasks esperando as mensagens chegar.
void taskReceberLoRa(void *pvParameter)
{
    if (rf95.available())
    {
        // Should be a message for us now
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
        if (rf95.recv(buf, &len))
        {

            Serial.print("Chegou: ");
            Serial.println((char *)buf);

            String ex = String((char *)buf);
            char chMsgLoRa[30];
            String(ex).toCharArray(chMsgLoRa, 30);
            char *infoMsgLoRa[5];
            infoMsgLoRa[0] = strtok(chMsgLoRa, "!"); //Mac que quem envio
            infoMsgLoRa[1] = strtok(NULL, "!");      //Mac de destino
            infoMsgLoRa[2] = strtok(NULL, "!");
            //Nome do projeto
            infoMsgLoRa[3] = strtok(NULL, "!"); //timeStamp
            infoMsgLoRa[4] = strtok(NULL, "!"); //Mensagem

            //primeiro checar se a mensagem e para ele

            if (localAddress = !infoMsgLoRa[1])
            {
                Serial.println("Mensagem nao e para mim");
                return;
            }

            //Se receber a msg do OK pegar o timeStamp

            if (infoMsgLoRa[4] == "ok")
            {

                controleRetirarLoRa(infoMsgLoRa[3].toInt()); //Trocar o T pelo timestamp recebido
                return;
            }

            //Se receber uma mensagem para ele
            String msg = localAddress + "!" + destino + "!" + projNome + "!" + String(infoMsgLoRa[3]) + "!" + "ok";
            enviarLoRa(msg);
        }
        else
        {
            Serial.println("recv failed");
        }
    }
}

void enviarSensorLoRa(String msg)
{
    timeStamp = pegarTimeStamp();
    String msgFinal = localAddress + "!" + destino + "!" + projNome + "!" + String(timeStamp) + "!" + msgSensores;

    //Função enviar se for sucesso
    enviarLoRa();
    controleGravarLoRa(msgFinal);
}
//Funcao para gravar no controle do lora
void controleGravarLoRa(String msg)
{

    for (int i = 0; i < 11; i++)
    {
        if (controleTimeStamp[i] == 0)
        {
            controleTimeStamp[i] = timeStamp;
            controleMsg[i] = msg;
            break;
        }
        if (i == 10)
        {
            Serial.println("Vetor Controle Lotado.");
        }
    }
}

void controleRetirarLoRa(int t)
{

    for (int i = 0; i < 11; i++)
    {
        if (controleTimeStamp[i] == t)
        {
            controleTimeStamp[i] = 0;
            controleMsg[i] = "";
        }
        if (i == 10)
        {
            Serial.println("Este timeStamp nao esta gravado.");
        }
    }

    //Função Geral de enviar dados.
    void enviarLoRa(String msg)
    {
        loraEnviar(msg);
    }
    //Função para checar o Controle das mensagens. Vai estar nas tasks;
    void checarControle(TimerHandle_t xTimer){
        int time = pegarTimeStamp();
        for (int i = 0; i < 11; i++)
        {
            if ((time - controleTimeStamp[i]) > 5)
            {
                enviarLoRa(controleMsg[i];);
            }
        }
    }

void receberLoRa()
{
    String ex;
    char chMsgLoRa[30];
    String(ex).toCharArray(chMsgLoRa, 30);
    char *infoMsgLoRa[5];
    infoMsgLoRa[0] = strtok(chMsgLoRa, "!");  //Mac que quem envio
    infoMsgLoRa[1] = strtok(NULL, "!");       //Mac de destino
    infoMsgLoRa[2] = strtok(NULL, "!");       //Nome do projeto
    infoMsgLoRa[3] = strtok(NULL, "!");       //timeStamp
    infoMsgLoRa[4] = strtok(NULL, "!");       //Mensagem

//primeiro checar se a mensagem e para ele

if(localAddress =! infoMsgLoRa[1]){
    Serial.println("Mensagem nao e para mim");
    return;
}

//Se receber uma mensagem para ele



//Se receber a msg do OK pegar o timeStamp
controleRetirarLoRa(infoMsgLoRa[3].toInt());//Trocar o T pelo timestamp recebido

}

void enviarSensorLoRa(String msg)
{

    String msgFinal = localAddress + "!" + destino + "!" + projNome + "!" + String(timeStamp) + "!" + msgSensores;

    //Função enviar se for sucesso
    enviarLoRa();
    controleLoRa(StringMsg);
}
//Funcao para gravar no controle do lora
void controleGravarLoRa(String msg){

 for (int i = 0; i < 11; i++)
    {
        if(controleTimeStamp[i]==0){
            controleTimeStamp[i] = timeStamp;
            controleMsg[i] = msg;
            break;
        }
        if(i==10){
            Serial.println("Vetor Controle Lotado.");
        }   
    }


}

void controleRetirarLoRa(int t){

    for (int i = 0; i < 11; i++)
    {
        if(controleTimeStamp[i]==t){
            controleTimeStamp[i] = 0;
            controleMsg[i] = "";
        }
        if(i==10){
            Serial.println("Este timeStamp nao esta gravado.");
        } 



}

//Função Geral de enviar dados.
void enviarLoRa(){ 



}
BLECharacteristic *characteristicTX; //através desse objeto iremos enviar dados para o client

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b" // UART service UUID
#define CHARACTERISTIC_UUID_RX "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_TX "4fafc201-1fb5-459e-8fcc-c5c9c331914b"

//callback  para envendos das características
class CharacteristicCallbacks: public BLECharacteristicCallbacks {
    
    void onWrite(BLECharacteristic *characteristic) {
      String msg = "";
      //retorna ponteiro para o registrador contendo o valor atual da caracteristica
      std::string rxValue = characteristic->getValue(); 
      //verifica se existe dados (tamanho maior que zero)
      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");
        
        for (int i = 0; i < rxValue.length(); i++) {
          msg= msg + rxValue[i];  
        }  
      }
      //TRATAR A MENSAGEM E SABER SE E PARA MIM OU NAO
      int x = msg.toInt();
      comando_ar(x);
    }
  
    
};

void blueInit(){
// Create the BLE Device
    BLEDevice::init("ESP_ArCondicionado"); // nome do dispositivo bluetooth
    // Create the BLE Server
    BLEServer *server = BLEDevice::createServer(); //cria um BLE server
    // Create the BLE Service
    BLEService *service = server->createService(SERVICE_UUID);

    // Create a BLE Characteristic para recebimento de dados
    BLECharacteristic *characteristic = service->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE);

    characteristic->setCallbacks(new CharacteristicCallbacks());
    // Start the service
    service->start();
    // Start advertising (descoberta do ESP32)
    server->getAdvertising()->start();


}

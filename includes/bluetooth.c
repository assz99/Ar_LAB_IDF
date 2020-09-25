BLECharacteristic *characteristicTX; //através desse objeto iremos enviar dados para o client

#define SERVICE_UUID "ab0828b1-198e-4351-b779-901fa0e0371e" // UART service UUID
#define CHARACTERISTIC_UUID_RX "4ac8a682-9736-4e5d-932b-e9b31405049c"
#define CHARACTERISTIC_UUID_TX "0972EF8C-7613-4075-AD52-756F33D4DA91"

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

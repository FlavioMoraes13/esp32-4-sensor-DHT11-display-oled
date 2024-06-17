//https://www.youtube.com/watch?v=UJpiIpmWPVM
//https://forum.arduino.cc/t/add-second-dht11-sensor-to-eps32-arduino-code/851681
//pino 22 do esp no sck do display
//pino 21 do esp no sda do display
//para o pino data do DHT NÃO USAR os pinos D2,D12,D18,D19,D21,D22,D23,D25,D26,D27,D33,D32,D34,D35
//para o pino data do DHT     USAR os pinos D4, D5,D13,D14,D15

#include <DHT.h>
#define DHTPIN1 4          //pino do esp32 para ligar o DHT11
#define DHTPIN2 5          //pino do esp32 para ligar o DHT11
#define DHTPIN3 13
#define DHTPIN4 14
#define DHTPIN5 15
#define DHTTYPE DHT11     //DHT sensor type (DHT11)


DHT dht1 (DHTPIN1, DHTTYPE);
DHT dht2 (DHTPIN2, DHTTYPE);
DHT dht3 (DHTPIN3, DHTTYPE);
DHT dht4 (DHTPIN4, DHTTYPE);
DHT dht5 (DHTPIN5, DHTTYPE);

#include <Adafruit_SSD1306.h>
#define OLED_LARGURA 128  // Número de Pixels do display OLED (Largura)
#define OLED_ALTURA  64   // Número de Pixels do display OLED (Altura)
#define OLED_RESET   4    // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(OLED_LARGURA, OLED_ALTURA, &Wire, OLED_RESET);//inicialização do display SSD1306

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);//inicialização do display e endereçamendo I2C
  display.clearDisplay(); // Limpa p display
  dht1.begin();            //inicializa o sensor DHT
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  Serial.begin(9600);     // Initialize serial communication.
}
 
void loop() 
{
  float umidade_z1 = dht1.readHumidity(); // Read humidity value
  float tempera_z1 = dht1.readTemperature(); // Read the temperature value in Celsius.
  Serial.print("ZONA 1:\t");
  Serial.print("Umidade: ");
  Serial.print(umidade_z1);
  Serial.print("%\t");        //Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(tempera_z1);
  Serial.println("°C");
        
  float umidade_z2= dht2.readHumidity(); // Read humidity value
  float tempera_z2= dht2.readTemperature(); // Read the temperature value in Celsius.
  Serial.print("ZONA 2:\t");
  Serial.print("Umidade: ");
  Serial.print(umidade_z2);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(tempera_z2);
  Serial.println("°C");
  
  float umidade_z3 = dht3.readHumidity(); // Read humidity value
  float tempera_z3 = dht3.readTemperature(); // Read the temperature value in Celsius.
  Serial.print("ZONA 3:\t");
  Serial.print("Umidade: ");
  Serial.print(umidade_z3);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(tempera_z3);
  Serial.println("°C");

  float umidade_z4 = dht4.readHumidity(); // Read humidity value
  float tempera_z4 = dht4.readTemperature(); // Read the temperature value in Celsius.
  Serial.print("ZONA 4:\t");
  Serial.print("Umidade: ");
  Serial.print(umidade_z4);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(tempera_z4);
  Serial.println("°C");

  float umidade_z5 = dht5.readHumidity(); // Read humidity value
  float tempera_z5 = dht5.readTemperature(); // Read the temperature value in Celsius.
  Serial.print("ZONA 5:\t");
  Serial.print("Umidade: ");
  Serial.print(umidade_z5);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(tempera_z5);
  Serial.println("°C");
   Serial.println("");
  
  float media_umidade=((umidade_z1+umidade_z2+umidade_z3+umidade_z4+umidade_z5)/5);
  float media_tempera=((tempera_z1+tempera_z2+tempera_z3+tempera_z4+tempera_z5)/5);
  Serial.print(" MEDIA:\t");
  Serial.print("Umidade: ");
  Serial.print(media_umidade);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(media_tempera);
  Serial.println("°C");
  Serial.println("");
  delay(2000); // Wait for 2 seconds between readings



/*
  display.clearDisplay();                 // Limpa p display
  display.setTextSize(1.5);               // Tamanho da fonte
  display.setTextColor(WHITE);            // Cor da fonte
  display.setCursor(1,8);                 // coordenada coluna=1 e linha=0 para imprimir
  display.println(" *** TEMPERATURA ***");// texto
  display.setTextSize(2);                 // Tamanho da fonte
  display.setTextColor(WHITE);            // Cor da fonte
  display.setCursor(24,16);               // coordenada coluna=24 e linha=16 para imprimir
  display.println(temperature);                  // Variável a ser impressa
  display.setCursor(83,8);                // coordenada coluna=83 e linha=8 para imprimir
  display.println(".");                   // ponto
  display.setCursor(93,16);               // Local de início do texto
  display.println("C");                   //texto
  
  display.setTextSize(1.5);               // Tamanho da fonte
  display.setCursor(1,33);                 // coordenada coluna=1 e linha=0 para imprimir
  display.println(" ***** UMIDADE *****");// texto
  display.setTextSize(2);                 // Tamanho da fonte
  display.setCursor(24,43);
  display.println(humidity);
  display.setCursor(93,46);               // Local de início do texto
  display.println("%");
  display.display();                      //finaliza a impressão no display
  delay(1000);  
*/
}

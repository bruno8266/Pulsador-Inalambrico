/**
 * @brief Pulsador inalámbrico: Receptor
 *
 * @author Bruno Enzo Benítez
 */
#include <Arduino.h>
#include <WifiEspNow.h>

#define MENSAJE_LLAVE 3
#define MENSAJE_PULSADOR_OFF 5
#define MENSAJE_PULSADOR_ON 4

//rx_mac_adress = {B4, E6, 2D, 1A, 2B, A5}
//tx_mac_adress = {CC, 50, E3, 07, 2D, 2F}

uint8_t tx_mac_address[6] = {0xCC, 0x50, 0xE3, 0x07, 0x2D, 0x2F};
uint8_t mensaje = 3;
size_t mensaje_tam = sizeof(mensaje);

bool conexion = false;

bool estado_led = false;

void
printReceivedMessage(const uint8_t mac[WIFIESPNOW_ALEN], const uint8_t* buf, size_t count,
                     void* arg)
{
  Serial.printf("Message from %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3],mac[4], mac[5]);
  for (int i = 0; i < (int) (count); ++i) {
    Serial.print( (buf[i]));
  }
	Serial.println();

	if(buf[0] == MENSAJE_LLAVE)
	  	{
			if(estado_led == false)
			{
				estado_led = true;
				//Serial.println("Modo LLAVE: Pulsador ON");
			}
			else
			{
				estado_led = false;
				//Serial.println("Modo LLAVE: Pulsador OFF");
			}
		}
	// Modo PULSADOR: pulsador ON
	if(buf[0] == MENSAJE_PULSADOR_ON)
	{
		estado_led = true;
		//Serial.println("Modo PULSADOR: pulsador ON");
	}
	// Modo PULSADOR: pulsador OFF
	if(buf[0] == MENSAJE_PULSADOR_OFF)
	{
		estado_led = false;
		//Serial.println("Modo PULSADOR: pulsador OFF");
	}
		digitalWrite(LED_BUILTIN,estado_led);
}

void setup() {

 	 /* Inicializamos el monitor serie en caso de debugear
	 Serial.begin(115200);
	 Serial.println();
 	 Serial.println("Hola Unitec");
	*/
	WiFi.mode(WIFI_STA);
	WifiEspNow.onReceive(printReceivedMessage, nullptr);

	conexion = WifiEspNow.begin();
  // Añadimos una conexión
  		while(conexion != true){
			WifiEspNow.addPeer(tx_mac_address, 0, nullptr);
		}
	/* En caso de debugear, descomentar
	if(conexion != true)
	{
		Serial.println("No se pudo inicializar ESP NOW");
	}
	else
	{
		Serial.println("Felicidades");
	}
		*/
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*  if(conexion == true)
	{
		Serial.println("Hola receptor");
 	}
	else
		{Serial.println("Sin conexion");}

*/
	
/*  Descomentar para leer la direccion MAC
	Serial.print("ESP Board. Direccion MAC:  ");
 	Serial.println(WiFi.macAddress());
*/	
}

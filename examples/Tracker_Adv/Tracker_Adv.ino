#include <Arduino.h>

#include <WM1110_Geolocation.hpp>
#include <WM1110_BLE.hpp>

void setup()
{
    Serial.begin(115200);
    while (!Serial) delay(100);  

    Serial.print("WM1110 BLE Advertising Example\r\n");  

    wm1110_ble.begin();

    wm1110_ble.setName("Wio Tracker 1110");

    wm1110_ble.setStartParameters(false);

}

void loop()
{    
    delay(1000);
    printf("Starting adv---------\r\n");
    wm1110_ble.startAdv();
    delay(10000);
    wm1110_ble.stopAdv();
    printf("Stoped adv---------\r\n");

    delay(1000); 
}

////////////////////////////////////////////////////////////////////////////////

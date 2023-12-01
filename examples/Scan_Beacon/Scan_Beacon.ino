#include <Arduino.h>

#include <WM1110_Geolocation.hpp>
#include <WM1110_BLE.hpp>


char ble_name[24]={0};
void setup()
{
    uint8_t len = 23;
    Serial.begin(115200);
    while (!Serial) delay(100);  

    Serial.print("WM1110 BLE Scan Example\r\n");  

    wm1110_ble.begin();

    wm1110_ble.setName("Wio Tracker 1110");

    wm1110_ble.getName(ble_name,len);

    wm1110_ble.setStartParameters(true);

}

void loop()
{    
    printf("Starting scan---------\r\n");
    wm1110_ble.startScan();
    delay(5000);

    wm1110_ble.stopScan();
    printf("Stoped scan---------\r\n");
    wm1110_ble.sortScanedResults();
    printf("Scaned results: \r\n");  
    wm1110_ble.displayScanedDatas( );

    delay(1000); 
}

////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>

#include <WM1110_Geolocation.hpp>
#include <WM1110_BLE.hpp>

uint8_t ble_scan_results_buf[244] = {0};
uint8_t ble_scan_results_size = 0;
void setup()
{
    Serial.begin(115200);
    while (!Serial) delay(100);  

    Serial.print("WM1110 BLE Transmit & Receive Example\r\n");  

    wm1110_ble.begin();

    wm1110_ble.setName("Wio Tracker 1110");

    wm1110_ble.setStartParameters();

    wm1110_ble.startAdv();
}

void loop()
{    
    if(wm1110_ble.getBleRecData(ble_scan_results_buf,&ble_scan_results_size))
    {
        printf("%s",ble_scan_results_buf);
        wm1110_ble.ble_trace_print("%s",ble_scan_results_buf);
        memset(ble_scan_results_buf,0,ble_scan_results_size);
        ble_scan_results_size = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////

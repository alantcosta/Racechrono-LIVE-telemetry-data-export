#include <Arduino.h>
#include "rcmonitor.h"            // https://github.com/aollin/racechrono-ble-diy-device

// Data to fecth from Racechrono
struct strmon monitors[] = {
#ifdef DUMMYTEST
    {"x_magnetic_field", "channel(device(magn), x_magnetic_field)", 1.0},
    {"y_magnetic_field", "channel(device(magn), y_magnetic_field)", 1.0}
#else
    {"Time Delta",        "channel(device(lap), delta_lap_time)*10.0", 0.1},
    {"Speed Delta",       "channel(device(gps), delta_speed)*10.0", 0.1}
#endif
};

void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("\nBooting...");
  initscreen();
  bootscreensequence();
  rcmonitorstart();
}


void loop() {
  static float timegain;
  static int16_t speedgain;
  if( rcmonitor() ) {
    timegain = monitorValues[0] * monitorMultipliers[0];
    speedgain = (int16_t) (monitorValues[1] * monitorMultipliers[1]);
  }
  delay(900);
}







// end

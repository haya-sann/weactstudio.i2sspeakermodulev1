#include "AudioTools.h"
#include "BluetoothA2DPSinkQueued.h"
#include "A2DPVolumeControl.h"

#define SD_PIN 5

I2SStream i2s;
BluetoothA2DPSinkQueued a2dp_sink(i2s);

void setup() {
    pinMode(SD_PIN, OUTPUT);
    digitalWrite(SD_PIN, LOW);

    auto cfg = i2s.defaultConfig();
    cfg.pin_bck = 27;
    cfg.pin_ws = 26;
    cfg.pin_data = 25;
    cfg.pin_mck = 0;
    i2s.begin(cfg);

    a2dp_sink.set_volume(0);
    a2dp_sink.start("PCM5100A_haya");

    delay(2000);

    digitalWrite(SD_PIN, HIGH);

    for (int v = 0; v <= 20; v++) {
        a2dp_sink.set_volume(v);
        delay(50);
    }
}

void loop() {
}
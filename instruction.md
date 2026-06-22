# WiFi Car Project - Setup Instructions

## Important Setup Instructions

Please carefully follow the instructions below before uploading and testing the project.

### 1. Arduino Nano Firmware

Upload the Arduino Nano code only to an **Arduino Nano** board.

* Select the correct Arduino Nano board from the Arduino IDE.
* Ensure the correct COM port is selected.
* Upload the Nano firmware before connecting the ESP8266 module.

---

### 2. ESP8266 Firmware Upload

Upload the ESP8266 code directly to the ESP8266 module.

If you do not have a dedicated USB-to-TTL programmer, you can use an Arduino Nano as a programmer by following these steps:

#### Arduino Nano as USB-to-Serial Adapter

1. Connect the **RST pin of the Arduino Nano to GND**.

   * This disables the ATmega328P and allows the Nano to act as a USB-to-Serial converter.

2. Make the following connections:

| ESP8266 | Arduino Nano                     |
| ------- | -------------------------------- |
| TX      | TX                               |
| RX      | RX                               |
| GND     | GND                              |
| VCC     | 3.3V (stable supply recommended) |

3. Put the ESP8266 into programming mode if required by your module.

4. Upload the ESP8266 firmware through the Arduino IDE.

---

### 3. ESP8266 Board Selection

Before uploading the ESP8266 code:

* Open Arduino IDE.
* Go to **Tools → Board**.
* Select:

```
Generic ESP8266 Module
```

Using any other board configuration may result in upload errors or unexpected behavior.

---

### 4. Recommended Wheel Configuration

For best movement performance and full utilization of the code functionality, use:

### Mechanum Wheels

Benefits:

* Omnidirectional movement
* Smooth lateral motion
* Better turning performance
* Full support for advanced movement algorithms

While standard wheels may work, Mechanum wheels provide the best experience and are strongly recommended.

---

## Recommended Hardware

* Arduino Nano
* ESP8266 (ESP-01 or compatible module)
* Motor Driver
* Mechanum Wheels
* Battery Pack
* Chassis Frame

---

## Notes

* Verify all wiring before powering the system.
* Use a stable power supply for the ESP8266.
* Ensure TX and RX connections are correct.
* Upload the appropriate firmware to the correct board.
* Mechanum wheels are recommended for achieving the intended motion behavior of the project.

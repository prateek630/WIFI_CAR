# WiFi Mecanum Car - Wiring and Pinouts

## System Overview

This project uses:

* Arduino Nano (Motor Controller)
* ESP8266 (WiFi Controller)
* 2 × L298N Motor Drivers
* 4 × DC Gear Motors
* 4 × Mecanum Wheels

The ESP8266 receives commands through WiFi and sends movement commands to the Arduino Nano through serial communication.

The Arduino Nano controls all four motors independently using two L298N motor drivers.

---

# ESP8266 ↔ Arduino Nano

## Serial Communication

| ESP8266 | Arduino Nano |
| ------- | ------------ |
| TX      | D0 (RX)      |
| RX      | D1 (TX)      |
| GND     | GND          |

Important:

* Both boards must share a common ground.
* TX and RX are connected directly because the Nano receives commands from the ESP8266.

---

# ESP8266 Programming Connection

To upload code to the ESP8266 using an Arduino Nano:

1. Connect Nano RST to GND.
2. Connect:

| ESP8266 | Arduino Nano |
| ------- | ------------ |
| TX      | TX           |
| RX      | RX           |
| GND     | GND          |

3. Select:

Generic ESP8266 Module

from the Arduino IDE board menu.

---

# Motor Driver 1 (Right Side Motors)

Controls:

* Front Right Motor
* Rear Right Motor

## L298N #1 Connections

| L298N Pin | Arduino Nano |
| --------- | ------------ |
| IN1       | D2           |
| IN2       | D3           |
| IN3       | D4           |
| IN4       | D5           |

### Motor Outputs

| L298N Output | Motor             |
| ------------ | ----------------- |
| OUT1 / OUT2  | Front Right Motor |
| OUT3 / OUT4  | Rear Right Motor  |

---

# Motor Driver 2 (Left Side Motors)

Controls:

* Front Left Motor
* Rear Left Motor

## L298N #2 Connections

| L298N Pin | Arduino Nano |
| --------- | ------------ |
| IN1       | D6           |
| IN2       | D7           |
| IN3       | D8           |
| IN4       | D9           |

### Motor Outputs

| L298N Output | Motor            |
| ------------ | ---------------- |
| OUT1 / OUT2  | Front Left Motor |
| OUT3 / OUT4  | Rear Left Motor  |

---

# Power Connections

## L298N Drivers

| Connection            |
| --------------------- |
| Battery + → 12V Input |
| Battery - → GND       |

Both motor drivers must share the same ground.

---

## Arduino Nano

| Pin | Connection       |
| --- | ---------------- |
| VIN | Battery Positive |
| GND | Common Ground    |

---

## ESP8266

| Pin | Connection     |
| --- | -------------- |
| VCC | Regulated 3.3V |
| GND | Common Ground  |

A dedicated 3.3V regulator is recommended for stable ESP8266 operation.

---

# Mecanum Wheel Layout

Top View

Front

FL          FR

RL          RR

Rear

Where:

* FL = Front Left
* FR = Front Right
* RL = Rear Left
* RR = Rear Right

Install mecanum wheels in an X-pattern for correct strafing movement.

---

# Supported Movements

The firmware supports:

* Forward
* Backward
* Strafe Left
* Strafe Right
* Clockwise Rotation
* Counter-Clockwise Rotation
* Forward Left
* Forward Right
* Backward Left
* Backward Right
* Pivot Turns
* Stop

For best performance, mecanum wheels are strongly recommended.

---

# Important Notes

1. Upload Arduino firmware only to the Arduino Nano.
2. Upload ESP8266 firmware only to the ESP8266.
3. Select "Generic ESP8266 Module" while uploading ESP8266 firmware.
4. Use mecanum wheels to achieve full movement functionality.
5. Ensure all grounds are connected together.
6. Verify motor directions and swap motor wires if a wheel rotates in the wrong direction.

# Additional ESP8266 Wiring and Power Recommendations

## ESP8266 ESP-01 Pin Connections

### Normal Operating Mode

| ESP8266 Pin | Connection           |
| ----------- | -------------------- |
| VCC         | 3.3V                 |
| GND         | GND                  |
| TX          | Arduino Nano D0 (RX) |
| RX          | Arduino Nano D1 (TX) |
| CH_PD / EN  | 3.3V                 |
| GPIO0       | Leave Open           |
| GPIO2       | Leave Open           |
| RST         | Leave Open           |

The CH_PD (EN) pin must be connected to 3.3V for the ESP8266 to operate correctly.

---

## ESP8266 Firmware Upload Connections

When uploading firmware to the ESP8266 using an Arduino Nano as a USB-to-Serial adapter:

### Arduino Nano Preparation

Connect:

| Arduino Nano |
| ------------ |
| RST → GND    |

This disables the Nano's microcontroller and allows the board to function as a USB-to-Serial converter.

---

### Upload Wiring

| ESP8266 Pin | Arduino Nano |
| ----------- | ------------ |
| TX          | TX           |
| RX          | RX           |
| GND         | GND          |
| VCC         | 3.3V         |
| CH_PD / EN  | 3.3V         |
| GPIO0       | GND          |
| GPIO2       | Leave Open   |
| RST         | Leave Open   |

### Entering Flash Mode

To upload code successfully:

GPIO0 must be connected to GND before powering or resetting the ESP8266.

This places the ESP8266 into bootloader mode and allows firmware uploading.

After the upload completes:

1. Disconnect GPIO0 from GND.
2. Reset or power-cycle the ESP8266.
3. The ESP8266 will boot normally and run the uploaded firmware.

---

## ESP-01 Pin Layout

```
    ESP-01

 ┌───────────┐
```

GPIO0        TX
GPIO2        CH_PD
GND        RST
RX        VCC
└───────────┘

---

# Power Supply Recommendations

## ESP8266 Warning

⚠️ Important

The ESP8266 is highly sensitive to voltage fluctuations.

Although some setups may appear to work using the Arduino Nano's onboard 3.3V pin, this is generally not recommended for long-term reliable operation.

For best stability:

* Use a dedicated 3.3V voltage regulator.
* Ensure the regulator can supply sufficient current during WiFi transmissions.
* Always share a common ground with the Arduino Nano and motor drivers.

Failure to provide a stable 3.3V supply may result in:

* Random resets
* WiFi disconnections
* Upload failures
* Unstable operation

---

## Motor Driver Power Recommendation

⚠️ Recommended for Best Performance

This project uses two L298N motor drivers controlling four motors.

For maximum torque, smoother movement, and reduced voltage drop, it is recommended to power each L298N motor driver from its own dedicated 12V power source.

Recommended configuration:

Power Source 1
└── L298N Driver #1
└── Right Side Motors

Power Source 2
└── L298N Driver #2
└── Left Side Motors

This configuration helps:

* Reduce voltage sag during acceleration
* Improve mecanum wheel performance
* Improve strafing capability
* Reduce motor stalls
* Improve battery life under load

---

## Common Ground Requirement

Regardless of the power configuration used:

The following grounds must always be connected together:

* Arduino Nano GND
* ESP8266 GND
* L298N Driver #1 GND
* L298N Driver #2 GND
* Battery/Power Supply Ground

A shared ground reference is mandatory for proper serial communication and motor control.

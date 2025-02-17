# PID_AutoDim_Light
ESP8266 automatic night light using an LDR and PID control to adjust LED brightness based on ambient light

# ESP8266 Night Light with PID Control

## 📌 Project Description
This project uses an **ESP8266** and an **LDR (Light Dependent Resistor)** to create an **automatic night light**. The brightness of an LED is adjusted dynamically using a **PID controller** to match the ambient light levels. When the room gets darker, the LED brightens gradually, and when it's bright, the LED dims accordingly.

## 🔧 Features
- 📡 **ESP8266-based** system
- 🌞 **LDR sensor for ambient light detection**
- 🔄 **PID control for smooth LED brightness adjustment**
- ⚡ **Energy-efficient adaptive lighting**

## 🛠️ Components Required
| Component | Description |
|-----------|------------|
| ESP8266 (NodeMCU/Wemos D1 Mini) | Microcontroller |
| LDR (Light Dependent Resistor) | Measures ambient light |
| 10KΩ Resistor | Used for voltage divider with LDR |
| LED | Output light source |
| 330Ω Resistor | Current limiting for LED |
| Jumper Wires | For connections |
| Breadboard | Prototyping |

## 🔌 Wiring Diagram
```
   (3.3V)
     │
    [LDR]
     │
     ├──► (A0 ESP8266)
     │
    [10KΩ]
     │
    (GND)
```
- **LDR to 3.3V**
- **One end of LDR to A0 (ADC) on ESP8266**
- **The other end of LDR connects to a 10KΩ resistor, which is grounded (GND)**
- **LED to GPIO2 (D4), with a 330Ω resistor in series to GND**

## 📜 Code Overview
- Reads **ambient light levels** via `analogRead(A0)`.
- Uses **PID control** to adjust LED brightness.
- Maps **PID output** to `analogWrite()` for smooth dimming.
- Implements **delays for stability** and prevents rapid fluctuations.

## 🚀 Setup and Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ESP8266_Night_Light.git
   cd ESP8266_Night_Light
   ```
2. Open `ESP8266_Night_Light.ino` in **Arduino IDE**.
3. Install the required libraries:
   - `PID_v1.h` (via Library Manager)
4. Connect ESP8266 and upload the code.
5. Open **Serial Monitor** to debug and tune PID values.

## 🔧 Adjusting PID Parameters
| Parameter | Effect |
|-----------|--------|
| `Kp` (Proportional) | Adjusts response speed |
| `Ki` (Integral) | Eliminates small errors over time |
| `Kd` (Derivative) | Reduces overshoot and oscillation |

To fine-tune brightness control, adjust these values:
```cpp
Kp = 1.2;  // Increase for faster response
Ki = 0.4;  // Adjust to eliminate steady-state error
Kd = 0.2;  // Helps stabilize transitions
```

## 📷 Demo and Screenshots
_Add photos or a GIF of the project in action_

## 📝 License
This project is open-source and released under the **MIT License**.

## 💡 Future Improvements
- 🔋 Low-power mode for battery efficiency
- 📡 MQTT or Web control for remote adjustment
- 🌈 RGB LED for color-based brightness feedback

---
Made with ❤️ by [Your Name] 🚀


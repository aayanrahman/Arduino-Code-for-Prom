# Arduino Finger Touch Promposal Project

This is a fun and creative **Arduino project** where a thermistor (temperature sensor) is used to detect when someone places their finger on it.  
After detecting the touch, the LCD screen shows an **"Analyzing..."** loading animation with percentage progress, and finally displays the message:

> **"Prom with me?"**

---

## What You Need
- Arduino Uno (or similar)
- 16x2 LCD Display (with 6 digital pins connected)
- Thermistor (temperature sensor)
- 10kΩ resistor (for thermistor voltage divider)
- Breadboard and jumper wires
- USB cable for uploading code
- Arduino IDE (free software)

---

## How It Works
1. **Startup Message**  
   The LCD shows:  
   ➔ `"Place finger on sensor..."`

2. **Finger Detection**  
   When a warm finger touches the thermistor, the Arduino confirms the touch by averaging multiple readings for accuracy.

3. **Loading Animation**  
   The LCD displays:  
   ➔ `"Analyzing..."`  
   ➔ Followed by `"Progress: 0%"`, `"Progress: 20%"`, ..., `"Progress: 100%"`

4. **Prom Invitation**  
   Once the "scan" is complete, it displays:  
   ➔ `"MATCH FOUND!"`  
   ➔ Then finally:  
   ➔ `"Prom with me?"`

---

## Setup Instructions
1. Wire the **thermistor** in a voltage divider setup:
   - One side to **5V**
   - Other side connected to **analog pin A0** and a **10kΩ resistor to GND**.

2. Connect the **LCD display**:
   - RS → Pin 12
   - E → Pin 11
   - D4 → Pin 5
   - D5 → Pin 4
   - D6 → Pin 3
   - D7 → Pin 6
   - RW → GND
   - VSS → GND
   - VDD → 5V
   - Contrast pin (V0) → Middle of a 10kΩ potentiometer (or set to GND for max contrast)

3. Upload the code using Arduino IDE.

---

## Calibration
- Adjust the `touchThreshold` value in the code if detection is unreliable.
- Typical values:
  - **No touch**: ~500
  - **Finger touch**: ~540–580 (depending on hand warmth).

```cpp
const int touchThreshold = 540;
const int noTouchThreshold = 500;
```

## MIT License
Feel free to use, modify, and share this project however you want!
Good luck asking your special someone to prom! 🎉

Made with <3 by Realjs


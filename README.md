# EEG Hardware Setup Guide
This guide provides step-by-step instructions for assembling the EEG signal acquisition system. The setup includes an Arduino Uno, an AD620 instrumentation amplifier, EEG electrodes, and the necessary wiring for signal processing and transmission.
![research1](https://github.com/user-attachments/assets/5b0e3c00-d662-4545-95fe-7b418074d178)


------------

## Hardware Components
### 1. Microcontroller
- Arduino Uno – Used to process EEG signals and communicate with a computer.

### 2. EEG Electrodes
- Dry or wet electrodes (minimum of three: signal, reference, and ground).
- Alligator clips for secure electrode connections.

### 3. Amplifier Circuit
- AD620 Instrumentation Amplifier – Used for signal amplification.

### 4. Resistor
A single resistor placed on the breadboard for signal stabilization.

### 5. Wiring Components
- Jumper wires – For connecting the amplifier, electrodes, and Arduino.
- Breadboard – Used for assembling the AD620 circuit.

### 6. Power Supply
- 5V from Arduino Uno – Powers the amplifier and EEG circuit.

  ![cb2e533d-48ff-4f09-9cc5-0372e7d88f0f](https://github.com/user-attachments/assets/c0627db5-ed9a-466f-9a7c-0998ac9c16ad)



------------

## Wiring Diagram & Connections

### AD620 Placement on Breadboard
- Placed on E6, E7, E8, E9 (left side) and F6, F7, F8, F9 (right side).

### Resistor Placement
- D6 to G6 on the breadboard.

###Connections to Arduino Uno
| Breadboard Pin  | Arduino Uno Pin |
| ------------- | ------------- |
| D7  | 5V (Analog)  |
| D8  | A0 (Analog Input) |
| D9  | Negative Bus strip |
| GND(Arduino)  | Negative Bus strip |

### Electrode Connections
| Breadboard Pin  | Electrode Connection |
| ------------- | ------------- |
| G7  | Signal Electrode (Alligator Clip)  |
| G8  | Signal Electrode (Alligator Clip) |
| G9  | Negative Bus strip |


------------

## Arduino Code
Upload the following code to the Arduino Uno to read and transmit EEG signals:

```cpp
const int SIGNAL_PIN = A0;  // Pin connected to the EEG signal
const int SAMPLING_RATE = 100;  // Sampling rate in Hz (matches Python code)
const int SAMPLING_INTERVAL = 1000 / SAMPLING_RATE;  // Interval in milliseconds

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  // Read the raw EEG signal
  int rawValue = analogRead(SIGNAL_PIN);

  // Convert the raw value to voltage (assuming 5V reference and 10-bit ADC)
  float voltage = rawValue * (5.0 / 1023.0);

  // Send the voltage value to the Python script
  Serial.print("Voltage: ");
  Serial.println(voltage, 4);  // Send voltage with 4 decimal places

  // Wait for the next sample
  delay(SAMPLING_INTERVAL);
}
```

------------

## Setup Instructions
### 1. Connect the Electrodes
- Attach the signal electrode to the scalp (e.g., forehead).
- Attach the reference electrode to a neutral location (e.g., earlobe).
- Attach the ground electrode to a location with minimal electrical activity (e.g., another earlobe).

### 2. Power Up the System
- Connect the Arduino Uno to your computer via USB.
- Ensure the AD620 amplifier receives power from the Arduino (5V).

### 3. Upload the Code
- Open the Arduino IDE.
- Copy and paste the provided code into a new sketch.
- Select the correct board (Arduino Uno) and port.
- Upload the code.

### 4. Test the Setup
- Open the Serial Monitor in the Arduino IDE (set baud rate to 9600).
- Observe the EEG signal values being printed.
- Ensure the values change when focusing or relaxing.
  
  ![Screenshot 2025-02-04 020223](https://github.com/user-attachments/assets/74084ba0-23f0-4eb4-a96c-d81cfd47a307)


------------

## Troubleshooting
### No Signal Detected
- Check all electrode connections and ensure they are properly attached to the skin.
- Verify that the AD620 amplifier is powered and correctly wired.

### Noisy or Unstable Signal
- Ensure the ground electrode is properly attached.
- Keep wiring away from power cables or other sources of electrical interference.

------------

## References
[AD620 Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ad620.pdf)
[Arduino Documentation](https://docs.arduino.cc/)
[ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/index.html)




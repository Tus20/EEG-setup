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

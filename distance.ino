/*
 * A simple project that will turn on a different LED depending on the value of an
 * attached distance sensor. The disance sensor for this code should be setup on
 * the analog input port #5
 */

// Pins for our on and off LEDs
int onLed = 3;
int offLed = 2;

void setup() {
	Serial.begin(9600);

	// Setup our ports as outputs
	pinMode(onLed, OUTPUT);
	pinMode(offLed, OUTPUT);
}

void loop() {
	// Grab the 'distance' from the sensor
	int sensorValue = analogRead(A5);

	if (sensorValue < 100) {
		// Small distance. Turn on the 'on' LED
		digitalWrite(onLed, HIGH);
		digitalWrite(offLed, LOW);
	} else {
		// Large distance. Turn on the 'off' LED
		digitalWrite(onLed, LOW);
		digitalWrite(offLed, HIGH);
	}

	// Print out the read value
	Serial.println(sensorValue);

	// Only check the sensor four times a second
	delay(250);
}

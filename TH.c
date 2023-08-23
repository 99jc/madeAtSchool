#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIMINGS  83
#define DHT_PIN      7
#define RED  	     1
#define GREEN        4
#define BLUE 	     5

void setup() {
	if (wiringPiSetup() < 0) {
		return;
	}
}

int* read_dht_data() {
	uint8_t 	laststate = 1;
	uint8_t		counter	= 0;
	uint8_t 	j = 0;
	uint8_t 	i;
	int* 		data = calloc(5, sizeof(int));

	pinMode(DHT_PIN, OUTPUT);
	digitalWrite(DHT_PIN, 0);
	delay(18);
	digitalWrite(DHT_PIN, 1);
	delayMicroseconds(40);

	pinMode(DHT_PIN, INPUT);

	for (i = 0; i < MAX_TIMINGS; i++) {
		counter = 0;
		while (digitalRead(DHT_PIN) == laststate) {
			counter++;
			delayMicroseconds(1);
			if (counter == 255) {
				break;
			}
		}
		laststate = digitalRead(DHT_PIN);
		if (counter == 255) {
			break;
		}

		if ((i >= 4) && (i % 2 == 0)) {
			data[j / 8] <<= 1;
			if ( counter > 16) {
				data[j / 8] |= 1;
			}
			j++;
		}
	}
	if ((j >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) {
		return data;
	}
	else  {
		free(data);
		return 0;
	}

}

void controlLED(int state) {
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);

	switch(state) {
		case 0:
			digitalWrite(RED, 1);
			digitalWrite(GREEN, 0);
			digitalWrite(BLUE, 1);
			break;
		case 1:
			digitalWrite(RED, 0);
			digitalWrite(GREEN, 1);
			digitalWrite(BLUE, 0);
			break;
		case 2:
			digitalWrite(RED, 1);
			digitalWrite(GREEN, 1);
			digitalWrite(BLUE, 0);
			break;
		case 3:
			digitalWrite(RED, 0);
			digitalWrite(GREEN, 0);
			digitalWrite(BLUE, 0);
			break;
		case 4:
			digitalWrite(RED, 0);
			digitalWrite(GREEN, 1);
			digitalWrite(BLUE, 1);
			break;
		defualt:
			digitalWrite(RED, 1);
			digitalWrite(GREEN, 1);
			digitalWrite(BLUE, 1);
			break;
	}

}

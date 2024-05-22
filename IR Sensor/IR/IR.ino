#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0xFD08F7) { // Compare with hexadecimal value directly
      Serial.println(1);
    } else {
      Serial.println(results.value, HEX);
    }
    irrecv.resume(); // Receive the next value
  }
}
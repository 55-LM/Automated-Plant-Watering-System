//This function accounts for our arduino being off by a factor of 4
float adjust_by_four(float time) {
  return time/4;
}

int pump_pin = 3;
int soil_dry_threshold = 2140; //Any measurement above this will be considered dry
int time_btwn_measurement = adjust_by_four(30000);
int watering_duration = adjust_by_four(2000);


void setup() {
  // First we want to setup our pump
  pinMode(pump_pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // Put your main code here, to run repeatedly:
  int moisture_value = analogRead(A0); //Tells our arduino to read an analog value from A0 pin
  Serial.println(moisture_value);

  if (moisture_value > soil_dry_threshold) {
    Serial.println("PUMP ON");
    digitalWrite(pump_pin, HIGH);
    delay(watering_duration);
    digitalWrite(pump_pin, LOW);
    Serial.println("PUMP OFF");
    delay(time_btwn_measurement);
  } else {
    digitalWrite(pump_pin, LOW);
    Serial.println("PUMP OFF");
  }
}

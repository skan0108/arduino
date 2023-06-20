#include <DHT.h>

//Constants
#define DHTPIN 3    // what pin we're connected to
#define DHTTYPE DHT22   // DHT22

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() 
{
  //Initialize serial port
  Serial.begin(9600);
  pinMode(2, INPUT);// gas digital-in
  pinMode(3, INPUT); // temp-hum digital-in
  pinMode(8, OUTPUT); // yellow led
  pinMode(9, OUTPUT); // green led
  pinMode(10, OUTPUT); // blue led

  //Initialize the DHT sensor
  dht.begin();  
}

void loop() 
{ 
  int sensorValue = analogRead(0); // read analog input pin 0
  int digitalValue = digitalRead(2);
  if (sensorValue > 90 || digitalValue == 1)
  {
    digitalWrite(8, HIGH);
  }
  else
    digitalWrite(8, LOW);
  Serial.print("Gas sensor: ");
  Serial.println(sensorValue, DEC); // prints the value read
  // Serial.println(digitalValue, DEC);
  
    
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();

  Serial.print("Celsius = ");
  Serial.print(temp);
  Serial.println("C");
  if(temp > 27) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

  if(hum > 50) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }


  Serial.print("Humidity =");
  Serial.println(hum);

  //2000mS delay between reads
  delay(2000);
}



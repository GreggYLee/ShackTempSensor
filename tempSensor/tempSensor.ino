//TMP36 Pin Variables
int ambientTemp = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        
int sensorPin2 = 1;
int sensorPin3 = 2;
int sensorPin4 = 3;    
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}

float getTemp(int inSensorPin)
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(inSensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
  // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  
 return (temperatureF);
}

void loop()                     // run over and over again
{
 Serial.print("ambientTemp "); 
 Serial.println(getTemp(ambientTemp)); 
 
 Serial.print("Sicon Temp "); 
 Serial.println(getTemp(sensorPin2));
 
 Serial.print("Vent Fan ");
 Serial.println(getTemp(sensorPin3)); 
 
 Serial.print("A/C ");
 Serial.println(getTemp(sensorPin4)); 
 
 Serial.println();
 delay(10000);                                     //waiting a second
}


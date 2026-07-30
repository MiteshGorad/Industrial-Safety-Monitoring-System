#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// -------------------- PINS --------------------
#define DHTPIN 2
#define DHTTYPE DHT11

#define MQ9 A0
#define BUZZER 6

// -------------------- THRESHOLDS --------------------
#define GAS_THRESHOLD 500
#define TEMP_THRESHOLD 40
#define HUM_LOW 30
#define HUM_HIGH 80
#define MOTION_THRESHOLD 15

// -------------------- OBJECTS --------------------
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_MPU6050 mpu;

void setup()
{
    Serial.begin(9600);

    dht.begin();

    lcd.begin();
    lcd.backlight();

    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);

    // MPU6050 Initialization
    if (!mpu.begin())
    {
        Serial.println("MPU6050 NOT FOUND!");
        lcd.setCursor(0, 0);
        lcd.print("MPU6050 ERROR");
        while (1);
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    lcd.setCursor(0, 0);
    lcd.print("Industrial");
    lcd.setCursor(0, 1);
    lcd.print("Safety System");

    delay(3000);
    lcd.clear();

    Serial.println("Industrial Safety Monitoring System Started");
}

void loop()
{
    // -------------------- READ SENSORS --------------------
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (isnan(temp) || isnan(hum))
    {
        Serial.println("Failed to read DHT11!");

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DHT11 ERROR");

        delay(2000);
        return;
    }

    int gasValue = analogRead(MQ9);

    sensors_event_t a, g, t;
    mpu.getEvent(&a, &g, &t);

    float totalAcc = sqrt(
        (a.acceleration.x * a.acceleration.x) +
        (a.acceleration.y * a.acceleration.y) +
        (a.acceleration.z * a.acceleration.z));

    // -------------------- ALERT CONDITIONS --------------------
    bool gasAlert = gasValue > GAS_THRESHOLD;
    bool motionAlert = totalAcc > MOTION_THRESHOLD;
    bool tempAlert = temp > TEMP_THRESHOLD;
    bool humAlert = (hum < HUM_LOW || hum > HUM_HIGH);

    bool alert = gasAlert || motionAlert || tempAlert || humAlert;

    // -------------------- BUZZER --------------------
    if (alert)
    {
        digitalWrite(BUZZER, HIGH);
    }
    else
    {
        digitalWrite(BUZZER, LOW);
    }

    // -------------------- SERIAL MONITOR --------------------
    Serial.println("\n========== SAFETY DATA ==========");

    Serial.print("Temperature : ");
    Serial.print(temp);
    Serial.println(" C");

    Serial.print("Humidity    : ");
    Serial.print(hum);
    Serial.println(" %");

    Serial.print("Gas Value   : ");
    Serial.println(gasValue);

    Serial.print("Acceleration: ");
    Serial.println(totalAcc);

    if (alert)
    {
        Serial.println("----- ALERTS -----");

        if (gasAlert)
            Serial.println("GAS LEAK DETECTED!");

        if (tempAlert)
            Serial.println("HIGH TEMPERATURE!");

        if (humAlert)
            Serial.println("HUMIDITY OUT OF RANGE!");

        if (motionAlert)
            Serial.println("MOTION / IMPACT DETECTED!");
    }
    else
    {
        Serial.println("SYSTEM STATUS: SAFE");
    }

    Serial.println("===============================");

    // -------------------- LCD DISPLAY --------------------
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print((int)temp);
    lcd.print("C ");

    lcd.print("H:");
    lcd.print((int)hum);
    lcd.print("%");

    lcd.setCursor(0, 1);

    if (gasAlert)
    {
        lcd.print("GAS ALERT!");
    }
    else if (tempAlert)
    {
        lcd.print("HIGH TEMP!");
    }
    else if (humAlert)
    {
        lcd.print("HUM ALERT!");
    }
    else if (motionAlert)
    {
        lcd.print("MOTION ALERT");
    }
    else
    {
        lcd.print("SYSTEM SAFE");
    }

    delay(2000);
}  


how to add this project in github 

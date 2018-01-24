//Add Library
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Explicit

//การกำหนดค่าคงที่
//String wifiSSID = "MastreEWTC_2.4G";
#define wifiSSID "MastreEWTC_2.4G"
#define wifiPassword "12345abcde"

#define firebaseHost "rmutsvnodemcu.firebaseio.com"
#define firebaseKey "29tXoQn9iydCSFjgCp8EvtcA4LhqLtAfRZQjQI2y"

int intIndex = 0;



void setup() {
  
//  การกำหนดช่องทางในการ Monitor
  Serial.begin(9600);

// การกำหนดข้อมูลเกี่ยวกับการเชื่อมต่อ wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiSSID, wifiPassword);
  Serial.println("Start Find WiFi");

  while (WiFi.status() != WL_CONNECTED) 
  
    {

//    ถ้า Condition True จะทำงานที่นี่
      Serial.print("#");
      delay(500);
       
    }

//    ถ้ามาทำงานตรงคื่อ Connected WiFi ได้แล้ว
    Serial.println();
    Serial.println("Success Connected WiFi");
    Serial.println(WiFi.localIP());
    

//ส่วนของการเชื่อมต่อ Firebase
    Firebase.begin(firebaseHost, firebaseKey);

  

} // setup



void loop() {

//  Serial.println("Hello Master UNG");
//  delay(2000);


//Check Conneced Firebase
Firebase.setInt("myTimes", intIndex);
if (Firebase.failed()) 
  { 
//    เมื่อก็ตามที่ไม่สามารถเข้า Firebase
      Serial.print("Cannot Connected Firebase : ");
      Serial.println(Firebase.error()); 
      return;
  }

      Serial.print("Success Connected Firebase Times ==> ");
      Serial.println(Firebase.getInt("myTimes"));

      intIndex++;
      delay(500);





  

} // loop







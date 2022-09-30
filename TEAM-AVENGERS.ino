#include <SoftwareSerial.h>
SoftwareSerial gsmSerial(8,7);
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>
#define SS_PIN 10 
#define RST_PIN 9 
MFRC522 mfrc522(SS_PIN,RST_PIN);
#include <MFRC522.h>
String NAME = "";  
String Mobile = "";  
String AIRLINE= "";  
String LUGGAGES = "";  
String notifi="";
void setup()   
{  
  
  Serial.begin(9600);   
  SPI.begin();          
  mfrc522.PCD_Init();   
  
  Serial.println();
  Serial.println();

  Serial.println();
  
}  
  
void loop()   
{  
   
       
    
    Serial.println("Enter your Name:");  
    while (Serial.available() == 0)  {}{} 
    NAME = Serial.readString();
     
    Serial.println("Enter your Moblie No:");  
    while (Serial.available() == 0) {}  
    Mobile = Serial.readString();  
    Serial.println("Your Airline:");  
    while (Serial.available() == 0) {}  
    AIRLINE = Serial.readString();  
    Serial.println("No of Luggages:");  
    while (Serial.available() == 0) {}  
    LUGGAGES = Serial.readString(); {}{}
    
    Serial.println("-------------------------");  
    Serial.println("ENTER YOUR NAME:" + NAME);  
    Serial.println("YOUR MOBILE NO:" + Mobile);  
    Serial.println("YOUR AIRLINE:" + AIRLINE);  
    Serial.println("NO OF LUGGAGES:" +  LUGGAGES); 
    while (Serial.available() == 0) {}
    while ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  while( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
    Serial.print("RFID tag :");
  String content= "";
  byte letter;
  for (byte j = 0; j < mfrc522.uid.size; j++) 
  {
     Serial.print(mfrc522.uid.uidByte[j] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[j], HEX);
     content.concat(String(mfrc522.uid.uidByte[j] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[j], HEX));
  }
  Serial.println(); 

  Serial.print("Notification : ");
  content.toUpperCase();
  if (content.substring(1) == "")
  {
    Serial.println("");
    Serial.println();
    delay(1000); 
    
 
  }
 
 else   {
    Serial.println(" ");
     while (Serial.available() == 0) {}{}
     delay(2000);
  

 
Serial.println();
    Serial.println("AT+CMGF=1"); 
    delay(1000);
    Serial.println();
    Serial.print("Sending notification"); 
     delay(2000);    
    Serial.print("\"+91XXXXXXXXXX\"");
    Serial.println();
   
    Serial.print("Your RFID issued!!");
    delay(3000);
    Serial.println();
    Serial.write(26);                
    while(1);
 }
 

 
 
 }
  
  
 
 


 

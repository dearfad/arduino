#include <SoftwareSerial.h>


#define WIFI_TX       5
#define WIFI_RX       6

SoftwareSerial wifi(WIFI_RX, WIFI_TX);   //RX, TX

String _comdata_wifi = "";             //for incoming wifi serial data

void setup() {

  Serial.begin(9600);
  wifi.begin(115200); 
  Serial.println("system is ready!");

  wifi.println("AT+CWMODE=3\r\n");
  delay(500);
  wifi.println("AT+CIPMUX=1\r\n");
  delay(500);
  wifi.println("AT+CIPSERVER=1,5000\r\n");
  delay(500);
}

void loop() {
  getWifiSerialData();
  if(Serial.available()){
    String order = "";
    while (Serial.available()){
      char cc = (char)Serial.read();
      order += cc;
      delay(2);
    }
    order.trim();
    wifi.println(order);
  }
  if(_comdata_wifi!=""){
    Serial.println(_comdata_wifi);
     Serial.println("\r\n");
//     for(int a=0;a<_comdata_wifi.length();a++)
//     {
//     Serial.println(a); 
//    Serial.println(_comdata_wifi[a]);  
//     }
if((_comdata_wifi[2]=='+')&&(_comdata_wifi[3]=='I')&&(_comdata_wifi[4]=='P'))//MCU接收到的数据为+IPD时进入判断控制0\1来使小灯亮与灭
            {
                if((_comdata_wifi[5]=='D')&&(_comdata_wifi[8]==','))
                     {   
                      if(_comdata_wifi[11]=='0')
                            {
                                  digitalWrite(LED,LOW);//0 灯灭   
                                   Serial.println("灯灭");            
wifi.println("灯灭");
//wifi模块向pc端或手机端 发送"灯灭
}

                           else if (_comdata_wifi[11]=='1')
                            {                                
                                   digitalWrite(LED,HIGH);    //1 灯亮
                                wifi.println("灯亮");  
                                Serial.println("灯亮");    
//wifi模块向pc端或手机端 发送"灯亮"            
                 }
           }   
        }      

    _comdata_wifi = String("");
  }
}

void getWifiSerialData(){
  while (wifi.available() > 0){
    _comdata_wifi += char(wifi.read());   //get wifi data
    delay(4);
  }
}


int sensor1 =10;
int sensor2 =11;
float x,y;
int i;

void setup()
{
  Serial.begin(9600);
   pinMode(sensor1,INPUT);
   pinMode(sensor2,INPUT);
   wifi_init();
}

void loop() 
{
x=digitalRead(sensor1);
y=digitalRead(sensor2);
Serial.print(x);
  if(x==0)
  {
 Serial.println("sensor1 is on");  
  }
    else if(y==0)
  {
    Serial.println("sensor2 is on");
  }
  else
  {
   Serial.println(" both are off");
  }
   i++;
 if(i>=1)
 {
  
  Serial.print("sending to server");

   sendtoserver();
   i=0;
}

}
 void sendtoserver()
{
        
                       Serial.print("sending");
                       // sensorValue = analogRead(A0);
                        //sensorValue1 =analogRead(A1);
                        serial_wifi_baud();
                        delay(100);
                        String temp="GET https://184.106.153.149/update?api_key=EC7DBA8E136YZHA9&field1=";
                     // String temp="GET https://184.106.153.149/update?api_key=V11Z1QYWSQ0JVWG9&field1=";
                             temp+=String(x);
                             temp+="&field2=";
                             temp+=String(1);//temp1
//                             temp+="&field3=";
//                             temp+=String(y);//temp1
//                           temp+="&field4=";
//                            temp+=String(A1);//temp1
                             temp+="\r\n";
                    
                             temp+="\r\n\r\n\r\n";
                      Serial.println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n");
                      delay(2000);
                      //Serial.println("AT+CIPSEND=0,"+String(temp.length()));
                       //Serial.println("\r\n");
                     
                      Serial.println("AT+CIPSEND=110\r\n");
                      delay(2000);
                      Serial.println(temp);
                      //Serial.println("GET https://184.106.153.149/update?api_key=9FUQ5PCW9XIL6A2G&field1=70&field2=90\r\n");
                      //Serial.print("GET https://184.106.153.149/update?api_key=9FUQ5PCW9XIL6A2G&field1=");
                      //Serial.print(temp); 
                       Serial.print("\r\n");
                      delay(2000);
                      Serial.println("\r\n\r\n\r\n\r\n\r\n\r\n");
                      delay(2000); 
                      delay(2000); 
                      delay(2000); 
                       delay(2000); 
                      delay(2000); 
                      delay(2000); 

                     // temp='0';

}

void wifi_init()
{
  Serial.println("wifi");
   serial_wifi_baud();
  Serial.println("AT");
  delay(2000);
  Serial.println("AT+CWMODE=1");
  delay(2000);
  Serial.println("AT+CWLAP");
  delay(2000);  delay(2000);  delay(2000);
  Serial.println("AT+CWJAP=\"NITHIN 0531\",\"NITH@123\"\r\n");     //change your user name and password here
  //Serial.println("AT+CWJAP=\"amrutha\",\"ammaappa\"\r\n");     //change your user name and password here
 
  delay(2000);
}
void serial_wifi_baud()
{
  Serial.begin(115200);
}

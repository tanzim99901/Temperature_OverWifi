void httppost ()
{
  esp.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");//start a TCP connection.

  if ( esp.find("OK")) {

    Serial.println("TCP connection ready");

  } 
  //delay(1000);

  String postRequest =

    "POST " + uri + " HTTP/1.0\r\n" +

    "Host: " + server + "\r\n" +

    "Accept: *" + "/" + "*\r\n" +

    "Content-Length: " + data.length() + "\r\n" +

    "Content-Type: application/x-www-form-urlencoded\r\n" +

    "\r\n" + data;

  String sendCmd = "AT+CIPSEND=";//determine the number of caracters to be sent.

  esp.print(sendCmd);

  esp.println(postRequest.length() );

  //delay(500);

  if (esp.find(">")) {
    Serial.println("Sending.."); esp.print(postRequest);

    if ( esp.find("SEND OK")) {
      Serial.println("Packet sent");

      while (esp.available()) {

        String tmpResp = esp.readString();

        Serial.println(tmpResp);
        received = 1;

      }
      digitalWrite(whitepin, HIGH);
      if (received)
      {
        digitalWrite(redpin, HIGH);
        delay(1000);
        digitalWrite(redpin, LOW);
        received = 0;
      }
      // close the connection

      esp.println("AT+CIPCLOSE");

    }

  }
}

//reset the esp8266 module

void reset()
{

  esp.println("AT+RST");
  delay(1000);
  if (esp.find("OK") ) Serial.println("Module Reset");
  delay(1000);
  esp.println("AT+CWMODE=3\r\n");
  if (esp.find("OK") ) Serial.println("Mode changed");
  delay(1000);

}

//connect to your wifi network

void connectWifi()
{
  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";

  esp.println(cmd);

  delay(4000);

  if (esp.find("OK")) {

    Serial.println("Connected!");
    connection = 1;
    digitalWrite(bluepin, HIGH);
  }

  else {
    Serial.println("Cannot connect to wifi");
    connection = 0;
    digitalWrite(bluepin, LOW);
  }
  if (!connection)
  {
    connectWifi();
  }
}

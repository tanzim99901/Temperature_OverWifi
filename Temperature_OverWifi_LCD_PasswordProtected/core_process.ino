void main_run()
{
  float temperature = getTemp();
  Serial.println(temperature);
  temp = temperature;
  data = "temperature=" + temp;// data sent must be under this form //name1=value1&name2=value2.
  temp = "";
  Serial.println("DATA READ");
  lcd.setCursor(6, 1);
  lcd.print(temperature);
  if (temperature >= threshold)
  {
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
    if (!temp_warn)
    {
      LCD_reset();
      LCD_hot_warn();
      delay(2000);
      temp_warn = 1;
      LCD_setup();
    }
  }
  if (temperature < threshold)
  {
    digitalWrite(greenpin, HIGH);
    digitalWrite(redpin, LOW);
    if (temp_warn)
    {
      temp_warn = 0;
      LCD_reset();
      LCD_cool_warn();
      delay(2000);
      LCD_setup();
    }
  }
  httppost();
  Serial.println("DATA SENT");
  digitalWrite(whitepin, LOW);
  
  //keypad_display();
}

void background_run()
{
  float temperature = getTemp();
  Serial.println(temperature);
  temp = temperature;
  data = "temperature=" + temp;// data sent must be under this form //name1=value1&name2=value2.
  temp = "";
  Serial.println("DATA READ");
  if (temperature >= threshold)
  {
    digitalWrite(redpin, HIGH);
    digitalWrite(greenpin, LOW);
  }
  if (temperature < threshold)
  {
    digitalWrite(greenpin, HIGH);
    digitalWrite(redpin, LOW);
  }
  httppost();
  Serial.println("DATA SENT");
  digitalWrite(whitepin, LOW);

  //keypad_display();
}

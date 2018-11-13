void check_password()
{
  lcd.setCursor(5, 1);
  while (1)
  {
    background_run();
    int j;
    char pass = myKeypad.getKey();
    if (int(pass) != 0)
    {
      Serial.print("*");
      lcd.print("*");
      if (pass == correct[currentPosition])
      {
        ++currentPosition;
        if (currentPosition == strlen(correct))
        {
          if (!wrong)
          {
            Serial.println("ACCESS GRANTED");
            currentPosition = 0;
            wrong = 0;
            access = 1;
            delay(500);
            lcd.clear();
            LCD_password();
            lcd.setCursor(4, 1);
            lcd.print("Correct!");
            delay(1000);
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("WELCOME!");
            break;
          }
          else
          {
            currentPosition = 0;
            Serial.println("ACCESS DENIED");
            wrong = 0;
            access = 0;
            delay(500);
            lcd.clear();
            LCD_password();
            lcd.setCursor(5, 1);
            lcd.print("Wrong!");
            delay(1000);
            lcd.clear();
            LCD_password();
            lcd.setCursor(5, 1);
          }
        }
      }
      else
      {
        wrong = 1;
        ++currentPosition;
        if (currentPosition == strlen(correct))
        {
          Serial.println("ACCESS DENIED");
          currentPosition = 0;
          wrong = 0;
          access = 0;
          delay(500);
          lcd.clear();
          LCD_password();
          lcd.setCursor(5, 1);
          lcd.print("Wrong!");
          delay(1000);
          lcd.clear();
          LCD_password();
          lcd.setCursor(5, 1);
        }
      }
    }
  }
}

void keypad_display()
{
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    Serial.print(keypressed);
  }
}

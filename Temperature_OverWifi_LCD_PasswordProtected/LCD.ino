void LCD_hot_warn()
{
  lcd.setCursor(5, 0);
  lcd.print("GETTING");
  lcd.setCursor(7, 1);
  lcd.print("HOT!");
}

void LCD_cool_warn()
{
  lcd.setCursor(5, 0);
  lcd.print("COOLING");
  lcd.setCursor(6, 1);
  lcd.print("DOWN!");
}

void LCD_setup()
{
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.clear(); // clear the screen
  lcd.setCursor(0, 1); // put cursor at colon 0 and row 0
  lcd.print("Temp: "); // print a text
}

void LCD_password()
{
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.clear(); // clear the screen
  lcd.setCursor(1, 0); // put cursor at colon 0 and row 0
  lcd.print("ENTER PASSWORD"); // print a text
}

void LCD_reset()
{
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  lcd.clear(); // clear the screen
}

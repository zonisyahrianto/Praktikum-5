#include<LiquidCrystal.h>
#define FOSC 16000000
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);
String dataSerial;

void initSerial(int baudrate){
  int ubrr = FOSC/16/baudrate-1;
  UBRR0H |= ubrr>>8;
  UBRR0L |= ubrr;
  UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
  UCSR0C |= (0<<UCSZ02)|(1<<UCSZ01)|(1<<UCSZ00);
  UCSR0C |= (0<<USBS0);
  UCSR0C |= (0<<UPM01)|(0<<UPM00);
  UCSR0B |= (1<<RXCIE0);
}

ISR(USART_RX_vect){
  char data = UDR0;
  if(data=='\n'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Incoming Data");
    lcd.setCursor(0,1);
    lcd.print(dataSerial);
    dataSerial = "";
  }
  else{
    if(data!='\r'){
      dataSerial += data;
    }
  }
}
void setup() {
  initSerial(9600);
  lcd.begin(16,2);
  lcd.clear();
  sei();
}

void loop() {
  
}

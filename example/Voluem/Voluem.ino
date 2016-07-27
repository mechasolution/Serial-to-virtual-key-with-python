#define PinA 2
#define PinB 3

unsigned long time = 0;
long count = 0;
long num = 0;
int color = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);



  pinMode(PinA, INPUT_PULLUP);
  pinMode(PinB, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);

  attachInterrupt(0, A, LOW);
  attachInterrupt(1, B, LOW);

  time = millis();
}

void loop()
{
  if (digitalRead(A0) == LOW) {
    while (digitalRead(A0) == LOW);
    Serial.write(0XAD);//음소거
    color = 1 - color;
  }
  if (color == 0) {//음소거 상태 LED
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  }
}

void A()
{
  if ((millis() - time) > 3)
  {
    Serial.write(0xAF);//음량 DOWN
    color = 0;
  }
  time = millis();
}

void B()
{
  if ((millis() - time) > 3)
  {
    Serial.write(0xAE);//음량 UP
    color = 0;
  }
  time = millis();
}
//[출처] 아두이노와 파이썬으로 컴퓨터 음량 조절하기 (pyserial, ctypes)|작성자 오픈랩

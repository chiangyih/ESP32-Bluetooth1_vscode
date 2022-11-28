#include <Arduino.h>
#include <BluetoothSerial.h>
BluetoothSerial BT;
char val;      // 宣告存放串列埠資料字元變數
int led=2;             //宣告led 接於 GPIO 2
void setup() 
{
  Serial.begin(115200);
  BT.begin("tsengBT");   //藍芽顯示名稱,請修改為自訂名稱
  pinMode(led , OUTPUT);     //設定 GPIO 2 為輸出 
}

void loop() 
{
  if (BT.available())  //判斷藍芽串列埠上是否有資料
  {
    val=BT.read();   //讀取串列資料，存放於val
    switch (val)
    {
      case '0':
         digitalWrite(led,LOW);
         break;
      case '1':
         digitalWrite(led,HIGH);
         break;
    }

  }
}
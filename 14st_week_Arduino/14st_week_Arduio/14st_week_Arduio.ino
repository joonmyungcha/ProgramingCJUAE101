#include<Servo.h>       //서보라이브러리 추가

#define stdAngle 90     //LED 점들을 위한 기준 각도 지정
#define numLED 2        //LED 갯수
#define Minanalog 0     //아날로그 최소값
#define Maxanalog 1023   //아날로그 최대값
#define MinAngle 0        //출력할 각도 최소
#define MaxAngle 180      //각도 최대
#define servoDelay 15     //서보모터의 딜레이
#define MaxSpeed 255      //LED 점등 속도 최대
#define MinSpeed 0        //점등 속도 최소

Servo myServo; //myServo 변수 선언

void LEDdigitalWrite(int numPin, int power, int fdelay)   //LED를 점등하는 함수
{
	digitalWrite(numPin, power);        //해당하는 핀에 출력, 입력 모드 선언
	delay(fdelay);                      //다음 함수를 fdelay동안 지연(1초=1000ms)
}

void ServoWrite(int servoangle, int fdelay)       //서보모터 작동시키는 함수
{
     myServo.write(servoangle);           //받아온 각도 값으로 서보모터에 출력
     delay(fdelay); 
}

void serialPrint(int potval, int fangle)    //시리얼 모니터에 시리얼 값 출력하는 함수
{
  Serial.print("analogValue : ");
  Serial.println(potval);
  Serial.print("Angle : ");
  Serial.println(fangle);
  Serial.print("\n");
}

int potVal;         //아날로그 값을 읽어올 변수 선언
int angle;          //서보모터 각도 변수
int RedPin = 2;     //2번 핀에 빨강 LED 연결
int BluePin = 3;    //3번 핀에 파랑 LED 연결
int PushPin = 6;    //푸쉬스위치 6번 핀에 연결
int potPin = A0;    //가변저항기 A0 핀에 연결
int aryPin[2] = {2, 3}; //2개의 LED 배열 선언 
int *paPin = aryPin;    //선언한 배열을 포인터에 대입
int Delay = 1000;   //1초동안 지연
int SpeedDelay;     //LED 점등 속도를 조절할 변수

void setup()        //전원이 들어오면 가장 먼저 한번만 실행
{
  myServo.attach(9);   //9번 핀에 서보모터 연결
  pinMode(PushPin, INPUT);  //푸쉬스위치 입력모드로 선언
  Serial.begin(9600); //초당 9600bit를 전송하도록 시리얼 통신 속도 초기화
  
  for(int i = 0; i < numLED; i++) //LED 갯수 2개까지 반복
  {
    pinMode(*(paPin + i), OUTPUT);    
    //반복문을 사용하여 앞서 선언한 포인터 출력모드로 선언
  }
}

void loop()   //함수 안의 명령을 반복해서 실행
{  
  potVal=analogRead(potPin);    //가변저항기의 아날로그 값을 읽어냄
  angle=map(potVal,Minanalog,Maxanalog,MinAngle,MaxAngle);    //아날로그 값을 0~180도로 바꿈
  serialPrint(potVal, angle); //시리얼 모니터에 아날로그값, 각도값 출력하는 함수 호출
  SpeedDelay = map(potVal, Minanalog, Maxanalog, MaxSpeed, MinSpeed);
  //가변저항기의 아날로그 값을 0~255로 바꿔줌
  if(digitalRead(PushPin) == HIGH)  //푸쉬스위치에 5V 전압이 흐를 때
  {

    if(angle <= stdAngle)   //각도 값이 90도보다 작을 때
    {
        ServoWrite(angle, servoDelay);  //서보모터를 해당 각도로 작동시키는 함수 호출
      
        LEDdigitalWrite(RedPin, HIGH, SpeedDelay);  //빨강 LED를 해당 점등속도로 점등시킴
  	  	Serial.print("RedLED:ON\n");
      
  	    LEDdigitalWrite(RedPin, LOW, SpeedDelay);
  		  Serial.print("RedLED:OFF\n");
    }
    
    else if(stdAngle < angle)   //각도 값이 90도보다 클 때
    {   
        ServoWrite(angle, servoDelay);    //서보 작동 함수 호출

   	  	LEDdigitalWrite(RedPin, HIGH, SpeedDelay);  //빨강 파랑 LED 모두 점등
  	  	Serial.print("RedLED:ON\n");                //아날로그 값이 커질수록 점등속도 빨라짐
		    LEDdigitalWrite(RedPin, LOW, SpeedDelay); 
  	  	Serial.print("RedLED:OFF\n");
      
   	  	LEDdigitalWrite(BluePin, HIGH, SpeedDelay);
  	  	Serial.print("BluePin:ON\n");
	    	LEDdigitalWrite(BluePin, LOW, SpeedDelay); 
  	  	Serial.print("BluePin:OFF\n");
    } 
  }
  
   else
  {
  	Serial.print("Switch : OFF\n");     //푸쉬스위치에 0V 전압이 흐를 때 
 	  delay(Delay);                        //시리얼 모니터에 스위치 off 출력
  }
}
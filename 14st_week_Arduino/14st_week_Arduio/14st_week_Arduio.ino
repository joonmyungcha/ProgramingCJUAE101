#include <LiquidCrystal.h>		//lcd를 사용하기 위한 라이브러리
#include <Servo.h>				//서보라이브러리

#define led_num 2				//LED 개수 2개
#define Minanalog 0				//아날로그 최소값
#define Maxanalog 1023			//아날로그 최대값
#define lcd_row 2				//lcd의 행 개수
#define lcd_column 16			//lcd의 열 개수
#define Minlight 0 				//변환할 밝기 최소값
#define Maxlight 255			//밝기 최대값
#define Distance_crosswalk 300	//횡단보도의 길이
#define One_second 1000			//1초
#define Maxservo 90				//서보모터 회전 최대 각도
#define Minservo 0				//최소 각도
#define Max_char 80


LiquidCrystal lcd(12, 11, 7, 6, 5, 4); //lcd 핀 번호 입력해줌
Servo myServo;	//myservo 변수 선언
extern volatile unsigned long timer0_millis; //millis() 리셋하기 위해 변수 선언

int greenPin = 2;
int redPin = 3;
int aryPin[2] = {2, 3};					//LED 핀 배열로 묶음
int *ledPin = aryPin;					//LED 배열을 포인터에 대입
int dis_Sensor = 13;					//초음파 센서 13번 핀
int led_Sensor = A0;					//조도센서 아날로그 값 받아오기 위한 A0 핀
int servoPin = 9;						//서보모터 9번핀
struct Serial_message {					//시리얼 모니터에 출력할 문자
	char ch1[Max_char];						//문자열 변수를 구조체로 묶어서 선언해줌
	char ch2[Max_char];
	char ch3[Max_char];
	char ch4[Max_char];
	char ch5[Max_char];
	char ch6[Max_char];
	};
struct Serial_message message{			//선언한 구조체 문자열 초기화
  	"You can't go.\n",
  	"Move the motor to degree 90.\n",
  	"People is moving now.\n",
  	"You can go.\n",
  	"Move the motor to degree 0.\n",
  	"People is not moving now.\n"
	};

void LEDWrite(int Red, int Green, int power, int nlight);//횡단보도에 사람의 존재 유무에 따른 LED 점등
														 //밤에 빛이 없을 때 밝게 빛나고 낮에는 꺼지는 LED 조도센서 활용
void Serial_Print_message1(struct Serial_message *mes);	 //시리얼 모니터네 문자열 구조체 출력 함수
void Serial_Print_message2(struct Serial_message *mes);



void setup()
{
  for(int i=0; i<led_num; i++)			//LED 핀의 포인터에 반복문을 사용하여
  {
    pinMode(*(ledPin + i), OUTPUT);		//핀번호와 출력모드 선언
  }
  pinMode(led_Sensor, INPUT);			//조도센서 핀번호 입력모드 선언
  
  lcd.begin(lcd_column, lcd_row);		//lcd는 16*2 칸임
  lcd.print("CrossWalk");				//0,0에 문자 출력
 
  myServo.attach(servoPin);				//서보모터 해당 핀에 연결
  
  Serial.begin(9600);					//초당 9600bit를 전송하도록 시리얼 통신 속도 초기화
}




void loop()
{	//초음파 신호 전송
  pinMode(dis_Sensor, OUTPUT);			//초음파센서 핀번호와 출력하기 위한 출력모드
  digitalWrite(dis_Sensor, LOW);		//9번을 low로 변경
  delayMicroseconds(2);					//2 microsecond 간 지연시키고(초기화 함수)
  digitalWrite(dis_Sensor, HIGH);		//다시 high로 변경, 이 때 트리거링이 시작됨
  delayMicroseconds(5);					//8개 소닉 버스트 발생하는 동안 시간 5 microsecond 간 지연
  digitalWrite(dis_Sensor, LOW);		//high 신호에서 low 신호로 변경
  	//초음파 신호 수신
  pinMode(dis_Sensor, INPUT);			//핀모드 변경, 수신하기 위한 입력모드로 변경
  double duration = pulseIn(dis_Sensor, HIGH);	//pulsin 함수:high에서 low, low에서 high로 바뀌는 시점까지의 타이밍을 잼
  double distance = duration * 340/ 10000/ 2;	//거리는 cm 단위로 바꿈, 거리 구하는 공식 대입
  
  int light = analogRead(led_Sensor);		//조도센서 아날로그 값으로 받아옴
  int ledlight = map(light, Minanalog, Maxanalog, Maxlight, Minlight);
 										    //조도센서의 아날로그 값을 0부터 255의 값으로 바꾸어줌
  if(distance < Distance_crosswalk)
  { 									 //초음파 센서가 인식한 위치가 횡단보도 길이보다 짧게 있을 때
   										 //즉 사람이 신호등을 건널 때
    lcd.setCursor(0,1);					 //lcd 다음 열 0,1에 Moving 출력
    lcd.print("STOP!!!");
    lcd.setCursor(8,1);					 //lcd 8,1에  
    lcd.print(millis()/One_second);		 //1초 단위로 바뀔 때마다 숫자 하나씩 증가
   										 //1000밀리초가 1초이므로 1000으로 나누어 1초 단위로 출력
    lcd.setCursor(9,1);					 //초 다음 s 단위 출력
    lcd.print(" s");
    
    LEDWrite(redPin, greenPin, LOW, ledlight);	//빨강LED 점등 함수
   
    myServo.write(Maxservo);		 	 //서보모터가 90도로 회전하여 차를 막음
    Serial_Print_message1(&message); 	 //시리얼 모니터 출력 함수
  }
  else									 //초음파 센서가 인식한 위치가 횡단보도 밖에 있을 때
  {
    lcd.setCursor(0,1);	
    lcd.print("No one. Go!");			 //lcd 2열에 Go 명령 출력
    
    LEDWrite(greenPin, redPin, LOW, ledlight);	//초록 LED 점등 함수
    
    myServo.write(Minservo);			 //서보모터가 0도로 돌아 차가 통행하게 함
   
    Serial_Print_message2(&message); 	 //시리얼 모니터 출력 함수
    timer0_millis = 0;					 //사람이 다 지나가면
   										 //timer0_millis 0으로 만들어 millis 초기화
  }
}



void LEDWrite(int Pin1, int Pin2, int power, int nlight)	//LED 점등 함수 정의
{
    analogWrite(Pin1, nlight);			//0~255로 바꾼 신호를 Pin1에 점등하여 밝기 조절
    digitalWrite(Pin2, power);			//다른 LED는 끔
}
void Serial_Print_message1(struct Serial_message *mes)		//구조체의 주소를 포인터에 넣어 함수 정의
{
    Serial.print(mes -> ch1);			//연산자를 통하여 포인터의 구조체 문자열 변수에 접근 후 출력
    Serial.print(mes -> ch2);
    Serial.print(mes -> ch3);  
    delay(One_second);					//1초 지연
    Serial.println(millis()/One_second);//1초 단위로 증가하며 출력
}
void Serial_Print_message2(struct Serial_message *mes)
{
    Serial.print(mes -> ch4);
    Serial.print(mes -> ch5);
    Serial.print(mes -> ch6);  
    delay(One_second);
}
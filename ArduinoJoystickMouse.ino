// JOYSTICKS @ ARDUINO SETUP

// 2° Joystick (right)
#define LEFT_CLICK A4     // SW
#define ANALOG_1_MOUSE A0 // VRy
#define ANALOG_2_MOUSE A1 // VRx
// +5v connected to pin 5V
// GND connected to one Arduino's GND

// 1° Joystick (left)
#define RIGHT_CLICK A5      // SW
#define ANALOG_1_SCROLL A2  // VRy
#define ANALOG_2_SCROLL A3  // VRx
#define HIGH_SCROLL 7       // +5v
// GND connected to the other Arduino's GND


void setup() {

  Serial.begin(9600);

  // 1° Joystick
  pinMode(LEFT_CLICK,INPUT);
  digitalWrite(LEFT_CLICK,HIGH);

  // 2° Joystick
  pinMode(RIGHT_CLICK,INPUT);
  digitalWrite(RIGHT_CLICK,HIGH);
  pinMode(HIGH_SCROLL, OUTPUT);
  digitalWrite(HIGH_SCROLL, HIGH);
};

void loop() {

  // MOUSE
  int z=0,xpos=0,ypos=0;
  int x=analogRead(ANALOG_1_MOUSE);
  int y=analogRead(ANALOG_2_MOUSE);
  int sensitivity=120;    // you can adjust the sensitivity

  if(x>=550)                     // when moved up 
    xpos=map(x,550,1023,0,sensitivity); 
  if(x<=450)                   // when moved down
    xpos=map(x,450,0,0,-sensitivity);   
  if(y>=550)                    // when moved right
    ypos=map(y,550,1023,0,sensitivity);  
  if(y<=450)                  // when moved left
    ypos=map(y,450,0,0,-sensitivity); 
  if(digitalRead(LEFT_CLICK)==LOW)   // when SW is pressed 
    z=1;
  else
    z=0;
  if(xpos!=0 or ypos!=0 or z==1){ // prints only when the joystick is moved or pressed
    Serial.print(xpos);    // print the data and separating by ":"
    Serial.print(":");
    Serial.print(ypos);
    Serial.print(":");
    Serial.println(z);
  }

  // SCROLL
  int x1=analogRead(ANALOG_1_SCROLL);
  int y1=analogRead(ANALOG_2_SCROLL);


  if(x1>=550)
    Serial.print("RIGHT\n");
  if(x1<=450)
    Serial.print("LEFT\n"); 
  if(y1>=550)
    Serial.print("UP\n");
  if(y1<=450)
    Serial.print("DOWN\n");

  if(digitalRead(RIGHT_CLICK)==LOW)
    Serial.print("RIGHT_CLICK\n");

  delay(100);
};

// JOYSTICKS @ ARDUINO SETUP

// 1° Joystick
#define CLICK_IZQUIERDO 9 // SW
#define ANALOG_1_MOUSE A0 // VRy
#define ANALOG_2_MOUSE A1 // VRx
// +5v connected to pin 5V
// GND connected to one Arduino's GND

// 2° Joystick
#define CLICK_DERECHO 10     // SW
#define ANALOG_1_SCROLL A2  // VRy
#define ANALOG_2_SCROLL A3  // VRx
#define HIGH_SCROLL 7       // +5v
// GND connected to the other Arduino's GND


void setup() {

  Serial.begin(9600);

  // 1er joystick
  pinMode(CLICK_IZQUIERDO,INPUT);
  digitalWrite(CLICK_IZQUIERDO,HIGH);

  // 2ndo Joystick
  pinMode(CLICK_DERECHO,INPUT);
  digitalWrite(CLICK_DERECHO,HIGH);
  pinMode(HIGH_SCROLL, OUTPUT);
  digitalWrite(HIGH_SCROLL, HIGH);


}

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
  if(digitalRead(9)==LOW)   // when SW is pressed 
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
    Serial.print("DERECHA\n");
  if(x1<=450)
    Serial.print("IZQUIERDA\n"); 
  if(y1>=550)
    Serial.print("ARRIBA\n");
  if(y1<=450)
    Serial.print("ABAJO\n");

  if(digitalRead(CLICK_DERECHO)==LOW)
    Serial.print("CLICK\n");

  delay(100);
}
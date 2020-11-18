import pyautogui, sys
import time 
import serial

# INSTALL DEPENDENCIES:
# pip install pyautogui
# pip install pyserial

pyautogui.FAILSAFE=False
ArduinoSerial=serial.Serial('/dev/ttyACM0',9600) # May change
time.sleep(1)

print("Presiona Ctrl+c para salir\n")

while True:
   try:
      data=str(ArduinoSerial.readline().decode('ascii'))  # read the data
      print(data)

      if data[0].isdigit() or data[0] == "-":
         # If mouse joystick was used, data sent are x-y positions in digits (±)

         (x,y,z)=data.split(":")           # assigns to x,y and z
         (X,Y)=pyautogui.position()        # read the cursor's current position
         x=int(x)                          # convert to int
         y=int(y)
         pyautogui.moveTo(X+x,Y-y)           # move cursor to desired position
         if '1' in z:                        # read the Status of LEFT_CLICK
            pyautogui.click(button="left")    # clicks left button

      else:
         if "UP" in data:
            pyautogui.scroll(5)   # scroll up 10 "clicks"
         elif "DOWN" in data:
            pyautogui.scroll(-5)   # scroll down 10 "clicks"
         elif "RIGHT" in data:
            pyautogui.hscroll(5)   # scroll right 10 "clicks"
         elif "LEFT" in data:
            pyautogui.hscroll(-5)   # scroll left 10 "clicks"

         elif "RIGHT_CLICK" in data:
            pyautogui.click(button="right")    # clicks right button
   except KeyboardInterrupt:
      print("\nAdiós\n")
      exit()

import pyautogui, sys
import time 
import serial

# INSTALL DEPENDENCIES:
# pip install pyautogui
# pip install pyserial

pyautogui.FAILSAFE=False
ArduinoSerial=serial.Serial('/dev/ttyACM0',9600) # May change
time.sleep(1)

while True:
   data=str(ArduinoSerial.readline().decode('ascii'))   #read the data

   if data[0].isdigit() or data[0] == "-":
      # Si se movió el cursero se envían las coordenadas en dígitos y ":"

      (x,y,z)=data.split(":")           # assigns to x,y and z
      (X,Y)=pyautogui.position()        #read the cursor's current position
      x=int(x)                           #convert to int
      y=int(y)
      pyautogui.moveTo(X+x,Y-y)           #move cursor to desired position
      if '1' in z:                        # read the Status of SW
         pyautogui.click(button="left")    # clicks left button

   else:
      if "ARRIBA" in data:
         pyautogui.scroll(5)   # scroll up 10 "clicks"
      elif "ABAJO" in data:
         pyautogui.scroll(-5)   # scroll down 10 "clicks"
      elif "DERECHA" in data:
         pyautogui.hscroll(5)   # scroll right 10 "clicks"
      elif "IZQUIERDA" in data:
         pyautogui.hscroll(-5)   # scroll left 10 "clicks"

      elif "CLICK" in data:
         pyautogui.click(button="right")    # clicks right button

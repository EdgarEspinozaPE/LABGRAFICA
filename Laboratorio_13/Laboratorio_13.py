import cv2 as cv
import numpy as np

image=cv.imread('parque1.jpg')
#ejercicio 1
image_rgb=cv.cvtColor(image,cv.COLOR_BGR2RGB)
cv.imshow('RGB',image_rgb)

#ejercicio 2
imagerotated = cv.rotate(image, cv.ROTATE_90_CLOCKWISE)
cv.imshow('imagen_rotada',imagerotated) 

#ejercicio 3
image_modified01=cv.imread('parque1.jpg')
#settings
radio = 45
font = cv.FONT_HERSHEY_SIMPLEX
fontScale = 0.7

image_modified01=cv.circle(image_modified01, (295,125), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (290,180), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (490,180), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (490,115), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (260,440), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (260,500), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (780,650), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'perro', (780,590), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (590,225), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (590,300), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (730,160), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (730,100), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified01=cv.circle(image_modified01, (850,190), radio, (255,0,0), 2)
image_modified01=cv.putText(image_modified01, 'humano', (850,130), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

cv.imshow('image_modifica01',image_modified01)

#ejercicio4
image_modified02=cv.imread('parque1.jpg')
#settings
penta1 = np.array([[[235,130],[295,70],[355,130],[315,180],[275,180]]], np.int32)
penta2 = np.array([[[430,185],[490,135],[550,185],[510,235],[470,235]]], np.int32)
penta3 = np.array([[[200,445],[265,395],[320,445],[280,495],[240,495]]], np.int32)
penta4 = np.array([[[720,650],[780,600],[840,650],[800,700],[760,700]]], np.int32)
penta5 = np.array([[[530,225],[590,175],[650,225],[610,275],[570,275]]], np.int32)
penta6 = np.array([[[670,160],[730,110],[790,160],[750,210],[710,210]]], np.int32)
penta7 = np.array([[[790,190],[850,140],[910,190],[870,240],[830,240]]], np.int32)

image_modified02 = cv.polylines(image_modified02, [penta1], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (290,180), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta2], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (490,115), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta3], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (260,500), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta4], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'perro', (780,590), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta5], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (590,300), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta6], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (730,100), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

image_modified02 = cv.polylines(image_modified02, [penta7], True, (255,0,0),2)
image_modified02=cv.putText(image_modified02, 'humano', (850,130), font,fontScale, (0,0,255), 2 , cv.LINE_AA)

cv.imshow('image_modifica02',image_modified02)

#ejercicio 5
imagedrawed1 = cv.imread('parque1.jpg')

option = 1
def drawshapes(event, x, y, flags, parameter):
    if option == 1:
        if event == cv.EVENT_LBUTTONDOWN: 
            cv.circle(imagedrawed1, (x, y), 40, (150, 180, 255), 2)
        
        elif event == cv.EVENT_RBUTTONDOWN: 
            cv.rectangle(imagedrawed1, (x, y), (x+60, y+60), (255, 105, 89), 2)

        elif event == cv.EVENT_MBUTTONDOWN: 
            
            triangle = np.array([[(x, y), (x+40, y+40), (x-40, y+40)]], dtype=np.int32) 
            triangle = triangle.reshape((-1, 1, 2)) 
            cv.polylines(imagedrawed1, [triangle], True, (240, 180, 75), 2) 
    
    elif option == 2:
        if event == cv.EVENT_LBUTTONDOWN: 
            cv.circle(imagedrawed1, (x-10, y-10), 40, (160, 47, 7 ), -1)
        
        elif event == cv.EVENT_RBUTTONDOWN:
            cv.rectangle(imagedrawed1, (x, y), (x+50, y+50), (160, 255, 205 ), -1)       
         
cv.namedWindow(winname='imagen_dibujos01') 
cv.setMouseCallback('imagen_dibujos01', drawshapes) 

#ejercicio 6    
imagedrawed2 = cv.imread('parque1.jpg')
drawing = False
xvalue = 0
yvalue = 0

def draw(event,x,y,label,parameters):
    global drawing ,xvalue,yvalue
    if event == cv.EVENT_LBUTTONDOWN:
        drawing=True
        xvalue = x
        yvalue = y
    elif event == cv.EVENT_MOUSEMOVE:
        if drawing:
            cv.rectangle(imagedrawed2,(xvalue,yvalue),(x,y),(255,0,0),-1)
    elif event == cv.EVENT_LBUTTONUP:
        drawing=False
        cv.rectangle(imagedrawed2,(xvalue,yvalue),(x,y),(255,0,0),-1)

cv.namedWindow(winname='imagen_dibujos02')
cv.setMouseCallback('imagen_dibujos02',draw)

#Compilacion del ejercicio 5 y 6
while True:
    cv.imshow('imagen_dibujos01', imagedrawed1)
    cv.imshow('imagen_dibujos02',imagedrawed2)

    clave = cv.waitKey(1) & 0xFF
    if clave == ord('1'):
        option = 1
    
    elif clave == ord('2'):
        option = 2 
        
    elif clave == ord('g'):
        break

cv.waitKey(0)
cv.destroyAllWindows()

'''
face_cascade = cv.CascadeClassifier('haarcascade_frontalface_default.xml')
faces = face_cascade.detectMultiScale(gray,1.1,4)
for(x,y,w,h) in faces:
    cv.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)
    cv.circle(image,)
'''
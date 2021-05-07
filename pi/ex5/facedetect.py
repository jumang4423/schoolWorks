import cv2
faceCascade = cv2.CascadeClassifier('.opencv-master/data/haarcascades/haarcascade_frontalface_default.xml')

img = cv2.imread('face.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
faces = faceCascade.detectMultiScale(gray)
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
cv2.imwrite('detected.jpg', img)

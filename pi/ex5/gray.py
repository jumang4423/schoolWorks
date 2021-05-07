import cv2
img = cv2.imread("ex5_1.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
cv2.imwrite("ex5_1_gray.jpg",gray)

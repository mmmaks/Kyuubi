import cv2
import numpy as np

def rectify(h):
	h = h.reshape((4,2))
	hnew = np.zeros((4,2),dtype = np.float32)

	add = h.sum(1)
	hnew[0] = h[np.argmin(add)]
	hnew[2] = h[np.argmax(add)]
	 
	diff = np.diff(h,axis = 1)
	hnew[1] = h[np.argmin(diff)]
	hnew[3] = h[np.argmax(diff)]

	return hnew

while(1):

	img = cv2.imread('img.jpg')
	tempImg = img
	imgray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
	temp = cv2.GaussianBlur(imgray,(5,5),0)
	thresh = cv2.adaptiveThreshold(temp, 255, 1, 1, 11, 2)
    
	im2, contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

	biggest = None
	max_area = 0
	for i in contours:
		area = cv2.contourArea(i)
		if area > 100:
			peri = cv2.arcLength(i,True)
			approx = cv2.approxPolyDP(i,0.02*peri,True)
			if area > max_area and len(approx)==4:
				biggest = approx
				max_area = area
    
	
	xx = 0

	for i in contours:
		area = cv2.contourArea(i)
		xx += 1
		if area == max_area:
			cv2.drawContours(tempImg, contours, xx-1, (0, 255, 0), 1)
			break

	biggest = rectify(biggest)
	h = np.array([ [0,0],[449,0],[449,449],[0,449] ],np.float32)

	retval = cv2.getPerspectiveTransform(biggest, h)
	warp = cv2.warpPerspective(imgray,retval,(450,450))

	cv2.imshow('frame', warp)
	cv2.imwrite('digitOnly.jpg', warp)
	k = cv2.waitKey(5) & 0xFF
	if k == 27:
		break

for i in biggest:
	print i
cv2.destroyAllWindows()


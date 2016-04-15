import numpy as np
import cv2

cap = cv2.VideoCapture(0)

LeftUpX = 150
LeftUpY = 100

RightDownX = 420
RightDownY = 370

while(True):
	# Capture frame-by-frame
	ret, frame = cap.read()

	# Display the resulting frame
	frame = cv2.flip(frame, 1)

	#drawing rectangle
	cv2.rectangle(frame,(LeftUpX, LeftUpY), (RightDownX, RightDownY), (0, 0, 0), 1)

	#drawing vertical lines
	cv2.line(frame, (LeftUpX + (-LeftUpX + RightDownX) / 3, LeftUpY), (LeftUpX + (-LeftUpX + RightDownX) / 3, RightDownY), (0, 0, 0), 1)
	cv2.line(frame, (LeftUpX + 2 * (-LeftUpX + RightDownX) / 3, LeftUpY), (LeftUpX + 2 * (-LeftUpX + RightDownX) / 3, RightDownY), (0, 0, 0), 1)

	#drawing horizontal lines
	cv2.line(frame, (LeftUpX, LeftUpY + (-LeftUpY + RightDownY) / 3), (RightDownX, LeftUpY + (-LeftUpY + RightDownY) / 3), (0, 0, 0), 1)
	cv2.line(frame, (LeftUpX, LeftUpY + 2 * (-LeftUpY + RightDownY) / 3), (RightDownX, LeftUpY + 2 * (-LeftUpY + RightDownY) / 3), (0, 0, 0), 1)
	#frame = frame[LeftUpY:RightDownY, LeftUpX:RightDownX]
	cv2.imshow('frame', frame)

	#saving all 9 blocks
	#First row
	img0 = frame[LeftUpY:(LeftUpY + (-LeftUpY + RightDownY) / 3), LeftUpX:(LeftUpX + (-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img0_0.jpg", img0)
	img1 = frame[LeftUpY:(LeftUpY + (-LeftUpY + RightDownY) / 3), (LeftUpX + (-LeftUpX + RightDownX) / 3):(LeftUpX + 2*(-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img0_1.jpg", img1)
	img2 = frame[LeftUpY:(LeftUpY + (-LeftUpY + RightDownY) / 3), (LeftUpX + 2*(-LeftUpX + RightDownX) / 3):RightDownX]
	cv2.imwrite("images/img0_2.jpg", img2)

	#Second row
	img3 = frame[(LeftUpY + (-LeftUpY + RightDownY) / 3):(LeftUpY + 2*(-LeftUpY + RightDownY) / 3), LeftUpX:(LeftUpX + (-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img1_0.jpg", img3)
	img4 = frame[(LeftUpY + (-LeftUpY + RightDownY) / 3):(LeftUpY + 2*(-LeftUpY + RightDownY) / 3), (LeftUpX + (-LeftUpX + RightDownX) / 3):(LeftUpX + 2*(-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img1_1.jpg", img4)
	img5 = frame[(LeftUpY + (-LeftUpY + RightDownY) / 3):(LeftUpY + 2*(-LeftUpY + RightDownY) / 3), (LeftUpX + 2*(-LeftUpX + RightDownX) / 3):RightDownX]
	cv2.imwrite("images/img1_2.jpg", img5)

	#Third row
	img6 = frame[(LeftUpY + 2*(-LeftUpY + RightDownY) / 3):RightDownY, LeftUpX:(LeftUpX + (-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img2_0.jpg", img6)
	img7 = frame[(LeftUpY + 2*(-LeftUpY + RightDownY) / 3):RightDownY, (LeftUpX + (-LeftUpX + RightDownX) / 3):(LeftUpX + 2*(-LeftUpX + RightDownX) / 3)]
	cv2.imwrite("images/img2_1.jpg", img7)
	img8 = frame[(LeftUpY + 2*(-LeftUpY + RightDownY) / 3):RightDownY, (LeftUpX + 2*(-LeftUpX + RightDownX) / 3):RightDownX]
	cv2.imwrite("images/img2_2.jpg", img8)

	if cv2.waitKey(1) & 0xFF == ord('q'):
		break


# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()

color0 = 0
color1 = 0
color2 = 0
img0 = cv2.imread('images/img0_0.jpg')
height, width, depth = img0.shape

hc = height / 2
wc = width / 2

YUpper = hc + 5
YLower = hc - 5

XUpper = wc + 5
XLower = wc - 5

# print XLower, " ",XUpper, " ", YLower, " ", YUpper


# print height
# print width
# print depth
# print img0.size
for i in range(XLower, XUpper):
	for j in range(YLower, YUpper):
		# print i," ",j
		color0 += img0[i, j, 0]
		color1 += img0[i, j, 1]
		color2 += img0[i, j, 2]

color0 /= (100)
color1 /= (100)
color2 /= (100)

# print img0[10, 10, 0]
# print img0[10, 10, 1]
# print img0[10, 10, 2]
print color0
print color1
print color2

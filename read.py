import numpy as np
import cv2

cap = cv2.VideoCapture(0)

LeftUpX = 150
LeftUpY = 100

unitD = 90

BLACK = (0,0,0)

RightDownX = 420
RightDownY = 370

pointsMatrix = [[(0,0) for i in xrange(0,4)] for i in xrange(0,4)]

pointsMatrix[0][0] = (LeftUpX,LeftUpY)

for i in xrange(0,4):
	for j in xrange(0,4):
		if i == 0 and j == 0:
			continue
		if j != 0:
			pointsMatrix[i][j] = (pointsMatrix[i][j - 1][0] + unitD, pointsMatrix[i][j - 1][1])
		else:
			pointsMatrix[i][j] = (pointsMatrix[i - 1][j][0] , pointsMatrix[i - 1][j][1] + unitD)

while(True):
	# Capture frame-by-frame
	ret, frame = cap.read()

	# Display the resulting frame
	frame = cv2.flip(frame, 1)

	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[0][i]), (pointsMatrix[3][i]), BLACK, 1)

	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[i][0]), (pointsMatrix[i][3]), BLACK, 1)

	cv2.imshow('frame', frame)

	for i in xrange(3):
		for j in xrange(3):
			img = frame[pointsMatrix[i][j][1]:pointsMatrix[i + 1][j + 1][1] , pointsMatrix[i][j][0]:pointsMatrix[i + 1][j + 1][0] ]
			cv2.imwrite("images/img"+str(i)+str(j)+".jpg", img)

	if cv2.waitKey(1) & 0xFF == ord('q'):
		break


# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()

color0 = 0
color1 = 0
color2 = 0
img0 = cv2.imread('images/img00.jpg')
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

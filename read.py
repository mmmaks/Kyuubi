import numpy as np
import cv2

cap = cv2.VideoCapture(0)

OFFSET = 5
LIMIT = 3

LeftUpX = 150
LeftUpY = 100

unitD = 90

BLACK = (0,0,0)

RightDownX = 420
RightDownY = 370

pointsMatrix = [[(0,0) for i in xrange(0,4)] for i in xrange(0,4)]
colorMatrix = [[[0,0,0] for i in xrange(0,4)] for i in xrange(0,4)]

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

	if cv2.waitKey(1) & 0xFF == ord('q'):
		for i in xrange(3):
			for j in xrange(3):
				img = frame[pointsMatrix[i][j][1]:pointsMatrix[i + 1][j + 1][1] , pointsMatrix[i][j][0]:pointsMatrix[i + 1][j + 1][0] ]
				cv2.imwrite("images/img"+str(i)+str(j)+".jpg", img)
				height, width, depth = img.shape

				hc = height / 2
				wc = width / 2

				YUpper = hc + OFFSET
				YLower = hc - OFFSET

				XUpper = wc + OFFSET
				XLower = wc - OFFSET

				color = [0 for loop1 in xrange(3)]

				for loop1 in range(XLower, XUpper):
					for loop2 in range(YLower, YUpper):
						for loop3 in xrange(3):
							color[loop3] += img[loop1, loop2, loop3]

				for loop1 in xrange(3):
					color[loop1] /= ( (2 * OFFSET) ** 2 ) * 1.0

				colorMatrix[i][j] = color

		break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()





# Detecting colors
color = ['Blue', 'Green', 'Orange', 'Red', 'White', 'Yellow']

bgrColor = {}

for clr in color:
	colorName = 'colors/' + clr + '.txt'
	f = open(colorName, 'r');
	#print clr
	value = []
	for line in f:
		line = line.replace('[', "")
		line = line.replace(']', "")
		line = line.split(', ')
		B = float(line[0])
		G = float(line[1])
		R = float(line[2])
		#print B,' ',G,' ',R
		value.append( (B, G, R) )
	bgrColor[clr] = value

# for clr in color:
# 	print clr
# 	for val in bgrColor[clr]:
		

for loop1 in xrange(LIMIT):
	for loop2 in xrange(LIMIT):
		minDiff = 11111111111111111
		blockColor = ""
		for clr in color:
			orgColor = colorMatrix[loop1][loop2]
			temp = 0
			for val in bgrColor[clr]:
				temp += abs(orgColor[0] - val[0])
				temp += abs(orgColor[1] - val[1])
				temp += abs(orgColor[2] - val[2])
			if temp < minDiff:
				minDiff = temp
				blockColor = clr
		print blockColor
	print ""

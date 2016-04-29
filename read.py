""" Takes each frame as input using webcam and for each block taking mean value of the BGR values, then compared with the recalculated data set, one having minimum difference with the current block willl be assigned that color """

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


# saving color values of the 
colorFaces = ['Blue', 'Green', 'Orange', 'Red', 'White', 'Yellow']

# in bgrColor bgr value of each color is saved using pre-calculated values
bgrColor = {}
for clr in colorFaces:
	colorName = 'colors/' + clr + '.txt'
	f = open(colorName, 'r');
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



# saving points of the matrix for the cube
for i in xrange(0,4):
	for j in xrange(0,4):
		if i == 0 and j == 0:
			continue
		if j != 0:
			pointsMatrix[i][j] = (pointsMatrix[i][j - 1][0] + unitD, pointsMatrix[i][j - 1][1])
		else:
			pointsMatrix[i][j] = (pointsMatrix[i - 1][j][0] , pointsMatrix[i - 1][j][1] + unitD)

countFaces = 0

# erase colors already saved in allFacesColors.txt
# with open('allFacesColors.txt', 'w') as fl:
# 	fl.write("")
with open('Algorithm/inp', 'w') as fl:
	fl.write("")

while(True):
	# Capture frame-by-frame
	ret, frame = cap.read()

	# flipping each frame horizontally
	frame = cv2.flip(frame, 1)

	# drawing the rectangle
	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[0][i]), (pointsMatrix[3][i]), BLACK, 1)
	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[i][0]), (pointsMatrix[i][3]), BLACK, 1)

	faceColors = [ ["NULL" for i in xrange(3)] for i in xrange(3)]

	for i in xrange(3):
		for j in xrange(3):

			# img contains each block
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

			# taking average of RGB values of each bock
			for loop1 in range(XLower, XUpper):
				for loop2 in range(YLower, YUpper):
					for loop3 in xrange(3):
						color[loop3] += img[loop1, loop2, loop3]

			for loop1 in xrange(3):
				color[loop1] /= ( (2 * OFFSET) ** 2 ) * 1.0

			colorMatrix[i][j] = color

			# initializing minDiff with one infinite value
			minDiff = 11111111111111111
			blockColor = ""
			for clr in colorFaces:
				orgColor = colorMatrix[i][j]
				temp = 0
				for val in bgrColor[clr]:
					temp += abs(orgColor[0] - val[0])
					temp += abs(orgColor[1] - val[1])
					temp += abs(orgColor[2] - val[2])
				if temp < minDiff:
					minDiff = temp
					blockColor = clr
			#print blockColor
			faceColors[i][j] = blockColor
			#print faceColors[i][j], ' ', i, ' ', j
			cv2.putText(frame, blockColor, (pointsMatrix[i][j][0] + 20, pointsMatrix[i][j][1] + 50), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,255,255),1)


	cv2.imshow('frame', frame)

	if cv2.waitKey(1) & 0xFF == ord(' '):
		# saving colors of each face to 
		# with open('allFacesColors.txt', 'a') as fl:
		with open('Algorithm/inp', 'a') as fl:
			for ii in xrange(3):
				for jj in xrange(3):
					fl.write(faceColors[ii][2-jj][0].lower())
					#print faceColors[ii][jj], ' ', ii, ' ', jj
					#print "mm"
					fl.write(' ')
				fl.write('\n')
				#print ""
			###fl.write('\n\n')
		countFaces += 1
		if countFaces == 6:
			break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()


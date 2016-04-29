""" This module takes images of the six faces of the solved cube and saves mean value of BGR value of each color """


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

color = ['Blue', 'Red', 'Yellow', 'Orange', 'White', 'Green']
countFaces = 0;
ind = 0

pointsMatrix[0][0] = (LeftUpX,LeftUpY)

# saving points of the matrix for the cube
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

	# flipping each frame horizontal wise
	frame = cv2.flip(frame, 1)

	# drawing the rectangle
	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[0][i]), (pointsMatrix[3][i]), BLACK, 1)
	for i in xrange(0,4):
		cv2.line(frame, (pointsMatrix[i][0]), (pointsMatrix[i][3]), BLACK, 1)

	# showing frame
	cv2.imshow('frame', frame)

	# if key 'space' is pressed
	if cv2.waitKey(1) & 0xFF == ord(' '):

		# colorpath for saving mean value of BGR for each color
		colorPath = 'colors/' + color[countFaces] + '.txt'
		with open(colorPath, 'w') as cp:
			cp.write("")
		countFaces += 1
		for i in xrange(3):
			for j in xrange(3):

				# saving each block image to images directory 
				img = frame[pointsMatrix[i][j][1]:pointsMatrix[i + 1][j + 1][1] , pointsMatrix[i][j][0]:pointsMatrix[i + 1][j + 1][0] ]
				cv2.imwrite("images/img"+str(i)+str(j)+".jpg", img)
				height, width, depth = img.shape

				hc = height / 2
				wc = width / 2

				YUpper = hc + OFFSET
				YLower = hc - OFFSET

				XUpper = wc + OFFSET
				XLower = wc - OFFSET

				colorThisBlock = [0 for loop1 in xrange(3)]

				# colorThisBlock contains mean value of this block
				for loop1 in range(XLower, XUpper):
					for loop2 in range(YLower, YUpper):
						for loop3 in xrange(3):
							colorThisBlock[loop3] += img[loop1, loop2, loop3]

				for loop1 in xrange(3):
					colorThisBlock[loop1] /= ( (2 * OFFSET) ** 2 ) * 1.0

				colorMatrix[i][j] = colorThisBlock
				print colorThisBlock
				# for item in colorThisBlock:
  				# print>>colorPath, str(item)
				with open(colorPath, 'a') as cp:
					cp.write(str(colorThisBlock))
					cp.write("\n")

		# if mean value of each face is saved, exit
		if countFaces == 6:
			break;

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
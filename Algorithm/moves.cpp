/*
	Cube representation

				00 01 02
				10 11 12
				20 21 22
				
	00 01 02	00 01 02	00 01 02	00 01 02
	10 11 12	10 11 12	10 11 12	10 11 12
	20 21 22	20 21 22	20 21 22	20 21 22

				00 01 02
				10 11 12
				20 21 22
*/


/*

This file contains all the moves required to solve a rubik's cube
This file does not contains the solution of any layer
It just contains the implementation of the moves such as L, R, U etc
This file is included in every layer solution

*/


#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a; i<b; i++)
#define PB push_back
using namespace std;
int i,j;


//THIS IS OUR MAIN CUBE
vector<vector<vector<char> > > cube;	// U(0), F(1), R(2), B(3), L(4), D(5)

vector<vector<char> > rotateFaceClockWise(vector<vector<char> > face) {
	vector<vector<char> > tempFace = face;
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			tempFace[j][3 - i - 1] = face[i][j];
		}
	}
	return tempFace;
}

void RotateMatrixLeft() {

	//changing F, R, D, L faces
	vector<vector<char> > mat;
	mat = cube[1];
	cube[1] = cube[2];
	cube[2] = cube[3];
	cube[3] = cube[4];
	cube[4] = mat;

	//rotating upper face clockwise
	cube[0] = rotateFaceClockWise(cube[0]);
	//rotating down face clockwise
	cube[5] = rotateFaceClockWise(cube[5]);
	cube[5] = rotateFaceClockWise(cube[5]);
	cube[5] = rotateFaceClockWise(cube[5]);

}

void RotateMatrixDown() {

	vector<vector<char> > mat;
	mat = cube[1];
	cube[1] = cube[0];
	cube[0] = cube[3];
	cube[3] = cube[5];
	cube[5] = mat;
	cube[0] = rotateFaceClockWise(cube[0]);
	cube[0] = rotateFaceClockWise(cube[0]);
	cube[3] = rotateFaceClockWise(cube[3]);
	cube[3] = rotateFaceClockWise(cube[3]);

	//rotating right face anticlockwise
	cube[2] = rotateFaceClockWise(cube[2]);
	cube[2] = rotateFaceClockWise(cube[2]);
	cube[2] = rotateFaceClockWise(cube[2]);

	//rotating left face anticlockwise
	cube[4] = rotateFaceClockWise(cube[4]);

}


//Function for Rotating the entire cube clockwise by 90 degrees
//Hence U becomes R and L becomes U
void RotateCubeClockwise()
{
	vector<vector<char> > temp;		//temp contains L
	temp = cube[4]; 

	//Front face gets Rotated by 90 deg clockwise
	cube[1] = rotateFaceClockWise(cube[1]);

	//Down becomes Left
	cube[4] = cube[5];

	//Right becomes Down
	cube[5] = cube[2];

	//Up becomes Right
	cube[2] = cube[0];

	//Left becomes Up
	cube[0] = temp;

	//Now the orientation of each face needs to be adjusted (The above format of cube must be followed)
	cube[4] = rotateFaceClockWise(cube[4]);
	cube[5] = rotateFaceClockWise(cube[5]);
	cube[2] = rotateFaceClockWise(cube[2]);
	cube[0] = rotateFaceClockWise(cube[0]);

	//Note that the back face has to be rotated 90 degree Counterclockwise
	cube[3] = rotateFaceClockWise(cube[3]);
	cube[3] = rotateFaceClockWise(cube[3]);
	cube[3] = rotateFaceClockWise(cube[3]);
}




//---------------FUNCTIONS FOR MOVES L, R, U, D, F, MR, MC---------------------------


//Function for move R
void MoveR()
{
	vector<char> temp; //temp = front face right column
	fl(i,0,3)
		temp.PB(cube[1][i][2]);
	
	//front face right column = down face right column
	fl(i,0,3)
		cube[1][i][2] = cube[5][i][2];

	//down face right column = back face left column
	fl(i,0,3)
		cube[5][i][2] = cube[3][3-i-1][0];

	//back face left column = up face right column
	fl(i,0,3)
		cube[3][i][0] = cube[0][3-i-1][2];

	//up face right column = front face right column
	fl(i,0,3)
		cube[0][i][2] = temp[i];

	cube[2] = rotateFaceClockWise(cube[2]);	
}


//Function for move L
void MoveL()
{
	//Make the back face as front apply Move R and restore the front face

	//Making back face as front
	RotateMatrixLeft();
	RotateMatrixLeft();

	MoveR();

	//Restoring the front face
	RotateMatrixLeft();
	RotateMatrixLeft();	
}


//Function for Move U
void MoveU()
{
	//Equivalent to Rotate cube clockwise, then perform R and then restore
	RotateCubeClockwise();
	MoveR();

	RotateCubeClockwise();
	RotateCubeClockwise();
	RotateCubeClockwise();
}


//Function for Move D
void MoveD()
{
	//Equivalent to Rotate cube clockwise, then perform L and then restore
	RotateCubeClockwise();
	MoveL();

	RotateCubeClockwise();
	RotateCubeClockwise();
	RotateCubeClockwise();	
}


//Function for Move MR i.e Middle row right 
void MoveMR()
{
	//This is equivalent to Move cube right, Then perform U and D'

	//Move Cube Right
	RotateMatrixLeft();	
	RotateMatrixLeft();
	RotateMatrixLeft();

	//Perform U
	MoveU();

	//Perform D'
	MoveD();
	MoveD();
	MoveD();
}


//Function for Move MC i.e Middle column up
void MoveMC()
{
	//This is equivalent to Move cube up, Then perform R' and L	

	//Move Cube Up
	RotateMatrixDown();	
	RotateMatrixDown();
	RotateMatrixDown();

	//Perform L
	MoveL();

	//Perform R'
	MoveR();
	MoveR();
	MoveR();
}


//Function for Move F
void MoveF()
{
	//This is equivalent to Move cube right, Then perform R and then restore the cube
	//Move Cube Right
	RotateMatrixLeft();	
	RotateMatrixLeft();
	RotateMatrixLeft();

	//Perform R
	MoveR();

	//Restore the front face
	RotateMatrixLeft();			
}


//Function for Move B
void MoveB()
{
	//This can be done by making back face as front, perform Move F and then restore
	
	//To make back as front
	RotateMatrixLeft();
	RotateMatrixLeft();

	//Move F
	MoveF();

	//Restore
	RotateMatrixLeft();
	RotateMatrixLeft();
}


//-----------------FUNCTIONS FOR ALL THE MOVES ARE COMPLETE NOW------------------------------



//taking input scrambled cube
void input() {
	for(int i=0;i<6;i++) {
		vector<vector<char> > mat;
		for(int j=0;j<3;j++) {
			vector<char> row;
			for(int k=0;k<3;k++) {
				char ch;
				cin>>ch;
				row.push_back(ch);
			}
			mat.push_back(row);
		}
		cube.push_back(mat);
	}
}

void printCube() {

	for(int j=0;j<3;j++) {
		for(int k=0;k<4;k++) {
			cout<<" ";
		}
		for(int k=0;k<3;k++) {
			cout<<cube[0][j][k];
		}
		cout<<"\n";
	}
	for(int i=0;i<3;i++) {
		int face = 4;
		for(int j=0;j<4;j++) {
			for(int k=0;k<3;k++) {
				cout<<cube[face][i][k];
			}
			cout<<" ";
			face = (face + 1) % 4;
		}
		cout<<"\n";
	}
	for(int j=0;j<3;j++) {
		for(int k=0;k<4;k++) {
			cout<<" ";
		}
		for(int k=0;k<3;k++) {
			cout<<cube[5][j][k];
		}
		cout<<"\n";
	}
	return ;
}


/*
int main() {

	input();

	
	printCube();
	printf("Move B\n\n");
	MoveF();
	printCube();

	//Solve();

}
*/
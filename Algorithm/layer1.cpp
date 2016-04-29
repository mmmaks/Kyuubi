/*

This file contains the solution to the first layer of the cube

*/


#include"moves.cpp"

struct corner
{
	char f,t,l;
};


vector<string> moves;
int num_moves_1;	//Tells number of moves required to solve layer 1


//A function to print moves
void printMoves(int x)
{
	fl(i,x,moves.size())
		cout<<moves[i]<<" ";
	cout<<endl;
}


//A function to eliminate unnecessary moves and convert LLL to L'
void CompressMoves()
{
	int n = moves.size(),i,j,count;

	vector<string> NewMoves;
	string str;

	fl(i,0,n)
	{
		count = 1;
		//cout<<i<<"---\n";
		fl(j,i+1,n)
		{
			if(moves[j]==moves[j-1])
				count++;
			else
			{
				count%=4;
				//cout<<i<<" "<<j-1<<" "<<count<<endl;
				if(count==1)
					NewMoves.PB(moves[j-1]);
				else if(count==2)
				{
					NewMoves.PB(moves[j-1]);
					NewMoves.PB(moves[j-1]);
				}
				else if(count==3)
				{
					str = moves[j-1];
					str+='\'';
					NewMoves.PB(str);
				}
				break;
			}
		}
		i = j-1;
	}

	moves = NewMoves;
}



//This function returns the top left corner of the cube
corner TopLeftCubie()
{
	corner temp;
	temp.f = cube[1][0][0];
	temp.t = cube[0][2][0];
	temp.l = cube[4][0][2];

	return temp;
}


//THIS IS THE MAIN ALGORITHM FOR SOLVING OUR CORNERS
//The parameter indicates the position of blue color wrt the algorithm we are following
void AlgoforCorner(int position)
{
	if(position==1)
	{
		MoveR();	MoveR();	MoveR();
		MoveD();	MoveD();	MoveD();
		MoveR();

		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");
	}

	else if(position==2)
	{
		MoveD();	MoveD();	MoveD();
		MoveR();	MoveR();	MoveR();
		MoveD();
		MoveR();

		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");
		moves.PB("R");	
	}

	else if(position==3)
	{
		MoveR();	MoveR();	MoveR();
		MoveD();
		MoveR();
		MoveD();
		MoveD();
		MoveR();	MoveR();	MoveR();
		MoveD();	MoveD();	MoveD();
		MoveR();

		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");
		moves.PB("R");
		moves.PB("D");
		moves.PB("D");
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");
	}

	else if(position==4)
	{
		MoveF();
		MoveD();
		MoveF();	MoveF();	MoveF();
		MoveD();
		MoveD();
		MoveR();	MoveR();	MoveR();
		MoveD();
		MoveR();

		moves.PB("F");
		moves.PB("D");
		moves.PB("F");		moves.PB("F");		moves.PB("F");
		moves.PB("D");
		moves.PB("D");
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");
		moves.PB("R");
	}

	else if(position==5)
	{
		MoveR();	MoveR();	MoveR();
		MoveD();	MoveD();	MoveD();
		MoveR();
		MoveD();
		MoveR();	MoveR();	MoveR();
		MoveD();	MoveD();	MoveD();
		MoveR();

		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");
		moves.PB("D");
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");
	}
}



//THIS IS THE MAIN ALGORITHM FOR SOLVING THE EDGES
//The parameter gives position of blue color according to the algorithm

void AlgoforEdge(int position)
{
	if(position==1)
	{
		MoveMC();	MoveMC();	MoveMC();
		MoveD();	MoveD();	MoveD();
		MoveD();	MoveD();	MoveD();
		MoveMC();

		moves.PB("MC");		moves.PB("MC");		moves.PB("MC");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("MC");
	}

	else if(position==2)
	{
		MoveD();	MoveD();	MoveD();
		MoveMC();	MoveMC();	MoveMC();
		MoveD();
		MoveMC();

		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("MC");		moves.PB("MC");		moves.PB("MC");
		moves.PB("D");
		moves.PB("MC");
	}

	else if(position==3)
	{
		MoveMR();
		MoveF();
		MoveMR();	MoveMR();	MoveMR();
		MoveF();	MoveF();	MoveF();

		moves.PB("MR");
		moves.PB("F");
		moves.PB("MR");		moves.PB("MR");		moves.PB("MR");
		moves.PB("F");		moves.PB("F");		moves.PB("F");
	}

	else if(position==4)
	{
		MoveMR();
		MoveF();	MoveF();	MoveF();
		MoveMR();	MoveMR();	MoveMR();
		MoveMR();	MoveMR();	MoveMR();
		MoveF();

		moves.PB("MR");
		moves.PB("F");		moves.PB("F");		moves.PB("F");
		moves.PB("MR");		moves.PB("MR");		moves.PB("MR");
		moves.PB("MR");		moves.PB("MR");		moves.PB("MR");
		moves.PB("F");			
	}

	else if(position==5)
	{
		MoveMC();	MoveMC();	MoveMC();
		MoveD();	MoveD();	MoveD();
		MoveD();	MoveD();	MoveD();
		MoveMC();
		MoveD();	MoveD();	MoveD();
		MoveMC();	MoveMC();	MoveMC();
		MoveD();
		MoveMC();

		moves.PB("MC");		moves.PB("MC");		moves.PB("MC");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("MC");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("MC");		moves.PB("MC");		moves.PB("MC");
		moves.PB("D");
		moves.PB("MC");
	}
}



//--------------------------------------PRIMING THE CUBE------------------------------------------------------


//This function returns whether the top left cubie is suitable for prime cubie or not
//If the cubie is suitable, it sets the cube in proper orientation
//i.e the blue color at the top and the cubie at top right
bool IsPrimeCubie()
{
	corner temp;
	temp = TopLeftCubie();

	if(temp.f=='b')
	{
		RotateMatrixDown();
		RotateCubeClockwise();
		RotateCubeClockwise();
		moves.PB("MCD");	moves.PB("RCC");	moves.PB("RCC");
		//printf("MOVES - MCD, RCC, RCC\n");
		return 1;
	}
	else if(temp.t=='b')
	{
		RotateMatrixLeft();
		RotateMatrixLeft();
		RotateMatrixLeft();
		moves.PB("MCL");	moves.PB("MCL");	moves.PB("MCL");
		//printf("MOVES - MCL, MCL, MCL\n");
		return 1;
	}
	else if(temp.l=='b')
	{
		RotateCubeClockwise();
		moves.PB("RCC");
		//printf("MOVES - RCC\n");
		return 1;
	}

	return 0;
}


//Prime Cubie is our first cubie which is used to prime or fix the cube
//We need to search for a cubie such that it contains a blue color while ensuring that blue is at top and cubie is at top right corner
//The resulting cube has the prime cubie at the top right of front face with blue color at top
void ReturnPrimeCubie()
{
	//We need to check for all the 8 cubies
	int count = 1;
	bool flag = 0;

	//Since IsPrimeCubie() orients the cubie, we have to break as soon as we get a prime cubie 
	flag = IsPrimeCubie();

	//Checking first four cubies wrt our front face
	while(!flag && count<=4)
	{
		MoveF();
		moves.PB("F");
		//printf("MOVES - F\n");
		count++;
		if(IsPrimeCubie())
		{
			flag = 1;
			break;
		}
	}


	//If we didn't get a prime cubie till now, we make the back face as front and continue the same operation
	if(!flag)
	{
		count = 1;
		RotateMatrixLeft();
		RotateMatrixLeft();
		moves.PB("MCL");	moves.PB("MCL");

		flag = IsPrimeCubie();

		while(!flag && count<=4)
		{
			MoveF();
			moves.PB("F");
			count++;
			if(IsPrimeCubie())
			{
				flag = 1;
				break;
			}
		}
	}
}


//This function finishes the priming of cube by bringing the blue face to the top
void FinishPrimeCube()
{
	if(cube[1][1][1]=='b')		//Front face is blue
	{
		MoveR();	MoveR();	MoveR();
		RotateMatrixDown();		RotateMatrixDown();		RotateMatrixDown();
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("MCD");	moves.PB("MCD");	moves.PB("MCD");
	}
	else if(cube[3][1][1]=='b')		//Back face is blue
	{
		RotateMatrixDown();
		MoveR();
		moves.PB("MCD");
		moves.PB("R");
	}
	else if(cube[2][1][1]=='b')		//Right face id blue
	{
		MoveF();
		RotateCubeClockwise();		RotateCubeClockwise();		RotateCubeClockwise();
		moves.PB("F");
		moves.PB("RCC");	moves.PB("RCC");	moves.PB("RCC");
	}
	else if(cube[4][1][1]=='b')		//Left face is blue
	{
		MoveF();	MoveF();	MoveF();
		RotateCubeClockwise();
		moves.PB("F");		moves.PB("F");		moves.PB("F");
		moves.PB("RCC");
	}
	else if(cube[5][1][1]=='b')		//Down face is blue
	{
		MoveF();	MoveF();
		RotateCubeClockwise();		RotateCubeClockwise();
		moves.PB("F");		moves.PB("F");
		moves.PB("RCC");	moves.PB("RCC");
	}
}


//------------------------------------CUBE IS PRIMED-------------------------------------------------------



//-----------------------------------SOLVING THE CORNERS---------------------------------------------------


//A function to check if the cubie with blue and "color" are at top right or bottom right
//If cubie is at desired position then it returns the position of blue color wrt the algorithm
//(See algorithm - It returns 4 if blue is front of top right cubie)
//If blue is at top it returns 6
//If cubie is not at proper position 0 is returned
int CheckForCorner(char color)
{
	//CHECK IF CUBIE IS AT TOP RIGHT

	//Case for returning 6
	//In case if blue is at correct position, "color" has to be in its correct position
	if((cube[0][2][2]=='b' && cube[1][0][2]==color))
		return 6;

	//Case for returning 5
	if(cube[2][0][0]=='b' && (cube[0][2][2]==color || cube[1][0][2]==color))
		return 5;

	//Case for returning 4
	if(cube[1][0][2]=='b' && (cube[0][2][2]==color || cube[2][0][0]==color))
		return 4;


	//CHECK IF CUBIE IS AT BOTTOM RIGHT

	//Case for returning 3
	if(cube[5][0][2]=='b' && (cube[1][2][2]==color || cube[2][2][0]==color))
		return 3;

	//Case for returning 2
	if(cube[1][2][2]=='b' && (cube[5][0][2]==color || cube[2][2][0]==color))
		return 2;

	//Case for returning 1
	if(cube[2][2][0]=='b' && (cube[1][2][2]==color || cube[5][0][2]==color))
		return 1;

	return 0;
}


//This Function Solves our Second Corner 
//Note that first corner is already solved after priming the cube :P
void SolveCorner1()
{
	//--------This part is just to bring the cubie at the correct position--------
	char color = cube[1][0][0];

	//Checking cubies in the bottom layer
	int count = 1, position;
	position = CheckForCorner(color);
	while(!position && count<=4)
	{
		count++;
		MoveD();
		moves.PB("D");
		position = CheckForCorner(color);
	}

	
	//After above checking only the top cubies of back face are remaining to check
	
	if(!position)
	{
		MoveB();
		MoveB();
		moves.PB("B");
		moves.PB("B");

		//Now those cubies are also in the bottom row so perform above check
		count = 1;
		position = CheckForCorner(color);
		while(!position && count<=4)
		{
			count++;
			MoveD();
			moves.PB("D");
			position = CheckForCorner(color);
		}		
	}

	
	//-------Now the cubie is at "position", so just perform the moves to solve

	AlgoforCorner(position);
}


//This Function Solves our Third Corner 
//Note that first corner is already solved after priming the cube :P
void SolveCorner2()
{
	//--------This part is just to bring the cubie at the correct position--------
	char color = cube[1][0][0];

	//Checking cubies in the bottom layer
	int count = 1, position;
	position = CheckForCorner(color);
	while(!position && count<=4)
	{
		count++;
		MoveD();
		moves.PB("D");
		position = CheckForCorner(color);
	}

	
	//After above checking only the top left cubie of back face is remaining to check
	
	if(!position)
	{
		MoveR();
		MoveR();
		moves.PB("R");
		moves.PB("R");

		//Now those cubies are also in the bottom row so perform above check
		count = 1;
		position = CheckForCorner(color);
		while(!position && count<=4)
		{
			count++;
			MoveD();
			moves.PB("D");
			position = CheckForCorner(color);
		}		
	}

	
	//-------Now the cubie is at "position", so just perform the moves to solve

	AlgoforCorner(position);
}


//This Function Solves our Final Corner 
//Note that first corner is already solved after priming the cube :P
void SolveCorner3()
{
	//--------This part is just to bring the cubie at the correct position--------
	char color = cube[1][0][0];

	//Checking cubies in the bottom layer
	int count = 1, position;
	position = CheckForCorner(color);
	while(!position && count<=4)
	{
		count++;
		MoveD();
		moves.PB("D");
		position = CheckForCorner(color);
	}
	
	//-------Now the cubie is at "position", so just perform the moves to solve

	AlgoforCorner(position);
}



//Driver function to solve all corners of layer 1
void SolveCorners()
{
	//After the cube is primed, we perform move MCL because algo tells us to do so :P
	//Make the right face as front
	RotateMatrixLeft();
	moves.PB("MCL");
	//printCube();
	SolveCorner1();
	//printMoves();
	
	//Make the right face as front
	RotateMatrixLeft();
	moves.PB("MCL");
	//printCube();
	SolveCorner2();
	//printMoves();

	//Make the right face as front
	RotateMatrixLeft();
	moves.PB("MCL");
	//printCube();
	SolveCorner3();
	//printMoves();

}


//---------------------------------ALL CORNERS OF LAYER 1 ARE SOLVED-------------------------------------


//This is the function which checks if the edge is at the position required by the algo
//If it is at the proper position, it returns position of blue color wrt the algo
//If edge is not at required position it returns 0
int CheckForEdge(char color)
{
	//Checking for case 6
	if(cube[0][2][1]=='b' && cube[1][0][1]==color)
		return 6;

	//Checking for case 5
	else if(cube[1][0][1]=='b' && cube[0][2][1]==color)
		return 5;

	//Checking for case 4
	else if(cube[1][1][2]=='b' && cube[2][1][0]==color)
		return 4;

	//Checking for case 3
	else if(cube[2][1][0]=='b' && cube[1][1][2]==color)
		return 3;

	//Checking for case 2
	else if(cube[1][2][1]=='b' && cube[5][0][1]==color)
		return 2;

	//Checking for case 1
	else if(cube[5][0][1]=='b' && cube[1][2][1]==color)
		return 1;	

	return 0;
}


void SolveCurrentEdge()
{
	//This is the color which must be present with blue one
	char color = cube[1][0][0];

	int count = 1, position;
	position = CheckForEdge(color);
	while(!position && count<=4)
	{
		//Move the up layer, atleast once in 4 moves the middle and bottom row cubies will be suitable for top row
		//This was possible because moving bottom two row right = Move top row left
		//But note that if we go in this way the value of "color" will change
		count++;
		MoveU();
		moves.PB("U");
		RotateMatrixLeft();		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");		moves.PB("MCL");		moves.PB("MCL");
		color = cube[1][0][0];

		position = CheckForEdge(color);
	}

	//Perform the moves according to the algorithm
	AlgoforEdge(position);
}


//This function returns true if the layer 1 is unsolved
//If layer is unsolved it orients the cube with that color strip in front
//If completely solved it returns 0
bool UnsolvedLayer()
{
	char color = cube[1][0][0];
	bool flag = 0;
	if(CheckForEdge(color)==6)
		flag = 1;

	int count = 0,i;

	while(CheckForEdge(color)==6 && count<4)
	{
		RotateMatrixLeft();
		count++;
		color = cube[1][0][0];
		if(CheckForEdge(color)!=6)
		{
			flag = 0;
			break;
		}
	}

	if(!flag)
	{
		//cout<<count<<endl;
		
		fl(i,0,count)
			moves.PB("MCL");
				
	}

	return flag;
}


//Driver function to solve all edges of layer 1
void SolveEdges()
{
	SolveCurrentEdge();
	//printMoves();
	//printCube();
	RotateMatrixLeft();
	moves.PB("MCL");

	
	SolveCurrentEdge();
	//printMoves();
	//printCube();
	RotateMatrixLeft();
	moves.PB("MCL");

	SolveCurrentEdge();
	//printMoves();
	//printCube();
	RotateMatrixLeft();
	moves.PB("MCL");

	SolveCurrentEdge();
	//printMoves();
	//printCube();
	RotateMatrixLeft();
	moves.PB("MCL");	

	
	while(!UnsolvedLayer())
	{
		SolveCurrentEdge();
		//printMoves();
		//printCube();
	}
	
}


//This is just to align colors with that of top layer
void FinishLayer1()
{
	char color = cube[1][1][1];
	char curr = cube[1][0][0];
	while(curr!=color)
	{
		MoveU();
		moves.PB("U");
		color = cube[1][1][1];
		curr = cube[1][0][0];
	}
}


//Driver function to solve layer 1
void SolveLayer1()
{
	//printf("\n\nPrimed incomplete cube\n");
	ReturnPrimeCubie();
	//printCube();
	//printMoves();

	//printf("\n\nPrimed cube\n");
	FinishPrimeCube();

	//printCube();	
	//printMoves();

	//printCube();	
	SolveCorners();

	//printMoves();

	//printCube();

	SolveEdges();
	//printCube();	

	
	FinishLayer1();
	//CompressMoves();
	//printMoves();
	//printCube();
	num_moves_1 = moves.size();	
}



/*
int main() 
{

	input();

	
	printCube();
	//printf("Move F\n\n");
	//MoveF();
	//printCube();

	SolveLayer1();

}
*/
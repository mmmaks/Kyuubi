/*
This file contains the solution to the final layer
*/

#include"layer2.cpp"



//Algo for function Make Cross
void AlgoForMakeCross()
{
	MoveF();
	MoveR();
	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveF();	MoveF();	MoveF();

	moves.PB("F");
	moves.PB("R");
	moves.PB("U");
	moves.PB("R'");
	moves.PB("U'");
	moves.PB("F'");
}


//Algo for aligning the cross
void AlgoForAlignCross()
{
	MoveR();
	MoveU();	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveU();	MoveU();	MoveU();

	moves.PB("R");
	moves.PB("U");		moves.PB("U");
	moves.PB("R");		moves.PB("R");		moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
	moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
	moves.PB("R");		moves.PB("R");		moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
}


//Algo for Making the corner, note that these corners need not be oriented
void AlgoForMakeCorner()
{
	MoveL();	MoveL();	MoveL();
	MoveU();
	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveL();
	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveU();	MoveU();	MoveU();

	moves.PB("L");		moves.PB("L");		moves.PB("L");
	moves.PB("U");
	moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
	moves.PB("L");
	moves.PB("U");
	moves.PB("R");		moves.PB("R");		moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
}


//Final algorithm for orienting the corners of final layer
void AlgoFinal()
{
	MoveR();
	MoveU();	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveR();
	MoveU();	MoveU();	MoveU();
	MoveR();	MoveR();	MoveR();
	MoveL();	MoveL();	MoveL();
	MoveU();	MoveU();
	MoveL();
	MoveU();
	MoveL();	MoveL();	MoveL();
	MoveU();
	MoveL();

	moves.PB("R");
	moves.PB("U");		moves.PB("U");
	moves.PB("R");		moves.PB("R");		moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
	moves.PB("R");
	moves.PB("U");		moves.PB("U");		moves.PB("U");
	moves.PB("R");		moves.PB("R");		moves.PB("R");
	moves.PB("L");		moves.PB("L");		moves.PB("L");
	moves.PB("U");		moves.PB("U");
	moves.PB("L");
	moves.PB("U");
	moves.PB("L");		moves.PB("L");		moves.PB("L");
	moves.PB("U");
	moves.PB("L");
}


//This function checks if there is a cross in top layer
//Note that this cross needs not be aligned
bool IsCross()
{
	if(cube[0][0][1]==cube[0][1][1] && cube[0][1][0]==cube[0][1][1] && cube[0][1][1]==cube[0][1][2] && cube[0][1][1]==cube[0][2][1])
		return 1;
	return 0;
}


//This function checks if there is a T at the above layer
//If there is a T, it orients it according to the algorithm
bool IsT()
{	
	//There can be 4 cases of T, handling each of them accordingly

	//cout<<"--"<<cube[0][1][1]<<" "<<cube[0][1][2]<<" "<<cube[0][2][1]<<endl;

	if(cube[0][1][1]==cube[0][1][2] && cube[0][1][2]==cube[0][0][1])
	{	
		RotateMatrixLeft();
		moves.PB("MCL");
		return 1;
	}
	else if(cube[0][1][1]==cube[0][1][2] && cube[0][1][2]==cube[0][2][1])
		return 1;
	else if(cube[0][1][1]==cube[0][1][0] && cube[0][1][1]==cube[0][0][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");		moves.PB("MCL");
		return 1;
	}
	else if(cube[0][1][1]==cube[0][1][0] && cube[0][1][1]==cube[0][2][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");		moves.PB("MCL");		moves.PB("MCL");
		return 1;	
	}

	return 0;
}


//This function checks if there is a line and if there is a line it orients it accordingly
//Else Light lo be :P
//This line is just a piece of crap to remind me of the state in which I was when I wrote this epic piece of shit with GOT music playing in my ears, note that GOT was aired earlier today in some countries and we are hoping to get it on torrent by 5 AM. And now I must get back to work because the music which was being played in my ears at that time wasn't actually GOT, LOL :P

bool IsLine()
{
	//Two cases are possible

	if(cube[0][1][0]==cube[0][1][1] && cube[0][1][1]==cube[0][1][2])
		return 1;
	else if(cube[0][0][1]==cube[0][1][1] && cube[0][1][1]==cube[0][2][1])
	{
		RotateMatrixLeft();
		moves.PB("MCL");
		return 1;
	}
	return 0;
}



//This function makes the cross
//Note that this cross need not be aligned
void MakeCross()
{
	if(IsCross())
		return;

	//Note that conditions are only used to orient the cube properly before executing the algo

	if(IsLine())
	{
		//cout<<"LINE\n";
		AlgoForMakeCross();
		//printCube();
		MakeCross();		
	}
	else if(IsT())
	{
		//cout<<"T\n";
		AlgoForMakeCross();
		//printCube();
		MakeCross();		
	}
	else
	{
		//cout<<"NO\n";
		AlgoForMakeCross();
		//printCube();
		MakeCross();
	}
}


//This function checks if there is an adjacent cross oriented
//It checks for all the adjacent crosses
//And if there is, we orient it at back and left face
bool IsAdjacentCross()
{
	//Check F and L
	if(cube[1][0][1]==cube[1][1][1] && cube[4][0][1]==cube[4][1][1])
	{
		RotateMatrixLeft();
		moves.PB("MCL");
		return 1;
	}
	//Check L and B
	else if(cube[4][0][1]==cube[4][1][1] && cube[3][0][1]==cube[3][1][1])
		return 1;
	//Check B and R
	else if(cube[3][0][1]==cube[3][1][1] && cube[2][0][1]==cube[2][1][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");	moves.PB("MCL");	moves.PB("MCL");
		return 1;
	}
	else if(cube[1][0][1]==cube[1][1][1] && cube[2][0][1]==cube[2][1][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");	moves.PB("MCL");
		return 1;
	}

	return 0;
}



//This function checks if there is an opposite cross possible
//If there is, orient it accordingly
bool IsOppositeCross()
{
	if(cube[1][0][1]==cube[1][1][1] && cube[3][0][1]==cube[3][1][1])
		return 1;
	else if(cube[2][0][1]==cube[2][1][1] && cube[4][0][1]==cube[4][1][1])
	{
		RotateMatrixLeft();
		moves.PB("MCL");
		return 1;
	}

	return 0;
}


//This function checks if the cross is made finally 
//That is the cross is also aligned accordingly
bool IsProperCross()
{
	if(cube[1][0][1]==cube[1][1][1] && cube[2][0][1]==cube[2][1][1] && cube[3][0][1]==cube[3][1][1] && cube[4][0][1]==cube[4][1][1])
		return 1;
	return 0;
}


//This functions continuously performs the U move and checks if there is one or more faces are aligned
//If alignment is adjacent, keep them left back
//Else keep them front and back
//If one is aligned then keep it in front
void AlignCross()
{
	int count = 1;
	bool flag = 0;

	//If cross is done then return
	if(IsProperCross())
		return;

	//Perform the U move and keep checking for cases
	while(!IsAdjacentCross() && !IsOppositeCross() && count<=4)
	{
		MoveU();
		moves.PB("U");
		count++;
			
		//If Proper cross is there simply return
		if(IsProperCross())
			return;
		//Else check if there is adjacent or opposite case
		else if(IsAdjacentCross() || IsOppositeCross())
		{
			flag = 1;
			break;
		}
	}

	//If flag = 0, it means that no two cross can be matched
	//So we match the cross with the front face (only one)
	//And then iteratively follow the Algo
	if(!flag)
	{
		int counter = 1;
		while(counter<=4)
		{
			if(cube[1][0][1]==cube[1][1][1])
				break;
			else
			{
				MoveU();
				moves.PB("U");
				counter++;
			}
		}
	}


	//While the cross is not made
	//Follow the algo 
	AlgoForAlignCross();
	AlignCross();
}


//This function checks if the cubie at top right is correct
//That is its at proper position but not properly oriented
bool CheckTopRight()
{
	char f = cube[1][1][1];
	char t = cube[0][1][1];
	char r = cube[2][1][1];

	if((f==cube[0][2][2] || f==cube[1][0][2] || f==cube[2][0][0]) && (t==cube[0][2][2] || t==cube[1][0][2] || t==cube[2][0][0]) && (r==cube[0][2][2] || r==cube[1][0][2] || r==cube[2][0][0]))
		return 1;

	return 0;
}


//This functionchecks if the cubie at top left corner is incorrect
//That is its not at its proper position
bool CheckTopLeft()
{
	char f = cube[1][0][0];
	char t = cube[0][2][0];
	char l = cube[4][0][2];

	if((f==cube[0][1][1] || f==cube[1][1][1] || f==cube[4][1][1]) && (t==cube[0][1][1] || t==cube[1][1][1] || t==cube[4][1][1]) && (l==cube[0][1][1] || l==cube[1][1][1] || l==cube[4][1][1]))
		return 0;

	return 1;	
}


//This function tells if the corners are now made
//Note that they need not be properly oriented
bool IsOkCorner()
{
	int count = 1;
	bool flag = 1;
	while(count<=4)
	{
		RotateMatrixLeft();
		if(!CheckTopRight())
		{
			flag = 0;
			break;
		}
		count++;
	}

	while(count<4)
	{
		RotateMatrixLeft();
		count++;
	}

	return flag;
}



void MakeCorners()
{
	int count = 1;
	
	while(count<=4)
	{
		//cout<<"R "<<count<<endl;
		if(IsOkCorner())
			break;
		else if(CheckTopLeft() && CheckTopRight())
		{
			AlgoForMakeCorner();
			cout<<"Yes ";
			count = 1;
		}
		else
		{
			RotateMatrixLeft();
			moves.PB("MCL");
			cout<<"No ";
			count++;
		}

		//cout<<count<<endl;
	}

	cout<<"NOT FOUND\n";
	printCube();
	cout<<"NOT FOUND\n";

	if(!IsOkCorner())
	{	
		printCube();
		AlgoForMakeCorner();
		printCube();
		MakeCorners();
	}
}



//A function to check if there is a correct line of cubies formed
//Function returns 1 if two of the cubies are oriented
//It returns 2 if three are oriented and the bad one is in top right
int Checkline()
{
	if(cube[0][2][0]==cube[0][1][1] && cube[1][0][0]==cube[1][1][1] && cube[4][0][2]==cube[4][1][1])
	{
		if(cube[0][0][0]==cube[0][1][1] && cube[4][0][0]==cube[4][1][1] && cube[3][0][2]==cube[3][1][1])
		{	
			if(cube[0][0][2]==cube[0][1][1] && cube[2][0][2]==cube[2][1][1] && cube[3][0][0]==cube[3][1][1])
				return 2;
			else if(cube[0][2][2]==cube[0][1][1] && cube[2][0][0]==cube[2][1][1] && cube[1][0][2]==cube[1][1][1])
			{
				RotateMatrixLeft();
				moves.PB("MCL");
				return 2;	
			}
			return 1;
		}
	}

	int count = 1;
	while(count<=4)
	{
		RotateMatrixLeft();
		moves.PB("MCL");
		count++;

		if(cube[0][2][0]==cube[0][1][1] && cube[1][0][0]==cube[1][1][1] && cube[4][0][2]==cube[4][1][1])
		{
			if(cube[0][0][0]==cube[0][1][1] && cube[4][0][0]==cube[4][1][1] && cube[3][0][2]==cube[3][1][1])
			{	
				if(cube[0][0][2]==cube[0][1][1] && cube[2][0][2]==cube[2][1][1] && cube[3][0][0]==cube[3][1][1])
					return 2;
				else if(cube[0][2][2]==cube[0][1][1] && cube[2][0][0]==cube[2][1][1] && cube[1][0][2]==cube[1][1][1])
				{
					RotateMatrixLeft();
					moves.PB("MCL");
					return 2;	
				}
				return 1;
			}
		}		

	}

	return 0;
}


//This function returns whether the cube is at its proper position to apply the algo
//If not, bring it to its original position
bool IsSuitable()
{
	if(cube[1][0][0]==cube[1][1][1] && cube[0][2][0]==cube[0][1][1] && cube[4][0][2]==cube[4][1][1])
		return 1;
	else if(cube[1][0][2]==cube[1][1][1] && cube[2][0][0]==cube[2][1][1] && cube[0][2][2]==cube[0][1][1])
	{
		RotateMatrixLeft();
		moves.PB("MCL");
		return 1;
	}
	else if(cube[0][0][2]==cube[0][1][1] && cube[2][0][2]==cube[2][1][1] && cube[3][0][0]==cube[3][1][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");		moves.PB("MCL");
		return 1;
	}
	else if(cube[0][0][0]==cube[0][1][1] && cube[3][0][2]==cube[3][1][1] && cube[4][0][0]==cube[4][1][1])
	{
		RotateMatrixLeft();		RotateMatrixLeft();		RotateMatrixLeft();
		moves.PB("MCL");		moves.PB("MCL");		moves.PB("MCL");
		return 1;	
	}
}


//This function returns true if the cube is unsolved
bool IsUnsolvedCube()
{
	int i,j,k;
	fl(i,0,6)
	{
		fl(j,0,3)
		{
			fl(k,0,3)
			{
				if(cube[i][j][k]!=cube[i][1][1])
					return 1;
			}
		}
	}

	return 0;
}


void AlignCorner()
{
	//cout<<"ENTER\n";
	if(Checkline())
	{
		AlgoFinal();
	}
	else if(IsSuitable())
	{
		AlgoFinal();
	}
	else
		AlgoFinal();

	if(IsUnsolvedCube())
	{	
		//cout<<"START\n";
		AlignCorner();
		//cout<<"DUMMY\n";
		//printCube();
	}
	//else
	//	cout<<"Here\n";
}



int main() 
{

	input();

	
	printCube();
	//printf("Move F\n\n");
	//MoveF();
	//printCube();
	
	SolveLayer1();

	cout<<"-------------FOLLOW THESE MOVES TO SOLVE SECOND LAYER-------------------\n";
	SolveLayer2();

	CompressMoves();

	cout<<"\n\nIN SHORT FOLLOW THESE TO SOLVE CUBE\n\n";
	printMoves(0);
	

	int l = moves.size();

	cout<<"---PURANA KHATM---------\n\n";

	//VERY IMPORTANT
	RotateCubeClockwise();		RotateCubeClockwise();
	printCube();


	MakeCross();

	printMoves(l);

	printCube();

	l = moves.size();

	AlignCross();

	printMoves(l);

	printCube();

	l = moves.size();

	cout<<"-------------------\n";

	MakeCorners();
	printMoves(l);
	printCube();

	l = moves.size();
	//cout<<"YES\n";

	AlignCorner();
	printMoves(l);
	printCube();
	
	freopen("out.txt","w",stdout);

	cout<<"----------PLEASE FOLLOW THE FOLLOWING MOVES ACCORDING TO STANDARD CUBE NOTATION-------------\n\n";

	printMoves(0);

}

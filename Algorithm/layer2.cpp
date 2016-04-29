/*
This file contains the solution to the second layer
*/

#include"layer1.cpp"


//This is used to check if SolveThisLayer gives at least one solution or not
//If it doesn't give atleast one solution we need to perform Dummy Move
int flagger;


//THIS IS THE MAIN ALGO FOR THIS LAYER
void AlgoForLayer(int flag)
{
	if(flag==1)		//LEFT
	{
		MoveD();
		MoveL();
		MoveD();	MoveD();	MoveD();
		MoveL();	MoveL();	MoveL();
		MoveD();	MoveD();	MoveD();
		MoveF();	MoveF();	MoveF();
		MoveD();
		MoveF();

		moves.PB("D");
		moves.PB("L");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("L");		moves.PB("L");		moves.PB("L");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("F");		moves.PB("F");		moves.PB("F");
		moves.PB("D");
		moves.PB("F");
	}
	else if(flag==2)	//RIGHT
	{
		MoveD();	MoveD();	MoveD();
		MoveR();	MoveR();	MoveR();
		MoveD();
		MoveR();
		MoveD();
		MoveF();
		MoveD();	MoveD();	MoveD();
		MoveF();	MoveF();	MoveF();

		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("R");		moves.PB("R");		moves.PB("R");
		moves.PB("D");
		moves.PB("R");
		moves.PB("D");
		moves.PB("F");
		moves.PB("D");		moves.PB("D");		moves.PB("D");
		moves.PB("F");		moves.PB("F");		moves.PB("F");
	}
}


//This function returns true if the layer is unsolved
//If the layer is fully solved, it returns false
bool IsUnsolvedLayer()
{
	int i;
	fl(i,1,5)
	{
		if((cube[i][1][0]!=cube[i][1][1]) || (cube[i][1][2]!=cube[i][1][1]))
			return 1;
	}
	return 0;
}


//Suitable T is one in which there is a full T formed in the current front face
//And the color beneath the T forming cubie (cubie in third layer) either belongs to the left or right face
//This function returns positive if there is a suitable T in front face else returns 0
//Note that this function doesn't change the orientation of the cube
//The positive value returned is same as that specified in the algorithm
//1 = It should go left, 2 = It should go to right
int IsSuitableT()
{
	if(cube[1][2][1]==cube[1][1][1] && cube[5][0][1]==cube[4][1][1])
		return 1;
	else if(cube[1][2][1]==cube[1][1][1] && cube[5][0][1]==cube[2][1][1])
		return 2;
	return 0;
}


//This function initializes counter = 1 and checks if in current orientation there is a full suitable T
//If no suitable T, perform MCL and then check if there is a T
//If any T found, set counter = 1 and perform the above steps again
//If no T found even after 4 MCL then counter++ perform D and do all the steps again
void SolveThisLayer()
{
	int flag = IsSuitableT();
	int counter = 1, count = 0,i;

	//Initialize counter = 1 and starts checking
	while(counter<=4)
	{
		//Check for suitable T while performing MCL
		while(!flag && count<4)
		{
			count++;
			RotateMatrixLeft();
			//moves.PB("MCL");
			flag = IsSuitableT();

		}

		if(flag)
		{	
			//cout<<counter<<" "<<count<<endl;
			counter = 1;
			//printCube();
			fl(i,0,count)
				moves.PB("MCL");
			
			AlgoForLayer(flag);
			//printMoves();
			flagger = 1;
		}
		else
		{
			counter++;
			//cout<<"See\n";
			//printCube();
			MoveD();
			moves.PB("D");
		}

		flag = IsSuitableT();
		count = 0;
	}
}


//In case SolveThisLayer doesn't give any solution, it means that the cubie which should form T is stuck in middle layer
//Hence any irrelevant cubie is swapped by performing the algo and so we get it back in bottom layer
void DummyMove()
{
	int count = 1;
	while(count<=4)
	{
		if(cube[1][1][0]!=cube[1][1][1] && cube[1][1][0]!='g' && cube[4][1][2]!='g')
		{	
			//printCube();
			AlgoForLayer(1);
			//printMoves();
			break;
		}
		else if(cube[1][1][2]!=cube[1][1][1] && cube[1][1][2]!='g' && cube[2][1][0]!='g')
		{	
			//printCube();
			AlgoForLayer(2);
			//printMoves();
			break;
		}
		else
		{
			count++;
			RotateMatrixLeft();
			moves.PB("MCL");
		}
	}
}


//Driver function to solve the second layer
void SolveLayer2()
{
	while(IsUnsolvedLayer())
	{
		flagger = 0;
		SolveThisLayer();
		if(!flagger)
		{	
			//cout<<"Dummy\n";
			DummyMove();
		}
	}
	//CompressMoves();
	
	int i;
	/*fl(i,num_moves_1,moves.size())
		cout<<moves[i]<<" ";
	cout<<endl;

	printCube();*/
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

	cout<<"-------------FOLLOW THESE MOVES TO SOLVE SECOND LAYER-------------------\n";
	SolveLayer2();

	CompressMoves();

	cout<<"\n\nIN SHORT FOLLOW THESE TO SOLVE CUBE\n\n";
	printMoves();

}
*/
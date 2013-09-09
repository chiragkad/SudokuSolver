#include<stdio.h>

// Function Prototypes
int solver(int [][9],int,int);
int filled(int sud[][9],int r,int c);
int place(int sud[][9],int k,int i,int key);

// Main
int main()
{
	int sud[9][9]={	{3,0,0,6,0,0,0,9,0},
					{0,0,8,0,0,1,2,0,0},
					{4,0,0,0,0,9,8,5,1},
					{0,0,0,0,0,0,5,7,0},
					{6,0,0,0,0,0,0,0,4},
					{0,1,9,0,0,0,0,0,0},
					{0,3,2,4,0,0,0,0,8},
					{0,0,4,1,0,0,3,0,0},
					{0,6,0,0,0,8,0,0,9}};
	int i,j;
	solver(sud,0,0);
	//Print Solved Grid
	if( filled(sud, 0, 0) )
    {
		printf("\n Solution : \n\n");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf(" %d ",sud[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("\n\n No Solution ! \n\n");
	return 0;
}

//Solves the Sudoku
int solver(int sud[][9],int r,int c)
{
	int i,a,b,flag=0;
	//Base condition when recursion should stop
	if(filled(sud,r,c))		
		return 1;
	//Checks for the next empty square
	for(a=r;a<9;a++)
	{
		for(b=0;b<9;b++)
		{
			if(sud[a][b]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			flag=0;
			break;
		}
	}
	//Set co-ordinates of empty square
	r=a;
	c=b;
	//Check for permutations
	//Recursive backtracking code 
	for(i=1;i<=9;i++)
	{
		if(place(sud,r,c,i))
		{
			sud[r][c]=i;		//Assign Value
			if(solver(sud,r,c)) //Recursive call
				return 1;
			sud[r][c]=0;        //Unassign value
		}
	}
	return 0;
}

//Checks if all places are fillied i.e. is the sudoku complete
int filled(int sud[][9],int r,int c)
{
	int i,j;
	for(i=r;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(sud[i][j]==0)
				return 0;
		}
	}
	if(i==9)
		return 1;
	return 0;
}

//Bounding Function
int place(int sud[][9],int k,int i,int key)
{
	int a,b,row,col,col1,j=0;
	row=(k/3)*3;
	col1=col=(i/3)*3;
	//Check row and column
	while(j<9)
	{
		if(sud[k][j]==key || sud[j][i]==key)
		{
			return 0;
		}
		j++;
	}
	//Check the 3x3 grid
	for(a=0;a<3;a++,row++)
	{
		col=col1;
		for(b=0;b<3;b++,col++)
		{
			if(sud[row][col]==key)
				return 0;
		}
	}
	return 1;
}

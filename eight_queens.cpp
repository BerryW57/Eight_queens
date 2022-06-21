#include<iostream>
using namespace std;

struct Queen
{
    int row;
    int col;
};

/*
 * mark the places that other queens can't be placed
 */
void Block(const Queen& q, int c[][8])
{
    for(int i = 0; i < 8; i++)
    {
        c[i][q.col] = 1;
    }
    int row = q.row, col = q.col;
    while(col >= 0 && col < 8 && row >= 0 && row < 8)
    {
        c[row][col]=1;
        col+=1;
        row-=1;
    }
    row = q.row; col = q.col;
    while(col >= 0 && col < 8 && row >= 0 && row < 8)
    {
        c[row][col]=1;
        col-=1;
        row+=1;
    }
    row = q.row; col = q.col;
    while(col >= 0 && col < 8 && row >= 0 && row < 8)
    {
        c[row][col]=1;
        col+=1;
        row+=1;
    }
    row = q.row; col = q.col;
    while(col >= 0 && col < 8 && row >= 0 && row < 8)
    {
        c[row][col]=1;
        col-=1;
        row-=1;
    }

}

/*
 * copy array1 to array2
 */
void CloneArray(int array1[][8], int array2[][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            array2[i][j] = array1[i][j];
        }
    }
}

/*
 * recursively place the queen row by row
 * if 
 */
int place(int row, int c[][8])
{
    if(row==7)
    {
        int count=0;
        for(int i=0; i<8; i++)
        {
            if(c[row][i]==0) count++;
        }
        return count;
    }
    int count = 0;
    for(int i=0; i<8; i++)
    {
        int tempChessBoard[8][8];
        if(c[row][i]==0)
        {
            CloneArray(c, tempChessBoard);
            Queen queen = {row, i};
            Block(queen, tempChessBoard);
            count+=place(row+1, tempChessBoard); 
        }
    }
    return count;
}

int main()
{
    int chessboard[8][8]={};
    int count = place(0, chessboard);
    cout<<"total number of solutions is: "<<count<<endl;
}
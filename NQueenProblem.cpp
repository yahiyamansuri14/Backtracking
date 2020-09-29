#include<bits/stdc++.h>
using namespace std;
int board[11][11];
    bool isPossible(int n,int row,int col){
        //for vertical check
        for(int i=row-1;i>=0;i--)
            if(board[i][col]==1)
                return false;
        //for upper left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
            if(board[i][j]==1)
                return false;
        //for upper right diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
            if(board[i][j]==1)
                return false;
    return true;
    }
    void nQueenHelper(int n,int row){
        if(row==n){
            //we have reached some solution
            //print the board matrix
            //return
            cout<<"Possible answers:-"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }
        //place at all possible positions
        //and move to smaller problem
        for(int j=0;j<n;j++){
            //checking if it is possible to place the queen at
            //this particular column of row 
            if(isPossible(n,row,j)){
                board[row][j]=1;
                nQueenHelper(n,row+1);
                board[row][j]=0;
            }
        }
        return;
        
    }
    void placeNQueens(int n){
        memset(board,0,11*11*sizeof(int));
        nQueenHelper(n,0);
    }

int main()
{
   placeNQueens(4);
   return 0;
}

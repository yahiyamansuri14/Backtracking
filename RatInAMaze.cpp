#include <bits/stdc++.h>
 using namespace std;
 void printSolution(int **solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
 }
 void mazeHelp(int maze[][20],int n,int **solution,int x,int y){
    //position can't be included if row and column reahces less than 0 or more than size
    //position can't be included if there is zero in maze matrix at that position i.e.maze[x][y]==0
    //position can't be included if the position already in one solution i.e. solution[x][y]=1
    if(x<0 || x>=n || y<0 || y>=n ||maze[x][y]==0 || solution[x][y]==1)
        return;
    //if i reach the destination point i.e. maze[n-1][n-1]
    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        printSolution(solution,n);
        return;
    }
    //including the position in solution where i am standing
    solution[x][y]=1;
    //i need to move in all direction Up,Down,Left,Right
    mazeHelp(maze,n,solution,x-1,y);
    mazeHelp(maze,n,solution,x+1,y);
    mazeHelp(maze,n,solution,x,y+1);
    mazeHelp(maze,n,solution,x,y-1);
    //once explore all direction of particular place make it zero so it will be used in further combinations
    solution[x][y]=0;
 }
 void ratInMaze(int maze[][20],int n){
    int **solution=new *int[n];
    for(int i=0;i<n;i++)
        solution[i]=new *int[n];
    mazeHelp(maze,n,solution,0,0);
 }
int main()
{
   int maze[20]
   ratInMaze(maze,n);
   return 0;
}

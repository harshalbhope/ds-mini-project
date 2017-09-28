//
// Created by Saurav Kanchan on 29-09-2017.
//

#include<stdio.h>

void DFS(int,int,int);
int visited[100],n=13;    //n is no of vertices and graph is sorted in array G[10][10]
int G[13][13] = {{0,  13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//1 panvel
                 {13, 0,  4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//2 cbd
                 {0,  4,  0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},//3 seawood
                 {0,  0,  3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},//4 nerul
                 {0,  0,  0, 3, 0, 5, 3, 0, 0, 0, 0, 0, 0},//5 juinagar
                 {0,  0,  0, 0, 5, 0, 3, 0, 3, 0, 0, 0, 0},//6 thurbe
                 {0,  0,  0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0},//7 sanpada
                 {0,  0,  0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},//8 vashi
                 {0,  0,  0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0},//9 kopar
                 {0,  0,  0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0},//10 ghansoli
                 {0,  0,  0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0},//11 rabale
                 {0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 8},//12 airoli
                 {0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0}//thane
};
void main()
{
    int i,j;


    //visited is initialized to zero
    for(i=0;i<n;i++)
        visited[i]=0;

    DFS(1,2,0);
}

void DFS(int src,int dest,int cur)
{
    int j;
    if(cur==dest){
        printf("There exists a path between  Station %d and Station %d",src,dest);
        return;
    }
    visited[cur]=1;

    for(j=0;j<n;j++)
        if(!visited[j]&&G[cur][j]!=0)
            DFS(src,dest,j);
}
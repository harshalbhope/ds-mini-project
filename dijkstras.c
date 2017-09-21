//#include <stdio.h>
//
////
//// Created by Saurav Kanchan on 18-09-2017.
////
//
//
//
//// A C / C++ program for Dijkstra's single source shortest
//// path algorithm. The program is for adjacency matrix
//// representation of the graph.
//#include <limits.h>
//
//// Number of vertices in the graph
//#define V 13
//
//// A utility function to find the vertex with minimum distance
//// value, from the set of vertices not yet included in shortest
//// path tree
//int minDistance(int dist[], int sptSet[]) {
//    // Initialize min value
//    int min = INT_MAX, min_index;
//
//    for (int v = 0; v < V; v++)
//        if (sptSet[v] == 0 && dist[v] <= min)
//            min = dist[v], min_index = v;
//
//    return min_index;
//}
//
//const char *getPlace(int n) {
//    n += 1;
//    switch (n) {
//        case 1:
//            return "Panvel";
//        case 2:
//            return "CBD Belapur";
//        case 3:
//            return "Seawood";
//        case 4:
//            return "Nerul";
//        case 5:
//            return "Jui Nagar";
//        case 6:
//            return "Thurbe";
//        case 7:
//            return "Sanpada";
//        case 8:
//            return "Vashi";
//        case 9:
//            return "Kopar Khairane";
//        case 10:
//            return "Ghansoli";
//        case 11:
//            return "Rabale";
//        case 12:
//            return "Airoli";
//        case 13:
//            return "Thane";
//        default:
//            return "";
//
//
//    }
//}
//
//// Function to print shortest path from source to j
//// using parent array
//
//void printPath(int parent[], int j) {
//    // Base Case : If j is source
//    if (parent[j] == -1)
//        return;
//
//    printPath(parent, parent[j]);
//
//    printf("%s| ", getPlace(j));
//}
//
//// A utility function to print the constructed distance
//// array
//int printSolution(int src,int dist[], int n, int parent[]) {
//    printf("Vertex\t\t Distance\t\tPath");
//    for (int i = 1; i < V; i++) {
//        printf("\n%s -> %s \t\t %d\t\t%s", getPlace(src), getPlace(i), dist[i], getPlace(src));
//        printPath(parent, i);
//    }
//}
//
//// Funtion that implements Dijkstra's single source shortest path
//// algorithm for a graph represented using adjacency matrix
//// representation
//void dijkstra(int graph[V][V], int src) {
//    int dist[V]; // The output array. dist[i] will hold
//    // the shortest distance from src to i
//
//    // sptSet[i] will 1 if vertex i is included / in shortest
//    // path tree or shortest distance from src to i is finalized
//    int sptSet[V];
//
//    // Parent array to store shortest path tree
//    int parent[V];
//
//    // Initialize all distances as INFINITE and stpSet[] as 0
//    for (int i = 0; i < V; i++) {
//        parent[0] = -1;
//        dist[i] = INT_MAX;
//        sptSet[i] = 0;
//    }
//
//    // Distance of source vertex from itself is always 0
//    dist[src] = 0;
//
//    // Find shortest path for all vertices
//    for (int count = 0; count < V - 1; count++) {
//        // Pick the minimum distance vertex from the set of
//        // vertices not yet processed. u is always equal to src
//        // in first iteration.
//        int u = minDistance(dist, sptSet);
//
//        // Mark the picked vertex as processed
//        sptSet[u] = 1;
//
//        // Update dist value of the adjacent vertices of the
//        // picked vertex.
//        for (int v = 0; v < V; v++)
//
//            // Update dist[v] only if is not in sptSet, there is
//            // an edge from u to v, and total weight of path from
//            // src to v through u is smaller than current value of
//            // dist[v]
//            if (!sptSet[v] && graph[u][v] &&
//                dist[u] + graph[u][v] < dist[v]) {
//                parent[v] = u;
//                dist[v] = dist[u] + graph[u][v];
//            }
//    }
//
//    // print the constructed distance array
//    printSolution(src, dist, V, parent);
//}
//
//// driver program to test above function
//int main() {
//    /* Let us create the example graph discussed above */
//    int graph[V][V] = {{0,  13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//1 panvel
//                       {13, 0,  4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//2 cbd
//                       {0,  4,  0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},//3 seawood
//                       {0,  0,  3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},//4 nerul
//                       {0,  0,  0, 3, 0, 5, 3, 0, 0, 0, 0, 0, 0},//5 juinagar
//                       {0,  0,  0, 0, 5, 0, 3, 0, 3, 0, 0, 0, 0},//6 thurbe
//                       {0,  0,  0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0},//7 sanpada
//                       {0,  0,  0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},//8 vashi
//                       {0,  0,  0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0},//9 kopar
//                       {0,  0,  0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 0},//10 ghansoli
//                       {0,  0,  0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0},//11 rabale
//                       {0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 8},//12 airoli
//                       {0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0}//thane
//    };
//
//    dijkstra(graph, 2);
//
//    return 0;
//}

#include "stdio.h"
#include "conio.h"
#define infinity 999
void dij(int n,int v,int cost[10][10],int dist[])
{
    int i,u,count,w,flag[10],min;
    for(i=1;i<=n;i++)
        flag[i]=0,dist[i]=cost[v][i];
    count=2;
    while(count<=n)
    {
        min=99;
        for(w=1;w<=n;w++)
            if(dist[w]<min && !flag[w])
                min=dist[w],u=w;
        flag[u]=1;
        count++;
        for(w=1;w<=n;w++)
            if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
                dist[w]=dist[u]+cost[u][w];
    }
}

void main()
{
    int v,i,j,dist[100],n=13;
    int cost[13][13]={{0,  13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//1 panvel
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
    printf("n Enter the source matrix:");
    scanf("%d",&v);
    dij(n,v,cost,dist);
    printf("n Shortest path:n");
    for(i=1;i<=n;i++)
        if(i!=v)
            printf("%d->%d,cost=%dn",v,i,dist[i]);
    getch();
}
/* C program to implement Dijkstra's algorithm to find shortest cost between any vertex pair */
#include<stdio.h>
#include <string.h>

#define inf 9999
#define size 13/*Defining maximum size of the matrix*/
const char *getPlace(int n) {
    n += 1;
    switch (n) {
        case 1:
            return "Panvel";
        case 2:
            return "CBD Belapur";
        case 3:
            return "Seawood";
        case 4:
            return "Nerul";
        case 5:
            return "Jui Nagar";
        case 6:
            return "Thurbe";
        case 7:
            return "Sanpada";
        case 8:
            return "Vashi";
        case 9:
            return "Kopar Khairane";
        case 10:
            return "Ghansoli";
        case 11:
            return "Rabale";
        case 12:
            return "Airoli";
        case 13:
            return "Thane";
        default:
            return "";


    }
}
int getStation(char stn[100]){
    if (strcmp(stn,"Panvel")==0)
        return 1;
    if (strcmp(stn,"CBD Belapur")==0)
        return 2;
    if (strcmp(stn,"Seawood")==0)
        return 3;
    if (strcmp(stn,"Nerul")==0)
        return 4;
    if (strcmp(stn,"Jui Nagar")==0)
        return 5;
    if (strcmp(stn,"Thurbe")==0)
        return 6;
    if (strcmp(stn,"Sanpada")==0)
        return 7;
    if (strcmp(stn,"Vashi")==0)
        return 8;
    if (strcmp(stn,"Kopar Khairane")==0)
        return 9;
    if (strcmp(stn,"Ghansoli")==0)
        return 10;
    if (strcmp(stn,"Rabale")==0)
        return 11;
    if (strcmp(stn,"Airoli")==0)
        return 12;
    if (strcmp(stn,"Thane")==0)
        return 13;
    return 0;

}

int main()
{
    int i,j,lcost,n=13,v1,v2;
    char sv1[100],sv2[100];
    int a[size][size] = {{0,  13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//1 panvel
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
    int dij(int[size][size],int,int,int);
//    printf("Enter the number of vertex : ");
//    scanf("%d",&n);
///*Input 0 if there is no direct edge between vertex pair*/
//    printf("Enter a weighted matrix(with weights) as input :n");
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            printf("Enter the value of a[%d][%d] : ",i,j);
//            scanf("%d",&a[i][j]);
//        }
//    }
//    printf("The entered matrix is:n");
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//            printf("%dt",a[i][j]);
//        printf("n");
//    }
    printf("Enter starting station:- ");
    scanf("%s",&sv1);
    printf("Enter ending station:- ");
    scanf("%s",&sv2);
    v1=getStation(sv1)-1;
    v2=getStation(sv2)-1;
/*Check for validity of input vertices*/
    if(v1<0||v1>n-1||v2<0||v2>n-1)
    {
        printf("!!!!!ERROR!!!!!n");
        printf("!!!!!Invalid station given!!!!!");
        return 0;
    }
    printf("Shortest path between %s & %s : \n", getPlace(v1),getPlace(v2));
    lcost=dij(a,n,v1,v2);
    printf("Shortest distance between  %s & %s: ",getPlace(v1),getPlace(v2));
    printf("%d",lcost);/*Print the shortest cost*/
}

int dij(int a[size][size],int n,int v1,int v2)
{
    int length[size],set[size],path[size],i,j,s,z,tmp,temp[size],c=0,f=0;
    s=v1;
    z=v2;
    int srch_min(int[],int[],int);
    for(i=0;i<n;i++)
        set[i]=0;
    for(i=0;i<n;i++)
    {
        if(a[s][i]==0)/*There is no direct edge between vertices s and i*/
        {
            length[i]=inf;
            path[i]=0;/*Empty path*/
        }
        else
        {
            length[i]=a[s][i];
            path[i]=s;/*s is immediate predecessor of i*/
        }
    }
    set[s]=1;/*s is included in the set*/
    length[s]=0;/*s is implicitly enumerated with length as 0*/
    while(set[z]!=1)/*Iteration will be considered until final vertex z belongs to s*/
    {
        j=srch_min(length,set,n);/*Select a vertex j with minimum label such that it is not included in the set[]*/
        set[j]=1;/*Vertex j is included in the set[]*/
        for(i=0;i<n;i++)
        {
            if(set[i]!=1)
            {
                if(a[i][j]!=0)
                {
                    if(length[j]+a[i][j]<length[i])/*When exsisting label is not minimum only then replacement is done*/
                    {
                        length[i]=length[j]+a[i][j];
                        path[i]=j;
                    }
                }
            }
        }
    }
    j=0;
    i=z;
    while(i!=s)
    {
        tmp=path[i];
        temp[j]=tmp;
        i=tmp;
        j++;
        c++;
    }
    for(j=c-1;j>=0;j--)
    {
        printf("%s -> ",getPlace(temp[j]));/*Print the shortest path*/
        if(temp[j]==z)
            f=1;
    }
    if(f!=1)
        printf("%s",getPlace(z));
    printf("\n");
    return length[z];
}
/*This function will return a vertex with minimum label such that it is not included in set[]*/
int srch_min(int length[],int set[],int n)
{
    int min,i,min_index;
    min=99999,min_index;
    for(i=1;i<n;i++)
    {
        if(set[i]!=1)
        {
            if(length[i]<min)
            {
                min=length[i];
                min_index=i;
            }
        }
    }
    return min_index;
}

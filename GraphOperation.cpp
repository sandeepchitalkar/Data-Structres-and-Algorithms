#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stack>
#include <queue> 

using namespace std;

float edge[15][15];
bool visit[15];
class City{
public:
    string name;
};

void BFS(City* ptr, int n)
{ int count = 0;
  int v1,v2;
  queue<int>itr;
  cout<<"\n Enter The Starting city Number ";  
  cin>>v1;
  visit[v1] = 1;
  cout<<"\n ---------- BFS ---------- ";
  itr.push(v1);
  while(! itr.empty())
  {
    v1 = itr.front();
    itr.pop();
    
    if(count > n-1)
          cout<<ptr[v1].name;     
    else
          cout<<ptr[v1].name<<"->";
          
    for(int v2 = 0;v2<n;v2++) 
         if(edge[v1][v2] != -1 && visit[v2] != 1)
               { itr.push(v2);
                  visit[v2] = 1;
                  count++;
                }
  }
  
     for(int i =0;i<15;i++)
        visit[i] = 0;
}

void DFS(City *ptr , int n)
{  int count = 0;
   int v1,v2;
   stack<int>itr;
   cout<<"\n Enter The Starting City ";
   cin>>v1;
   itr.push(v1);
   visit[v1] = 1;
   cout<<"\n ---------- DFS ---------- ";
   while(!itr.empty())
   { 
     v1 = itr.top();
     itr.pop();
     
    if(count > n-1 )
          cout<<ptr[v1].name;     
    else
          cout<<ptr[v1].name<<"->";
          
     for(int v2 = 0;v2<n;v2++)
         if(edge[v1][v2] != -1 && visit[v2] != 1)
              { itr.push(v2);  
                visit[v2] = 1;
                count++;
                }   
   }
   
        for(int i =0;i<15;i++)
        visit[i] = 0;
}

void adj_mat(City* ptr , int n)
{
  cout<<"\n ------- Adjacent Matrix ------- "<<endl;

  cout<<setw(9)<<" ";
  for(int index = 0; index < n; index++)
           cout<<setw(10)<<ptr[index].name;

  cout<<endl;
 
  for(int i = 0;i<n;i++){
       cout<<"\n"<<setw(9)<<ptr[i].name<<"|";
       for(int j=0;j<n;j++)
             cout<<setw(10)<<edge[i][j];
   }
}


void adj_list(City *ptr,int n)
{
  cout<<"\n ------- Adjacency List ------- "<<endl;
  for(int i=0 ; i<n ; i++){
       cout<<"\n\n"<<ptr[i].name<<"->";
     for(int j=0; j<n; j++)
           if(edge[i][j] != -1)
                 cout<<ptr[j].name<<" - ";
 }
}




int main()
{   
   for(int i = 0;i < 15; i++)
       for(int j = 0;j<15;j++)
          edge[i][j] = edge[j][i] = -1;
          
   for(int i =0;i<15;i++)
        visit[i] = 0;
        
   City *ptr;
   int n,op,v1,v2;
   float time;
   cout<<"\n Enter The Number oF Citites Want To Add In Graph : ";
   cin>>n;
   ptr = new City[n];
   cout<<"\n Enter The Name Of Cities ";
   for(int i = 0;i < n ;i++){
         cout<<"\n"<<i<<". ";
         cin>>ptr[i].name;
  }
while(1){
x:  cout<<"\n\n 1. Enter The Time of Flight Between Two Cities (IN MIN) "
      <<"\n 2. Storage Representation "
      <<"\n 3. BFS Traversal "
      <<"\n 4. DFS Traversal "
      <<"\n 5. Exit "
      <<"\n\n Enter The OpTion : ";
  cin>>op;
 
  switch(op) {
     
       case 1:
              cout<<"\n Enter The Number of Two Cities ";
              cin>>v1>>v2;
              if( (v1>-1) && (v2>-1) && (v1<n) && (v2<n) )  {
                  cout<<"\n Enter The Time of Flight Between "<<ptr[v1].name<<" And "<<ptr[v2].name<<" : ";
                  cin>>time;
                  edge[v1][v2] = edge[v2][v1] = time; 
              }

              else 
                  cout<<"\n The City Number is Invalid ";
              break;

       case 2:
            y:   cout<<"\n\n 1. Adjacent Matrix "
                   <<"\n 2. Adjacency List "
                   <<"\n 3. Return To Main Menu "
                   <<"\n Enter Option ";
               cin>>op;
            
               switch(op) {
                 case 1:
                        adj_mat(ptr,n);
                        break;
                 case 2:
                        adj_list(ptr,n);
                        break;   
                 case 3:
                        goto x;
                 default:
                        cout<<"\n Invalid Option ";
                        break;
               }
               goto y;

       case 3:
              BFS(ptr,n);
              break;

       case 4: 
             DFS(ptr,n);
             break;

       case 5:
             exit(0);

       default:
               cout<<"\n Invalid Option ";
               break;

  } 
}
  delete(ptr);
}

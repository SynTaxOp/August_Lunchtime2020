#include<bits/stdc++.h>
#include<chrono>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector <pair<int,int>> vp;
typedef pair<long long,long long> pl;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
#define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i++:i--)
#define fa(i,N)  for(auto i:N)
#define gi map <int,si>
#define gc map <char,set<char>>
#define all(X) X.begin(), X.end()
#define all(X) X.begin(), X.end()
#define T5 100001
#define mod 1000000007
int m[500][500];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto start = chrono::high_resolution_clock::now(); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    int tc=0;
    while((tc++)<t)
    {
      int N,M;
      cin>>N>>M;
      vi IR(N); //Intital Ratings.
      vi temp(N); //A temporary Vector of size N.
      pi rating[N]; //A array of pair cointaining best rating and the month on which that is acheived for all N players
      pi rank[N]; //A array of pair cointaining best rank and the month on which that is acheived for all N players
      fo(i,0,N) //Initializing rank and rating with high values. 
      {
        rank[i]={1000,-1}; 
        rating[i]={1500,-20}; 
      }
      fo(i,0,N)
      {
        cin>>IR[i]; //Taking Initial ratings as input.
      }
      int a;
      fo(i,0,N)
      {
        fo(j,0,M)
        {
          cin>>m[i][j];  //Storing changes in ratings in a 2D matrix
        }
      }
     int ct=0; 
     fo(i,0,M)  //A loop for M months
     {
       fo(j,0,N) //A loop for N players
       {
         IR[j]+=m[j][i]; //Updating the rating of all players
         if(IR[j]>rating[j].first){rating[j].first=IR[j];rating[j].second=i;} //If max rating achieved,change the max rating and the month
       }
       temp=IR;
       sort(all(temp),greater<int>()); //Sorting current ratings into desending order
       fo(j,0,N) 
       {
         auto itr=find(temp.begin(),temp.end(),IR[j]); //Finding the rank of the jth player in the sorted vector
         int rk=itr-temp.begin()+1; //Calculating rank
         if(rk<rank[j].first){rank[j].first=rk;rank[j].second=i;} //If best rank achieved,change the best rank and the month
       }
     }
     fo(j,0,N)
     {
        if(rank[j].second !=rating[j].second){ct++;}  //if the month when max ratings is achieved is not equal to the month when best rank is achieved,increment the counter
     }
     cout<<ct<<endl; //Printing count(Answer)
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken =  
    chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    time_taken *= 1e-9; 
    #ifndef ONLINE_JUDGE
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl;  
    #endif
    
  }
  

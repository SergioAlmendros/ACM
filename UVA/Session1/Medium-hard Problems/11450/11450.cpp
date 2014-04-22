#include <iostream>
#include <vector>
#include <set>
using namespace std;

int maxMoney = -1;
set<pair<int,int> > rep;

void printVectorOfVector(vector<vector<int> > &v){

  for(int i=0; i<int(v.size()); ++i){
    for(int j=0; j<int(v[i].size()); ++j){
      cout<<" "<<v[i][j];
    }
    cout<<endl;
  }
  cout<<endl;

}

void best(int c, int s, int cmax, int m,vector<vector<int> > &v){

  if(c == cmax){
    if(s <= m && s > maxMoney)
      maxMoney = s;
    return;
  }
  
  if(rep.find(make_pair(c,s)) != rep.end()){
  
    return;
  }else{
    rep.insert(make_pair(c,s));
  }
  
  if(s > m) return;
  
  for(int i=0; i< int(v[c].size()); ++i){
  
    best(c+1,s+v[c][i],cmax,m,v);
    
  }
  
}

int main(){

  int n,m,c,k,x;
  cin>>n;
  vector<vector<int> > v;
  
  for(int i=0; i<n; i++){
    cin>>m;
    cin>>c;
    v.resize(c);
    for(int j=0; j<c; j++){
      cin>>k;
      v[j].resize(k);
      for(int w=0; w<k; w++){
        cin>>x;
        v[j][w] = x;
      }
    }   

    best(0,0,c,m,v);
    
    if(maxMoney == -1)
      cout<<"no solution"<<endl;
    else
      cout<<maxMoney<<endl;
    
    v.clear();
    rep.clear();
    maxMoney = -1;
    
  }
  
  return 0;
  
  
}












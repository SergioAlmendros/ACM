#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int length = 100;
int width = 75;

void printVector(vector<float> &v){

  for(int i=0; i<int(v.size()); ++i){
    cout<<" "<<v[i];
  }
  cout<<endl;

}

void printVectorofPairs(vector<pair<float,float> > &v){

  for(int i=0; i<int(v.size()); ++i){
  
    cout<<"("<<v[i].first<<", "<<v[i].second<<")"<<endl;
  
  }

}

void makePairsL(vector<float> &vl,vector<pair<float,float> > &vpl, float m){

  float x,y;
  //cout<<m/2<<endl;
  for(int i=0; i<int(vl.size()); ++i){
    
    x = vl[i] - m/2;
    if(x < 0) x = 0;
    y = vl[i] + m/2;
    if(y > 75) y = 75;
    
    vpl.push_back(make_pair(x,y));
    
  }
  //printVectorofPairs(vpl);
}

void makePairsW(vector<float> &vl,vector<pair<float,float> > &vpl, float m){

  float x,y;
  //cout<<m/2<<endl;
  for(int i=0; i<int(vl.size()); ++i){
    
    x = vl[i] - m/2;
    if(x < 0) x = 0;
    y = vl[i] + m/2;
    if(y > 100) y = 100;
    
    vpl.push_back(make_pair(x,y));
    
  }
  //printVectorofPairs(vpl);
}

bool checkPairs(vector<pair<float,float> > &vpl,vector<pair<float,float> > &vpw){

  //LENGTH
  if(vpl[0].first != 0.0)
    return false;
  if(vpl[int(vpl.size())-1].second != 75.0)
    return false;
    
  for(int i=0; i<int(vpl.size())-1; ++i){
    
    if(vpl[i].second < vpl[i+1].first)
      return false;
    
  }  
  
  //WIDTH
  if(vpw[0].first != 0.0)
    return false;
  if(vpw[int(vpw.size())-1].second != 100.0)
    return false;
    
  for(int i=0; i<int(vpw.size())-1; ++i){
    
    if(vpw[i].second < vpw[i+1].first)
      return false;
    
  }
  
  return true;
}

int main(){

  int l,w;
  float m,x;
  vector<float> vl,vw;
  vector<pair<float,float> > vpl,vpw;
  
  while(true){
  
  
    cin>>l>>w>>m;
    if(l == 0 && w == 0 && m == 0.0)
      break;
    //cout<<l<<" "<<w<<" "<<m<<endl;
    
    for(int i=0; i<l; ++i){
      cin>>x;
      vl.push_back(x); 
    }
    for(int i=0; i<w; ++i){
      cin>>x;
      vw.push_back(x); 
    }
    
    sort(vl.begin(),vl.end());
    //printVector(vl);
    makePairsL(vl,vpl,m);
    
    sort(vw.begin(),vw.end());
    //printVector(vw);
    makePairsW(vw,vpw,m);
    
    if( checkPairs(vpl,vpw) )
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;    
    
    vl.clear();
    vw.clear();
    vpw.clear();
    vpl.clear();
  }

}





















#include <iostream>
#include <vector>

using namespace std;

struct line {
  pair<int,int> pi;
  pair<int,int> pf;
};

void printVectorLines(vector<line> &vl){

  for(int i=0; i<int(vl.size()); i++){
    cout<<"("<<vl[i].pi.first<<","<<vl[i].pi.second<<") --> ";
    cout<<"("<<vl[i].pf.first<<","<<vl[i].pf.second<<")"<<endl;
  } 

}

int main(){

  int vertex,p1,p2,maxy=0;
  vector<pair<int,int> > v;
  pair<int,int> p;
  vector<line> vl;
  
  while(cin >> vertex){
    if(vertex == 0) break;
    maxy=0;
    v.clear();
    vl.clear();
    
    for(int i=0; i<vertex; i++){
      
      cin >> p1 >> p2;
      //cout<<p1<<"-"<<p2<<endl; 
      v.push_back(make_pair(p1,p2));
      if(maxy < p2) maxy = p2;
    }
    v.push_back(v[0]);
    cin >> p1 >> p2;
    //cout<<p1<<"-"<<p2<<endl;
    p = make_pair(p1,p2);
    //cout<<int(v.size())<<endl;
    
    for(int i=1; i<int(v.size()); i++){
    
      //cout<<"("<<v[i-1].first<<","<<v[i-1].second<<") --> ";
      //cout<<"("<<v[i].first<<","<<v[i].second<<")"<<endl;
      
      if(v[i-1].first != v[i].first){
        line l;
        if(v[i-1].first > v[i].first){
          l.pf = v[i-1];
          l.pi = v[i]; 
        }else if(v[i-1].first <= v[i].first){
          l.pi = v[i-1];
          l.pf = v[i]; 
        }
        vl.push_back(l);
        
      }
    }
    
    //printVectorLines(vl);
    
    int c = 0;
    while(true){
      for(int i=0; i<int(vl.size()); i++){
        if(vl[i].pi.second == p.second && p.first >= vl[i].pi.first && p.first <= vl[i].pf.first )
          c++;
      }
      p.second++;
      if(p.second > maxy) break;
    }
    //cout<<c<<endl;
    if(c%2 == 0) cout<<"F"<<endl;
    else cout<<"T"<<endl;
    
  }

}



























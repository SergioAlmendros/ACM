#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct line{
  int xs;
  int ys;
  int xe;
  int ye;
};

struct square{
  pair<int,int> lb; //Left-bottom
  pair<int,int> lt;
  pair<int,int> rt;
  pair<int,int> rb;
};

int cross(pair<int,int> a, pair<int,int> b){
  return a.first*b.second - a.second*b.first;
}

bool intersect(line a, line b){
  
  pair<int,int> va = make_pair(a.xe-a.xs,a.ye-a.ys);
  pair<int,int> vb = make_pair(b.xe-b.xs,b.ye-b.ys);
  
  pair<int,int> ab = make_pair(a.xs-b.xs,a.ys-b.ys);
  
  if(cross(va,vb) == 0) return false;
  
  float s = (cross(ab,va))/(cross(va,vb));
  float t = (cross(ab,vb))/(cross(va,vb));
  
  if(s >= 0.0 && s <= 1.0 && t >= 0.0 && t <= 1.0)
    return true;
  
  return false;
}

void print(vector<line> &v){

  for(int i=0; i<int(v.size()); i++){
    cout<<"("<<v[i].xs<<","<<v[i].ys<<") --> ";
    cout<<"("<<v[i].xe<<","<<v[i].ye<<")"<<endl;
  }

}

int main(){

  int n;
  bool intrs = false;
  
  cin >> n;
  line l,l2;
  square s;
  vector<line> v,h; //Lineas verticales, y lineas horizontales
  
  for(int i=0; i<n; i++){
  
    cin >> l.xs;
    cin >> l.ys;
    cin >> l.xe;
    cin >> l.ye;
    
    cin >> s.lt.first;
    cin >> s.lt.second;
    cin >> s.rb.first;
    cin >> s.rb.second;
    
    s.lb.first = s.lt.first;
    s.lb.second = s.rb.second;
    s.rt.first = s.rb.first;
    s.rt.second = s.lt.second;
    
    l2.xs = s.lb.first;
    l2.ys = s.lb.second;
    l2.xe = s.lt.first;
    l2.ye = s.lt.second;
    v.push_back(l2);
    
    l2.xs = s.rb.first;
    l2.ys = s.rb.second;
    l2.xe = s.rt.first;
    l2.ye = s.rt.second;
    v.push_back(l2);
    
    l2.xs = s.lb.first;
    l2.ys = s.lb.second;
    l2.xe = s.rb.first;
    l2.ye = s.rb.second;
    v.push_back(l2);
    
    l2.xs = s.lt.first;
    l2.ys = s.lt.second;
    l2.xe = s.rt.first;
    l2.ye = s.rt.second;
    v.push_back(l2);
    
    //print(v);
    
    for(int j=0; j<int(v.size()); j++){
      if(intersect(l,v[j])){
        //cout<<"entra2"<<endl;
        intrs = true;
        break;
      }
    }
    
    
    if(intrs)
      cout<<"T"<<endl;
    else
      cout<<"F"<<endl;
      
    intrs = false;
    v.clear();
    
  }
  return 0;
}




















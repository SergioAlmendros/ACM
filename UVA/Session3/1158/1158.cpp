#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printVector(vector<int> &v){
  
  cout<<"\n PrintVector"<<endl;
  for(int i=0; i<int(v.size()); ++i){
    cout<<v[i]<<endl;
  }
  cout<<endl;

}

int main(){

  int n;
  double c2=0;
  int i=0;
  set<int> v; //monedas
  int max = 400000;
  int res[400001];
  
  bool a = false, b = false;
  while(!a || !b){
    
    i++;
    c2 += i*i;
    if( c2 <= max ){
      v.insert(c2);
    }else a = true;
    
    if( i*i*i <= max ){
      v.insert(i*i*i);
    }else b = true;
  }
  res[0] = 0;
  
  for (int c = 1; c <= max; ++c) {
    res[c] = c;
    for(set<int>::iterator it = v.begin(); it != v.end(); it++){
      //cout << " " << *it;
      if (*it <= c && 1 + res[c - *it] < res[c])
        res[c] = 1 + res[c - *it];
    }
  }
  
  while(true){
  
    cin >> n;
    if(n == -1) break;
    cout << res[n] << endl;
  }
  
  return 0;

}


























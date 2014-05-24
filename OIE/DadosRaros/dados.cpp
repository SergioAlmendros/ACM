#include <iostream>
#include <vector>

using namespace std;

int main(){

  int t,y,k,n;
  vector<int> v; //caras
  
  cin >> t;
  //cout<<t<<endl;
  for(int i=0; i<t; ++i){
  
    cin >> y >> k >> n;
    //cout<<y<<" "<<k<<" "<<n;
    v.resize(n);
    for(int j=0; j<n; ++j){
      cin >> v[j];
      //cout<<" "<<v[j];
    }
    //cout<<endl;
  
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){

  int in,ind = 0;
  bool endline = false;
  vector<vector<int> > v;
  vector<int> v2;
  
  while(cin >> in){
    
    if(in == 0 && endline == false){
      endline = true;
      ind ++;
      cout<<1<<endl;
    }else if(in > 0){
      endline = false;
      v.push_back(v2);
      v[ind].push_back(in);
      cout<<2<<endl;
    }else if(in == 0 && endline == true)
      cout<<3<<endl;
      break;
  }
  
  cout<<"size: "<<int(v.size())<<endl;

  return 0;
}

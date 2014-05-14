#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int A[4098];

int toInt(string s){
  
  int sum = 0;
  for(int i=0; i<int(s.length()); ++i){
    if(s[i] == '1') sum += pow(2,int(s.length())-i-1);
  }
  return sum; 
}

int main(){

  string s;
  int n;
  getline(cin,s);
  
  while(getline(cin,s)){
    
    while (s.find("o")!=std::string::npos)
      s.replace(s.find("o"),1,"1");
    while (s.find("-")!=std::string::npos)
      s.replace(s.find("-"),1,"O");
    //cout<<s<<endl;
    n = toInt(s);
    //cout<<n<<endl;
    
    cout<<((n & 7)>>1)<<endl;
    
    
  }

}


















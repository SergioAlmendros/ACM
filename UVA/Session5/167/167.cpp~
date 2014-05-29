#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int queen[8];
int maxv=0;

int B[8][8];

bool good(int k, int i){

  for(int j=0; j<k; j++){
  
    if( queen[j] == i )
      return false;
    
    if( abs(j - k) == abs(queen[j] - i) )
      return false;
  
  }
  
  return true;

}

void pos(int k){

  if( k == 8 ){
    //cout<<"Found a solution"<<endl;
    int c = 0;
    for(int i=0; i<8; i++){
      c += B[i][queen[i]];
      //cout<<" "<<B[i][queen[i]];
    }
    //cout<<endl;
    if(maxv < c) maxv = c;
    
  }else{
    for(int i=0; i<8; i++){
      if( good(k,i) ){
      
        queen[k] = i;
        pos(k+1);
      
      }
    }
  }
}

int main(){

  int k;
  
  cin >> k;
  string r;
  
  
  for(int l=0; l<k; l++){
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++)
        cin >> B[i][j];
    }
    pos(0);
    
    ostringstream convert;
    convert << maxv;
    r = convert.str();
    
    while(int(r.length()<5)){
      r = " " + r;
    }
    cout<<r<<endl;
    
    maxv = 0;
  }
  
  
}


























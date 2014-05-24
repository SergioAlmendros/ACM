#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m;

long long comb[52][52][52]; //n,k,m

int main(){

  int n,k;

  for(int k=1; k<=50; k++){
    for(int i=0; i<=50; i++){
      for(int j=0; j<=50; j++){        
        
        if(i==0 && j==0){
          comb[i][j][k] = 1;
        }else if(i==0 || j==0){
          comb[i][j][k] = 0;
        }else{
          long long kk = 0;
          for(int l=1; l<=k && i-l>=0 && j-1 >= 0; l++){
            kk += comb[i-l][j-1][k];
          }
          comb[i][j][k] = kk;
        
        }
      }
    }
  }
  
  while(cin >> n >> k >> m){
    cout<<comb[n][k][m]<<endl;
  }
  
  return 0;
}

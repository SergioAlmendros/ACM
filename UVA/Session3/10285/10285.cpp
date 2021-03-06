#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[101][101];
int n,r,c;
int ch = 0;

bool any(int i, int j){
  
  if(i > 0)
    if(A[i-1][j] < A[i][j])
      return true;
  
  if(i < r-1)
    if(A[i+1][j] < A[i][j])
      return true;
  
  if(j > 0)
    if(A[i][j-1] < A[i][j])
      return true;
      
  if(j < c-1)
    if(A[i][j+1] < A[i][j])
      return true;
  
  return false;
}

int max4(int a, int b, int c, int d){

  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  sort(v.begin(), v.end());
  //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<endl;
  return v[3];
}

int snow(int i, int j){
  
  //cout<<"("<<i<<","<<j<<")"<<endl;
  
  int a1,a2,a3,a4;
  a1 = 0;
  a2 = 0;
  a3 = 0;
  a4 = 0;
  
  if(!any(i,j)) return 1; 
  else{
    
    if(i > 0)
      if(A[i-1][j] < A[i][j])
        a1 = snow(i-1,j);
    
    if(i < r-1)
      if(A[i+1][j] < A[i][j])
        a2 = snow(i+1,j);
    
    if(j > 0)
      if(A[i][j-1] < A[i][j])
        a3 = snow(i,j-1);
        
    if(j < c-1)
      if(A[i][j+1] < A[i][j])
        a4 = snow(i,j+1);
        
    
    return 1 + max4(a1,a2,a3,a4);
    
  }
  
  return -1;
  
}

int main(){

  
  string name;
  vector<int> v;
  
  cin >> n;
  //cout<<n<<endl;
  for(int i=0; i<n; ++i){
    cin >> name >> r >> c;
    //cout<<name<<" "<<r<<" "<<c<<endl;
    for(int j=0; j<r; j++){
      for(int k=0; k<c; ++k){
        cin >> A[j][k];
        //cout<<" "<<A[j][k];
      }
      //cout<<endl;
    }
    
    for(int j=0; j<r; j++){
      for(int k=0; k<c; ++k){
        v.push_back(snow(j,k));
      }
    }
    sort(v.begin(), v.end());
    cout<<name<<": ";
    cout<<v[int(v.size())-1]<<endl;
    
    //cout<<snow(0,1)<<endl;
    
    for(int j=0; j<r; j++){
      for(int k=0; k<c; ++k){
        A[j][k] = 0;
      }
    }
    v.clear();
  }  

}

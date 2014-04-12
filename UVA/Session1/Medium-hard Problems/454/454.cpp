#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Pares unicos ordenados alfabeticamente
//Cada linea debe estar ordenada alfabeticamente

void printVector(vector<string> &v){

  for(int i=0; i<int(v.size()); i++){
    cout<< " " << v[i] << endl;
  }

}

void printVectorPairs(vector<pair<string,string> > &v){

  for(int i=0; i<int(v.size()); i++){
  
    cout<< v[i].first << "-" << v[i].second << endl;
  
  }

}

bool anagram(string a, string b){

  while (a.find(" ")!=std::string::npos){
    a.replace(a.find(" "),1,"");}
  while (b.find(" ")!=std::string::npos){
    b.replace(b.find(" "),1,"");}
    
  if(a.size() != b.size())
    return false;
  
  //cout << a << "-" << b << endl;
  
    
  while(a.size() > 0){
    if(b.find(a[0])!=std::string::npos){
      //cout << a << "-" << b << endl;
      b.replace(b.find(a[0]),1,"");
      a.replace(0,1,"");
    }else{return false;}
  }
  
  
  return true;

}
/*bool compare_by_pair(const pair& lhs, const pair& rhs) {

  if(int(lhs.first)
    return lhs.word < rhs.word;
}*/


void deleteRepetedPairs(vector<pair<string,string> > &v){

  vector<pair<string,string> > v2;
  for(int i=0;i<int(v.size()); i++){
    if( find(v2.begin(), v2.end(), v[i] != v2.end() )
      v2.push_back(v[i]);  
  }
  
  for(int i=0;i<int(v2.size()); i++){
    if( find(v2.begin(),v2.end(), make_pair(v2[i].second,v2[i].first)) != v2.end()){
      
      //Saber cual es el primero alfabeticamente
      //Poner los dos pares en dos strings, meterlo en 1 vector, y ordenarlo con un sort directamente.
      //Guardarlo en otro vector  
      
    }
  }

}


int main(){

  vector<string> v;
  vector<pair<string,string> > vp;
  string s;
  int t;
  cin>>t;
  int c=2;
  
  for(int i=0; i<t;i++){
    while(getline(cin,s)){
      if(c == 0){
        if(s == "")
          break;

          
        v.push_back(s);
      }
      c--;
      if(c<0) c = 0;
    }
    //printVector(v);
    
    for(int i=0; i<int(v.size()); i++){
      for(int j=0; j<int(v.size()); j++){
        
        if(i!=j){
        
          if(anagram(v[i],v[j])){
            //cout << v[i] << " = " << v[j] << endl;
            vp.push_back(make_pair(v[i],v[j]));
          }
        }  
        
      }  
    }
    printVectorPairs(vp);
    cout << "---------------" << endl;
    deleteRepetedPairs(vp);
    v.clear();
    vp.clear();
  }
  
}

















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


void addNonRepetedPairs(vector<pair<string,string> > &v){

  //printVectorPairs(v);

  vector<pair<string,string> > vf;

  int i = 0;
  
  while(!v.empty()){
  
    vf.push_back(v[0]);
    v.erase(v.begin()+0);
    
    
    vector<pair<string,string> >::iterator position = find(v.begin(), v.end(), vf[i]);
    if (position != v.end())
      v.erase(position);
      
    position = find(v.begin(), v.end(), make_pair( vf[i].second,vf[i].first ));
    if (position != v.end())
      v.erase(position);
    
    i++;
  }
    //cout<<endl;
    //printVectorPairs(vf);
  
  v = vf;
  vf.clear();
  


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
    //cout << "----" << endl;
    sort(v.begin(),v.end());
    
    for(int j=0; j<int(v.size()); j++){
      for(int k=0; k<int(v.size()); k++){
        
        if(j!=k){
        
          if(anagram(v[j],v[k])){
            //cout << v[i] << " = " << v[j] << endl;
            vp.push_back(make_pair(v[j],v[k]));
          }
        }  
        
      }  
    }
    //printVectorPairs(vp);
    //cout << "---------------" << endl;
    addNonRepetedPairs(vp);
    //printVectorPairs(vp);
    
    for(int j=0; j<int(vp.size()); ++j){
    
      cout<< vp[j].first << " = " << vp[j].second << endl;
    
    }
    if(i+1 < t)
      cout<<endl;
    v.clear();
    vp.clear();
  }
  
}

















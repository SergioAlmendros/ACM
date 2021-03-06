#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void printVector(vector<vector<int> > &v){
  
  for(int i=0; i<int(v.size())-1; i++){
    for(int j=0; j<int(v[i].size()); j++)
      cout<<" "<<v[i][j];
    cout<<endl;
  }
  
}

int main(){

  int in,ind = 0;
  bool endline = false, done;
  vector<vector<int> > v;
  vector<int> v2;
  v.push_back(v2);
  
  while(cin >> in){
    
    //cout<<in<<":"<<endl;
    if(in == 0 && endline == false){
      endline = true;
      ind ++;
      v.push_back(v2);
      //cout<<" 1"<<endl;
    }else if(in > 0){
      endline = false;
      v[ind].push_back(in);
      //cout<<" 2"<<endl;
    }else if(in == 0 && endline == true){
      //cout<<" 3"<<endl;
      break;
    }
  }
  
  //printVector(v);
  //cout<<int(v.size())<<endl;
  
  int segmax = 5*60*60; //5 horas
  int tiempo;
  int eureka = 0;
  int hours, minutes, seconds;
  string h,m,s;          
  ostringstream convert;
  
  for(int i=0; i<int(v.size())-1; i++){
  
    //cout<<"entra"<<endl;
    sort(v[i].begin(),v[i].end());
    done = false;
    //cout<<v[i][0]<<"-"<<int(v[i].size())<<endl;
    
    for(int j=v[i][0]; j<=segmax; j++){
      
      eureka = 0;
      //Calcular por cada semaforo si en este segundo estan en verde
      //Verde: 0 hasta v[i][j]-5
      //Naranja: v[i][j]-5 hasta v[i][j]
      //Rojo: v[i][j] hasta 2*v[i][j]
      
      for(int k=0; k<int(v[i].size()); k++){
      
        tiempo = j % (2 * v[i][k]); //Esta operacion me dira si esta en Verde, Naranja, o rojo.
        if( tiempo < v[i][k]-5 ){
          eureka++;
        }else break;
                
      }
      if(eureka == int(v[i].size())){
        
        //cout<<j<<endl;
        
        hours = (j / 60 / 60) % 24;
        minutes = (j / 60) % 60;
        seconds = j % 60;

        convert << hours;
        h = convert.str();
        convert.str("");
        convert.clear();
        
        convert << minutes;
        m = convert.str();
        convert.str("");
        convert.clear();
        
        convert << seconds;
        s = convert.str();
        convert.str("");
        convert.clear();
        
        if(h.size() < 2) h = "0" + h;
        if(m.size() < 2) m = "0" + m;
        if(s.size() < 2) s = "0" + s;
        
        cout<<h<<":"<<m<<":"<<s<<endl;
        done = true;
        break; 
         
      }
    }
    if(!done) cout<<"Signals fail to synchronise in 5 hours"<<endl;
      
  
  }

  return 0;
}





























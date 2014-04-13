#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <list>
using namespace std;

void printVectorPairs(vector<pair<string,string> > &v){

  for(int i=0; i<int(v.size()); i++){
  
    cout<< v[i].first << "-" << v[i].second << endl;
  
  }

}

void printVector(vector<string> &v){

  for(int i=0; i<int(v.size()); i++){
    cout<< "  " << v[i] << endl;
  }

}

void printSet(set<string> &s){

  for(set<string>::iterator it = s.begin(); it != s.end(); it++){
    cout << "  " << *it;
  }
  cout<<endl;

}

void findChild(string f, string m, map<string,string> &m1, map<string,vector<string> > &m2, set<string> &vs){

  vector<pair<string,string> > v;
  
  //cout << f << " could be:" << endl;
  for(int i=0; i<int(m2[f.substr(0,f.length()-1)].size()); ++i){

    //cout << " " << m2[f.substr(0,f.length()-1)][i] << endl;
    
    for(int j=0; j<int(m2[m.substr(0,m.length()-1)].size()); ++j){
      
      v.push_back(make_pair(m2[f.substr(0,f.length()-1)][i], m2[m.substr(0,m.length()-1)][j]));
      
    }

  }
  
  //printVectorPairs(v);
  string a,b,c,d;
  string p6 = "+";
  string p7 = "-";
  
  for(int i=0; i<int(v.size()); ++i){
    
    a = v[i].first[0];
    b = v[i].second[0];
    c = a+b;
    if(m1.find(c) != m1.end()){
          d = m1[c] + p6;
          vs.insert(d);
          d = m1[c] + p7;
          vs.insert(d);
        }
      
    b = v[i].second[1];
    c = a+b;
    if(m1.find(c) != m1.end()){
          d = m1[c] + p6;
          vs.insert(d);
          d = m1[c] + p7;
          vs.insert(d);
        }
    
    a = v[i].first[1];
    b = v[i].second[0];
    c = a+b;
    if(m1.find(c) != m1.end()){
          d = m1[c] + p6;
          vs.insert(d);
          d = m1[c] + p7;
          vs.insert(d);
        }
    
    b = v[i].second[1];
    c = a+b;
    if(m1.find(c) != m1.end()){
          d = m1[c] + p6;
          vs.insert(d);
          d = m1[c] + p7;
          vs.insert(d);
        }
    
  }
  //printSet(vs);

}

void findParent(string p, string h, map<string,string> &m1, map<string,vector<string> > &m2, set<string> &vs){
  
  h = h.substr(0,h.length()-1);
  
  list<string> s;
  s.push_back("AA");
  s.push_back("AB");
  s.push_back("AO");
  s.push_back("BB");
  s.push_back("BO");
  s.push_back("OO");
  
  string p2,p3,p4,p5;
  string p6 = "+";
  string p7 = "-";
  
  for(int i=0; i<int(m2[p.substr(0,p.length()-1)].size()); ++i){
    p2 = m2[p.substr(0,p.length()-1)][i];
    for(list<string>::iterator it = s.begin(); it != s.end(); it++){
  
      p4 = p2[0];
      p5 = (*it)[0];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
        
      p4 = p2[0];
      p5 = (*it)[1];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = p2[1];
      p5 = (*it)[0];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = p2[1];
      p5 = (*it)[1];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = (*it)[0];
      p5 = p2[0];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = (*it)[0];
      p5 = p2[1];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = (*it)[1];
      p5 = p2[0];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
      p4 = (*it)[1];
      p5 = p2[1];
      p3 = p4 + p5;
      if(m1.find(p3) != m1.end())
        if(m1[p3] == h){
          p4 = m1[(*it)] + p6;
          vs.insert(p4);
          p4 = m1[(*it)] + p7;
          vs.insert(p4);
        }
      
    
    }
  }
  
  //printSet(vs);

}

void printSet2(set<string> &s){

  int siz = s.size();
  cout << "{";
  for(set<string>::iterator it = s.begin(); it != s.end(); it++){
    cout << *it;
    if(siz > 1)
      cout << ", ";
    
    siz--;
  }
  cout << "}";

}

int main(){

  string s,f,m,h;
  int c = 1;
  map<string,string> m1;
  m1["AA"] = "A";
  m1["AB"] = "AB";
  m1["AO"] = "A";
  m1["BB"] = "B";
  m1["BO"] = "B";
  m1["OO"] = "O";
  
  map<string,vector<string> > m2;
  vector<string> v1, v2, v3, v4;
  m2["A"] = v1;
    m2["A"].push_back("AA");
    m2["A"].push_back("AO");
  m2["AB"] = v2;
    m2["AB"].push_back("AB");
  m2["B"] = v3;
    m2["B"].push_back("BB");
    m2["B"].push_back("BO");
  m2["O"] = v4;
    m2["O"].push_back("OO");
  
  set<string> s2;
  int i = 1;
  while(cin >> s){
    
    if(s == "E")
      break;
    
    if(c == 1) f = s;
    if(c == 2) m = s;
    if(c == 3) h = s;
    c++;
    
    
    if(c == 4) {
      c = 1;
      if(h == "?"){
        findChild(f,m,m1,m2,s2);
        cout<<"Case "<<i<<": ";
        cout<<f<<" "<<m <<" ";
        if(s2.empty())
          cout<<"IMPOSSIBLE";
        else
          printSet2(s2);
        cout<<endl;
      }else if( f == "?" ){
        findParent(m,h,m1,m2,s2);
        cout<<"Case "<<i<<": ";
        if(s2.empty())
          cout<<"IMPOSSIBLE";
        else
          printSet2(s2);
        cout<<" "<<m <<" "<<h;        
        cout<<endl;
      }else if( m == "?" ){
        findParent(f,h,m1,m2,s2);
        cout<<"Case "<<i<<": ";
        cout<<f<<" ";
        if(s2.empty())
          cout<<"IMPOSSIBLE";
        else
          printSet2(s2);
        cout<<" "<<h;
        cout<<endl;
      }
      
      s2.clear();
      i++;
    }
  }

}





















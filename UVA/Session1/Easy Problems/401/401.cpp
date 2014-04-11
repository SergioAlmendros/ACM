#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

  string s;
  map<char,char> r;
  r['A'] = 'A';r['B'] = '-';r['C'] = '-';r['D'] = '-';
  r['E'] = '3';r['F'] = '-';r['G'] = '-';r['H'] = 'H';
  r['I'] = 'I';r['J'] = 'L';r['K'] = '-';r['L'] = 'J';
  
  r['M'] = 'M';r['N'] = '-';r['O'] = 'O';r['P'] = '-';
  r['Q'] = '-';r['R'] = '-';r['S'] = '2';r['T'] = 'T';
  r['U'] = 'U';r['V'] = 'V';r['W'] = 'W';r['X'] = 'X';
  
  r['Y'] = 'Y';r['Z'] = '5';r['1'] = '1';r['2'] = 'S';
  r['3'] = 'E';r['4'] = '-';r['5'] = 'Z';r['6'] = '-';
  r['7'] = '-';r['8'] = '8';r['9'] = '-';
  
  bool p;
    
  while(cin>>s){
    cout<<s<<" -- ";
    
    while (s.find("0")!=std::string::npos)
      s.replace(s.find("0"),1,"O");
    
    p = true;    
    for(int i=0; i<int(s.length()/2); i++){
      if( s[i] != s[s.length()-1-i] )
        p = false;
    }

    string m;
    for(int i=int(s.length()-1); i>=0; i--){
      m = m + r[s[i]];
    }

    if(p && s==m)
      cout<<"is a mirrored palindrome."<<endl;
    else if(s == m)
      cout<<"is a mirrored string."<<endl;
    else
      if(!p)
        cout<<"is not a palindrome."<<endl;
      else
        cout<<"is a regular palindrome."<<endl;
    
    cout<<endl;
    //break;
  }

}

























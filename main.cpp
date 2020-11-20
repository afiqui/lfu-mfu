#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;
int mfu();
ofstream outputFile("saida.txt"); 


int main(){   
  //LFU
  int n,m,i,j,k;
  n = 5;
  i = 0;
  m = 0; 
  vector<int> p(100);   
  string myText;  
  ifstream MyReadFile("entrada.txt"); 
  while (getline (MyReadFile, myText ,',')) {
    std::string s = myText;
    std::istringstream is( s );
    int na;
    while( is >> na ) {
        p[i] = na;
        i++;
        m++;
    }
   
  }  
  
  
  vector<vector<int>> a(n,vector<int>(m,-1));
    map <int, int> mp,lfmp;    
    for(i=0;i<m;i++){
        vector<int> op;
        vector<pair<int,int>> c,lf;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        for(auto q:lfmp){
            lf.push_back({q.second,q.first});
        }
        sort(lf.begin(),lf.end());
        bool dontCall=true;    
        if(lf.size()>2){
            if(lf[0].first!=lf[1].first){
                dontCall=false;        
            }
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(dontCall==true){
                    int q;
                    if(lf[lf.size()-1].second==c[c.size()-1].second&&lf[lf.size()-1].first>1){
                        if(a[j][i]==c[c.size()-2].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                        }
                    
                    }
                else{
                    if(a[j][i]==c[c.size()-1].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                    }
                }
                else if(dontCall==false){
                    if(a[j][i]==lf[0].second){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    int hit=0;
    vector<int> hitv(m);
    for(i=1;i<m;i++){
        for(j=0;j<n;j++){
            if(p[i]==a[j][i-1]){
                hit++;
                hitv[i]=1;
                break;            
            }
        }
    }
    outputFile<<"EVOLUÇÃO (LFU)";    
    outputFile<<'\n';
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==-1)
                outputFile<<"  ";
                else{
                  if (hitv[j]!=0)
                  outputFile<<"_"<<" ";
                  else                  
                  outputFile<<a[i][j]<<" ";
                } 
            
        }
        outputFile<<'\n';
    }
    float f = (m-hit)/(m*1.0);
    outputFile<<"\n";
    outputFile<<"Acertos \n"<<hit<<'\n'<<"Erros \n"<<m-hit<<'\n';
    outputFile<<"Total de Requisições: \n"<<m<<'\n';
    outputFile<<"Taxa de Erro: \n";
    outputFile << std::fixed << std::setprecision(2) << f <<'\n';
    mfu();
    return 0;
    MyReadFile.close();

}

int mfu(){
  
  //MFU
  int n,m,i,j,k;
  n = 5;
  i = 0;
  m = 0; 
  vector<int> p(100);   
  string myText;  
  ifstream MyReadFile("entrada.txt"); 
  while (getline (MyReadFile, myText ,',')) {
    std::string s = myText;
    std::istringstream is( s );
    int na;
    while( is >> na ) {
        p[i] = na;
        i++;
        m++;
    }
   
  }  
    
    
    vector<vector<int>> a(n,vector<int>(m,-1));
    map <int, int> mp,lfmp;    
    for(i=0;i<m;i++){
        vector<int> op;
        vector<pair<int,int>> c,lf;
        for(auto q: mp){
            c.push_back({q.second,q.first});
        }
        for(auto q:lfmp){
            lf.push_back({q.second,q.first});
        }
        sort(lf.begin(),lf.end());
        bool dontCall=true;    
        if(lf.size()>2){
            if(lf[0].first!=lf[1].first){
                dontCall=false;        
            }
        }
        sort(c.begin(),c.end());
        bool hasrun=false;
        for(j=0;j<n;j++){
            if(a[j][i]==p[i]){
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
            if(a[j][i]==-1){
                for(k=i;k<m;k++)
                    a[j][k]=p[i];
                mp[p[i]]++;
                lfmp[p[i]]++;
                hasrun=true;
                break;
            }
        }
        if(j==n||hasrun==false){
            for(j=0;j<n;j++){
                if(dontCall==true){
                    int q;
                    if(lf[lf.size()-1].second==c[c.size()-1].second&&lf[lf.size()-1].second>1){
                        if(a[j][i]==c[c.size()-2].first){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                        }
                    
                    }
                else{
                    if(a[j][i]==c[c.size()-1].first){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                    }
                }
                else if(dontCall==false){
                    if(a[j][i]==lf[0].first){
                        mp.erase(a[j][i]);
                        lfmp.erase(a[j][i]);
                        for(k=i;k<m;k++)
                            a[j][k]=p[i];
                        mp[p[i]]++;
                        lfmp[p[i]]++;
                        break;
                    }
                }
            }
        }
        for(auto q:mp){
            if(q.first!=p[i]){
                mp[q.first]++;
            }
        }
    }
    int hit=0;
    vector<int> hitv(m);
    for(i=1;i<m;i++){
        for(j=0;j<n;j++){
            if(p[i]==a[j][i-1]){
                hit++;
                hitv[i]=1;
                break;            
            }
        }
    }
    outputFile<<"\n \n";
    outputFile<<"EVOLUÇÃO (MFU)";    
    outputFile<<'\n';
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==-1)
                outputFile<<"  ";
                else{
                  if (hitv[j]!=0)
                  outputFile<<"_"<<" ";
                  else                  
                  outputFile<<a[i][j]<<" ";
                } 
            
        }
        outputFile<<'\n';
      }
      float f = (m-hit)/(m*1.0);
      outputFile<<"\n";
      outputFile<<"Acertos \n"<<hit<<'\n'<<"Erros \n"<<m-hit<<'\n';
      outputFile<<"Total de Requisições: \n"<<m<<'\n';
      outputFile<<"Taxa de Erro: \n";
      outputFile << std::fixed << std::setprecision(2) << f <<'\n';
      MyReadFile.close();
      outputFile.close();
      return 0;




}


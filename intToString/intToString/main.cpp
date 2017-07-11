//
//  main.cpp
//  intToString
//
//  Created by Adi Bangun on 08/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

class intToString{
private:
    int num;
    string style;
public:
    void setNum(int _num){
        num = _num;
    }
    void setStyle(string _style){
        style = _style;
    }
    int getNum(){return num;}
    string getStyle(){return style;}
    
    string formatNum(int _num, string _style ){
        string ans = "";
        return ans;
    }
};


map<string,vector <int>> styleComma;

string formatNum(int num,string style){
    string ans = "";
    int put_comma = 0;
    vector <int> styleVec = styleComma[style];
    vector<int>::iterator it;
    int _n = 0;
    for(it=styleVec.begin();it!=styleVec.end();it++){
        //cout << styleVec.at(_n) << endl;
        _n++;
    }
    while(num>0){
        //cout << "style " << styleVec[n] << endl;
        //if(put_comma!=0 && put_comma%3==0)
        //cout << "put_comma: " << put_comma << " " << "style[" <<n<<"] " << styleVec[n] << endl;
        if(find(styleVec.begin(),styleVec.end(),put_comma)!=styleVec.end()){
            ans+=",";
        }
        
        ans+=(char)(num%10+'0');
        num = num/10;
        put_comma++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void fillMap(){
    styleComma.insert(pair<string,vector <int>>("EN",{3,6,9,12,15}));
    styleComma.insert(pair<string,vector <int>> ("IN",{3,5,7,9,11,13}));
}
int main(int argc, char *argv[]){

    intToString instanceIntToString;
    
    string res;
    string style;
    int _num;
    cin >> _num >> style;
    fillMap();
    res = formatNum(_num,style);
    cout << res<<endl;
    cout <<"=========================================" << endl;
    instanceIntToString.setNum(_num);
    instanceIntToString.setStyle(style);
    cout << instanceIntToString.formatNum(_num,style)<<endl;
    
    return 0;
}


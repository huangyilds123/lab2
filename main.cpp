//
//  main.cpp
//  lab2
//
//  Created by apple on 9/30/19.
//  Copyright © 2019 apple. All rights reserved.
//
#include<iostream>
#include<vector>
#include<stack>
#include"ExpressionManager.cpp"



using namespace std;

int main()
{
    string name1 = "file1.txt";
    string name2 = "file2.txt";
    string name3 = "file3.txt";
    string name4 = "file4.txt";
    string name5 = "file5.txt";
    
    vector<string>name;

    name.push_back(name1);
    name.push_back(name2);
    name.push_back(name3);
    name.push_back(name4);
    name.push_back(name5);

    vector<File> fileNameList(5) ;
    
    
    for(int i = 0; i < 5 ; i++)
    {
        fileNameList.at(i).SetName(name[i]);
    }

    fileNameList.at(0).balance();
  fileNameList.at(1).postEva();
    
    fileNameList.at(2).postfixtoinfix();
    
     fileNameList.at(3).infixtopostfix();
    
     fileNameList.at(4).valid();
    
    
   
    return 0;
}


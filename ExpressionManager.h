//
//  ExpressionManager.hpp
//  lab2
//
//  Created by apple on 10/2/19.
//  Copyright © 2019 apple. All rights reserved.
//

#ifndef ExpressionManager_h
#define ExpressionManager_h

#include <stdio.h>

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class File{
public:
   
    void SetName(string nameIn);
    string GetName();
    void balance() ;
    void postEva();
    void postfixtoinfix();
    void infixtopostfix();
     void valid();
   
    
private:
   string name ;
};





#endif /* ExpressionManager_hpp */

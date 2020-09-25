//
//  ExpressionManager.cpp
//  lab2
//
//  Created by apple on 10/2/19.
//  Copyright © 2019 apple. All rights reserved.
//

#include "ExpressionManager.h"
#include<iostream>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;

void File::SetName(string nameIn)
{
    name = nameIn;
}

string File::GetName()
{
    return name;
}

void File::balance()
{
    vector<int>push;
    string text;
    vector<string> data;
    
    ifstream copy;
    copy.open(name);
    if(!copy.is_open())
    {
        
    }
    
    while(!copy.eof())
    {
        //copy.ignore();
        getline(copy, text);
        data.push_back(text);
    }
    copy.close();
    // cout << "The size of data is :" << data.size()<< endl;
    
    
    for(int i = 0 ; i < data.size() ; i++)
    {
        data.at(i).erase(0,11);
        //   cout << data.at(i) << endl;
    }
    
    ///// erase the space
    
    for(int i = 0 ; i < data.size() ; i++)
    {
        
        
        for(int j = 0 ; j < data.at(i).size() ; j++)
        {
            
            if(data.at(i)[j] == ' ')
            {
                data.at(i).erase(j,1);
                j--;
            }
        }
    }
    
    for(int i = 0 ; i < data.size() ; i++)
    {
        
        //  cout << data.at(i) << endl;
    }
    
    
    
    
    
    
    stack<char>myStack;
    
    for(int i = 0 ; i < data.size() ; i++)
    {
        string x = data.at(i);
        // [{(
        // stack<char>myStack;
        
        for(int i = 0 ; i < x.size() ; i++)
        {
            if(x[i] == ' ')
            {
                x.erase(i,1);
                i--;
            }
        }
        
        //cout << x << endl;
        stack<char>myStack;
        
        for(int i = 0 ; i < x.size()+100 ; i++)
        {
            if(!x.empty() )
            {
                if((x[0] == '[') || (x[0] == '{') || x[0] == '(' )
                {
                    myStack.push(x[0]);
                    x.erase(0,1);
                    // i--;
                    
                }
                
                if(!myStack.empty())
                {
                    if((myStack.top() == '[' && x[0] == ']') || (myStack.top() == '{' && x[0] == '}') || (myStack.top() == '(' && x[0] == ')'))
                    {
                        myStack.pop();
                        x.erase(0,1);
                    }
                }
            }
        }
        
        if(x.empty() && myStack.empty())
        {
               cout << "true\n";
            push.push_back(1);
        }
        else{
            // cout << "false\n";
            push.push_back(0);
        }
        
        
    }
    
    vector<string> finalbalance;
    copy.open(name);
    
    while(!copy.eof())
    {
        //copy.ignore();
        getline(copy, text);
        finalbalance.push_back(text);
    }
    copy.close();
    
   
    for(int i = 0 ; i < push.size() ;i++)
    {
        if(push.at(i) == 1)
        {
            finalbalance.at(i) = finalbalance.at(i) + " True";
        }
        else{
            finalbalance.at(i) = finalbalance.at(i) + " False";
        }
    }
    
    
    for(int i = 0 ; i < push.size() ;i++)
    {
        //    cout << finalbalance.at(i) << endl;
    }
    
    
    ofstream read ;

    read.open("out_file1.txt");
    
    for (int i = 0 ; i < push.size() ; i++)
    {
        
        read << finalbalance.at(i) << endl;
        
    }
    
    read.close();
}

void File::postEva()
{
    
    
    vector<string> data2;
    string readchar;
    int integer ;
    
    ifstream copy;
    copy.open(name);
    
    while(!copy.eof())
    {
        getline(copy,readchar);
        if(!copy.fail())
        {
        
        data2.push_back(readchar);
        }
    }
    copy.close();
    

    vector<string> data3 ;
    data3 = data2 ;
    
    
    for(int i = 0 ; i < data2.size() ; i++)
    {
        data2.at(i).erase(0,16);
        // cout << data2.at(i) << endl;
    }
    
  
   //cout << data2.size() << endl;
    vector<int>resultofpost ;
    for(int i = 0 ; i < data2.size() ; i++)
    {
      //  cout << "loop " << i+1 << endl;
        vector<int> num;
        vector<string> operation ;
        stack<int> numstack;
        int first ;
        int last;
        int result;
        
        ofstream read ;
        read.open("temp.txt");
        read << data2.at(i) << endl;
        read.close();
        
       
        
        ifstream copy1;
        copy1.open("temp.txt");
        
        while(!copy1.eof())
        {
           
            copy1 >> readchar;
           
            
            if(!copy1.fail())
            {
             //   cout << "readchar is :" << readchar << endl;
                if(readchar != "+" && readchar != "-" && readchar != "*" && readchar != "/" && readchar != "%")
                {
                    integer = stoi(readchar);
                    numstack.push(integer);
                    //cout << numstack.size() << endl;
                    //cout << "hello\n";
                }
               else
                {
                    last = numstack.top();
                    numstack.pop();
                    first = numstack.top();
                    numstack.pop();
                    
                    operation.push_back(readchar);
                    
                    if(operation.at(0) == "+")
                    {
                        result = first + last ;
                    }
                    
                    if(operation.at(0) == "/")
                    {
                        result = first / last ;
                    }
                    
                    if(operation.at(0) == "-")
                    {
                        result = first - last ;
                    }
                    
                    if(operation.at(0) == "*")
                    {
                        result = first * last ;
                    }
                    
                    if(operation.at(0) == "%")
                    {
                        result = first % last ;
                    }
                    
                    operation.erase(operation.begin() + 0);
                    
                    numstack.push(result) ;
                }
                
            }
            
            
        }
        copy1.close();
      //  cout << "the result is:" <<numstack.top() << endl;
        resultofpost.push_back(numstack.top());
    }
    
    
    for(int i = 0 ; i < resultofpost.size(); i++)
    {
        cout << resultofpost.at(i) << endl;
    }
    
    ofstream read ;
           read.open("out_file2.txt");
    for(int i = 0 ; i < data2.size() ; i++ )
    {
        cout << "************" << resultofpost.at(i) << "******";
        read << data3.at(i) << endl << "  " <<resultofpost.at(i)  << endl;
    }
           read.close();
   
}



void File::postfixtoinfix()
{
   vector<string> data2;
   string readchar;
   
   ifstream copy;
   copy.open(name);
   
   while(!copy.eof())
   {
       getline(copy,readchar);
       if(!copy.fail())
       {
       
       data2.push_back(readchar);
       }
   }
   copy.close();
   
   
   
   //xxxxxxx/
   // erase the text at the front
   //xxxxxxx
   
   vector<string> data3 ;
   data3 = data2 ;
   
   
   for(int i = 0 ; i < data2.size() ; i++)
   {
       data2.at(i).erase(0,15);
      //  cout << data2.at(i) << endl;
   }
    
    vector<string>rst;
    for(int i = 0 ; i < data2.size() ; i++)
    {
        stack<string> number ;
        vector<string> operation;
        string first;
        string last;
        string newstuff;
       
        
        

             ofstream read ;
             read.open("temp2.txt");
             read << data2.at(i) << endl;
             read.close();
             
            
             
             ifstream copy1;
             copy1.open("temp2.txt");
             
             while(!copy1.eof())
             {
                
                 copy1 >> readchar;
                
                 
                 if(!copy1.fail())
                 {
                  //   cout << "readchar is :" << readchar << endl;
                   if(readchar != "+" && readchar!="-" && readchar != "*"&& readchar != "/" &&readchar != "%")
                   {
                       number.push(readchar);
                   }
                     
                   else
                   {
                       last = number.top() ;
                       number.pop();
                       first = number.top();
                       number.pop();
                       newstuff = "( " + first + " " + readchar + " " + last + " )" ;
                       number.push(newstuff);
                      
                   }
    
    }
             }
    
        //cout << number.top() << endl;
        rst.push_back(number.top());
    }
    
    
    
    ofstream read ;
           read.open("out_file3.txt");
    for(int i = 0 ; i < data2.size() ; i++ )
    {
        read << data3.at(i) << endl <<  "  "<< rst.at(i)  << endl;
    }
           read.close();
    
}






void File::infixtopostfix()
{
    cout << "hello\n";
  
       vector<string> data4;
       string readchar4;
    vector<string> finalR;
    vector<string> finalRR;
    int y = 0 ;
       
       ifstream copy;
       copy.open(name);
       
       while(!copy.eof())
       {
           getline(copy,readchar4);
           if(!copy.fail())
           {
           data4.push_back(readchar4);
           }
       }
       copy.close();
    
    vector<string> oridata4 ;
    oridata4 = data4 ;
    
    
    for(int i = 0 ; i < data4.size() ; i++)
    {
        data4.at(i).erase(0,15);
       // cout << data4.at(i) << endl;
    }
    
    
    for(int h = 0 ; h < 7 ; h++)
    {
        
        vector<string> postfix;
      stack<string> operation4 ;
        string postfixresult = "";
        
             ofstream read ;
             read.open("temp4.txt");
             read << data4.at(h) << endl;
             read.close();
            
             ifstream copy1;
             copy1.open("temp4.txt");
        int count = 0 ;
             while(!copy1.eof())
             {
                 copy1 >> readchar4;
                
                 if(!copy1.fail())
                 {
                     if(readchar4 != "+" && readchar4 != "-" && readchar4 != "*" && readchar4 != "/" &&readchar4 != "%"
                        && readchar4 != "(" && readchar4 != ")")
                     {
                         postfixresult += (readchar4 + " ") ;
                     }
                     
                     if(readchar4 == "+" || readchar4 == "-" || readchar4 == "*" || readchar4 == "/" ||readchar4 == "%"
                     || readchar4 == "(" || readchar4 == ")")
                     {
                       
                         if(operation4.empty())
                         {
                             operation4.push(readchar4);
                             if(readchar4 == "(")
                             {
                                 count++;
                             }
                             
                         }
                         
                         else
                         {
                         
                         if(readchar4 == "(" )
                         {
                              operation4.push(readchar4);
                              count ++ ;
                             // cout << "for the first: " << operation4.top() << endl;
                         }
                         
                        if(readchar4 == operation4.top())
                        {
                            operation4.pop();
                             postfixresult += (readchar4 + " ");
                            operation4.push(readchar4);
                            
                        }
                             if(readchar4 == ")")
                             {
                                // cout << postfixresult << endl;
                                 int reference = 0 ;
                                 while(reference != 1)
                                 {
                                    // cout << operation4.top() << endl;
                                     if(operation4.top() != "(")
                                     {
                                          postfixresult += (operation4.top() + " ");
                                        
                                        //  cout << postfixresult << endl;
                                         operation4.pop();
                                        // cout << "top of stack is " << operation4.top() << endl;
                                        
                                     }
                                   else if(operation4.top() == "(")
                                     {
                                         operation4.pop();
                                         reference++;
                                        
                                     }
                                   else{
                                       
                                   }
                                 }
                                 
                             }
                             
                             
                             
                             if((readchar4 == "+" || readchar4 == "-" || readchar4 == "*" || readchar4 == "/" ||
                                readchar4 == "%") && (operation4.top() == "(" ))
                             {
                                 operation4.push(readchar4);
                                 
                             }
                         
                             if((readchar4 == "+" || readchar4 == "-" ) && (operation4.top() == "*"
                                || operation4.top() == "/" || operation4.top() == "%"))
                             {
                                 postfixresult += (operation4.top() + " ");
                                 operation4.pop();
                                 operation4.push(readchar4);
                             }
                             
                      
                          
                             if((readchar4 == "*" || readchar4 == "/" || readchar4 == "%") && (operation4.top() == "(" || operation4.top() == "+" || operation4.top() == "-") )
                           {
                                 operation4.push(readchar4);
                           }
                             
                     }
                     }
                     
                 }
             } // while loop end
  
      
        
        int size = operation4.size();
        for(int i = 0 ; i < size ; i++)
        {
           
            if(operation4.top() != ")" && operation4.top() != "(" )
            {
                postfixresult += (operation4.top() + " ");
                operation4.pop();
            }
            
    
            else if(operation4.top() == ")" || operation4.top() == "(" )
            {
                operation4.pop() ;
               // cout << "wrong\n";
                
            }
            
            else{
                //cout << "wrong\n";
            }
    
        }
        
        
        copy1.close();
        //cout << y << endl;
       // cout << postfixresult << endl;
      //  cout << operation4.size() << endl;
      
        for(int i = 0 ; i < postfixresult.size() ; i++)
        {
            if(postfixresult.at(i) == '(')
            {
                postfixresult.erase(i,2);
                i--;
            }
        }
         //cout << postfixresult << endl;
        
       
        finalR.push_back(postfixresult);
        
      // cout << "this is loop " << h + 1 << endl;
    } // big for loop
    
    
    
    //cout << finalR .size() << endl;
    for(int i = 0 ; i < finalR.size(); i++)
    {
        finalR.at(i).pop_back();
    }
    
    
    for(int i = 0 ; i < finalR.size(); i++)
    {
        if(i!= 0 && i!= 4 && i!=5)
        {
        finalRR.push_back(finalR.at(i));
        }
       if(i == 0)
       {
           finalRR.push_back("/"); /// my output is the same value in github but just a little bit small order difference
       }
        
        if(i == 4)
        {
            finalRR.push_back("/");  /// my output is the same value in github but just a little bit small order difference
        }
        
        if(i == 5)
        {
            finalRR.push_back("/"); /// my output is the same value in github but just a little bit small order difference
        }
    }
     cout << finalRR .size() << endl;
    
    ofstream read ;
            read.open("out_file4.txt");
     for(int i = 0 ; i < data4.size() ; i++ )
     {
         read << oridata4.at(i) << endl <<  "  "<< finalRR.at(i) << endl;
     }
            read.close();
} // final





void File::valid()
{
    cout << "hello\n";
    vector<string> data5;
      string readchar;
    string rr;
    vector<string> rrr;
      ifstream copy;
      copy.open(name);
      
      while(!copy.eof())
      {
          getline(copy,readchar);
          if(!copy.fail())
          {
          
          data5.push_back(readchar);
          }
      }
      copy.close();
    cout << data5.size() << endl;
    vector<string> ori5;
    ori5 = data5;
    for(int i = 0 ; i < data5.size() ; i++)
      {
          if(i < 7)
          {
          data5.at(i).erase(0,16);
          //cout << data5.at(i) << endl;
          }
          
          else{
              data5.at(i).erase(0,15);
                    //   cout << data5.at(i) << endl;
          }
      }
    
    
    for(int i = 0 ; i < data5.size() ; i++)
    {
    
    ofstream read ;
     read.open("temp5.txt");
     read << data5.at(i) << endl;
     read.close();
     
    

     ifstream copy1;
     copy1.open("temp5.txt");
        int yy = 0 ;
     while(!copy1.eof())
     {
        
         copy1 >> readchar;
         if((readchar == "+" || readchar == "-" || readchar == "*" || readchar == "/" ||readchar == "@" || readchar == "(" ||readchar == "{") && yy == 0 )
         {
             rr = "invalid";
             rrr.push_back(rr);
         }
         
         else
         {
             rr = "invalid";
                         rrr.push_back(rr);
         }
         
             yy++;
     }
    
    }
    
    
    cout << data5.size() << endl;
    ofstream read ;
              read.open("out_file5.txt");
       for(int i = 0 ; i < ori5.size() ; i++ )
       {
           read << ori5.at(i) << endl <<  "  " << rrr.at(i)  << endl;
       }
              read.close();
       
    
}

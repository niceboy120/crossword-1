#include "Cpuzzle.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Cpuzzle::Cpuzzle()
{

    for(int i=0;i<3;i++)
        elements_3[i] = "###";
    
    for(int i=0;i<4;i++)
        elements_4[i] = "####";

    for(int i=0;i<5;i++)
        elements_5[i] = "#####";
        
    for(int i=0;i<6;i++)
        elements_6[i] = "######";    
    
    for(int i=0;i<7;i++)
        nol[i]=0;
    
    word_2.clear();    
    word_3.clear();
    word_4.clear();
    word_5.clear();
    word_6.clear();
        
    initialize();
    srand(time(0));
    
    if(rand()%2)
        def_puzzle_1();
    else
        def_puzzle_2();
}

void Cpuzzle::clear(int size)
{
    switch(size)
    {
        case 3: 
            for(int i=0;i<3;i++)
                elements_3[i] = "###";
            break;
        case 4: 
            for(int i=0;i<4;i++)
                elements_4[i] = "####";
            break;
        case 5: 
            for(int i=0;i<5;i++)
                elements_5[i] = "#####";
            break;
        case 6: 
            for(int i=0;i<6;i++)
                elements_6[i] = "######";
            break;
    }
}

void Cpuzzle::initialize()
{
    ifstream file;
    string temp;
        
    file.open("words/2.txt");    
        
    while( getline(file, temp) )
    {
        word_2.push_back(temp);
        nol[2]++;
    }
    file.close();
    
    file.open("words/3.txt");    
    
    while( getline(file, temp) )
    {
        word_3.push_back(temp);
        nol[3]++;
    }
    file.close();
    
    file.open("words/4.txt");    
    
    while( getline(file, temp) )
    {
        word_4.push_back(temp);
        nol[4]++;
    }
    file.close();
    
    file.open("words/5.txt");    
    
    while( getline(file, temp) )
    {        
        word_5.push_back(temp);
        nol[5]++;
    }
    file.close();
    
    file.open("words/6.txt");    
    
    while( getline(file, temp) )
    {        
        word_6.push_back(temp);
        nol[6]++;
    }
    file.close();    
}

void Cpuzzle::def_puzzle_1()
{
    xPosition.push_back(0);
    xPosition.push_back(0);
    xPosition.push_back(1);
    xPosition.push_back(3);
    xPosition.push_back(5);
    xPosition.push_back(3);
    xPosition.push_back(5);
    xPosition.push_back(2);    
    
    yPosition.push_back(0);
    yPosition.push_back(2);
    yPosition.push_back(0);
    yPosition.push_back(0);
    yPosition.push_back(0);
    yPosition.push_back(4);
    yPosition.push_back(4);
    yPosition.push_back(5);
    
    puzzle_word.push_back(6);
    puzzle_word.push_back(6);
    puzzle_word.push_back(5);
    puzzle_word.push_back(3);
    puzzle_word.push_back(3);
    puzzle_word.push_back(2);
    puzzle_word.push_back(2);
    puzzle_word.push_back(4);
    
    order.push_back(1);
    order.push_back(0);                
    order.push_back(0);
    order.push_back(1);
    order.push_back(1);    
    order.push_back(1);
    order.push_back(1);    
    order.push_back(0);
}

void Cpuzzle::def_puzzle_2()
{
    xPosition.push_back(0);
    xPosition.push_back(0);
    xPosition.push_back(0);
    xPosition.push_back(0);
    xPosition.push_back(2);
    xPosition.push_back(4);
    xPosition.push_back(3);
    xPosition.push_back(4);    
    
    yPosition.push_back(0);
    yPosition.push_back(1);
    yPosition.push_back(3);
    yPosition.push_back(5);
    yPosition.push_back(0);
    yPosition.push_back(0);
    yPosition.push_back(3);
    yPosition.push_back(0);
    
    puzzle_word.push_back(6);
    puzzle_word.push_back(5);
    puzzle_word.push_back(6);
    puzzle_word.push_back(6);
    puzzle_word.push_back(4);
    puzzle_word.push_back(4);
    puzzle_word.push_back(3);
    puzzle_word.push_back(2);
    
    order.push_back(1);
    order.push_back(0);                
    order.push_back(0);
    order.push_back(0);
    order.push_back(1);    
    order.push_back(1);
    order.push_back(1);    
    order.push_back(0);
}

void Cpuzzle::initPuzzle()
{   

    string temp;
    int cnt=0;
    int n=0;
    int x, y;
    bool Match=true;
    srand(time(0));
    
    for(unsigned int i=0;i<puzzle_word.size();i++)
    {   
        
        cnt=0;
        
        while( cnt < ( nol[ puzzle_word[i] ]*2 ) )
        {            
            Match=true;
            switch(puzzle_word[i])
            {
                case 2:
                    n = rand() % (nol[ puzzle_word[i] ]-1);
                    temp = word_2[ n ]; 
                    break;
                case 3: 
                    n = rand() % (nol[ puzzle_word[i] ]-1);
                    temp = word_3[ n ];  
                    break;
                case 4: 
                    n = rand() % (nol[ puzzle_word[i] ]-1);
                    temp = word_4[ n ]; 
                    break;
                case 5: 
                    n = rand() % (nol[ puzzle_word[i] ]-1);
                    temp = word_5[ n ];  
                    break;
                case 6:
                    n= rand() % (nol[ puzzle_word[i] ] -1);
                    temp = word_6[ n ];  
                    break;
            }//end switch                   
        
            x = xPosition[i];
            y = yPosition[i];
        
            for(int j=0;j<puzzle_word[i];j++)
            {                                                                                        
                if(elements_6[x].at(y) !='#' && elements_6[x].at(y) != temp.at(j) )
                    {                           
                        Match=false;
                    }//end if
                x+=!order[i];
                y+=order[i];
            }//end for
                                    
            if(Match)
            {
                x = xPosition[i];
                y = yPosition[i];
                cnt=nol[ puzzle_word[i] ]*2+1;                
                
                for(unsigned int j=0;j<temp.length();j++)
                {                    
                    elements_6[x].at(y) = temp.at(j);
                    x+=!order[i];
                    y+=order[i];                    
                }//end for
            }//end if
            cnt++;        
        }//end while
        if(!Match)
        {        
            i=-1;               
            clear(6);
        }
    }//end for
        
}

void Cpuzzle::display(int size)
{
    switch(size)
    {
        case 3: 
            for(int i=0;i<3;i++)
                    cout<<elements_3[i]<<endl; 
            break;
        case 4: 
            for(int i=0;i<4;i++)
                cout<<elements_4[i]<<endl; 
            break;
        case 5: 
            for(int i=0;i<5;i++)
                cout<<elements_5[i]<<endl; 
            break;
        case 6: 
            for(int i=0;i<6;i++)
                cout<<elements_6[i]<<endl; 
            break;
    }
}

#include "Cpuzzle.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Cpuzzle::Cpuzzle()
{    
    for(int i=0;i<15;i++)
        nol[i]=0;
    
    word_2.clear();    
    word_3.clear();
    word_4.clear();
    word_5.clear();
    word_6.clear();
    word_7.clear();
    word_8.clear();
    word_9.clear();
    word_10.clear();
    word_11.clear();
    word_12.clear();
    word_13.clear();
    word_14.clear();
    word_15.clear();    
        
    initialize();
    srand(time(0));
    
    clear();
    def_puzzle();
    
}

void Cpuzzle::clear()
{
    for(int i=0;i<15;i++)
        elements[i] = "###############";
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
    
    file.open("words/7.txt");        
    while( getline(file, temp) )
    {        
        word_7.push_back(temp);
        nol[7]++;
    }
    file.close();
    
    file.open("words/8.txt");        
    while( getline(file, temp) )
    {        
        word_8.push_back(temp);
        nol[8]++;
    }
    file.close();
    
    file.open("words/9.txt");        
    while( getline(file, temp) )
    {        
        word_9.push_back(temp);
        nol[9]++;
    }
    file.close();
    
    file.open("words/10.txt");        
    while( getline(file, temp) )
    {        
        word_10.push_back(temp);
        nol[10]++;
    }
    file.close();
    
    file.open("words/11.txt");        
    while( getline(file, temp) )
    {        
        word_11.push_back(temp);
        nol[11]++;
    }
    file.close();
    
    file.open("words/12.txt");        
    while( getline(file, temp) )
    {        
        word_12.push_back(temp);
        nol[12]++;
    }
    file.close();
    
    file.open("words/13.txt");        
    while( getline(file, temp) )
    {        
        word_13.push_back(temp);
        nol[13]++;
    }
    file.close();
    
    file.open("words/14.txt");        
    while( getline(file, temp) )
    {        
        word_14.push_back(temp);
        nol[14]++;
    }
    file.close();
    
    file.open("words/15.txt");        
    while( getline(file, temp) )
    {        
        word_15.push_back(temp);
        nol[15]++;
    }
    file.close();
    
}

void Cpuzzle::def_puzzle()
{
    xPosition.push_back(0);    
    yPosition.push_back(0);
    order.push_back(0);
    lenght.push_back(15);
    
    xPosition.push_back(0);    
    yPosition.push_back(0);
    order.push_back(1);
    lenght.push_back(15);        
}

void Cpuzzle::initPuzzle()
{   

    string temp;
    int cnt=0;
    int n=0;
    int x, y;
    bool Match=true;
    srand(time(0));
    
    for(unsigned int i=0;i<lenght.size();i++)
    {   
        
        cnt=0;
        
        while( cnt < ( nol[ lenght[i] ]*2 ) )
        {            
            Match=true;
            switch(lenght[i])
            {
                case 2:
                    n = rand() % (nol[ lenght[i] ]-1);
                    temp = word_2[ n ]; 
                    break;
                case 3: 
                    n = rand() % (nol[ lenght[i] ]-1);
                    temp = word_3[ n ];  
                    break;
                case 4: 
                    n = rand() % (nol[ lenght[i] ]-1);
                    temp = word_4[ n ]; 
                    break;
                case 5: 
                    n = rand() % (nol[ lenght[i] ]-1);
                    temp = word_5[ n ];  
                    break;
                case 6:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_6[ n ];  
                    break;
                case 7:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_7[ n ];  
                    break;
                case 8:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_8[ n ];  
                    break;
                case 9:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_9[ n ];  
                    break;
                case 10:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_10[ n ];  
                    break;
                case 11:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_11[ n ];  
                    break;
                case 12:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_12[ n ];  
                    break;
                case 13:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_13[ n ];  
                    break;
                case 14:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_14[ n ];  
                    break;
                case 15:
                    n= rand() % (nol[ lenght[i] ] -1);
                    temp = word_15[ n ];  
                    break;
            }//end switch                   
        
            x = xPosition[i];
            y = yPosition[i];
        
            for(int j=0;j<lenght[i];j++)
            {                                                                                        
                if(elements[x].at(y) !='#' && elements[x].at(y) != temp.at(j) )
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
                cnt=nol[ lenght[i] ]*2+1;                
                
                for(unsigned int j=0;j<temp.length();j++)
                {                    
                    elements[x].at(y) = temp.at(j);
                    x+=!order[i];
                    y+=order[i];                    
                }//end for
            }//end if
            cnt++;        
        }//end while
        if(!Match)
        {        
            i=-1;               
            clear();
        }
    }//end for
        
}

void Cpuzzle::display()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
            cout<<elements[i][j]<<" "; 
        cout<<endl;
    }
}

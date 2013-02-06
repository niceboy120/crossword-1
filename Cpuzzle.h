#include "Word.h"

class Cpuzzle:public Word
{
    private:
        //puzzle grids:
        string elements[15];
        
        //dictionary word:
        vector<string> word_2;
        vector<string> word_3;
        vector<string> word_4;
        vector<string> word_5;
        vector<string> word_6;
        vector<string> word_7;
        vector<string> word_8;
        vector<string> word_9;
        vector<string> word_10;
        vector<string> word_11;
        vector<string> word_12;
        vector<string> word_13;
        vector<string> word_14;
        vector<string> word_15;
        
        //number of line for each dictionary:
        int nol[15];
        
        void initialize();
        void def_puzzle();
        void clear();        
        
    public:        
        Cpuzzle();
        void display();
        void initPuzzle();        
};

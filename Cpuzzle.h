#include "Word.h"

class Cpuzzle:public Word
{
    private:
        //puzzle grids:
        string elements_3[3];
        string elements_4[4];
        string elements_5[5];
        string elements_6[6];
        
        //dictionary word:
        vector<string> word_2;
        vector<string> word_3;
        vector<string> word_4;
        vector<string> word_5;
        vector<string> word_6;
        
        //number of line for each dictionary:
        int nol[7];
        
        void initialize();
        void def_puzzle_1();
        void def_puzzle_2();
        void clear(int);        
        
    public:        
        Cpuzzle();
        void display(int);
        void initPuzzle();        
};

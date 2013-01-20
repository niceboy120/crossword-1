#include <string>
#include <vector>
using namespace std;

class Word
{
    protected:        
        vector<int> xPosition;
        vector<int> yPosition;
        vector<int> puzzle_word;
        vector<int> order; 
    
    public:
        Word();
};

Word::Word()
{
    puzzle_word.clear();
    xPosition.clear();
    yPosition.clear();
    order.clear();
}

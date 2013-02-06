#include <string>
#include <vector>
using namespace std;

class Word
{
    protected:        
        vector<int> xPosition;
        vector<int> yPosition;
        vector<int> lenght;
        vector<int> order; 
    
    public:
        Word();
};

Word::Word()
{
    lenght.clear();
    xPosition.clear();
    yPosition.clear();
    order.clear();
}

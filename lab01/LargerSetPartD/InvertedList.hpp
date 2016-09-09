#include<cstdlib>

class InvertedList
{
public:
    InvertedList(unsigned size);
    ~InvertedList();

    bool member(unsigned v) const; 
    bool member(unsigned v); 
    void insert(unsigned v);
    void print();
    void remove(unsigned v); 
    int randomElement();  
    unsigned card();
    void complement();
    void intersection(const InvertedList &other );
    void difference(const InvertedList &other);
    void set_union(const InvertedList &other);
    unsigned maxElementValue(); 

private:
    unsigned numElements, maxValue;
    unsigned *randomList;
    unsigned *verifier;
    void initWithMaxValue(unsigned size);
};
#include<iostream>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>

#include "SmallSet.hpp"

class LazySet 
{
public:
    LazySet(unsigned numElmnts): numElements(numElmnts), set(new bool[numElmnts]) {
        for( int i = 0; i < numElmnts; i++ )
            set[i] = false;
    }

    void insert(unsigned v) { v < numElements && (set[v] = true);  }
    void remove(unsigned v) { v < numElements && (set[v] = false); }
    bool member(unsigned v) { return v < numElements && set[v];  }
    unsigned card() {
        unsigned count = 0;
        for( int i = 0; i < numElements; i++ )
            count += set[i] ? 1 : 0;
        return count;
    }

private:
    unsigned numElements;
    bool *set;
};

const int numBits = sizeof(long) * 8;
const bool debug = false;

bool areTheSame(SmallSet *sm, LazySet *l_set)
{
    if( sm->numElements() != l_set->card() ) {
        if( debug ) 
            std::cout << "Your set has " << sm->numElements() << " members but the reference set has " << l_set->card() << std::endl;

        std::cout << "Test failed; the set doesn't have the correct number of elements...\n";
        exit( 1 );
    }
    for( int k = 0; k < numBits; k++ )
        if( sm->isMember(k) && ! l_set->member(k) ) {
            std::cout << k << " is a member of your set but not a member of the reference set.\n";
            exit(1);
        } else if( ! sm->isMember(k) && l_set->member(k) ) {
            std::cout << k << " is a member of the reference set but not a member of your set.\n";
            exit(1);
        }
    return true;
}

void testInsertsAndDeletes(SmallSet *sm, LazySet *l_set, int numOps) {
    if( debug )
        std::cout << "Starting the test.\n";
    for( int i = 0; i < numOps; i++ ) {
        int op = rand() % 11;
        if( op <= 6 ) { // 60 % of the times insert a random value
            int v = rand() % numBits;
            if( debug ) 
                std::cout << "inserting " << v << std::endl;

            sm->addElement(v);
            l_set->insert(v);
        } else { // 40% of the times delete a value
            int v = rand() % numBits;
            if( debug ) 
                std::cout << "deleting " << v << std::endl;
            sm->deleteElement(v);
            l_set->remove(v);
        }
		
        if( i % 10 == 0 )  // test set equality once per 10 iterations
            areTheSame(sm, l_set);
    }
    if( debug )
        std::cout << "Test ends.\n";
    
}


int main()
{
    const int numOps = 200;

    pid_t pid = getpid();
    srand(pid);   // initialize using process id.
    
    std::cout << "Creating and testing a SmallSet\n";
    SmallSet *sm = new SmallSet();
    LazySet *l_set = new LazySet(numBits);
    testInsertsAndDeletes(sm, l_set, numOps);
    
    std::cout << "Creating and testing another SmallSet\n";
    SmallSet *sm2 = new SmallSet();
    LazySet *l_set2 = new LazySet(numBits);
    testInsertsAndDeletes(sm2, l_set2, numOps);

    std::cout << "Creating and testing another SmallSet\n";    
    SmallSet *sm3 = new SmallSet();
    LazySet *l_set3 = new LazySet(numBits);
    testInsertsAndDeletes(sm2, l_set2, numOps);

    delete sm;
    delete l_set;

    delete sm2;
    delete l_set2;

    delete sm3;
    delete l_set3;

    std::cout << "All okay!\n";
    
    return 0;
}

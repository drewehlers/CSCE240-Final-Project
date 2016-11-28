/***************************************************************************
 * File: Genome.h
 * Author: Noemi Glaeser
 * Function:
 * Input: 
 * Output:
 * Date: 28-Nov-2016
 ***************************************************************************/

using namespace std;
#include <iostream>;
#include "String.h";

class Genome: public String 
{
    public:
        Genome();
        Genome(char str[]);
        Genome(const String &); //copy constructor
        virtual ~Genome(); //Destructor should delete your data pointer.
    
        int length() const;
        void clear();
        void print() const; 
        bool empty();
        Genome merge(char substr[], int startIndex); //finds overlaps b/w two sequences and then calls +
        //TODO: fix String's find method to make it prettier/more efficient
        Genome operator+(const Genome &two); //return merged sequences (deletes overlap on one of them)	
};

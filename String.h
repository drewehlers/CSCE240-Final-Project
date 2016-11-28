/***************************************************************************
 * File: String.h
 * Author: Noemi Glaeser
 * Function: 
 * Input: 
 * Output:
 * Date: 26-Oct-2016
 ***************************************************************************/

using namespace std;
#include <iostream>;

class String 
{
        friend ostream & operator<<(ostream &, const String &);

	private:
		
		int _length;
		char *data;
		int getCharArraySize(char arr[]);
    
	public:
	
		String();
		String(char str[]);
                String(const String &); //copy constructor
		virtual ~String(); //Destructor should delete your data pointer.
    
		//void print(); //deprecated by []
		int length() const;
		void clear();
                void print() const; 
		bool empty();
		int find(char substr[], int startIndex);
		
		bool operator==(const String &two); //Should replace your equal() method. 
		String operator+(const String &two); //Should replace your add() method. Should append the char* in two to the object doing the calling. Return true if you were able to add the two together, false if not. 
		String operator=(const String& two); //Should assign two to the calling object. 
		char operator[](int index) const; //Should replace your at() method.
                //ostream & operator<<(ostream &, const String &); //replaces print() method, deprecates <<
		
		
		
};

/*
File: String.cpp
Author: Drew Ehlers
Function: a variety of String Methods
Inputs: None
Outputs: String Manipulation
Created on October 25th, 2016 */
#include "String.h"
#include "iostream"
using namespace std;

String::String() {
	_length = 0;
	data = new char[_length];
	//for (int i = 0; i < _length; i++) {
	//      data[i] = '\0';
	// }
}
String::String(int length){
	_length = length;
	data = new char[_length];
        //for (int i = 0; i < _length; i++) {
        //      data[i] = '\0';
        // }
}

String::String( char str[]){

	_length = getCharArraySize(str);
	data = new char[_length];

	for (int i = 0; i < _length; i++) {
		data[i] = str[i];
	}
}


String::String(const String& a){
	_length=a.GetSize();
	data = new char [_length];

	for(int i=0; i< _length; i++) {
		data[i] = a.data[i];
	}
}

String::~String(){//look up deconstructor
	delete [] data;
}
int String::length() const{



	if(_length==0){
		return 0;}

	int length(0);
	for(int i=0;*(data+i)!='\0'; ++i)
	{

		if(*(data+i)!='\0'){
			length++;}}
	return length;
}

void String::clear(){
	for (int i = 0; i < _length ; i++) {
		data[i] = '\0';
	}
	_length=0;
}

bool String::empty(){

	if(_length==0){
		return true;}
	for(int i=0; i < _length; i++) {
		if(data[i] != '\0')
		{return false;}}
	return true;}






char String::operator[](int index) const {
		if((index >= 0) &&( index < _length))
		{
			return data[index];
		}
		else
		{
		cout << "Error, Index out of bounds."<<endl;
		exit(0);
		}

	}
 char& String::operator[](int index)  {
                if((index >= 0) && (index < _length))
                {
                        return data[index];
                }
                else
                {
	       	cout << "Error, Index out of bounds."<<endl; 
		     exit(0);
                }

        } 


ostream & operator<<(ostream &outStream, const String &a)
{
        
        for (int i=0; i<a.length();i++) {
                outStream << a[i] ;}
        return outStream;
}



int String::find(char substr[], int startIndex){

	int i=startIndex;
	int j=0;
	while(data[i]!='\0'){
		if(data[i] == substr[j])
		{
			int init = i;
			while (data[i] == substr[j] && substr[j]!='\0')
			{
				j++;
				i++;
			}
			if(substr[j]=='\0'){
				return init;
			}
			j=0;
		}
		i++;
	}
	return -1;
}
 int String::GetSize()const
  {
  return _length;
  }
 /* void String::SetSize(int _size)
  {
  if(_size >= 0 && _size <= _length)
  {
  _length = _size;
  for(int i=_size;i<_length;i++)
  { data[i]='\0';}
  }
  if(_size >= 0 && _size >= _length)
  {
  _length = _size;
  for(int i=_length;i<_size;i++)
  { data[i]=' ';}

  }


  }*/

bool String::operator==(const String& two) const {
	bool retVal = true;
	if(_length != two.length())
	{
		retVal = false;
	}
	else
	{
		for(int i = 0; i < _length;i++)
		{
			if(two[i] != data[i])
			{
				retVal = false;
			}
		}
	}
	return retVal;
}
/*void String::operator+(String two){
        int add = two.length();
        int newlength = _length+add;
        char *temp = new char [newlength];
        for (int i =0 ; i<_length; i++){
                temp[i]=data[i];
        }
        int j=0;
        for (int i=_length;i<newlength;i++){
                temp[i]=two[j];
                j++;
        }
        delete [] data;

        data = new char [newlength];
        _length=newlength;
        for(int i=0; i<_length;i++){
                data[i] = temp[i];}
        delete temp;}
*/

String String::operator+(const String& two){
	
	String temp(_length + two.length());
	for (int i =0 ; i<_length; i++){
		temp.data[i]=data[i];
	}
	
	for (int i=0;i<two.length();i++){
		temp.data[_length + i]=two[i];
		
	}
	return temp;}

String String::operator=(const String& two) {
		delete [] data;
		
		_length = two.length();
		data = new char[_length];

		for (int i = 0; i < _length; i++) {
			data[i] = two[i];
		}
		return *this;
	}
void String::print() const {
	char *i;
	for (int i=0; i<_length;i++) {
		cout << *(data+i);}
	if(_length==0){
		cout << "NULL" << endl;
	}
	cout <<endl;
}

int String::getCharArraySize(char arr[]){
	int CharArraySize(0);
	for(int i=0; arr[i]!='\0'; ++i)
	{   CharArraySize++;}
	return CharArraySize;

}


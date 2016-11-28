/*********************************************************************
 * File: String.cpp
 * Author: nglaeser
 * Function: Define String object class with pointer (hw 5)
 * Input: 
 * Output:  
 * Created: 14 Sep 2016
 * 
 * Copyright (C) 2016 by Noemi Glaeser
 **********************************************************************/

#include <iostream>
#include <cstdlib>
#include "String.h"

/***** private *****/
int String::getCharArraySize(char arr[])
{
    int size(0);
    int i(0);
    while(arr[i] != '\0')
    {
        size++;
        i++;
    }
    return size;
}


/**** constructors *****/
String::String()
{
    _length = 0;

    data = NULL;
}
String::String(char str[])
{
// Assume initialized properly i.e. with "" and thus has \0

    _length = getCharArraySize(str);
    data = new char[_length];
    // deep copy because str is passed in and will be deallocated as soon as you exit this constructor
    for(int i = 0; i < getCharArraySize(str); i++)
        data[i] = str[i];
}

/**** copy constructor ****/
String::String(const String &str)
{
    _length = getCharArraySize(str.data);
    data = new char[_length];
    // deep copy because str is passed in and will be deallocated as soon as you exit this constructor
    for(int i = 0; i < _length; i++)
        data[i] = str.data[i];
}

/**** deconstructor ****/
String::~String()
{
    delete [] data;
}

/*** public methods ****/
int String::length() const
{
    return _length;
}

void String::clear()
{
    // reset size
    _length = 0;
}

bool String::empty()
{
    if(_length == 0)
        return true;
    return false;
}

int String::find(char substr[], int startIndex)
{
    int ans = -1;
    for(int i = startIndex; i < (_length - startIndex + 1); i++)
    {
        if(i >= _length)
            return -1;
        // find index of the first letter of the substring
        if(data[i] == substr[0])
        {
            ans = i;
            for(int j = 1; j < getCharArraySize(substr); j++)
            {
                if((i+j) >= _length)
                    return -1;
                // break if the rest of the substring is not matched
                if(data[i+j] != substr[j])
                {
                   ans = -1;
                   break;
                }
            }
            // if the full substring was found, return the answer (first occurrence)
            if(ans != -1)
                return ans;
        }
        //if first letter of substring was not even found
    }
    return ans;
}

void String::print() const
{
    if(_length == 0)
        cout << "NULL" << endl;
    else
    {
        for(int i = 0; i < _length; i++)
        {
            cout << data[i];
        }
        cout << endl;
    }
}

/*** operator overloads ****/
bool String::operator==(const String &two) //replaces equal() method from hw4
{
    //check size first
    if(two.length() != _length)
        return false;
    //then check contents
    for(int i = 0; i < _length; i++)
    {
        if(data[i] != two[i])
            return false;
    }
    return true;
}

String String::operator+(const String &two) //replaces add() method
{
    // create temp array
    char *temp = new char[_length + two.length()];
    for(int i = 0; i < _length; i++)
        temp[i] = data[i];
    for(int i = 0; i < two.length(); i++)
        temp[_length+i] = two[i];

//    String ans = new String(temp);
    String ans(temp);
    return ans;
}

String String::operator=(const String &two)
{
    _length = getCharArraySize(two.data);

    delete [] data;
    data = new char[_length];
    for(int i = 0; i < _length; i++)
        data[i] = two[i];
    String copy(data);
    return copy;
}

char String::operator[](int index) const //replaces at() method
{
    if(index < _length)
        return data[index];
    else
        cout << "Error, index out of bounds.";
    return '\0';
}

ostream & operator<<(ostream &outstream, const String &str)
{
    if(str.length() == 0)
        outstream << "NULL" << endl;
    else
    {
        for(int i = 0; i < str.length(); i++)
        {
            outstream << str.data[i];
        }
        outstream << endl;
    }
    return outstream; //to enable cascading
}


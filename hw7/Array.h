//
//  Array.h
//  hw7
//
//  Created by Kuan-Ping Chang  on 2/20/16.
//  Copyright © 2016 Kuan-Ping Chang . All rights reserved.
//

#ifndef Template_Array_h
#define Template_Array_h

using namespace std;
#include <iomanip>
#include "assert.h"
#include <exception>

template
< typename Type >
class Array
{
private:
    int len;
    Type * buf;
public:
    Array( int newLen )
    : len( newLen ), buf( new Type[newLen] )
    {
    }
    Array( Array & l )
    : len( l.len ), buf( new Type[l.len] )
    {
        for ( int i = 0; i < l.len; i++ )
            buf[i] = l.buf[i];
    }
    
    //Exception
    int length()
    {
        return len;
    }
    
    
    Type & operator [] ( int i )
    {
        if (i<0 || i >= len){
            throw IndexOutOfBoundsException();
        }
        assert( 0 <= i && i < len );
        return buf[i];
    }
    void print( ostream & out )
    {
        for (int i = 0; i < len; i++)
            out << setw(5) << setprecision(2) << fixed << buf[i];
    }
    friend ostream & operator << ( ostream & out, Array & a )
    {
        a.print( out );
        return out;
    }
    friend ostream & operator << ( ostream & out, Array * ap )
    {
        ap->print( out );
        return out;
    }
    // note the overloading of operator << on a pointer as well

    class IndexOutOfBoundsException:public exception
    {
        virtual const char* what() const throw()
        {
            return "Index out of bounds";
        }
    };
};




#endif /* Template_Array.h */
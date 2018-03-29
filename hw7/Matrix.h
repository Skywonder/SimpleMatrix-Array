//
//  Matrix.h
//  hw7
//
//  Created by Kuan-Ping Chang  on 2/20/16.
//  Copyright © 2016 Kuan-Ping Chang . All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h
#include "Array.h"

template
<typename Element>
class Matrix
{
private:
    int rows, cols;
    // define m as an Array of Array pointers using the
    Array <Array<Element> * > m;
    // template you defined above
public:
    Matrix(int newRows, int newCols )
    : rows( newRows ), cols( newCols ), m( rows )
    {
        for (int i = 0; i < rows; i++ )
            m[i] = new Array < Element >( cols );
    }
    int numRows()
    {
        return rows;
    }
    int numCols()
    {
        return cols;
    }
    Array<Element> & operator [] (int row )
    {
        if (row > rows){
            throw IndexOutOfBoundsException();
        }
        return * m[row];
    }
    
    
    void print( ostream & out )
    {
        // You can write this one too, but use the Array::operator<<
        for (int i = 0; i < rows; ++i)
        {
            out << *m[i] << endl;
        }
    }
    friend ostream & operator << ( ostream & out, Matrix & m )
    {
        m.print( out );
        return out;
    }
    
    class IndexOutOfBoundsException:public exception
    {
        virtual const char* what() const throw()
        {
            return "Index out of bounds";
        }
    };
};


#endif /* Matrix_h */

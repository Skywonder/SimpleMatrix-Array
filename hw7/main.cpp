//
//  main.cpp
//  hw7
//
//  Created by Kuan-Ping Chang  on 2/20/16.
//  Copyright © 2016 Kuan-Ping Chang . All rights reserved.
//

#include <iostream>
#include "Array.h"
#include "Matrix.h"
using namespace std;

template
< class T >
void fillMatrix( Matrix <T> & m )
{
    int i, j;
    for ( i = 0; i < m.numRows(); i++ )
        m[i][0] = T();
    for ( j = 0; j < m.numCols(); j++ )
        m[0][j] = T();
    for ( i = 1; i < m.numRows(); i++ )
        for ( j = 1; j < m.numCols(); j++ )
        {
            m[i][j] = T(i * j);
        }
}
void test_int_matrix()
{
    Matrix < int > m(10,5);
    fillMatrix( m );
    cout << m;
    
}

void test_double_matrix()
{
    Matrix <double> m(8, 8);
    fillMatrix(m);
    cout << m;
    
}

void test_float_matrix()
{
    Matrix <float> m(5, 5);
    fillMatrix(m);
    cout << m;
}

void test_exception()
{
    Matrix<int> m(5, 4);
    fillMatrix(m);
    Matrix<double> d(10,10);
    fillMatrix(d);
    // PUT YOUR TRY/CATCH HERE AND TEST EXCEPTIONS
    try
    {
        int index = 100;
        Array<int> x = m[index];
    }
    catch (Matrix<int>::IndexOutOfBoundsException & e) {
        cout << "Matrix Index out of bounds (int) " << endl;
    }
    
    try
    {
        Array<double> x = d[0];
        double y = x[10];
    }
    catch (Array<double> :: IndexOutOfBoundsException & e){
        cout << "Array index out of bounds (double)" << endl;
    }
}


int main()
{
    test_int_matrix();
    test_double_matrix();
    test_float_matrix();
    test_exception();
    return 0;
}


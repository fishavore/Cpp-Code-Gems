#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

/*
Functors are essentially function objects,
i.e. objects with the function call operator overloaded.
Primary use of functors is in place of function pointers,
where the functor would be able to store data 
across multiple function calls without the use of  
global variables.
*/

namespace Functor 
{
    int globalVariable = 0;
    void sumFunction(int val)
    {
        globalVariable += val;
    }
    
    struct SumFunctor
    {
        int sum;
        SumFunctor() : sum{0} {}
        void operator()(int val) 
        {
            sum += val;
        }
    };
    
    void start()
    {
        std::cout << "Inside Functor.\n";
        int size = 5;
        int arr[] = {1, 3, 5, 7, 9};
        
        // method 1 - using function and global variable
        globalVariable = 0; 
        // need to reset global variable everytime functionality is used
        std::for_each(arr, arr+size, sumFunction);
        std::cout << "Sum is " << globalVariable << std::endl;
        
        // method 2 - using functor
        SumFunctor sum;
        std::for_each(arr, arr+size, sum);
        std::cout << "Sum is " << sum.sum << std::endl;
    }
    
}

//
//  LogNAl.c
//  MaxSum
//
//  Created by scorpiozj on 10/4/13.
//  Copyright (c) 2013 scorpiozj. All rights reserved.
//

#include <stdio.h>
int binarySearch(const int A[], int number, int len)
{
    int start = 0, end = len - 1;
    int mid = (start + end)/2;
    while (start <= end)
    {
        if (A[mid] < number)
        {
            start = mid + 1;
        }
        else if (A[mid] > number)
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
        mid = (start + end)/2;
    }
    return -1;
    
    return 0;
}
int binarySearch2(const int A[], int number, int start, int end)
{
    if (start == end)
    {
        if (number == A[start])
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = (start + end)/2;
        if (A[mid] > number)
        {
            return binarySearch2(A, number, start, mid);
        }
        else
        {
            if (A[mid] < number)
            {
                return binarySearch2(A, number, mid, end);
            }
            else
            {
                return mid;
            }
        }
    }
}

unsigned int GCD(unsigned int m, unsigned int n)
{
    while (n > 0)
    {
        unsigned int gcd = m % n;
        m = n;
        n = gcd;
    }
    return m;
}

//
//  main.c
//  MaxSum
//
//  Created by scorpiozj on 10/3/13.
//  Copyright (c) 2013 scorpiozj. All rights reserved.
//

#include <stdio.h>
#include "LogNAl.h"

int maxIn3(int a, int b, int c)
{
    int temp = (a > b)?a:b;
    return (temp > c)?temp:c;
}

static int maxSubSum (const int A[], int left, int right)
{
    int maxLeftSum = 0, maxRightSum = 0;
    int maxLeftBorderSum = 0, maxRightBorderSum = 0;
    int leftBorderSum = 0, rightBorderSum = 0;
    int center, i;
    if (left == right)
    {
        if (A[left] > 0)
        {
//            printf("%d :%d\n",left,A[left]);
            return A[left];
        }
        else
        {
            return 0;
        }
    }
    
    center = (left + right) / 2;
    maxLeftSum = maxSubSum(A, left, center);
    maxRightSum = maxSubSum(A, center + 1, right);
    
    for (i = center; i >= left; i--)
    {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    for (i = center + 1; i <=right ; i++)
    {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }
    int result = maxIn3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    printf("from %d to %d : %d\n",left,right,result);
    return result;

}

int maxSubsequenceSum (const int A[], int len)
{
    return maxSubSum(A, 0, len - 1);
}
void printArray(const int A[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}
/*
 O(N): get the number only once
 */
int maxSubSumOn(const int A[], int len)
{
    
    int sum = 0, maxSum = 0;
    for (int i = 0; i < len; i ++)
    {
        sum += A[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
    
}
int main(int argc, const char * argv[])
{

    // insert code here...
//    const int A[] = {4,3,-5,10};
//    int len = sizeof(A)/sizeof(int);
//    int maxSum = maxSubsequenceSum(A, len);
//    printf("maxSUm : %d\n",maxSum);
//
//    printf("another method:\n");
//    int maxSum2 = maxSubSumOn(A, len);
//    printf("another result: %d\n",maxSum2);
    
    
    const int sortedA[] = {3,6,12,14, 19,21};
    int sortLen = sizeof(sortedA)/sizeof(int);
    int target = 21;
    int pos = binarySearch(sortedA, target, sortLen);
    printf("pos of %d is %d\n",target,pos);
    
    int pos2 = binarySearch2(sortedA, target, 0, sortLen);
    printf("pos2 of %d is %d\n",target,pos2);
    
    
    int gcd = GCD(23*21, 23*11);
    printf("GCD is %d\n",gcd);
    return 0;
}


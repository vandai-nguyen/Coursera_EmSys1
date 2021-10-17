/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Declarations and comments of functions
 *
 * <Add Extended Description Here>
 *
 * @author Van Dai Nguyen
 * @date 17.10.2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdlib.h>

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints the statistics of an array
 *
 * @param median 
 * @param mean
 * @param maximum
 * @param minimum
 *
 * @return void
 */
 
 void print_statistics(double median, double mean, int maximum, int minimum)
 {
      printf("Median: %lf\n", median);
      printf("Mean: %lf\n", mean);
      printf("Maximum: %i\n", maximum);
      printf("Minimum: %i\n", minimum);
 }

/**
 * @brief Prints the array to the screen
 *
 * @param A is the array to be printed
 * @param n is the length of the array
 *
 * @return void
 */
 
 void print_array(int A[], int n)
 {
      int i = 0;
      for(i = 0; i < n; i++)
      {
         printf("%i\n", A[i]);
      }
 }
 
/**
 * @brief Finds the median of given array
 *
 * @param A is the given array
 * @param n is the length of the array
 * @return double
 */
 
 double find_median(int A[], int n)
 {
     int p; double median;
     
     if(n%2 == 0)
     {
       p = n/2;
       median = (A[p] + A[p-1])/2;
     }else{
       p = (n+1)/2;
       median = A[p];
     }
     
     return median;
 }
 
/**
 * @brief find the mean of given array
 *
 *
 * @param A is the given array
 * @param n is the length of given array
 *
 * @return double
 */
 
 double find_mean(int A[], int n)
 {
        int i, mean, sum;
        
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum = sum + A[i];
        }
        
        mean = sum / n;
        
        return mean;
 }
 
/**
 * @brief Finds the maximum of given array
 *
 * @param A is the given array
 * @param n is the length of given array
 *
 * @return int
 */
 
 int find_maximum(int A[], int n)
 {
     return A[0];
 }
 
/**
 * @brief Finds the minimum of given array
 *
 * @param A is the given array
 * @param n is the length of given array
 *
 * @return int
 */
 
 int find_minimum(int A[], int n)
 {
     return A[n-1];
 }
 
/**
 * @brief Help function of mergeSort
 *
 *
 * @param A is the given array
 * @param left is the smallest index of given array
 * @param right is the biggest index of given array
 * @param mid is the middle index of given array
 *
 * @return void
 */
 
 void merge(int A[], int left, int mid, int right)
 {
	int lengthSubArray1 = mid - left + 1;
	int lengthSubArray2 = right - mid;
	
	int* leftArray = (int*) malloc(lengthSubArray1*sizeof(int));
	int* rightArray = (int*) malloc(lengthSubArray2*sizeof(int));
	
	for(int i = 0; i < lengthSubArray1; i++)
	{
		leftArray[i] = A[left+i];
	}
	for(int j = 0; j < lengthSubArray2; j++)
	{
		rightArray[j] = A[mid+1+j];
	}
	
	int indexSubArray1 = 0;
	int indexSubArray2 = 0;
	int indexMergedArray = left;
	
	while((indexSubArray1 < lengthSubArray1) && (indexSubArray2 < lengthSubArray2))
	{
		if(leftArray[indexSubArray1] >= rightArray[indexSubArray2])
		{
			A[indexMergedArray] = leftArray[indexSubArray1];
			indexSubArray1++;
		}else{
			A[indexMergedArray] = rightArray[indexSubArray2];
			indexSubArray2++;
		}
		indexMergedArray++;
	}
	
	while(indexSubArray1 < lengthSubArray1)
	{
		A[indexMergedArray] = leftArray[indexSubArray1];
		indexSubArray1++;
		indexMergedArray++;
	}
	
	while(indexSubArray2 < lengthSubArray2)
	{
		A[indexMergedArray] = rightArray[indexSubArray2];
		indexSubArray2++;
		indexMergedArray++;
	}
 }
 
/**
 * @brief Help function of sort_array()
 *
 * (using merge sort, with merge() as a help function)
 *
 * @param A is the given array
 * @param left is the smallest index of given array
 * @param right is the biggest index of given array
 *
 * @return void
 */
 
 void mergeSort(int A[], int left, int right)
 {
    if (left >= right)
        return; 
    
    int mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
 }

/**
 * @brief Sorts the array from largest to smallest
 *
 *
 * @param A is the given array
 * @param n is the length of given array
 *
 * @return void
 */
 
 void sort_array(int A[], int n)
 {
      mergeSort(A, 0, n-1);
 }
 
 


#endif /* __STATS_H__ */

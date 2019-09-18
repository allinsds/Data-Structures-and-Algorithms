#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
/************************************选择排序*******************************************/
void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//设置最小值的索引依次为待排序的第一个元素的索引
		int minindex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				//查找待排序数组的中的最小值，并将最小值的索引交换
				minindex = j;
		//C++11标准库swap交换函数就在std命名空间中，老的标准在#include<algorithm>中
		swap(arr[i], arr[minindex]);
	}
}
template<typename T>
void SelectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//设置最小值的索引依次为待排序的第一个元素的索引
		int minindex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				//查找待排序数组的中的最小值，并将最小值的索引交换
				minindex = j;
		//C++11标准库swap交换函数就在std命名空间中，老的标准在#include<algorithm>中
		swap(arr[i], arr[minindex]);
	}
}
/*————————————————————————————————————————————*/

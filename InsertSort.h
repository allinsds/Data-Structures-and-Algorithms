#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
/************************************插入排序*******************************************/
/*
template <typename T>
void InsertSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j + 1] < arr[j])
				swap(arr[j + 1], arr[j]);
		}
	}

}
*/
template <typename T>
void InsertSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//寻找元素arr[i]合适的插入位置
		T tmp = arr[i];
		//j为插入位置的索引
		int j;
		//不采用for循环中定义 int j 方法，不然j是局部变量，跳出for,就会被析构掉
		for (j = i; j > 0 && (arr[j - 1] > tmp); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}
/*————————————————————————————————————————————*/


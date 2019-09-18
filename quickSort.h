#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//————————————————————快速排序——————————————---—/
//对arr[L...R]部分进行parttition操作
//返回给p，使得arr[L,...p-1]<arr[p];arr[p+1...r]>arr[p]
template <typename T>
int __partition(T arr[], int L, int R)
{
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	int j = L;
	for (int i = L + 1; i <= R; i++)
	{
		if (arr[L] > arr[i])
		{
			swap(arr[i], arr[++j]);

		}
	}
	swap(arr[L], arr[j]);
	return j;
}

template <typename T>
int __partition2(T arr[], int L, int R)
{
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	int i = L + 1, j = R;
	//一定要保证，最后交换的值是处于小于arr[L]状态
	while (i <= R && i <= j)
	{

		if (arr[i] >= arr[L])
		{
			while (j >= L + 1 && i <= j)
			{
				if (arr[j] <= arr[L])
				{
					swap(arr[i], arr[j]);

					//printf("3");
					j--;
					break;
				}
				j--;


			}
			//printf("1");

		}
		//printf("2");
		i++;

	}
	swap(arr[L], arr[j]);
	return j;
}
//对arr[L...R]部分进行parttition操作
template <typename T>
int __partition2_1(T arr[], int L, int R)
{
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	int i = L + 1, j = R;
	//一定要保证，最后交换的值是处于小于arr[L]状态
	while (true)
	{
		while (i <= R && arr[i] < arr[L])i++;
		while (j >= L + 1 && arr[j] > arr[L])j--;
		if (i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap(arr[L], arr[j]);
	return j;
}

//_quickSort 分成三部分的优化方法
template <typename T>
//对arr[l...r]部分进行快速排序
void _quickSort(T arr[], int L, int R)
{
	if (L >= R)
		return;
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	//arr[L+1...LT]<[L]   arr[LT+1...i)==a[L] arr[j,R]>a[L]
	int i = L + 1, j = R + 1, LT = L;
	//一定要保证，最后交换的值是处于小于arr[L]状态
	while (i < j)
	{
		if (arr[i] < arr[L])
		{
			swap(arr[i], arr[++LT]);
			i++;
		}
		else if (arr[i] == arr[L])
		{
			i++;
		}
		else
		{
			swap(arr[i], arr[--j]);
		}
	}
	swap(arr[L], arr[LT]);
	_quickSort(arr, L, LT - 1);
	_quickSort(arr, j, R);
}
template <typename T>
void quickSort(T arr[], int n)
{
	srand(time(NULL));
	_quickSort(arr, 0, n - 1);
}

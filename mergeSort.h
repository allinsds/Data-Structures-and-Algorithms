#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//—————————————————————归并排序————————————————————/
//将arr[l...mid]和arr[mid + 1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int L, int mid, int R)
{

	//开辟零时空间
	T *aux = new T[1 + R - L];
	//给开辟的空间赋值
	for (int i = L; i <= R; i++)
	{
		aux[i - L] = arr[i];
	}
	int i = L;
	int j = mid + 1;
	for (int k = L; k <= R; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - L];
			j++;
		}
		else if (j > R)
		{
			arr[k] = aux[i - L];
			i++;
		}//只有i,j不越界，才能进行下面的归并
		else if (aux[i - L] < aux[j - L])
		{
			arr[k] = aux[i - L];
			i++;
		}
		else {
			arr[k] = aux[j - L];
			j++;
		}

	}
	delete[] aux;
}

//排序的数组，起始索引，终止索引 对arr[l....r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int L, int R)
{
	if (L >= R)
		return;
	int mid = L + (R - L) / 2;
	__mergeSort(arr, L, mid);
	__mergeSort(arr, mid + 1, R);
	__merge(arr, L, mid, R);


}

template <typename T>
void mergeSort(T arr[], int n)
{
	//排序的数组，起始索引，终止索引
	__mergeSort(arr, 0, n - 1);
}

//————————————————————————————————————————————/
//————————————————————自低向上的归并排序———————————————/
template <typename T>
void mergeSortBu(T arr[], int n)
{
	//sz 表示每次分成多少份的大小
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz < n; i = i + sz + sz)
			//对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	}

}


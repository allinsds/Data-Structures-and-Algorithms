#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//�����������������������������������������������򡪡�������������������������---��/
//��arr[L...R]���ֽ���parttition����
//���ظ�p��ʹ��arr[L,...p-1]<arr[p];arr[p+1...r]>arr[p]
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
	//һ��Ҫ��֤����󽻻���ֵ�Ǵ���С��arr[L]״̬
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
//��arr[L...R]���ֽ���parttition����
template <typename T>
int __partition2_1(T arr[], int L, int R)
{
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	int i = L + 1, j = R;
	//һ��Ҫ��֤����󽻻���ֵ�Ǵ���С��arr[L]״̬
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

//_quickSort �ֳ������ֵ��Ż�����
template <typename T>
//��arr[l...r]���ֽ��п�������
void _quickSort(T arr[], int L, int R)
{
	if (L >= R)
		return;
	swap(arr[L], arr[rand() % (R - L + 1) + L]);
	//arr[L+1...LT]<[L]   arr[LT+1...i)==a[L] arr[j,R]>a[L]
	int i = L + 1, j = R + 1, LT = L;
	//һ��Ҫ��֤����󽻻���ֵ�Ǵ���С��arr[L]״̬
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

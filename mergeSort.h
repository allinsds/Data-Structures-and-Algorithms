#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//�������������������������������������������鲢���򡪡�������������������������������������/
//��arr[l...mid]��arr[mid + 1...r]�����ֽ��й鲢
template <typename T>
void __merge(T arr[], int L, int mid, int R)
{

	//������ʱ�ռ�
	T *aux = new T[1 + R - L];
	//�����ٵĿռ丳ֵ
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
		}//ֻ��i,j��Խ�磬���ܽ�������Ĺ鲢
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

//��������飬��ʼ��������ֹ���� ��arr[l....r]�ķ�Χ��������
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
	//��������飬��ʼ��������ֹ����
	__mergeSort(arr, 0, n - 1);
}

//����������������������������������������������������������������������������������������/
//�����������������������������������������Ե����ϵĹ鲢���򡪡���������������������������/
template <typename T>
void mergeSortBu(T arr[], int n)
{
	//sz ��ʾÿ�ηֳɶ��ٷݵĴ�С
	for (int sz = 1; sz <= n; sz += sz)
	{
		for (int i = 0; i + sz < n; i = i + sz + sz)
			//��arr[i...i+sz-1]��arr[i+sz...i+2*sz-1]���й鲢
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	}

}


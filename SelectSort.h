#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
/************************************ѡ������*******************************************/
void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//������Сֵ����������Ϊ������ĵ�һ��Ԫ�ص�����
		int minindex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				//���Ҵ�����������е���Сֵ��������Сֵ����������
				minindex = j;
		//C++11��׼��swap������������std�����ռ��У��ϵı�׼��#include<algorithm>��
		swap(arr[i], arr[minindex]);
	}
}
template<typename T>
void SelectionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//������Сֵ����������Ϊ������ĵ�һ��Ԫ�ص�����
		int minindex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minindex])
				//���Ҵ�����������е���Сֵ��������Сֵ����������
				minindex = j;
		//C++11��׼��swap������������std�����ռ��У��ϵı�׼��#include<algorithm>��
		swap(arr[i], arr[minindex]);
	}
}
/*����������������������������������������������������������������������������������������*/

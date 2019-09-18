#pragma once
#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
/************************************��������*******************************************/
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
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		T tmp = arr[i];
		//jΪ����λ�õ�����
		int j;
		//������forѭ���ж��� int j ��������Ȼj�Ǿֲ�����������for,�ͻᱻ������
		for (j = i; j > 0 && (arr[j - 1] > tmp); j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}
/*����������������������������������������������������������������������������������������*/


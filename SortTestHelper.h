#pragma once
#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;
namespace SortTestHelper
{
	//����N��Ԫ�ص�������飬ÿ��Ԫ��Ԫ�ص����������Ϊ[rangeL,rangeR]
	int* generateRandArray(int n,int rangeL,int rangeR)
	{
		assert(rangeL<=rangeR);
		//����һ����̬���飬����n�����Ϳռ䣬arr��ָ���������ĵ�һԪ��ָ��
		int *arr = new int[n];
		//���õ�ǰ��ʱ����Ϊ��������ӣ��������� ����#include<ctime>
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1);


		return arr;
	}
	int* generateOrder(int n, int rangeL, int rangeR)
	{
		assert(rangeL < rangeR);
		assert(n < rangeR - rangeL);
		int *arr = new int[n];
		for (int i = rangeL; i <n; i++)
		{
			arr[i - rangeL] = i;
		}
		return arr;
	}
	template<typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//���arr[0...n]��������
	template<typename T>
	bool issort(T arr[], int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			//��ֹ�����ʹ��i<n-1
			if (arr[i] > arr[i+1])
				return 0;
		}
		return 1;
	}

	int *copyIntArray(int a[], int n) {

		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
	template<typename T>
	//void(*sort)(T [],int)����ָ��
	void testSort(string sortname,void(*sort)(T [],int),T arr[],int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(issort(arr, n));
		
		cout << sortname << " :" << double(endTime - startTime) / CLOCKS_PER_SEC << " S" <<endl;
	}
}








#pragma once
#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;
namespace SortTestHelper
{
	//生成N个元素的随机数组，每个元素元素的随机数返回为[rangeL,rangeR]
	int* generateRandArray(int n,int rangeL,int rangeR)
	{
		assert(rangeL<=rangeR);
		//定义一个动态数组，分配n个整型空间，arr是指向这个数组的第一元素指针
		int *arr = new int[n];
		//利用当前的时间作为随机的种子，进行设置 包含#include<ctime>
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
	//检查arr[0...n]的有序性
	template<typename T>
	bool issort(T arr[], int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			//防止溢出，使得i<n-1
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
	//void(*sort)(T [],int)函数指针
	void testSort(string sortname,void(*sort)(T [],int),T arr[],int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(issort(arr, n));
		
		cout << sortname << " :" << double(endTime - startTime) / CLOCKS_PER_SEC << " S" <<endl;
	}
}








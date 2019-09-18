#pragma once
#include<iostream>

using namespace std;

struct student
{
	string name;
	int score;
	//< 号的重载，排序算法中当比较student时会用到
	bool operator<(const student &otherstudent)
	{
		return score != otherstudent.score ? score < otherstudent.score: name < otherstudent.name;
	}
	//<< 输出号的重载
	friend ostream& operator<<(ostream &os, const student &student)
	{
		os << "student:" << student.name << "　" << student.score<< endl;
		return os;
	}
};
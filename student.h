#pragma once
#include<iostream>

using namespace std;

struct student
{
	string name;
	int score;
	//< �ŵ����أ������㷨�е��Ƚ�studentʱ���õ�
	bool operator<(const student &otherstudent)
	{
		return score != otherstudent.score ? score < otherstudent.score: name < otherstudent.name;
	}
	//<< ����ŵ�����
	friend ostream& operator<<(ostream &os, const student &student)
	{
		os << "student:" << student.name << "��" << student.score<< endl;
		return os;
	}
};
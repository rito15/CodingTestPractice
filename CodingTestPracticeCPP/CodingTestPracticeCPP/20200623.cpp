// https://programmers.co.kr/learn/courses/30/lessons/42577?language=cpp
// �ؽ� - ��ȭ��ȣ ���

/*
	1. ���� ����
		- ��ȭ��ȣ��(vector<string>)�� ���� ��ȣ�� ��,
		  �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ��
		  (�� : "12"�� "123"�� ���ξ�)

		- �ش��ϴ� ��쿡�� false, �׷��� ������ true ����

	2. ����� ����
		(1)
			[1] �Է�
			  {"119", 97674223", "1195524421"}

			[2] ���
			  false

		(2)
			[1] �Է�
			  {"123", 456", "789"}

			[2] ���
			  true

		(3)
			[1] �Է�
			  {"12", "123", "1235", "567", "88"}

			[2] ���
			  false

	3. Ǯ��
		(1) ���� for������ ��� ���ڿ��� ���� ��
		    => ª�� ���ڿ��� �� ���ڿ��� subString���� ��

		(2) ���� �� �� ���ڿ��� �� ���ڿ����� ���ξ����� ��
*/

#include "common.h"

bool solution_20200623(vector<string> phone_book)
{
	for (string number1 : phone_book)
	{
		for (string number2 : phone_book)
		{
			// �� ��Ʈ�� �� ���� ����
			size_t shortLength =
				number1.length() <= number2.length() ?
				number1.length() : number2.length();

			// ���� ���Ͽ� ã��
			if (number1 != number2 &&
				!number1.compare(0, shortLength, number2))
			{
				cout << "[1] " + number1 << ", [2] " + number2 << endl;
				return false;
			}
		}
	}

	return true;
}
// https://programmers.co.kr/learn/courses/30/lessons/42576
// �ؽ� - �������� ���� ����

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	map<string, int> partMap;

	// ���� ��Ͽ��� Ȯ���ϰ� �ʿ� �߰�
	for (auto iter = participant.begin(); iter != participant.end(); iter++)
	{
		auto target = partMap.find(*iter);

		// �������� ������ 1�� �߰�
		if (target == partMap.end())
		{
			partMap.insert(make_pair(*iter, 1));
		}
		// �����ϸ� +1
		else
		{
			target->second += 1;
		}
	}

	// ������ ��Ͽ��� Ȯ���ϰ� �ʿ��� ����
	for (auto iter = completion.begin(); iter != completion.end(); iter++)
	{
		auto target = partMap.find(*iter);

		// �����ϸ� -1
		if (target != partMap.end())
		{
			if (target->second == 1)
			{
				partMap.erase(target);
			}
			else
			{
				target->second -= 1;
			}
		}
	}

	return partMap.begin()->first;
}
// https://programmers.co.kr/learn/courses/30/lessons/42576
// 해시 - 완주하지 못한 선수

#include "common.h"

string solution_20200621(vector<string> participant, vector<string> completion)
{
	map<string, int> partMap;

	// 참가 목록에서 확인하고 맵에 추가
	for (auto iter = participant.begin(); iter != participant.end(); iter++)
	{
		auto target = partMap.find(*iter);

		// 존재하지 않으면 1로 추가
		if (target == partMap.end())
		{
			partMap.insert(make_pair(*iter, 1));
		}
		// 존재하면 +1
		else
		{
			target->second += 1;
		}
	}

	// 완주자 목록에서 확인하고 맵에서 감소
	for (auto iter = completion.begin(); iter != completion.end(); iter++)
	{
		auto target = partMap.find(*iter);

		// 존재하면 -1
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
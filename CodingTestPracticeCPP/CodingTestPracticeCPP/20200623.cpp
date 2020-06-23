// https://programmers.co.kr/learn/courses/30/lessons/42577?language=cpp
// 해시 - 전화번호 목록

/*
	1. 문제 정의
		- 전화번호부(vector<string>)에 적힌 번호들 중,
		  한 번호가 다른 번호의 접두어인 경우가 있는지 확인
		  (예 : "12"는 "123"의 접두어)

		- 해당하는 경우에는 false, 그렇지 않으면 true 리턴

	2. 입출력 예시
		(1)
			[1] 입력
			  {"119", 97674223", "1195524421"}

			[2] 출력
			  false

		(2)
			[1] 입력
			  {"123", 456", "789"}

			[2] 출력
			  true

		(3)
			[1] 입력
			  {"12", "123", "1235", "567", "88"}

			[2] 출력
			  false

	3. 풀이
		(1) 이중 for문으로 모든 문자열을 서로 비교
		    => 짧은 문자열을 긴 문자열의 subString으로 비교

		(2) 정렬 후 앞 문자열이 뒷 문자열들의 접두어인지 비교
*/

#include "common.h"

bool solution_20200623(vector<string> phone_book)
{
	for (string number1 : phone_book)
	{
		for (string number2 : phone_book)
		{
			// 두 스트링 중 작은 길이
			size_t shortLength =
				number1.length() <= number2.length() ?
				number1.length() : number2.length();

			// 접두 비교하여 찾음
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
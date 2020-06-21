// https://programmers.co.kr/learn/courses/30/lessons/42578?language=csharp
// 해시 - 위장

/*
    1. 문제 정의
        - {옷 이름, 타입} 꼴의 페어를 받아 각각의 타입별로 개별 컨테이너에 저장
        - 타입의 개수(n), 타입별 옷의 개수(n1, n2, ...)에 따라 nCm (m = 1 ~ n)에서 (각 nCm에서 뽑아낸 값들의 곱)들을 모두 더한 값 구하기

    2. 예시
        - n = 1, n1 = 3                 => 3
        - n = 2, n1 = 2, n2 = 1         => (2 + 1) + (2 * 1) => 3 + 2 => 5
        - n = 3, n1 = 3, n2 = 2, n3 = 2 => (3 + 2 + 2) * ((3 * 2) + (2 * 2) + (2 * 3)) + (3 * 2 * 2) => 7 + 16 + 12 => 35

    3. 풀이 전략
        - Dictionary를 이용해 타입별 옷의 개수를 저장 : <string, int>
        - 빠른 개수 참조를 위해 옷의 개수들을 리스트에 저장 : List<int>
        - 정수형 리스트로부터 mCn의 모든 조합을 골라내는 메소드 구현 : int[][] Combination(List<int> list, int count)
        - 조합 메소드를 통해 각 count별 조합 내 모든 원소의 곱의 합들 구하기
        - 곱의 합들을 모두 더한 결과 => 정답
*/

using System;
using System.Collections.Generic;

public class Solution_20200621_2
{
    public int solution(string[,] clothes)
    {
        // 1. 각 타입별 옷 개수 저장
        Dictionary<string, int> clothNumbersByTypes = new Dictionary<string, int>();

        // 2. 옷 개수들만 리스트에 저장
        List<int> clothTypeNumbersList = new List<int>();

        // 1. 각 타입별 옷의 개수를 딕셔너리에 저장
        for (int i = 0; i < clothes.Length / clothes.Rank; i++)
        {
            string clothType = clothes[i, 1];

            if (!clothNumbersByTypes.ContainsKey(clothType))
            {
                clothNumbersByTypes.Add(clothType, 1);
            }
            else
            {
                clothNumbersByTypes[clothType] += 1;
            }
        }

        // 2. 옷의 개수들(Value)만 뽑아 리스트에 저장
        foreach (int value in clothNumbersByTypes.Values)
        {
            clothTypeNumbersList.Add(value);
        }

        int answer = 0;

        Console.WriteLine();
        return answer;
    }

}
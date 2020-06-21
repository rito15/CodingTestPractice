// https://programmers.co.kr/learn/courses/30/lessons/42578?language=csharp
// 해시 - 위장

using System;
using System.Collections.Generic;

public class Solution
{
    public static int solution(string[,] clothes)
    {

        List<string> clothTypeList = new List<string>();
        List<int> clothTypeNumbersList = new List<int>();

        Dictionary<string, int> clothNumbersByTypes = new Dictionary<string, int>();
        Dictionary<int, int> combinationDict = new Dictionary<int, int>();

        for (int i = 0; i < clothes.Length / clothes.Rank; i++)
        {
            string clothType = clothes[i, 1];

            if (!clothNumbersByTypes.ContainsKey(clothType))
            {
                clothNumbersByTypes.Add(clothType, 1);
                clothTypeList.Add(clothType);
            }
            else
            {
                clothNumbersByTypes[clothType] += 1;
            }
        }

        // Comb Init
        foreach (int value in clothNumbersByTypes.Values)
        {
            combinationDict.Add(value, 0);
            clothTypeNumbersList.Add(value);
        }

        for (int i = 0; i < clothTypeNumbersList.Count; i++)
        {
            Console.WriteLine($"[{i}] {clothTypeNumbersList[i]}");
        }
        Console.WriteLine();

        int answer = 0;

        // 조합 계산 (count : 1개 ~ N개 뽑기)
        for (int count = 1; count <= clothTypeList.Count; count++)
        {
            // 이번 조합 계산에 완료된 타입 수
            int completed = 0;

            // 조합 계산 누적 수 초기화
            foreach (int key in clothTypeNumbersList)
            {
                combinationDict[key] = 0;
            }

            while (completed < clothTypeList.Count)
            {
                // 피연산자 개수
                int operandCount = 0;

                // 곱 결과
                int mult = 1;

                while (operandCount < count)
                {
                    foreach (int key in clothTypeNumbersList)
                    {
                        Console.WriteLine($"Key : {key}, 누적 : {combinationDict[key]}");

                        if (combinationDict[key] < count)
                        {
                            //Console.WriteLine($"Count : {count}, operand : {key}");

                            mult *= key;
                            operandCount++;

                            combinationDict[key] += 1;

                            if (combinationDict[key] == count)
                                completed++;
                        }
                    }
                }

                Console.WriteLine(mult);

                answer += mult;
            }
        }

        Console.WriteLine();
        return answer;
    }

}
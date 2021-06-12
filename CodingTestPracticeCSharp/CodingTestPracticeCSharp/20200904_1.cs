// https://programmers.co.kr/learn/courses/30/lessons/42584?language=csharp
// 스택/큐 - 주식가격

using System.Collections.Generic;

public class Solution_20200904_1
{
    public int[] solution(int[] prices)
    {
        int len = prices.Length;
        int[] answer = new int[len];

        for (int i = 0; i < len; i++)
        {
            int term = 0;
            int j = i + 1;
            while (j < len && prices[i] <= prices[j])
            {
                term++;
                j++;
            }

            if (term == 0 && i < len - 1)
                term++;

            answer[i] = term;
        }

        return answer;
    }
}
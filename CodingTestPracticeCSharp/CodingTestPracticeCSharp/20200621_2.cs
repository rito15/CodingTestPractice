// https://programmers.co.kr/learn/courses/30/lessons/42578?language=csharp
// 해시 - 위장

/*
    1. 문제 정의
        - [옷 이름, 옷 종류] 형태가 이어지는 이차원 배열이 주어짐
        - 종류가 서로 다른 옷이면 같이 입을 수 있음
        - 최소 한 개의 옷은 입어야 함
        - 입을 수 있는 옷 조합의 개수를 정수로 출력

    2. 입력 및 출력 예시
        (1)

         [1] 입력
           : { 
               {"yellow_hat",      "headgear"}, 
               {"blue_sunglasses", "eyewear"},
               {"green_turban",    "headgear"}
             }

         [2] 출력
           : 5

        (2)

         [1] 입력
           : { 
               {"crow_mask",       "face"}, 
               {"blue_sunglasses", "face"},
               {"smoky_makeup",    "face"}
             }

         [2] 출력
           : 3

    3. 풀이 - 알고리즘
     :   (A종류의 옷 개수 + 안입는 경우의 수(1))
       * (B종류의 옷 개수 + 안입는 경우의 수(1))
       * ... * (...)
       - 아무것도 안입는 경우의 수(1)

    4. 풀이 - 자료구조
     - Dictionary<string, int>를 사용하여 각 타입별 옷 개수 저장
*/

using System;
using System.Collections.Generic;

public class Solution_20200621_2
{
    public int solution(string[,] clothes)
    {
        // 각 타입별 옷 개수 저장
        Dictionary<string, int> clothesNumbersByTypes = new Dictionary<string, int>();

        for (int i = 0; i < clothes.Length / 2; i++)
        {
            string currentClothesType = clothes[i, 1];

            // 해당 타입명을 이미 갖고 있으면 수량 + 1
            if (clothesNumbersByTypes.ContainsKey(currentClothesType))
            {
                clothesNumbersByTypes[currentClothesType]++;
            }
            // 해당 타입명에 대한 수량 처음 등록(1)
            else
            {
                clothesNumbersByTypes.Add(currentClothesType, 1);
            }
        }
        
        int answer = 1;
        foreach (int count in clothesNumbersByTypes.Values)
        {
            answer *= (count + 1);
        }

        return answer - 1;
    }

}
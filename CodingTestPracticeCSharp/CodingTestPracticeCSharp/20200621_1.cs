// https://programmers.co.kr/learn/courses/30/lessons/12901
// 연습문제 - 2016년

public class Solution
{
    public string solution(int a, int b)
    {
        //                        1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12
        int[] daysOfMonths = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        //                    0      1      2      3      4      5      6
        string[] dayNames = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

        int dayValue = b + 4; // +4 : 금요일 기준
        for (int i = 0; i < a; i++)
        {
            dayValue += daysOfMonths[i];
        }

        dayValue %= 7;
        return dayNames[dayValue];
    }
}

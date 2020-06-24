// https://programmers.co.kr/learn/courses/30/lessons/42579?language=csharp
// 해시 - 베스트앨범

using System;
using System.Collections;
using System.Collections.Generic;

public class Solution_20200623_1
{
    class ListReverser : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            if (x == y) return 0;
            return (x > y) ? -1 : 1;
        }
    }

    public struct IndexPlayCountPair
    {
        public int index;
        public int playCount;

        public IndexPlayCountPair(int i, int p)
        {
            index = i; playCount = p;
        }
    }

    public int[] solution(string[] genres, int[] plays)
    {
        // SortedList - Key : plays, Value : index
        // Dictionary - Key : genres, Value : <plays, index>
        // 각 장르별 모든 노래 저장
        //Dictionary<string, SortedList<int, int>> allMusicDict = new Dictionary<string, SortedList<int, int>>();
        Dictionary<string, List<IndexPlayCountPair>> allMusicDict = new Dictionary<string, List<IndexPlayCountPair>>();

        // 각 장르별 최대 재생횟수만 갱신하며 저장
        Dictionary<string, int> maxPlaysDIct = new Dictionary<string, int>();

        for (int i = 0; i < genres.Length; i++)
        {
            string genreName = genres[i];
            int playCount = plays[i];

            // 1. 각 장르별 모든 노래 저장
            allMusicDict.TryGetValue(genreName, out var sList);
            if (sList == null)
            {
                //sList = new SortedList<int, int>(new ListReverser());
                sList = new List<IndexPlayCountPair> { new IndexPlayCountPair(-1, -1), new IndexPlayCountPair(-1, -1) };
                allMusicDict.Add(genreName, sList);
            }

            // sList는 [0], [1]만 사용하면 됨 => [0]의 카운트가 더 큼, 카운트가 같으면 인덱스가 낮음
            // [1]보다 playCount가 큰지 비교
            if (sList[1].playCount < playCount)
            {
                sList[1] = new IndexPlayCountPair(i, playCount);

                if (sList[0].playCount < sList[1].playCount)
                {
                    var temp = sList[0];
                    sList[0] = sList[1];
                    sList[1] = temp;
                }
            }

            // 2. 각 장르별 최대 재생 횟수 갱신
            if (!maxPlaysDIct.ContainsKey(genreName))
                maxPlaysDIct.Add(genreName, playCount);
            else
            {
                if (maxPlaysDIct[genreName] < playCount)
                    maxPlaysDIct[genreName] = playCount;
            }
        }

        // 3. 반대로 <재생횟수, 장르명> 꼴 정렬 리스트 생성
        SortedList<int, string> sortedMaxPlayGenreList = new SortedList<int, string>(new ListReverser());
        foreach (string genre in maxPlaysDIct.Keys)
        {
            sortedMaxPlayGenreList.Add(maxPlaysDIct[genre], genre);
        }

        // 4. 각 장르별 2개씩 뽑기
        List<int> answerList = new List<int>();
        foreach (string genreName in sortedMaxPlayGenreList.Values)
        {
            //Console.WriteLine($"{key} - {sortedMaxPlayGenreList[key]}");
            foreach (var pair in allMusicDict[genreName])
            {
                if (pair.index > -1) Console.WriteLine($"[{genreName}] {pair.index}, {pair.playCount}");

                if (pair.index > -1) answerList.Add(pair.index);
            }
        }

        return answerList.ToArray();
    }
}
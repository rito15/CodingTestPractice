// https://programmers.co.kr/learn/courses/30/lessons/42579?language=csharp
// 해시 - 베스트앨범

/*
    - 정답 !
*/

using System.Collections.Generic;

public class Solution_20200902_1
{
    class Song
    {
        public int      Index { get; set; }
        public string   Genre { get; set; }
        public int      Plays { get; set; }
    }

    struct indexPlaysPair
    {
        public int index;
        public int plays;

        public indexPlaysPair(int i, int p)
        {
            index = i; plays = p;
        }
    }

    struct genrePlaysPair
    {
        public string genre;
        public int plays;

        public genrePlaysPair(string g, int p)
        {
            genre = g; plays = p;
        }
    }

    public int[] solution(string[] genres, int[] plays)
    {
        int songCount = genres.Length;

        // 정답 리스트
        List<int> answer = new List<int>();

        // 모든 노래 목록
        List<Song> songList = new List<Song>();

        // 각 장르별 플레이 횟수 누적
        Dictionary<string, int> genrePlayTotalDict = new Dictionary<string, int>();
        List<genrePlaysPair> genrePlayTotalList = new List<genrePlaysPair>();

        // 각 장르별 노래 목록 딕셔너리 : <장르명, <인덱스, 재생횟수> >
        Dictionary<string, List<indexPlaysPair>> eachGenreSongsDict = new Dictionary<string, List<indexPlaysPair>>();

        for (int i = 0; i < songCount; i++)
        {
            Song song = new Song { Index = i, Genre = genres[i], Plays = plays[i] };
            songList.Add(song);

            // 각 장르별 플레이 누적 횟수 증가
            if (genrePlayTotalDict.ContainsKey(song.Genre))
                genrePlayTotalDict[song.Genre] += song.Plays;
            else
                genrePlayTotalDict.Add(song.Genre, song.Plays);

            // 각 장르별 노래 목록 생성
            if(!eachGenreSongsDict.ContainsKey(song.Genre))
                eachGenreSongsDict.Add(song.Genre, new List<indexPlaysPair>());

            eachGenreSongsDict[song.Genre].Add(new indexPlaysPair(song.Index, song.Plays));

            //Console.WriteLine($"{song.Index, 2} : {song.Genre, 10} : {song.Plays, 5}");
        }

        // 각 장르별 노래 목록 - 재생 횟수, 인덱스로 정렬
        foreach (var songListByGenre in eachGenreSongsDict.Values)
        {
            songListByGenre.Sort((a, b) => a.index.CompareTo(b.index));
            songListByGenre.Sort((a, b) => -a.plays.CompareTo(b.plays));
        }

        // 각 장르별 누적 횟수 종합, 재생횟수로 정렬
        foreach (var genrePlayPair in genrePlayTotalDict)
        {
            genrePlayTotalList.Add(new genrePlaysPair(genrePlayPair.Key, genrePlayPair.Value));
        }

        //Console.WriteLine();
        //foreach (var gp in genrePlayTotalList)
        //{
        //    Console.WriteLine($"{gp.genre,10} : {gp.totalPlays,5}");
        //}
        //Console.WriteLine();

        genrePlayTotalList.Sort((a, b) => -a.plays.CompareTo(b.plays));

        //foreach (var gp in genrePlayTotalList)
        //{
        //    Console.WriteLine($"{gp.genre,10} : {gp.totalPlays,5}");
        //}
        //Console.WriteLine();

        // 종합 재생횟수가 많은 순서의 장르별로 노래 2개씩 뽑기
        foreach (var gp in genrePlayTotalList)
        {
            int i = 0;

            foreach (var song in eachGenreSongsDict[gp.genre])
            {
                if (i < 2)
                {
                    answer.Add(song.index);
                }
                i++;
            }
        }

        return answer.ToArray();
    }
}
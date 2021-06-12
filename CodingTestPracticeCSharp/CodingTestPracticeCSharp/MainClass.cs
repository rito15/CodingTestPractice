using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingTestPracticeCSharp
{
    class MainClass
    {
        public static void Main()
        {
            object answer = null;

            //answer = new Solution_20200621_1().solution(5, 24); // TUE

            //answer = new Solution_20200621_2().solution(new[,] { { "crow_mask", "face" }, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } }); // 3
            //answer = new Solution_20200621_2().solution(new[,] { { "yellow_hat", "headgear" }, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } }); // 5

            //answer = new Solution_20200902_1().solution(
            //    new[] { "classic", "pop", "classic", "classic", "pop", "pop", "pop", "Ballad",  },
            //    new[] { 500,        600,  150,       800,       2500,  2500,  2500,  3500,     }
            //    );

            //foreach (var item in answer as Array)
            //{
            //    Console.Write($"{item} ");
            //}

            answer = new Solution_20200904_1().solution(new[] { 1, 2, 3, 2, 3 });

            string ansStr = "[ ";
            foreach (var item in answer as Array)
            {
                ansStr += $"{item} ";
            }
            Console.WriteLine($"{ansStr}]");
        }
    }
}

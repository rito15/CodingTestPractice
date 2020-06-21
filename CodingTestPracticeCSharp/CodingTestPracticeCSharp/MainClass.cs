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
            //var answer = new Solution().solution(5, 24); // TUE

            //var answer = new Solution_20200621_1().solution(new[,] { { "crow_mask", "face" }, { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } }); // 3
            var answer = new Solution_20200621_2().solution(new[,] { { "yellow_hat", "headgear" }, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" } }); // 5

            Console.WriteLine(answer);
        }
    }
}

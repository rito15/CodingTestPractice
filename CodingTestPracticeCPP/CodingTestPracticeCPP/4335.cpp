#include <iostream>
#include <string>
#define OK false
#define NO true
#define DEFAULT -1

using namespace std;

void main_4335()
{
    int inputNum = DEFAULT;
    string inputHint;

    bool probs[11] = { };
    int answer = DEFAULT;
    bool isLier = false;
    int sum = 0;

    while (true)
    {
        string temp;
        getline(cin, temp);
        inputNum = stoi(temp);

        if(inputNum == 0) break;
        getline(cin, inputHint);

        // 이미 거짓말쟁이로 판명 완료
        if (isLier) continue;

        if (answer == DEFAULT)
        {
            if (inputHint == "too high")
            {
                for (int i = inputNum; i <= 10; i++)
                {
                    if (probs[i] == OK)
                    {
                        sum++;
                        probs[i] = NO;
                    }
                }
            }
            else if (inputHint == "too low")
            {
                for (int i = 1; i <= inputNum; i++)
                {
                    if (probs[i] == OK)
                    {
                        sum++;
                        probs[i] = NO;
                    }
                }
            }
        }
        if (inputHint == "right on")
        {
            // 이미 정답이 밝혀졌음에도 거짓말을 하는 경우
            if ((answer != DEFAULT && answer != inputNum)
            // 후보에서 제외됐는데 정답이라고 하는 경우
                || probs[inputNum] == NO)
            {
                isLier = true;
                continue;
            }
            else
            {
                answer = inputNum;
            }
        }

        if(sum == 10)
            isLier = true;
    }

    if(isLier)
        printf("Stan is dishonest");
    else
        printf("Stan may be honest");
}
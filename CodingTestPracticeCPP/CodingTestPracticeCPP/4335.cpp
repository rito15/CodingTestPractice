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

        // �̹� ���������̷� �Ǹ� �Ϸ�
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
            // �̹� ������ ������������ �������� �ϴ� ���
            if ((answer != DEFAULT && answer != inputNum)
            // �ĺ����� ���ܵƴµ� �����̶�� �ϴ� ���
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
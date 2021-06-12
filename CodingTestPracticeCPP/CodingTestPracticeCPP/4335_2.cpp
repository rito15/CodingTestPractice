#include <iostream>
#include <string>
using namespace std;

int main_4335_2()
{
    int inputNum;
    string inputHint;
    bool probs[11] = { };
    bool isLier = false;

    while (true)
    {
        string temp;
        getline(cin, temp);
        inputNum = stoi(temp);

        if (inputNum == 0) break;
        getline(cin, inputHint);

        if (inputHint == "too high")
        {
            for (int i = inputNum; i <= 10; i++)
                probs[i] = true;
        }
        else if (inputHint == "too low")
        {
            for (int i = 1; i <= inputNum; i++)
                probs[i] = true;
        }
        else if(probs[inputNum] == true)
            isLier = true;
    }

    if (isLier)
        printf("Stan is dishonest");
    else
        printf("Stan may be honest");

    return 0;
}
/* https://programmers.co.kr/learn/courses/30/lessons/17676?language=cpp

    [�߼� Ʈ����]

    �Է� : 1~2000 ������ ��Ʈ�� �迭(����)

    �� ��Ʈ�� ����
    - ����Ϸ�ð� S, ó���ð� T
    - S : 2016-09-15 hh:mm:ss.sss ���� (���� ����)
    - T : 0.000s ���� (�ִ� �Ҽ��� ��° �ڸ�, �� �ڿ��� s)

    - ����
      2016-09-15 03:10:33.020 0.011s
      => ���� 3�� 10�� 33.010�ʺ��� 3�� 10�� 33.020�ʱ��� 0.011�ʵ��� ó����

    - 0.001 <= T <= 3.000

    - lines �迭�� S�� �������� �������� ���� �Ǿ�����
*/

// ���̵�� : �� �ð����� ����, �������� Ȯ���ؼ� �ش� �ð��� ó���� ������ ������ �ľ�

#include "common.h"

//#include <string>
//#include <vector>
using namespace std;

const int index_hh = 11;
const int index_mm = 14;
const int index_ss = 17;
const int index_ms = 20;
const int index_T  = 24;

class LogData
{
public:
    int beginTime;
    int endTime;
    int processTime;

    LogData() {}

    LogData(string dataString)
    {
        beginTime = 0.0f;
        endTime = 0.0f;

        // 1. �Ϸ�ð� �����
        
        int hh = stoi(dataString.substr(index_hh, 2));
        int mm = stoi(dataString.substr(index_mm, 2));
        int ssms = stoi(dataString.substr(index_ss, 2)) * 1000
                 + stoi(dataString.substr(index_ms, 3));

        endTime += hh * 10000000;
        endTime += mm * 100000;
        endTime += ssms;

        processTime = stod(dataString.substr(index_T, 5)) * 1000;

        //cout << hh << " : " << mm << " : " << ssms << " / " << processTime << endl;

        // 2. ���۽ð� �����

        ssms -= (processTime - 1);

        if (ssms < 0)
        {
            mm--;
            ssms += 60000;
        }
        if (mm < 0)
        {
            hh--;
            mm += 60;
        }

        beginTime += hh * 10000000;
        beginTime += mm * 100000;
        beginTime += ssms;

        //cout << hh << " : " << mm << " : " << ssms << " / " << processTime << endl;

        cout << "Begin : " << beginTime << endl;
        cout << "End   : " << endTime << endl;
        cout << "Proc  : " << processTime << endl << endl;
    }
};

// basisBegin + 0.99�� ���� �ð��� ��� �����Ϳ� ���ԵǴ��� �˻�
// �����ϸ� 1, �ƴϸ� 0 ����
int checkByBasisBegin(LogData data, int basisBeginTime)
{
    int basisEndTime = basisBeginTime + 999;

    return
        basisBeginTime <= data.endTime && basisEndTime >= data.beginTime;
}

// basisEnd - 0.99�� ���� �ð��� ��� �����Ϳ� ���ԵǴ��� �˻�
// �����ϸ� 1, �ƴϸ� 0 ����
int checkByBasisEnd(LogData data, int basisEndTime)
{
    int basisBeginTime = basisEndTime - 999;

    return
        basisBeginTime <= data.endTime && basisEndTime >= data.beginTime;
}

int solution20200916_1(vector<string> lines)
{
    int max = 0;
    int length = lines.size();

    vector<LogData> logVec;// = new vector<LogData>();

    // �迭 �ʱ�ȭ
    for (int i = 0; i < length; i++)
    {
        logVec.push_back(lines[i]);
    }

    // ������ ������ ���� Ȯ��
    for (int i = 0; i < length; i++)
    {
        int thisMax = 0;

        // 1. Check by Basis Begin Time
        for (int j = 0; j < length; j++)
        {
            thisMax += checkByBasisBegin(logVec[j], logVec[i].beginTime);
        }

        if (thisMax > max)
            max = thisMax;

        thisMax = 0;

        // 2. Check by Basis End Time
        for (int j = 0; j < length; j++)
        {
            thisMax += checkByBasisBegin(logVec[j], logVec[i].endTime);
        }

        if (thisMax > max)
            max = thisMax;
    }

    //cout << max << endl;

    return max;
}
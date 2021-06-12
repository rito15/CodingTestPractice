/* https://programmers.co.kr/learn/courses/30/lessons/17676?language=cpp

    [추석 트래픽]

    입력 : 1~2000 길이의 스트링 배열(벡터)

    각 스트링 구성
    - 응답완료시간 S, 처리시간 T
    - S : 2016-09-15 hh:mm:ss.sss 형식 (고정 길이)
    - T : 0.000s 형식 (최대 소수점 셋째 자리, 맨 뒤에는 s)

    - 예시
      2016-09-15 03:10:33.020 0.011s
      => 오전 3시 10분 33.010초부터 3시 10분 33.020초까지 0.011초동안 처리됨

    - 0.001 <= T <= 3.000

    - lines 배열은 S를 기준으로 오름차순 정렬 되어있음
*/

// 아이디어 : 각 시간들의 시작, 끝지점만 확인해서 해당 시간에 처리한 데이터 개수만 파악

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

        // 1. 완료시간 만들기
        
        int hh = stoi(dataString.substr(index_hh, 2));
        int mm = stoi(dataString.substr(index_mm, 2));
        int ssms = stoi(dataString.substr(index_ss, 2)) * 1000
                 + stoi(dataString.substr(index_ms, 3));

        endTime += hh * 10000000;
        endTime += mm * 100000;
        endTime += ssms;

        processTime = stod(dataString.substr(index_T, 5)) * 1000;

        //cout << hh << " : " << mm << " : " << ssms << " / " << processTime << endl;

        // 2. 시작시간 만들기

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

// basisBegin + 0.99초 내의 시간이 대상 데이터에 포함되는지 검사
// 포함하면 1, 아니면 0 리턴
int checkByBasisBegin(LogData data, int basisBeginTime)
{
    int basisEndTime = basisBeginTime + 999;

    return
        basisBeginTime <= data.endTime && basisEndTime >= data.beginTime;
}

// basisEnd - 0.99초 내의 시간이 대상 데이터에 포함되는지 검사
// 포함하면 1, 아니면 0 리턴
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

    // 배열 초기화
    for (int i = 0; i < length; i++)
    {
        logVec.push_back(lines[i]);
    }

    // 구간별 데이터 개수 확인
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
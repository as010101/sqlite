
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <io.h>
#include <memory>
//#define _CRT_SECURE_NO_WARNINGS
extern "C"

{
#include "sqlite3.h"
};

using namespace std;

//out<<lineStream <<endl;/////ȫ�ַ�Χִ����䣿����




//shared_ptr<ofstream> ptr_out;

ofstream* ptr_out=nullptr;











int LoadMyInfo(void* para, int n_column, char** column_value, char** column_name);
int tableInfo(void* para, int n_column, char** column_value, char** column_name);
int fieldWrite(void* para, int n_column, char** column_value, char** column_name);

void listFiles(const char* dir);


int fieldWrite(void* para, int n_column, char** column_value, char** column_name)
{
    ofstream outdata("D:/common/field.csv",ios::app);
    string str;
    for (int i = 0; i < n_column; i++)
    {
        if (i == 0)
        {
            str = str + column_value[i];
        }
        else
        {
            str = str + "," + column_name[i];
        }
        
    }
    outdata << str << endl;

    cout << "�ֶζ�ȡ���" << endl;


    return 0;
}

int tableInfo(void* para, int n_column, char** column_value, char** column_name)
{
    for (int i = 0; i < n_column; i++)
    {
        std::cout<<column_value[i]<<endl;
    }
    return 0;

}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int main()
{
    char dir[200] = "D:/common";
    //cout << "Enter a directory: ";
    //cin.getline(dir, 200);

    listFiles(dir);


    return 0;
}

void listFiles(const char* dir)
{
    char dirNew[200];
    strcpy(dirNew, dir);
    strcat(dirNew, "\\*.*");    // ��Ŀ¼�������"\\*.*"���е�һ������,����_findnext��handle,findData�����صĲ��������ж��Ƿ���Ŀ¼��
                                //�ǵĻ�,��һ��������Ŀ¼��handleӦ����ָ��ǰĿ¼��һ��ָ������
    intptr_t handle;
    _finddata_t findData;
    //string mypath("D:/mydata/my.csv");
    //ofstream  myof(mypath, ios::app);

    //string field("ʱ��,��Ʊ����,��Ʊ����,ǰ����,���̼�,��߼�,��ͼ�,���̼�,������,���׽��");
    //myof << field << endl;

    handle = _findfirst(dirNew, &findData);
    if (handle == -1)        // ����Ƿ�ɹ�
        return;
    do
    {
        double Pprice = 0;//��ʼ������Ϊ0
        if (findData.attrib & _A_SUBDIR)
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n";

            // ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
            strcpy(dirNew, dir);
            strcat(dirNew, "\\");
            strcat(dirNew, findData.name);

            listFiles(dirNew);
        }
        else
        {
            cout << findData.name << "\t" << findData.size << " bytes.\n";
///-------------------------------------------------------------------------------MarketData----------------------------------------------------
            string fileStr = string(findData.name);
           string  outPath = "D:/commonDB/Market/" + fileStr.substr(0, fileStr.size()-3)+"---Market.csv";             ///ȫ�ֱ���
            string dbPath= "D:/common/" + fileStr;
            ofstream out(outPath, ios::app);   ///����ļ����
            ptr_out = &out;
            
           
            string field = "Id,ExchangeID,SecurityID,DataTimeStamp,IngressTimeStamp,IngressTimeUsec,ProcessTimeStamp,ProcessTimeUsec,PublishTimeUsec,AskPrice1,AskVolume1,BidPrice1,BidVolume1,AskPrice2,AskVolume2,BidPrice2,BidVolume2,AskPrice3,AskVolume3,BidPrice3,BidVolume3,AskPrice4,AskVolume4,BidPrice4,BidVolume4,AskPrice5,AskVolume5,BidPrice5,BidVolume5,AskPrice6,AskVolume6,BidPrice6,BidVolume6,AskPrice7,AskVolume7,BidPrice7,BidVolume7,AskPrice8,AskVolume8,BidPrice8,BidVolume8,AskPrice9,AskVolume9,BidPrice9,BidVolume9,AskPrice10,AskVolume10,BidPrice10,BidVolume10,UpperLimitPrice,LowerLimitPrice,OpenPrice,PreClosePrice,LastPrice,HighestPrice,LowestPrice,Volume,Turnover,TotalAskAmount,TotalBidAmount,TotalAskVolume,TotalBidVolume,FirstLevelBuyOrderVolumes,FirstLevelSellOrderVolumes,UpdateType,UpdatePrice,UpdateVolume,Source";
            out << field << endl;
            sqlite3* db = nullptr;
            int result = -1;
            result = sqlite3_open(dbPath.c_str(), &db);
            if (result != 0)
            {
                std::cout << "��ʧ��" << std::endl;
            }

     

            result = sqlite3_exec(db, "SELECT *  FROM  realtimeMarketdata  ", LoadMyInfo, NULL, NULL);

            //-----------------------------------------------------------------------------

     

            ////--------------------------------------------------------------Transactions---------------------------------------

            outPath= "D:/commonDB/Transactions/" + fileStr.substr(0, fileStr.size() - 3) + "---Transactions.csv";
            field = "2014,SubSeq,ExchangeID,SecurityID,TradeTime,TradePrice,TradeVolume,ExecType,BuyNo,SellNo,Info1,Info2,Info3";
            ofstream outT(outPath, ios::app);
            ptr_out = &outT;
            outT << field << endl;
            result = sqlite3_exec(db, "SELECT *  FROM  Transactions  ", LoadMyInfo, NULL, NULL);









            /////---------------------------------------------------------------------------------------------------



            ////--------------------------------------------------------------OrderDetails---------------------------------------
            outPath = "D:/commonDB/OrderDetails/" + fileStr.substr(0, fileStr.size() - 3) + "---OrderDetails.csv";
            field = "2014,SubSeq,ExchangeID,SecurityID,OrderTime,Price,Volume,Side,OrderType,Info1,Info2,Info3,ArrivedTime";
            ofstream outO(outPath, ios::app);
            ptr_out = &outO;
            outO << field << endl;
            result = sqlite3_exec(db, "SELECT *  FROM  OrderDetails  ", LoadMyInfo, NULL, NULL);








            /////---------------------------------------------------------------------------------------------------

        }

    } while (_findnext(handle, &findData) == 0);

    _findclose(handle);    // �ر��������
}








int LoadMyInfo(void* para, int n_column, char** column_value, char** column_name)

{

    //para������ sqlite3_exec �ﴫ��� void * ����

    //ͨ��para����������Դ���һЩ�����ָ�루������ָ�롢�ṹָ�룩��Ȼ����������ǿ��ת���ɶ�Ӧ�����ͣ���������void*���ͣ�����ǿ��ת����������Ͳſ��ã���Ȼ�������Щ����

    //n_column����һ����¼�ж��ٸ��ֶ� (��������¼�ж�����)

    // char ** column_value �Ǹ��ؼ�ֵ������������ݶ������������ʵ�����Ǹ�1ά���飨��Ҫ��Ϊ��2ά���飩��ÿһ��Ԫ�ض���һ�� char * ֵ����һ���ֶ����ݣ����ַ�������ʾ����/0��β��

    //char ** column_name �� column_value�Ƕ�Ӧ�ģ���ʾ����ֶε��ֶ�����



     //����Ҳ�ʹ�� para �������������Ĵ���.



    int i=0;

    //printf("��¼���� %d ���ֶ� /n", n_column);
    string str;
    for (i = 0; i < n_column; i++)

    {
        if (i == 0)
        {
            str = str + column_value[i];
        }
        else
        {
            str = str + "," + column_value[i];
        }

      //  printf("�ֶ���: %s  �ֶ�ֵ: %s /n", column_name[i], column_value[i]);

    }
    (*ptr_out)<< str << endl;

    //printf("------------------ /n");

    return 0;

}

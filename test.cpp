
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

//out<<lineStream <<endl;/////全局范围执行语句？？？




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

    cout << "字段读取完成" << endl;


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
    strcat(dirNew, "\\*.*");    // 在目录后面加上"\\*.*"进行第一次搜索,根据_findnext（handle,findData）返回的参数属性判断是否是目录，
                                //是的话,进一步遍历子目录，handle应该是指向当前目录的一个指针索引
    intptr_t handle;
    _finddata_t findData;
    //string mypath("D:/mydata/my.csv");
    //ofstream  myof(mypath, ios::app);

    //string field("时间,股票代码,股票名称,前收盘,开盘价,最高价,最低价,收盘价,交易量,交易金额");
    //myof << field << endl;

    handle = _findfirst(dirNew, &findData);
    if (handle == -1)        // 检查是否成功
        return;
    do
    {
        double Pprice = 0;//初始化昨收为0
        if (findData.attrib & _A_SUBDIR)
        {
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;

            cout << findData.name << "\t<dir>\n";

            // 在目录后面加上"\\"和搜索到的目录名进行下一次搜索
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
           string  outPath = "D:/commonDB/Market/" + fileStr.substr(0, fileStr.size()-3)+"---Market.csv";             ///全局变量
            string dbPath= "D:/common/" + fileStr;
            ofstream out(outPath, ios::app);   ///输出文件句柄
            ptr_out = &out;
            
           
            string field = "Id,ExchangeID,SecurityID,DataTimeStamp,IngressTimeStamp,IngressTimeUsec,ProcessTimeStamp,ProcessTimeUsec,PublishTimeUsec,AskPrice1,AskVolume1,BidPrice1,BidVolume1,AskPrice2,AskVolume2,BidPrice2,BidVolume2,AskPrice3,AskVolume3,BidPrice3,BidVolume3,AskPrice4,AskVolume4,BidPrice4,BidVolume4,AskPrice5,AskVolume5,BidPrice5,BidVolume5,AskPrice6,AskVolume6,BidPrice6,BidVolume6,AskPrice7,AskVolume7,BidPrice7,BidVolume7,AskPrice8,AskVolume8,BidPrice8,BidVolume8,AskPrice9,AskVolume9,BidPrice9,BidVolume9,AskPrice10,AskVolume10,BidPrice10,BidVolume10,UpperLimitPrice,LowerLimitPrice,OpenPrice,PreClosePrice,LastPrice,HighestPrice,LowestPrice,Volume,Turnover,TotalAskAmount,TotalBidAmount,TotalAskVolume,TotalBidVolume,FirstLevelBuyOrderVolumes,FirstLevelSellOrderVolumes,UpdateType,UpdatePrice,UpdateVolume,Source";
            out << field << endl;
            sqlite3* db = nullptr;
            int result = -1;
            result = sqlite3_open(dbPath.c_str(), &db);
            if (result != 0)
            {
                std::cout << "打开失败" << std::endl;
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

    _findclose(handle);    // 关闭搜索句柄
}








int LoadMyInfo(void* para, int n_column, char** column_value, char** column_name)

{

    //para是你在 sqlite3_exec 里传入的 void * 参数

    //通过para参数，你可以传入一些特殊的指针（比如类指针、结构指针），然后在这里面强制转换成对应的类型（这里面是void*类型，必须强制转换成你的类型才可用）。然后操作这些数据

    //n_column是这一条记录有多少个字段 (即这条记录有多少列)

    // char ** column_value 是个关键值，查出来的数据都保存在这里，它实际上是个1维数组（不要以为是2维数组），每一个元素都是一个 char * 值，是一个字段内容（用字符串来表示，以/0结尾）

    //char ** column_name 跟 column_value是对应的，表示这个字段的字段名称



     //这里，我不使用 para 参数。忽略它的存在.



    int i=0;

    //printf("记录包含 %d 个字段 /n", n_column);
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

      //  printf("字段名: %s  字段值: %s /n", column_name[i], column_value[i]);

    }
    (*ptr_out)<< str << endl;

    //printf("------------------ /n");

    return 0;

}

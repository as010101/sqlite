#pragma once
#include<memory>
#include "Lev2MdStruct.h"

using namespace std;


class dataFromSqlite
{


public:
	dataFromSqlite();








private:
	shared_ptr<vector<Lev2::RealtimeDepthMarketDataEx>> m_pData;   //指向一个vector，vecto里面装每一行行情数据
};
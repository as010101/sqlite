#pragma once
#include<memory>
#include "Lev2MdStruct.h"

using namespace std;


class dataFromSqlite
{


public:
	dataFromSqlite();








private:
	shared_ptr<vector<Lev2::RealtimeDepthMarketDataEx>> m_pData;   //ָ��һ��vector��vecto����װÿһ����������
};
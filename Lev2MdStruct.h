#ifndef __Lev2MdStruct_h__
#define __Lev2MdStruct_h__

#include <string>
#include <map>
#include <vector>


namespace Lev2
{
	using namespace std;
	const int Multiplier = 1000;

	struct OrderDetail
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		int OrderTime;
		double Price;
		long long int Volume;
		unsigned char Side;
		unsigned char OrderType;
		long long int MainSeq;
		long long int SubSeq;
		long long int ArriveTimeUsec;

		/**
		* Obtains a tuple containing all of the exception's data members.
		* @return The data members in a tuple.
		*/

		std::tuple<const unsigned char&, const ::std::string&, const int&, const double&, const long long int&, const unsigned char&, const unsigned char&, const long long int&, const long long int&, const long long int&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, OrderTime, Price, Volume, Side, OrderType, MainSeq, SubSeq, ArriveTimeUsec);
		}
	};

	struct Transaction
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		int TradeTime;
		double TradePrice;
		long long int TradeVolume;
		unsigned char ExecType;
		long long int MainSeq;
		long long int SubSeq;
		long long int BuyNo;
		long long int SellNo;
		long long int ArriveTimeUsec;

		/**
		* Obtains a tuple containing all of the exception's data members.
		* @return The data members in a tuple.
		*/

		std::tuple<const unsigned char&, const ::std::string&, const int&, const double&, const long long int&, const unsigned char&, const long long int&, const long long int&, const long long int&, const long long int&, const long long int&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, TradeTime, TradePrice, TradeVolume, ExecType, MainSeq, SubSeq, BuyNo, SellNo, ArriveTimeUsec);
		}
	};

	enum class TimeType : unsigned char
	{
		Arrive,
		EnterOrderMap,
		BeforePublish,
		AfterPublish
	};

	using Times = ::std::map<TimeType, long long int>;

	struct Order
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		double Price;
		long long int VolumeLeft;
		long long int Volume;
		long long int VolumeFill;
		long long int VolumeCancel;
		long long int MainSeq;
		long long int SubSeq;
		Times TimeSeq;
		/**
		* Obtains a tuple containing all of the exception's data members.
		* @return The data members in a tuple.
		*/

		std::tuple<const unsigned char&, const ::std::string&, const double&, const long long int&, const long long int&, const long long int&, const long long int&, const long long int&, const long long int&, const Times&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, Price, VolumeLeft, Volume, VolumeFill, VolumeCancel, MainSeq, SubSeq, TimeSeq);
		}

	};

	struct RealtimeDepthMarketData
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		double AskPrice1;
		long long int AskVolume1;
		double BidPrice1;
		long long int BidVolume1;
		double LastPrice;
		double HighestPrice;
		double LowestPrice;
		long long int Volume;
		double Turnover;
		double TotalAskAmount;
		double TotalBidAmount;
		long long int TotalAskVolume;
		long long int TotalBidVolume;
		long long int AskCount1;
		long long int BidCount1;
		double AskPrice2;
		long long int AskVolume2;
		long long int AskCount2;
		double AskPrice3;
		long long int AskVolume3;
		long long int AskCount3;
		double AskPrice4;
		long long int AskVolume4;
		long long int AskCount4;
		double AskPrice5;
		long long int AskVolume5;
		long long int AskCount5;
		double AskPrice6;
		long long int AskVolume6;
		long long int AskCount6;
		double AskPrice7;
		long long int AskVolume7;
		long long int AskCount7;
		double AskPrice8;
		long long int AskVolume8;
		long long int AskCount8;
		double AskPrice9;
		long long int AskVolume9;
		long long int AskCount9;
		double AskPrice10;
		long long int AskVolume10;
		long long int AskCount10;
		double BidPrice2;
		long long int BidVolume2;
		long long int BidCount2;
		double BidPrice3;
		long long int BidVolume3;
		long long int BidCount3;
		double BidPrice4;
		long long int BidVolume4;
		long long int BidCount4;
		double BidPrice5;
		long long int BidVolume5;
		long long int BidCount5;
		double BidPrice6;
		long long int BidVolume6;
		long long int BidCount6;
		double BidPrice7;
		long long int BidVolume7;
		long long int BidCount7;
		double BidPrice8;
		long long int BidVolume8;
		long long int BidCount8;
		double BidPrice9;
		long long int BidVolume9;
		long long int BidCount9;
		double BidPrice10;
		long long int BidVolume10;
		long long int BidCount10;
		int DataTimeStamp;

		/**
		 * Obtains a tuple containing all of the exception's data members.
		 * @return The data members in a tuple.
		 */

		std::tuple<const unsigned char&, const ::std::string&, const double&, const long long int&, const double&, const long long int&, const double&, const double&, const double&, const long long int&, const double&, const double&, const double&, const long long int&, const long long int&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const int&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, AskPrice1, AskVolume1, BidPrice1, BidVolume1, LastPrice, HighestPrice, LowestPrice, Volume, Turnover, TotalAskAmount, TotalBidAmount, TotalAskVolume, TotalBidVolume, AskCount1, BidCount1, AskPrice2, AskVolume2, AskCount2, AskPrice3, AskVolume3, AskCount3, AskPrice4, AskVolume4, AskCount4, AskPrice5, AskVolume5, AskCount5, AskPrice6, AskVolume6, AskCount6, AskPrice7, AskVolume7, AskCount7, AskPrice8, AskVolume8, AskCount8, AskPrice9, AskVolume9, AskCount9, AskPrice10, AskVolume10, AskCount10, BidPrice2, BidVolume2, BidCount2, BidPrice3, BidVolume3, BidCount3, BidPrice4, BidVolume4, BidCount4, BidPrice5, BidVolume5, BidCount5, BidPrice6, BidVolume6, BidCount6, BidPrice7, BidVolume7, BidCount7, BidPrice8, BidVolume8, BidCount8, BidPrice9, BidVolume9, BidCount9, BidPrice10, BidVolume10, BidCount10, DataTimeStamp);
		}
	};

	using OrderVolumes = ::std::vector<int>;
	enum class TriggerType : unsigned char
	{
		Buy,
		Sell,
		Cancel
	};

	enum class SourceType : unsigned char
	{
		Snap,
		Realtime,
		Replay
	};

	enum class UpdateTypeEnum : unsigned char
	{
		OrderBuy,
		OrderSell,
		Traded,
		Canceled
	};

	struct RealtimeDepthMarketDataEx
	{
		int Id = 0;
		unsigned char ExchangeID = 0;
		::std::string SecurityID;
		double AskPrice1 = 0;
		long long int AskVolume1 = 0LL;
		double BidPrice1 = 0;
		long long int BidVolume1 = 0LL;
		double UpperLimitPrice = 0;
		double LowerLimitPrice = 0;
		double PreClosePrice = 0;
		double OpenPrice = 0;
		double LastPrice = 0;
		double HighestPrice = 0;
		double LowestPrice = 0;
		long long int Volume = 0LL;
		double Turnover = 0;
		double TotalAskAmount = 0;
		double TotalBidAmount = 0;
		long long int TotalAskVolume = 0LL;
		long long int TotalBidVolume = 0LL;
		long long int AskCount1 = 0LL;
		long long int BidCount1 = 0LL;
		double AskPrice2 = 0;
		long long int AskVolume2 = 0LL;
		long long int AskCount2 = 0LL;
		double AskPrice3 = 0;
		long long int AskVolume3 = 0LL;
		long long int AskCount3 = 0LL;
		double AskPrice4 = 0;
		long long int AskVolume4 = 0LL;
		long long int AskCount4 = 0LL;
		double AskPrice5 = 0;
		long long int AskVolume5 = 0LL;
		long long int AskCount5 = 0LL;
		double AskPrice6 = 0;
		long long int AskVolume6 = 0LL;
		long long int AskCount6 = 0LL;
		double AskPrice7 = 0;
		long long int AskVolume7 = 0LL;
		long long int AskCount7 = 0LL;
		double AskPrice8 = 0;
		long long int AskVolume8 = 0LL;
		long long int AskCount8 = 0LL;
		double AskPrice9 = 0;
		long long int AskVolume9 = 0LL;
		long long int AskCount9 = 0LL;
		double AskPrice10 = 0;
		long long int AskVolume10 = 0LL;
		long long int AskCount10 = 0LL;
		double BidPrice2 = 0;
		long long int BidVolume2 = 0LL;
		long long int BidCount2 = 0LL;
		double BidPrice3 = 0;
		long long int BidVolume3 = 0LL;
		long long int BidCount3 = 0LL;
		double BidPrice4 = 0;
		long long int BidVolume4 = 0LL;
		long long int BidCount4 = 0LL;
		double BidPrice5 = 0;
		long long int BidVolume5 = 0LL;
		long long int BidCount5 = 0LL;
		double BidPrice6 = 0;
		long long int BidVolume6 = 0LL;
		long long int BidCount6 = 0LL;
		double BidPrice7 = 0;
		long long int BidVolume7 = 0LL;
		long long int BidCount7 = 0LL;
		double BidPrice8 = 0;
		long long int BidVolume8 = 0LL;
		long long int BidCount8 = 0LL;
		double BidPrice9 = 0;
		long long int BidVolume9 = 0LL;
		long long int BidCount9 = 0LL;
		double BidPrice10 = 0;
		long long int BidVolume10 = 0LL;
		long long int BidCount10 = 0LL;
		int DataTimeStamp = 0;
		int IngressTimeStamp = 0;
		long long int IngressTimeUsec = 0LL;
		int ProcessTimeStamp = 0;
		long long int ProcessTimeUsec = 0LL;
		int PublishTimeStamp = 0;
		long long int PublishTimeUsec = 0LL;
		TriggerType Trigger = ::Lev2::TriggerType::Buy;
		::std::string TriggerName;
		long long int MaxBidVolume1 = 0LL;
		long long int MaxAskVolume1 = 0LL;
		SourceType Source = ::Lev2::SourceType::Snap;
		OrderVolumes FirstLevelBuyOrderVolumes;
		OrderVolumes FirstLevelSellOrderVolumes;
		UpdateTypeEnum UpdateType = ::Lev2::UpdateTypeEnum::OrderBuy;
		double UpdatePrice = 0;
		long long int UpdateVolume = 0LL;

		/**
		 * Obtains a tuple containing all of the exception's data members.
		 * @return The data members in a tuple.
		 */

		std::tuple<const int&, const unsigned char&, const ::std::string&, const double&, const long long int&, const double&, const long long int&, const double&, const double&, const double&, const double&, const double&, const double&, const double&, const long long int&, const double&, const double&, const double&, const long long int&, const long long int&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const double&, const long long int&, const long long int&, const int&, const int&, const long long int&, const int&, const long long int&, const int&, const long long int&, const TriggerType&, const ::std::string&, const long long int&, const long long int&, const SourceType&, const OrderVolumes&, const OrderVolumes&, const UpdateTypeEnum&, const double&, const long long int&> ice_tuple() const
		{
			return std::tie(Id, ExchangeID, SecurityID, AskPrice1, AskVolume1, BidPrice1, BidVolume1, UpperLimitPrice, LowerLimitPrice, PreClosePrice, OpenPrice, LastPrice, HighestPrice, LowestPrice, Volume, Turnover, TotalAskAmount, TotalBidAmount, TotalAskVolume, TotalBidVolume, AskCount1, BidCount1, AskPrice2, AskVolume2, AskCount2, AskPrice3, AskVolume3, AskCount3, AskPrice4, AskVolume4, AskCount4, AskPrice5, AskVolume5, AskCount5, AskPrice6, AskVolume6, AskCount6, AskPrice7, AskVolume7, AskCount7, AskPrice8, AskVolume8, AskCount8, AskPrice9, AskVolume9, AskCount9, AskPrice10, AskVolume10, AskCount10, BidPrice2, BidVolume2, BidCount2, BidPrice3, BidVolume3, BidCount3, BidPrice4, BidVolume4, BidCount4, BidPrice5, BidVolume5, BidCount5, BidPrice6, BidVolume6, BidCount6, BidPrice7, BidVolume7, BidCount7, BidPrice8, BidVolume8, BidCount8, BidPrice9, BidVolume9, BidCount9, BidPrice10, BidVolume10, BidCount10, DataTimeStamp, IngressTimeStamp, IngressTimeUsec, ProcessTimeStamp, ProcessTimeUsec, PublishTimeStamp, PublishTimeUsec, Trigger, TriggerName, MaxBidVolume1, MaxAskVolume1, Source, FirstLevelBuyOrderVolumes, FirstLevelSellOrderVolumes, UpdateType, UpdatePrice, UpdateVolume);
		}
	};

	struct DepthMarketDataSnap
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		int DataTimeStamp;
		double PreClosePrice;
		double OpenPrice;
		long long int NumTrades;
		long long int TotalVolumeTrade;
		double TotalValueTrade;
		long long int TotalBidVolume;
		double AvgBidPrice;
		long long int TotalAskVolume;
		double AvgAskPrice;
		double HighestPrice;
		double LowestPrice;
		double LastPrice;
		double BidPrice1;
		long long int BidVolume1;
		double AskPrice1;
		long long int AskVolume1;
		double AskPrice2;
		long long int AskVolume2;
		double AskPrice3;
		long long int AskVolume3;
		double BidPrice2;
		long long int BidVolume2;
		double BidPrice3;
		long long int BidVolume3;
		double AskPrice4;
		long long int AskVolume4;
		double AskPrice5;
		long long int AskVolume5;
		double BidPrice4;
		long long int BidVolume4;
		double BidPrice5;
		long long int BidVolume5;
		double AskPrice6;
		long long int AskVolume6;
		double AskPrice7;
		long long int AskVolume7;
		double BidPrice6;
		long long int BidVolume6;
		double BidPrice7;
		long long int BidVolume7;
		double AskPrice8;
		long long int AskVolume8;
		double AskPrice9;
		long long int AskVolume9;
		double BidPrice8;
		long long int BidVolume8;
		double BidPrice9;
		long long int BidVolume9;
		double BidPrice10;
		long long int BidVolume10;
		double AskPrice10;
		long long int AskVolume10;
		int Info1;
		int Info2;
		int Info3;
		double UpperLimitPrice;
		double LowerLimitPrice;
		double ClosePrice;
		unsigned char MDSecurityStat;
		int FirstLevelBuyNum;
		OrderVolumes FirstLevelBuyOrderVolumes;
		int FirstLevelSellNum;
		OrderVolumes FirstLevelSellOrderVolumes;

		/**
		 * Obtains a tuple containing all of the exception's data members.
		 * @return The data members in a tuple.
		 */

		std::tuple<const unsigned char&, const ::std::string&, const int&, const double&, const double&, const long long int&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const double&, const double&, const double&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const double&, const long long int&, const int&, const int&, const int&, const double&, const double&, const double&, const unsigned char&, const int&, const OrderVolumes&, const int&, const OrderVolumes&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, DataTimeStamp, PreClosePrice, OpenPrice, NumTrades, TotalVolumeTrade, TotalValueTrade, TotalBidVolume, AvgBidPrice, TotalAskVolume, AvgAskPrice, HighestPrice, LowestPrice, LastPrice, BidPrice1, BidVolume1, AskPrice1, AskVolume1, AskPrice2, AskVolume2, AskPrice3, AskVolume3, BidPrice2, BidVolume2, BidPrice3, BidVolume3, AskPrice4, AskVolume4, AskPrice5, AskVolume5, BidPrice4, BidVolume4, BidPrice5, BidVolume5, AskPrice6, AskVolume6, AskPrice7, AskVolume7, BidPrice6, BidVolume6, BidPrice7, BidVolume7, AskPrice8, AskVolume8, AskPrice9, AskVolume9, BidPrice8, BidVolume8, BidPrice9, BidVolume9, BidPrice10, BidVolume10, AskPrice10, AskVolume10, Info1, Info2, Info3, UpperLimitPrice, LowerLimitPrice, ClosePrice, MDSecurityStat, FirstLevelBuyNum, FirstLevelBuyOrderVolumes, FirstLevelSellNum, FirstLevelSellOrderVolumes);
		}
	};

	using RealtimeDepthMarketDataExSeq = ::std::vector<RealtimeDepthMarketDataEx>;

	using OrderDetailSeq = ::std::vector<OrderDetail>;

	using TransactionSeq = ::std::vector<Transaction>;

	using Orders = ::std::vector<Order>;

	using OrderMap = ::std::map<::std::string, Order>;

	struct EachLevelOrder
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		unsigned char Side;
		double Price;
		long long int Volume;
		long long int Count;
		Orders OrderList;

		/**
		 * Obtains a tuple containing all of the exception's data members.
		 * @return The data members in a tuple.
		 */

		std::tuple<const unsigned char&, const ::std::string&, const unsigned char&, const double&, const long long int&, const long long int&, const Orders&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, Side, Price, Volume, Count, OrderList);
		}
	};

	struct FirstLevelSnap
	{
		unsigned char ExchangeID;
		::std::string SecurityID;
		unsigned char Side;
		double Price;
		long long int Volume;
		long long int Count;
		OrderDetailSeq OrderDetailList;

		/**
		 * Obtains a tuple containing all of the exception's data members.
		 * @return The data members in a tuple.
		 */

		std::tuple<const unsigned char&, const ::std::string&, const unsigned char&, const double&, const long long int&, const long long int&, const OrderDetailSeq&> ice_tuple() const
		{
			return std::tie(ExchangeID, SecurityID, Side, Price, Volume, Count, OrderDetailList);
		}
	};

	enum class SubscribeType : unsigned char
	{
		SubOrder,
		SubFirstLevelSnap,
		SubFastTenLevOrder,
		SubRealtimeDepthMarketData,
		SubSnapDepthMarketData,
		SubTransaction
	};

	using MultiLevelOrderBuy = ::std::map<int, EachLevelOrder>;

	using MultiLevelOrderSell = ::std::map<int, EachLevelOrder>;

}
#endif
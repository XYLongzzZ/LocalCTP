#pragma once
// coding by GB2312
#include "ThostFtdcUserApiDataType.h"
#include "stdafx.h"

namespace localCTP{

constexpr TThostFtdcErrorMsgType ErrMsgUserInfoIsEmpty = "CTP:��֤ʧ��(UserID��BrokerID����Ϊ��Ŷ)";
constexpr TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsLastTime = "CTP:��֤ʧ��(UserID��BrokerID��Ҫ���ϴε�¼ʱ��ͬŶ)";
constexpr TThostFtdcErrorMsgType ErrMsgNotAuth = "CTP:��¼ʧ��(û����֤)";
constexpr TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsAuth = "CTP:��¼ʧ��(UserID��BrokerID��Ҫ����֤ʱ��ͬŶ)";
constexpr TThostFtdcErrorMsgType ErrMsgDuplicateOrder = "CTP:�ظ��ı���(OrderRef��ȴ�ǰ�����ֵҪ��Ŷ)";
constexpr TThostFtdcErrorMsgType ErrMsg_INVALID_ORDERSIZE = "CTP:���Ϸ��ı�������(��Ϊ����)";
constexpr TThostFtdcErrorMsgType ErrMsg_EXCHANGE_ID_IS_WRONG = "CTP:�������������";
constexpr TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_NOT_FOUND = "CTP:�Ҳ�����Լ";
constexpr TThostFtdcErrorMsgType ErrMsg_BAD_PRICE_VALUE = "CTP:��֧�ֵļ۸�(��Ҫ��PriceTick��������):";
constexpr TThostFtdcErrorMsgType ErrMsg_NotExistOrder = "CTP:����������Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_AlreadyDoneOrder = "CTP:�����ѽ����޷��ٳ�Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportModifyOrder = "CTP:����ֻ�ܳ����޷��ĵ�Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_PRICETYPE_NOTSUPPORT_BYEXCHANGE = "CTP:��������֧�ֵļ۸�����(OrderPriceType)";
constexpr TThostFtdcErrorMsgType ErrMsg_BAD_FIELD_ONLY_SPECULATION = "CTP:�����ֶ�����(��ϵͳֻ֧��Ͷ������)(CombHedgeFlag)";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportContingentCondition = "CTP:��֧�������������Ŷ(ContingentCondition)";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportTimeCondition = "CTP:��֧�ֵ���Ч������Ŷ(TimeCondition)";
constexpr TThostFtdcErrorMsgType ErrMsg_NoMarketData = "CTP:�ú�Լû����������:";
constexpr TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_MARGINRATE_NOT_FOUND = "CTP:�ú�Լû�б�֤��������";
constexpr TThostFtdcErrorMsgType ERRMSG_INSTRUMENT_COMMISSIONRATE_NOT_FOUND = "CTP:�ú�Լû��������������:";// not used
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_NOT_ENOUGH = "CTP:�����ʽ���";
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������:";
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_TODAY_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������:";
constexpr char CONDITIONAL_ORDER_SYSID_PREFIX[10] = "TJBD_";

// ͨ��������������,�ж��Ƿ���(���ϱ�ϵͳ�����)������
inline bool isConditionalType(TThostFtdcContingentConditionType	contingentCondition)
{
    return contingentCondition == THOST_FTDC_CC_LastPriceGreaterThanStopPrice ||
        contingentCondition == THOST_FTDC_CC_LastPriceGreaterEqualStopPrice ||
        contingentCondition == THOST_FTDC_CC_LastPriceLesserThanStopPrice ||
        contingentCondition == THOST_FTDC_CC_LastPriceLesserEqualStopPrice;
}

inline std::string getStatusMsgByStatus(TThostFtdcOrderStatusType status)
{
    switch (status)
    {
        case THOST_FTDC_OST_AllTraded: // '0'
            return "ȫ���ɽ�";                
        case THOST_FTDC_OST_PartTradedQueueing: // '1'
            return "���ֳɽ�";
        case THOST_FTDC_OST_PartTradedNotQueueing: // '2'
            return "���ֳɽ����ڶ�����";
        case THOST_FTDC_OST_NoTradeQueueing: // '3'
            return "δ�ɽ�";
        case THOST_FTDC_OST_NoTradeNotQueueing: // '4'
            return "δ�ɽ����ڶ�����";
        case THOST_FTDC_OST_Canceled: // '5'
            return "�ѳ���";
        case THOST_FTDC_OST_Unknown: // 'a'
            return "δ֪";
        case THOST_FTDC_OST_NotTouched: // 'b'
            return "��δ����";
        case THOST_FTDC_OST_Touched: // 'c'
            return "�Ѵ���";
        default:
            return "δ֪";
    }
}

inline bool isTradingDay(const CLeeDateTime& date = CLeeDateTime::GetCurrentTime())
{
    const int dayOfWeek = date.GetDayOfWeek();
    if (dayOfWeek == 6 || dayOfWeek == 0)//TODO:�����жϳ��ټ���
    {
        return false;
    }
    return true;
}

inline std::string get_direction_name(const std::string& direction)
{
    static const std::map<std::string, std::string> direction_name_map{
        {std::string(1, THOST_FTDC_D_Buy), "��   "},
        {std::string(1, THOST_FTDC_D_Sell), "   ��"}
    };
    auto it_direction = direction_name_map.find(direction);
    if (it_direction != direction_name_map.end())
    {
        return it_direction->second;
    }
    else
    {
        return "δ֪";
    }
}
inline std::string get_direction_name(TThostFtdcDirectionType dir)
{
    return get_direction_name(std::string(1, dir));
}
inline std::string get_exchange_name(const std::string& ExchangeID)
{
    static const std::map<std::string, std::string> exchange_name_map{
        {"INE", "��Դ����"},
        {"SHFE", "������"},
        {"CFFEX", "�н���"},
        {"DCE", "������"},
        {"CZCE", "֣����"},
        {"GFEX", "������"},
        {"BSE", "������"},
        {"SSE", "�Ͻ���"},
        {"SHSE", "�Ͻ���"},
        {"SZSE", "���"}
    };
    auto it_exchange = exchange_name_map.find(ExchangeID);
    if (it_exchange != exchange_name_map.end())
    {
        return it_exchange->second;
    }
    else
    {
        return "δ֪";
    }
}
inline std::string get_open_close_name(const std::string& open_or_close)
{
    static const std::map<std::string, std::string> open_or_close_name_map{
        {std::string(1, THOST_FTDC_OF_Open), "��"},
        {std::string(1, THOST_FTDC_OF_Close), "  ƽ"},
        {std::string(1, THOST_FTDC_OF_CloseToday), "ƽ��"},
        {std::string(1, THOST_FTDC_OF_CloseYesterday), "ƽ��"},
        {std::string(1, THOST_FTDC_OF_ForceClose), "ǿƽ"},
        {std::string(1, THOST_FTDC_OF_ForceOff), "ǿ��"},
        {std::string(1, THOST_FTDC_OF_LocalForceClose), "����ǿƽ"}
    };
    auto it_open_or_close = open_or_close_name_map.find(open_or_close);
    if (it_open_or_close != open_or_close_name_map.end())
    {
        return it_open_or_close->second;
    }
    else
    {
        return "δ֪";
    }
}
inline std::string get_open_close_name(TThostFtdcOffsetFlagType open_or_close)
{
    return get_open_close_name(std::string(1, open_or_close));
}

///ƽ����ϸ
struct CloseDetail
{
    ///���͹�˾����
    TThostFtdcBrokerIDType BrokerID;
    ///Ͷ���ߴ���
    TThostFtdcInvestorIDType InvestorID;
    ///����������
    TThostFtdcExchangeIDType ExchangeID;
    ///��Լ����
    TThostFtdcInstrumentIDType InstrumentID;
    ///��������(������)
    TThostFtdcDateType OpenDate;
    ///���ּ۸�
    TThostFtdcPriceType OpenPrice;
    ///���ֳɽ����
    TThostFtdcTradeIDType OpenTradeID;
    ///ƽ������(������)
    TThostFtdcDateType CloseDate;
    ///ƽ��ʱ��
    TThostFtdcTimeType CloseTime;
    ///ƽ�ֳɽ��۸�
    TThostFtdcPriceType ClosePrice;
    ///ƽ�ֳɽ����
    TThostFtdcTradeIDType CloseTradeID;
    ///ƽ��ӯ��
    TThostFtdcMoneyType CloseProfit;
    ///ʵ��ƽ������(ƽ��orƽ��)
    TThostFtdcOffsetFlagType CloseFlag;
};

///���㵥
struct SettlementData
{
    ///���͹�˾����
    TThostFtdcBrokerIDType BrokerID;
    ///Ͷ���ߴ���
    TThostFtdcInvestorIDType InvestorID;
    ///���㵥����
    std::string SettlementContent;
    ///���㵥����(������)
    TThostFtdcDateType TradingDay;
    ///ȷ������(������)
    TThostFtdcDateType ConfirmDay;
    ///ȷ��ʱ��
    TThostFtdcTimeType ConfirmTime;
};

} // end namespace localCTP

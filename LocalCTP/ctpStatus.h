#pragma once
// coding by GB2312
#include "ThostFtdcUserApiDataType.h"
#include <string>

constexpr TThostFtdcErrorMsgType ErrMsgUserInfoIsEmpty = "CTP:��֤ʧ��(UserID��BrokerID����Ϊ��Ŷ)";
constexpr TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsLastTime = "CTP:��֤ʧ��(UserID��BrokerID��Ҫ���ϴε�¼ʱ��ͬŶ)";
constexpr TThostFtdcErrorMsgType ErrMsgNotAuth = "CTP:��¼ʧ��(û����֤)";
constexpr TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsAuth = "CTP:��¼ʧ��(UserID��BrokerID��Ҫ����֤ʱ��ͬŶ)";
constexpr TThostFtdcErrorMsgType ErrMsgDuplicateOrder = "CTP:�ظ��ı���(OrderRef��ȴ�ǰ�����ֵҪ��Ŷ)";
constexpr TThostFtdcErrorMsgType ErrMsg_INVALID_ORDERSIZE = "CTP:���Ϸ��ı�������(��Ϊ����)";
constexpr TThostFtdcErrorMsgType ErrMsg_EXCHANGE_ID_IS_WRONG = "CTP:�������������";
constexpr TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_NOT_FOUND = "CTP:�Ҳ�����Լ";
constexpr TThostFtdcErrorMsgType ErrMsg_BAD_PRICE_VALUE = "CTP:��֧�ֵļ۸�(��Ҫ��PriceTick��������)";
constexpr TThostFtdcErrorMsgType ErrMsg_NotExistOrder = "CTP:����������Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_AlreadyDoneOrder = "CTP:�����ѽ����޷��ٳ�Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportModifyOrder = "CTP:����ֻ�ܳ����޷��ĵ�Ŷ";
constexpr TThostFtdcErrorMsgType ErrMsg_PRICETYPE_NOTSUPPORT_BYEXCHANGE = "CTP:��������֧�ֵļ۸�����";
constexpr TThostFtdcErrorMsgType ErrMsg_BAD_FIELD_ONLY_SPECULATION = "CTP:�����ֶ�����(��ϵͳֻ֧��Ͷ������)";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportContingentCondition = "CTP:��֧�������������Ŷ(ContingentCondition)";
constexpr TThostFtdcErrorMsgType ErrMsg_NotSupportTimeCondition = "CTP:��֧�ֵ���Ч������Ŷ(TimeCondition)";
constexpr TThostFtdcErrorMsgType ErrMsg_NoMarketData = "CTP:�ú�Լû����������";
constexpr TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_MARGINRATE_NOT_FOUND = "CTP:�ú�Լû�б�֤��������";
constexpr TThostFtdcErrorMsgType ERRMSG_INSTRUMENT_COMMISSIONRATE_NOT_FOUND = "CTP:�ú�Լû��������������";
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_NOT_ENOUGH = "CTP:�����ʽ���";
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������";
constexpr TThostFtdcErrorMsgType ERRMSG_AVAILABLE_TODAY_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������";
constexpr char CONDITIONAL_ORDER_SYSID_PREFIX[10] = "TJBD_";

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
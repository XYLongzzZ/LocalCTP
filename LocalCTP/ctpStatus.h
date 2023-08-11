#pragma once
// coding by GB2312
#include "ThostFtdcUserApiDataType.h"
#include <string>

const TThostFtdcErrorMsgType ErrMsgUserInfoIsEmpty = "CTP:��֤ʧ��(UserID��BrokerID����Ϊ��Ŷ)";
const TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsLastTime = "CTP:��֤ʧ��(UserID��BrokerID��Ҫ���ϴε�¼ʱ��ͬŶ)";
const TThostFtdcErrorMsgType ErrMsgNotAuth = "CTP:��¼ʧ��(û����֤)";
const TThostFtdcErrorMsgType ErrMsgUserInfoNotSameAsAuth = "CTP:��¼ʧ��(UserID��BrokerID��Ҫ����֤ʱ��ͬŶ)";
const TThostFtdcErrorMsgType ErrMsgDuplicateOrder = "CTP:�ظ��ı���(OrderRef��ȴ�ǰ�����ֵҪ��Ŷ)";
const TThostFtdcErrorMsgType ErrMsg_INVALID_ORDERSIZE = "CTP:���Ϸ��ı�������(��Ϊ����)";
const TThostFtdcErrorMsgType ErrMsg_EXCHANGE_ID_IS_WRONG = "CTP:�������������";
const TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_NOT_FOUND = "CTP:�Ҳ�����Լ";
const TThostFtdcErrorMsgType ErrMsg_BAD_PRICE_VALUE = "CTP:��֧�ֵļ۸�(��Ҫ��PriceTick��������)";
const TThostFtdcErrorMsgType ErrMsg_NotExistOrder = "CTP:����������Ŷ";
const TThostFtdcErrorMsgType ErrMsg_AlreadyDoneOrder = "CTP:�����ѽ����޷��ٳ�Ŷ";
const TThostFtdcErrorMsgType ErrMsg_NotSupportModifyOrder = "CTP:����ֻ�ܳ����޷��ĵ�Ŷ";
const TThostFtdcErrorMsgType ErrMsg_PRICETYPE_NOTSUPPORT_BYEXCHANGE = "CTP:��������֧�ֵļ۸�����";
const TThostFtdcErrorMsgType ErrMsg_BAD_FIELD_ONLY_SPECULATION = "CTP:�����ֶ�����(��ϵͳֻ֧��Ͷ������)";
const TThostFtdcErrorMsgType ErrMsg_NotSupportContingentCondition = "CTP:��֧��������Ŷ(ContingentCondition)";
const TThostFtdcErrorMsgType ErrMsg_NotSupportTimeCondition = "CTP:��֧�ֵ���Ч������Ŷ(TimeCondition)";
const TThostFtdcErrorMsgType ErrMsg_NoMarketData = "CTP:�ú�Լû����������";
const TThostFtdcErrorMsgType ErrMsg_INSTRUMENT_MARGINRATE_NOT_FOUND = "CTP:�ú�Լû�б�֤��������";
const TThostFtdcErrorMsgType ERRMSG_INSTRUMENT_COMMISSIONRATE_NOT_FOUND = "CTP:�ú�Լû��������������";
const TThostFtdcErrorMsgType ERRMSG_AVAILABLE_NOT_ENOUGH = "CTP:�����ʽ���";
const TThostFtdcErrorMsgType ERRMSG_AVAILABLE_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������";
const TThostFtdcErrorMsgType ERRMSG_AVAILABLE_TODAY_POSITION_NOT_ENOUGH = "CTP:ƽ��ʱ�ֲֲ���,��ǰ��ƽ������";

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
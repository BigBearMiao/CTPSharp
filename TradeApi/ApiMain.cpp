
#include "stdafx.h"
#include "TradeApi.h"
#include "..\api\x86\ThostFtdcUserApiDataType.h"
#include "..\api\x86\ThostFtdcUserApiStruct.h"

// UserApi����
CThostFtdcTraderApi* pUserApi;

//�ص�����
CBOnFrontConnected cbOnFrontConnected = 0;		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
CBOnFrontDisconnected cbOnFrontDisconnected = 0;		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
CBOnHeartBeatWarning cbOnHeartBeatWarning = 0;		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
CBRspUserLogin cbRspUserLogin = 0;	///��¼������Ӧ
CBRspUserLogout cbRspUserLogout = 0;	///�ǳ�������Ӧ
CBRspUserPasswordUpdate cbRspUserPasswordUpdate = 0;	///�û��������������Ӧ
CBRspTradingAccountPasswordUpdate cbRspTradingAccountPasswordUpdate = 0;	///�ʽ��˻��������������Ӧ
CBRspOrderInsert cbRspOrderInsert = 0;	///����¼��������Ӧ
CBRspParkedOrderInsert cbRspParkedOrderInsert = 0;	///Ԥ��¼��������Ӧ
CBRspParkedOrderAction cbRspParkedOrderAction = 0;	///Ԥ�񳷵�¼��������Ӧ
CBRspOrderAction cbRspOrderAction = 0;	///��������������Ӧ
CBRspQueryMaxOrderVolume cbRspQueryMaxOrderVolume = 0;	///��ѯ��󱨵�������Ӧ
CBRspSettlementInfoConfirm cbRspSettlementInfoConfirm = 0;	///Ͷ���߽�����ȷ����Ӧ
CBRspRemoveParkedOrder cbRspRemoveParkedOrder = 0;	///ɾ��Ԥ����Ӧ
CBRspRemoveParkedOrderAction cbRspRemoveParkedOrderAction = 0;	///ɾ��Ԥ�񳷵���Ӧ
CBRspExecOrderInsert cbRspExecOrderInsert = 0;	///ִ������¼��������Ӧ
CBRspExecOrderAction cbRspExecOrderAction = 0;	///ִ���������������Ӧ
CBRspForQuoteInsert cbRspForQuoteInsert = 0;	///ѯ��¼��������Ӧ
CBRspQuoteInsert cbRspQuoteInsert = 0;	///����¼��������Ӧ
CBRspQuoteAction cbRspQuoteAction = 0;	///���۲���������Ӧ
CBRspBatchOrderAction cbRspBatchOrderAction = 0;	///������������������Ӧ
CBRspOptionSelfCloseInsert cbRspOptionSelfCloseInsert = 0;	///��Ȩ�ԶԳ�¼��������Ӧ
CBRspOptionSelfCloseAction cbRspOptionSelfCloseAction = 0; ///��Ȩ�ԶԳ����������Ӧ
CBRspCombActionInsert cbRspCombActionInsert = 0;	///�������¼��������Ӧ
CBRspQryOrder cbRspQryOrder = 0;	///�����ѯ������Ӧ
CBRspQryTrade cbRspQryTrade = 0;	///�����ѯ�ɽ���Ӧ
CBRspQryInvestorPosition cbRspQryInvestorPosition = 0;	///�����ѯͶ���ֲ߳���Ӧ
CBRspQryTradingAccount cbRspQryTradingAccount = 0;	///�����ѯ�ʽ��˻���Ӧ
CBRspQryInvestor cbRspQryInvestor = 0;	///�����ѯͶ������Ӧ
CBRspQryTradingCode cbRspQryTradingCode = 0;	///�����ѯ���ױ�����Ӧ
CBRspQryInstrumentMarginRate cbRspQryInstrumentMarginRate = 0;	///�����ѯ��Լ��֤������Ӧ
CBRspQryInstrumentCommissionRate cbRspQryInstrumentCommissionRate = 0;	///�����ѯ��Լ����������Ӧ
CBRspQryExchange cbRspQryExchange = 0;	///�����ѯ��������Ӧ
CBRspQryInstrument cbRspQryInstrument = 0;	///�����ѯ��Լ��Ӧ
CBRspQryDepthMarketData cbRspQryDepthMarketData = 0;	///�����ѯ������Ӧ
CBRspQrySettlementInfo cbRspQrySettlementInfo = 0;	///�����ѯͶ���߽�������Ӧ
CBRspQryTransferBank cbRspQryTransferBank = 0;	///�����ѯת��������Ӧ
CBRspQryInvestorPositionDetail cbRspQryInvestorPositionDetail = 0;	///�����ѯͶ���ֲ߳���ϸ��Ӧ
CBRspQryNotice cbRspQryNotice = 0;	///�����ѯ�ͻ�֪ͨ��Ӧ
CBRspQrySettlementInfoConfirm cbRspQrySettlementInfoConfirm = 0;	///�����ѯ������Ϣȷ����Ӧ
CBRspQryInvestorPositionCombineDetail cbRspQryInvestorPositionCombineDetail = 0;	///�����ѯͶ���ֲ߳���ϸ��Ӧ
CBRspQryCFMMCTradingAccountKey cbRspQryCFMMCTradingAccountKey = 0;	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
CBRspQryEWarrantOffset cbRspQryEWarrantOffset = 0;	///�����ѯ�ֵ��۵���Ϣ��Ӧ
CBRspQryInvestorProductGroupMargin cbRspQryInvestorProductGroupMargin = 0;	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
CBRspQryExchangeMarginRate cbRspQryExchangeMarginRate = 0;	///�����ѯ��������֤������Ӧ
CBRspQryExchangeMarginRateAdjust cbRspQryExchangeMarginRateAdjust = 0;	///�����ѯ������������֤������Ӧ
CBRspQryExchangeRate cbRspQryExchangeRate = 0;	///�����ѯ������Ӧ
CBRspQrySecAgentACIDMap cbRspQrySecAgentACIDMap = 0;	///�����ѯ�����������Ա����Ȩ����Ӧ
CBRspQryProductExchRate cbRspQryProductExchRate = 0;	///�����ѯ��Ʒ���ۻ���
CBRspQryProductGroup cbRspQryProductGroup = 0;	///�����ѯ��Ʒ��
CBRspQryMMInstrumentCommissionRate cbRspQryMMInstrumentCommissionRate = 0;	///�����ѯ�����̺�Լ����������Ӧ
CBRspQryMMOptionInstrCommRate cbRspQryMMOptionInstrCommRate = 0;	///�����ѯ��������Ȩ��Լ��������Ӧ
CBRspQryInstrumentOrderCommRate cbRspQryInstrumentOrderCommRate = 0;	///�����ѯ������������Ӧ
CBRspQrySecAgentTradingAccount cbRspQrySecAgentTradingAccount = 0;	///�����ѯ�ʽ��˻���Ӧ
CBRspQrySecAgentCheckMode cbRspQrySecAgentCheckMode = 0;	///�����ѯ�����������ʽ�У��ģʽ��Ӧ
CBRspQryOptionInstrTradeCost cbRspQryOptionInstrTradeCost = 0;	///�����ѯ��Ȩ���׳ɱ���Ӧ
CBRspQryOptionInstrCommRate cbRspQryOptionInstrCommRate = 0;	///�����ѯ��Ȩ��Լ��������Ӧ
CBRspQryExecOrder cbRspQryExecOrder = 0;	///�����ѯִ��������Ӧ
CBRspQryForQuote cbRspQryForQuote = 0;	///�����ѯѯ����Ӧ
CBRspQryQuote cbRspQryQuote = 0;	///�����ѯ������Ӧ
CBRspQryOptionSelfClose cbRspQryOptionSelfClose = 0;	///�����ѯ��Ȩ�ԶԳ���Ӧ
CBRspQryInvestUnit cbRspQryInvestUnit = 0;	///�����ѯͶ�ʵ�Ԫ��Ӧ
CBRspQryCombInstrumentGuard cbRspQryCombInstrumentGuard = 0;	///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
CBRspQryCombAction cbRspQryCombAction = 0;	///�����ѯ���������Ӧ
CBRspQryTransferSerial cbRspQryTransferSerial = 0;	///�����ѯת����ˮ��Ӧ
CBRspQryAccountregister cbRspQryAccountregister = 0;///�����ѯ����ǩԼ��ϵ��Ӧ
CBRspError cbRspError = 0;	///����Ӧ��
CBRtnOrder cbRtnOrder = 0;	///����֪ͨ
CBRtnTrade cbRtnTrade = 0;	///�ɽ�֪ͨ
CBErrRtnOrderInsert cbErrRtnOrderInsert = 0;	///����¼�����ر�
CBErrRtnOrderAction cbErrRtnOrderAction = 0;	///������������ر�
CBRtnInstrumentStatus cbRtnInstrumentStatus = 0;	///��Լ����״̬֪ͨ
CBRtnTradingNotice cbRtnTradingNotice = 0;	///����֪ͨ
CBRtnErrorConditionalOrder cbRtnErrorConditionalOrder = 0;	///��ʾ������У�����
CBRtnExecOrder cbRtnExecOrder = 0;	///ִ������֪ͨ
CBErrRtnExecOrderInsert cbErrRtnExecOrderInsert = 0;	///ִ������¼�����ر�
CBErrRtnExecOrderAction cbErrRtnExecOrderAction = 0;	///ִ�������������ر�
CBErrRtnForQuoteInsert cbErrRtnForQuoteInsert = 0;	///ѯ��¼�����ر�
CBRtnQuote cbRtnQuote = 0;	///����֪ͨ
CBErrRtnQuoteInsert cbErrRtnQuoteInsert = 0;	///����¼�����ر�
CBErrRtnQuoteAction cbErrRtnQuoteAction = 0;	///���۲�������ر�
CBRtnForQuoteRsp cbRtnForQuoteRsp = 0;	///ѯ��֪ͨ
CBRtnCFMMCTradingAccountToken cbRtnCFMMCTradingAccountToken = 0;	///��֤���������û�����
CBErrRtnBatchOrderAction cbErrRtnBatchOrderAction = 0;	///����������������ر�
CBRtnOptionSelfClose cbRtnOptionSelfClose = 0;	///��Ȩ�ԶԳ�֪ͨ
CBErrRtnOptionSelfCloseInsert cbErrRtnOptionSelfCloseInsert = 0;	///��Ȩ�ԶԳ�¼�����ر�
CBErrRtnOptionSelfCloseAction cbErrRtnOptionSelfCloseAction = 0;	///��Ȩ�ԶԳ��������ر�
CBRtnCombAction cbRtnCombAction = 0;	///�������֪ͨ
CBErrRtnCombActionInsert cbErrRtnCombActionInsert = 0;	///�������¼�����ر�
CBRspQryContractBank cbRspQryContractBank = 0;	///�����ѯǩԼ������Ӧ
CBRspQryParkedOrder cbRspQryParkedOrder = 0;	///�����ѯԤ����Ӧ
CBRspQryParkedOrderAction cbRspQryParkedOrderAction = 0;	///�����ѯԤ�񳷵���Ӧ
CBRspQryTradingNotice cbRspQryTradingNotice = 0;	///�����ѯ����֪ͨ��Ӧ
CBRspQryBrokerTradingParams cbRspQryBrokerTradingParams = 0;	///�����ѯ���͹�˾���ײ�����Ӧ
CBRspQryBrokerTradingAlgos cbRspQryBrokerTradingAlgos = 0;	///�����ѯ���͹�˾�����㷨��Ӧ
CBRspQueryCFMMCTradingAccountToken cbRspQueryCFMMCTradingAccountToken = 0;	///�����ѯ��������û�����
CBRtnFromBankToFutureByBank cbRtnFromBankToFutureByBank = 0;	///���з��������ʽ�ת�ڻ�֪ͨ
CBRtnFromFutureToBankByBank cbRtnFromFutureToBankByBank = 0;	///���з����ڻ��ʽ�ת����֪ͨ
CBRtnRepealFromBankToFutureByBank cbRtnRepealFromBankToFutureByBank = 0;	///���з����������ת�ڻ�֪ͨ
CBRtnRepealFromFutureToBankByBank cbRtnRepealFromFutureToBankByBank = 0;	///���з�������ڻ�ת����֪ͨ
CBRtnFromBankToFutureByFuture cbRtnFromBankToFutureByFuture = 0;	///�ڻ����������ʽ�ת�ڻ�֪ͨ
CBRtnFromFutureToBankByFuture cbRtnFromFutureToBankByFuture = 0;	///�ڻ������ڻ��ʽ�ת����֪ͨ
CBRtnRepealFromBankToFutureByFutureManual cbRtnRepealFromBankToFutureByFutureManual = 0;	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
CBRtnRepealFromFutureToBankByFutureManual cbRtnRepealFromFutureToBankByFutureManual = 0;	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
CBRtnQueryBankBalanceByFuture cbRtnQueryBankBalanceByFuture = 0;	///�ڻ������ѯ�������֪ͨ
CBErrRtnBankToFutureByFuture cbErrRtnBankToFutureByFuture = 0;	///�ڻ����������ʽ�ת�ڻ�����ر�
CBErrRtnFutureToBankByFuture cbErrRtnFutureToBankByFuture = 0;	///�ڻ������ڻ��ʽ�ת���д���ر�
CBErrRtnRepealBankToFutureByFutureManual cbErrRtnRepealBankToFutureByFutureManual = 0;	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
CBErrRtnRepealFutureToBankByFutureManual cbErrRtnRepealFutureToBankByFutureManual = 0;	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
CBErrRtnQueryBankBalanceByFuture cbErrRtnQueryBankBalanceByFuture = 0;	///�ڻ������ѯ����������ر�
CBRtnRepealFromBankToFutureByFuture cbRtnRepealFromBankToFutureByFuture = 0;	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
CBRtnRepealFromFutureToBankByFuture cbRtnRepealFromFutureToBankByFuture = 0;	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
CBRspFromBankToFutureByFuture cbRspFromBankToFutureByFuture = 0;	///�ڻ����������ʽ�ת�ڻ�Ӧ��
CBRspFromFutureToBankByFuture cbRspFromFutureToBankByFuture = 0;	///�ڻ������ڻ��ʽ�ת����Ӧ��
CBRspQueryBankAccountMoneyByFuture cbRspQueryBankAccountMoneyByFuture = 0;	///�ڻ������ѯ�������Ӧ��
CBRtnOpenAccountByBank cbRtnOpenAccountByBank = 0;	///���з������ڿ���֪ͨ
CBRtnCancelAccountByBank cbRtnCancelAccountByBank = 0;	///���з�����������֪ͨ
CBRtnChangeAccountByBank cbRtnChangeAccountByBank = 0;	///���з����������˺�֪ͨ

//===============

//��ȡ�ӿڰ汾
TRADEAPI_API const char* GetApiVersion()
{
	return CThostFtdcTraderApi::GetApiVersion();
}

//����
TRADEAPI_API void Connect(char *frontAddr, char *pszFlowPath)
{
	// ��ʼ��UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);			// ����UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// ע���¼���
	pUserApi->SubscribePublicTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// ע�ṫ����
	pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// ע��˽����
	pUserApi->RegisterFront(frontAddr);							// connect
	pUserApi->Init();
	//pUserApi->Join();
}

//�Ͽ�
TRADEAPI_API void DisConnect()
{
	pUserApi->RegisterSpi(NULL);
	pUserApi->Release();
	pUserApi = NULL;
}

//��ȡ������
TRADEAPI_API const char* GetTradingDay()
{
	return pUserApi->GetTradingDay();
}

//�����û���¼����
TRADEAPI_API int ReqUserLogin(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcUserIDType userID, TThostFtdcPasswordType password)
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, userID);
	strcpy_s(req.Password, password);
	strcpy_s(req.UserProductInfo, "HF");
	return pUserApi->ReqUserLogin(&req, requestID);
}
//���͵ǳ�����
TRADEAPI_API int ReqUserLogout(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcUserIDType investorID)
{
	CThostFtdcUserLogoutField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, investorID);
	return pUserApi->ReqUserLogout(&req, requestID);
}
//�����û�����
TRADEAPI_API int ReqUserPasswordUpdate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcUserIDType userID, TThostFtdcUserIDType oldPassword, TThostFtdcPasswordType newPassword)
{
	CThostFtdcUserPasswordUpdateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, userID);
	strcpy_s(req.OldPassword, oldPassword);
	strcpy_s(req.NewPassword, newPassword);
	return pUserApi->ReqUserPasswordUpdate(&req, requestID);
}
///�ʽ��˻������������
TRADEAPI_API int ReqTradingAccountPasswordUpdate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcAccountIDType accountID, TThostFtdcUserIDType oldPassword, TThostFtdcPasswordType newPassword)
{
	CThostFtdcTradingAccountPasswordUpdateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.AccountID, accountID);
	strcpy_s(req.NewPassword, newPassword);
	strcpy_s(req.OldPassword, oldPassword);
	return pUserApi->ReqTradingAccountPasswordUpdate(&req, requestID);
}
//��ȫ��¼����
TRADEAPI_API int ReqUserSafeLogin(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcUserIDType userID, TThostFtdcPasswordType password)
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, userID);
	strcpy_s(req.Password, password);
	strcpy_s(req.UserProductInfo, "HF");
	return pUserApi->ReqUserLogin2(&req, requestID);
}
//��ȫ�����û�����
TRADEAPI_API int ReqUserPasswordSafeUpdate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcUserIDType userID, TThostFtdcUserIDType oldPassword, TThostFtdcPasswordType newPassword)
{
	CThostFtdcUserPasswordUpdateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, userID);
	strcpy_s(req.OldPassword, oldPassword);
	strcpy_s(req.NewPassword, newPassword);
	return pUserApi->ReqUserPasswordUpdate2(&req, requestID);
}
//����¼������
TRADEAPI_API int ReqOrderInsert(int requestID, CThostFtdcInputOrderField *pOrder)
{
	int siez = sizeof(CThostFtdcInputOrderField);
	strcpy_s(pOrder->BusinessUnit, "HF");
	return pUserApi->ReqOrderInsert(pOrder, requestID);
}
//������������
TRADEAPI_API int ReqOrderAction(int requestID, CThostFtdcInputOrderActionField *pOrder)
{
	return pUserApi->ReqOrderAction(pOrder, requestID);
}
///��ѯ��󱨵���������
TRADEAPI_API int ReqQueryMaxOrderVolume(int requestID, CThostFtdcQueryMaxOrderVolumeField *pMaxOrderVolume)
{
	return pUserApi->ReqQueryMaxOrderVolume(pMaxOrderVolume, requestID);
}
//Ͷ���߽�����ȷ��
TRADEAPI_API int ReqSettlementInfoConfirm(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcSettlementInfoConfirmField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqSettlementInfoConfirm(&req, requestID);
}
///ִ������¼������
TRADEAPI_API int ReqExecOrderInsert(int requestID, CThostFtdcInputExecOrderField *pInputExecOrder)
{
	return pUserApi->ReqExecOrderInsert(pInputExecOrder, requestID);
}
///ִ�������������
TRADEAPI_API int ReqExecOrderAction(int requestID, CThostFtdcInputExecOrderActionField *pInputExecOrderAction)
{
	return pUserApi->ReqExecOrderAction(pInputExecOrderAction, requestID);
}
///ѯ��¼������
TRADEAPI_API int ReqForQuoteInsert(int requestID, CThostFtdcInputForQuoteField *pInputForQuote)
{
	return pUserApi->ReqForQuoteInsert(pInputForQuote, requestID);
}
///����¼������
TRADEAPI_API int ReqQuoteInsert(int requestID, CThostFtdcInputQuoteField *pInputQuote)
{
	return pUserApi->ReqQuoteInsert(pInputQuote, requestID);
}
///���۲�������
TRADEAPI_API int ReqQuoteAction(int requestID, CThostFtdcInputQuoteActionField *pInputQuoteAction)
{
	return pUserApi->ReqQuoteAction(pInputQuoteAction, requestID);
}
///����������������
TRADEAPI_API int ReqBatchOrderAction(int requestID, CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction)
{
	return pUserApi->ReqBatchOrderAction(pInputBatchOrderAction, requestID);
}
///��Ȩ�ԶԳ�¼������
TRADEAPI_API int ReqOptionSelfCloseInsert(int requestID, CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose)
{
	return pUserApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, requestID);
}
///��Ȩ�ԶԳ��������
TRADEAPI_API int ReqOptionSelfCloseAction(int requestID, CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction)
{
	return pUserApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, requestID);
}
///�������¼������
TRADEAPI_API int ReqCombActionInsert(int requestID, CThostFtdcInputCombActionField *pInputCombAction)
{
	return pUserApi->ReqCombActionInsert(pInputCombAction, requestID);
}
///�����ѯ����
TRADEAPI_API int ReqQryOrder(int requestID, CThostFtdcQryOrderField *pQryOrder)
{
	return pUserApi->ReqQryOrder(pQryOrder, requestID);
}
///�����ѯ�ɽ�
TRADEAPI_API int ReqQryTrade(int requestID, CThostFtdcQryTradeField *pQryTrade)
{
	return pUserApi->ReqQryTrade(pQryTrade, requestID);
}
//�����ѯͶ���ֲ߳�
TRADEAPI_API int ReqQryInvestorPosition(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInvestorPositionField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryInvestorPosition(&req, requestID);
}
//�����ѯ�ʽ��˻�
TRADEAPI_API int ReqQryTradingAccount(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQryTradingAccountField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQryTradingAccount(&req, requestID);
}
///�����ѯͶ����
TRADEAPI_API int ReqQryInvestor(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQryInvestorField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQryInvestor(&req, requestID);
}
///�����ѯ���ױ���
TRADEAPI_API int ReqQryTradingCode(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcClientIDType clientID, TThostFtdcExchangeIDType	exchangeID)
{
	CThostFtdcQryTradingCodeField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (clientID != NULL)
		strcpy_s(req.ClientID, clientID);
	if (exchangeID != NULL)
		strcpy_s(req.ExchangeID, exchangeID);
	return pUserApi->ReqQryTradingCode(&req, requestID);
}
///�����ѯ��Լ��֤����
TRADEAPI_API int ReqQryInstrumentMarginRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID, TThostFtdcHedgeFlagType	hedgeFlag)
{
	CThostFtdcQryInstrumentMarginRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	if (hedgeFlag != NULL)
		req.HedgeFlag = hedgeFlag;						//*��*�ܲ���null�������в�ѯ
	return pUserApi->ReqQryInstrumentMarginRate(&req, requestID);
}
///�����ѯ��Լ��������
TRADEAPI_API int ReqQryInstrumentCommissionRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInstrumentCommissionRateField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryInstrumentCommissionRate(&req, requestID);
}
///�����ѯ������
TRADEAPI_API int ReqQryExchange(int requestID, TThostFtdcExchangeIDType exchangeID)
{
	CThostFtdcQryExchangeField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.ExchangeID, exchangeID);
	return pUserApi->ReqQryExchange(&req, requestID);
}
//�����ѯ��Լ
TRADEAPI_API int ReqQryInstrument(int requestID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInstrumentField req;
	memset(&req, 0, sizeof(req));
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryInstrument(&req, requestID);
}
//�����ѯ����
TRADEAPI_API int ReqQryDepthMarketData(int requestID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryDepthMarketDataField req;
	memset(&req, 0, sizeof(req));
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryDepthMarketData(&req, requestID);
}
///�����ѯͶ���߽�����
TRADEAPI_API int ReqQrySettlementInfo(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcDateType	tradingDay)
{
	CThostFtdcQrySettlementInfoField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (tradingDay != NULL)
		strcpy_s(req.TradingDay, tradingDay);
	return pUserApi->ReqQrySettlementInfo(&req, requestID);
}
//��ѯ�ֲ���ϸ
TRADEAPI_API int ReqQryInvestorPositionDetail(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInvestorPositionDetailField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryInvestorPositionDetail(&req, requestID);
}
///�����ѯ�ͻ�֪ͨ
TRADEAPI_API int ReqQryNotice(int requestID, TThostFtdcBrokerIDType brokerID)
{
	CThostFtdcQryNoticeField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	return pUserApi->ReqQryNotice(&req, requestID);
}
///�����ѯ������Ϣȷ��
TRADEAPI_API int ReqQrySettlementInfoConfirm(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQrySettlementInfoConfirmField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQrySettlementInfoConfirm(&req, requestID);
}
///�����ѯ**���**�ֲ���ϸ
TRADEAPI_API int ReqQryInvestorPositionCombineDetail(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInvestorPositionCombineDetailField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.CombInstrumentID, instrumentID);
	return pUserApi->ReqQryInvestorPositionCombineDetail(&req, requestID);
}
///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
TRADEAPI_API int ReqQryCFMMCTradingAccountKey(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQryCFMMCTradingAccountKeyField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQryCFMMCTradingAccountKey(&req, requestID);
}
///�����ѯ�ֵ��۵���Ϣ
TRADEAPI_API int ReqQryEWarrantOffset(int requestID, CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset)
{
	return pUserApi->ReqQryEWarrantOffset(pQryEWarrantOffset, requestID);
}
///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
TRADEAPI_API int ReqQryInvestorProductGroupMargin(int requestID, CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin)
{
	return pUserApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, requestID);
}
///�����ѯ��������֤����
TRADEAPI_API int ReqQryExchangeMarginRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInstrumentIDType instrumentID, TThostFtdcHedgeFlagType hedgeFlag)
{
	CThostFtdcQryExchangeMarginRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	req.HedgeFlag = hedgeFlag;
	return pUserApi->ReqQryExchangeMarginRate(&req, requestID);
}
///�����ѯ������������֤����
TRADEAPI_API int ReqQryExchangeMarginRateAdjust(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInstrumentIDType instrumentID, TThostFtdcHedgeFlagType hedgeFlag)
{
	CThostFtdcQryExchangeMarginRateAdjustField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	req.HedgeFlag = hedgeFlag;
	return pUserApi->ReqQryExchangeMarginRateAdjust(&req, requestID);
}
///�����ѯ����
TRADEAPI_API int ReqQryExchangeRate(int requestID, CThostFtdcQryExchangeRateField *pQryExchangeRate)
{
	return pUserApi->ReqQryExchangeRate(pQryExchangeRate, requestID);
}
///�����ѯ�����������Ա����Ȩ��
TRADEAPI_API int ReqQrySecAgentACIDMap(int requestID, CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap)
{
	return pUserApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, requestID);
}
///�����ѯ��Ʒ���ۻ���
TRADEAPI_API int ReqQryProductExchRate(int requestID, TThostFtdcInstrumentIDType productID)
{
	CThostFtdcQryProductExchRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.ProductID, productID);
	return pUserApi->ReqQryProductExchRate(&req, requestID);
}
///�����ѯ��Ʒ��
TRADEAPI_API int ReqQryProductGroup(int requestID, TThostFtdcInstrumentIDType productID, TThostFtdcExchangeIDType exchangeID)
{
	CThostFtdcQryProductGroupField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.ProductID, productID);
	strcpy_s(req.ExchangeID, exchangeID);
	return pUserApi->ReqQryProductGroup(&req, requestID);
}
///�����ѯ�����̺�Լ��������
TRADEAPI_API int ReqQryMMInstrumentCommissionRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryMMInstrumentCommissionRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryMMInstrumentCommissionRate(&req, requestID);
}
///�����ѯ��������Ȩ��Լ������
TRADEAPI_API int ReqQryMMOptionInstrCommRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryMMOptionInstrCommRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryMMOptionInstrCommRate(&req, requestID);
}
///�����ѯ����������
TRADEAPI_API int ReqQryInstrumentOrderCommRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryInstrumentOrderCommRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryInstrumentOrderCommRate(&req, requestID);
}
///�����ѯ�ʽ��˻�
TRADEAPI_API int ReqQrySecAgentTradingAccount(int requestID, CThostFtdcQryTradingAccountField *pQryTradingAccount)
{
	return pUserApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, requestID);
}
///�����ѯ�����������ʽ�У��ģʽ
TRADEAPI_API int ReqQrySecAgentCheckMode(int requestID, CThostFtdcQrySecAgentCheckModeField *pQrySecAgentCheckMode)
{
	return pUserApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, requestID);
}
///�����ѯ��Ȩ���׳ɱ�
TRADEAPI_API int ReqQryOptionInstrTradeCost(int requestID, CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost)
{
	return pUserApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, requestID);
}
///�����ѯ��Ȩ��Լ������
TRADEAPI_API int ReqQryOptionInstrCommRate(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryOptionInstrCommRateField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	return pUserApi->ReqQryOptionInstrCommRate(&req, requestID);
}
///�����ѯִ������
TRADEAPI_API int ReqQryExecOrder(int requestID, CThostFtdcQryExecOrderField *pQryExecOrder)
{
	return pUserApi->ReqQryExecOrder(pQryExecOrder, requestID);
}
///�����ѯѯ��
TRADEAPI_API int ReqQryForQuote(int requestID, CThostFtdcQryForQuoteField *pQryForQuote)
{
	return pUserApi->ReqQryForQuote(pQryForQuote, requestID);
}
///�����ѯ����
TRADEAPI_API int ReqQryQuote(int requestID, CThostFtdcQryQuoteField *pQryQuote)
{
	return pUserApi->ReqQryQuote(pQryQuote, requestID);
}
///�����ѯ��Ȩ�ԶԳ�
TRADEAPI_API int ReqQryOptionSelfClose(int requestID, CThostFtdcQryOptionSelfCloseField *pQryOptionSelfClose)
{
	return pUserApi->ReqQryOptionSelfClose(pQryOptionSelfClose, requestID);
}
///�����ѯͶ�ʵ�Ԫ
TRADEAPI_API int ReqQryInvestUnit(int requestID, CThostFtdcQryInvestUnitField *pQryInvestUnit)
{
	return pUserApi->ReqQryInvestUnit(pQryInvestUnit, requestID);
}
///�����ѯ��Ϻ�Լ��ȫϵ��
TRADEAPI_API int ReqQryCombInstrumentGuard(int requestID, CThostFtdcQryCombInstrumentGuardField *pQryCombInstrumentGuard)
{
	return pUserApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, requestID);
}
///�����ѯ�������
TRADEAPI_API int ReqQryCombAction(int requestID, CThostFtdcQryCombActionField *pQryCombAction)
{
	return pUserApi->ReqQryCombAction(pQryCombAction, requestID);
}
///�����ѯ����֪ͨ
TRADEAPI_API int ReqQryTradingNotice(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQryTradingNoticeField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQryTradingNotice(&req, requestID);
}
///�����ѯ���͹�˾���ײ���
TRADEAPI_API int ReqQryBrokerTradingParams(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQryBrokerTradingParamsField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQryBrokerTradingParams(&req, requestID);
}
///�����ѯ���͹�˾�����㷨
TRADEAPI_API int ReqQryBrokerTradingAlgos(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcExchangeIDType exchangeID, TThostFtdcInstrumentIDType instrumentID)
{
	CThostFtdcQryBrokerTradingAlgosField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	if (exchangeID != NULL)
		strcpy_s(req.ExchangeID, exchangeID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);

	return pUserApi->ReqQryBrokerTradingAlgos(&req, requestID);
}
///Ԥ��¼������
TRADEAPI_API int ReqParkedOrderInsert(int requestID, CThostFtdcParkedOrderField *ParkedOrder)
{
	return pUserApi->ReqParkedOrderInsert(ParkedOrder, requestID);
}
///Ԥ�񳷵�¼������
TRADEAPI_API int ReqParkedOrderAction(int requestID, CThostFtdcParkedOrderActionField *ParkedOrderAction)
{
	return pUserApi->ReqParkedOrderAction(ParkedOrderAction, requestID);
}
///����ɾ��Ԥ��
TRADEAPI_API int ReqRemoveParkedOrder(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcParkedOrderIDType parkedOrderID)
{
	CThostFtdcRemoveParkedOrderField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	strcpy_s(req.ParkedOrderID, parkedOrderID);
	return pUserApi->ReqRemoveParkedOrder(&req, requestID);
}
///����ɾ��Ԥ�񳷵�
TRADEAPI_API int ReqRemoveParkedOrderAction(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcParkedOrderActionIDType parkedOrderActionID)
{
	CThostFtdcRemoveParkedOrderActionField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	strcpy_s(req.ParkedOrderActionID, parkedOrderActionID);
	return pUserApi->ReqRemoveParkedOrderAction(&req, requestID);
}

///�����ѯת������
TRADEAPI_API int ReqQryTransferBank(int requestID, TThostFtdcBankIDType bankID, TThostFtdcBankBrchIDType bankBrchID)
{
	CThostFtdcQryTransferBankField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BankID, bankID);
	strcpy_s(req.BankBrchID, bankBrchID);
	return pUserApi->ReqQryTransferBank(&req, requestID);
}
///�����ѯת����ˮ
TRADEAPI_API int ReqQryTransferSerial(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcAccountIDType accountID, TThostFtdcBankIDType bankID)
{
	CThostFtdcQryTransferSerialField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.AccountID, accountID);
	strcpy_s(req.BankID, bankID);
	return pUserApi->ReqQryTransferSerial(&req, requestID);
}
///�����ѯ����ǩԼ��ϵ
TRADEAPI_API int ReqQryAccountregister(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcAccountIDType accountID, TThostFtdcBankIDType bankID)
{
	CThostFtdcQryAccountregisterField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.AccountID, accountID);
	strcpy_s(req.BankID, bankID);
	return pUserApi->ReqQryAccountregister(&req, requestID);
}
///�����ѯǩԼ����
TRADEAPI_API int ReqQryContractBank(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcBankIDType bankID, TThostFtdcBankBrchIDType bankBrchID)
{
	CThostFtdcQryContractBankField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	if (bankID != NULL)
		strcpy_s(req.BankID, bankID);
	if (bankBrchID != NULL)
		strcpy_s(req.BankBrchID, bankBrchID);
	return pUserApi->ReqQryContractBank(&req, requestID);
}
///�����ѯԤ��
TRADEAPI_API int ReqQryParkedOrder(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID, TThostFtdcExchangeIDType exchangeID)
{
	CThostFtdcQryParkedOrderField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	if (exchangeID != NULL)
		strcpy_s(req.ExchangeID, exchangeID);
	return pUserApi->ReqQryParkedOrder(&req, requestID);
}
///�����ѯԤ�񳷵�
TRADEAPI_API int ReqQryParkedOrderAction(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcInstrumentIDType instrumentID, TThostFtdcExchangeIDType exchangeID)
{
	CThostFtdcQryParkedOrderActionField  req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	if (instrumentID != NULL)
		strcpy_s(req.InstrumentID, instrumentID);
	if (exchangeID != NULL)
		strcpy_s(req.ExchangeID, exchangeID);
	return pUserApi->ReqQryParkedOrderAction(&req, requestID);
}
///�����ѯ��������û�����
TRADEAPI_API int ReqQueryCFMMCTradingAccountToken(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcQueryCFMMCTradingAccountTokenField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.InvestorID, investorID);
	return pUserApi->ReqQueryCFMMCTradingAccountToken(&req, requestID);
}
///�ڻ����������ʽ�ת�ڻ�����
TRADEAPI_API int ReqFromBankToFutureByFuture(int requestID, CThostFtdcReqTransferField *reqTransfer)
{
	return pUserApi->ReqFromBankToFutureByFuture(reqTransfer, requestID);
}
///�ڻ������ڻ��ʽ�ת��������
TRADEAPI_API int ReqFromFutureToBankByFuture(int requestID, CThostFtdcReqTransferField *reqTransfer)
{
	return pUserApi->ReqFromFutureToBankByFuture(reqTransfer, requestID);
}
///�ڻ������ѯ�����������
TRADEAPI_API int ReqQueryBankAccountMoneyByFuture(int requestID, CThostFtdcReqQueryAccountField *reqQueryAccount)
{
	return pUserApi->ReqQueryBankAccountMoneyByFuture(reqQueryAccount, requestID);
}
//========================================
///==================================== �ص����� =======================================
TRADEAPI_API void WINAPI RegOnFrontConnected(CBOnFrontConnected cb)		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
{
	cbOnFrontConnected = cb;
}

TRADEAPI_API void WINAPI RegOnFrontDisconnected(CBOnFrontDisconnected cb)		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
{
	cbOnFrontDisconnected = cb;
}

TRADEAPI_API void WINAPI RegOnHeartBeatWarning(CBOnHeartBeatWarning cb)		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
{
	cbOnHeartBeatWarning = cb;
}

TRADEAPI_API void WINAPI RegRspUserLogin(CBRspUserLogin cb)	///��¼������Ӧ
{
	cbRspUserLogin = cb;
}
TRADEAPI_API void WINAPI RegRspUserLogout(CBRspUserLogout cb)	///�ǳ�������Ӧ
{
	cbRspUserLogout = cb;
}
TRADEAPI_API void WINAPI RegRspUserPasswordUpdate(CBRspUserPasswordUpdate cb)	///�û��������������Ӧ
{
	cbRspUserPasswordUpdate = cb;
}
TRADEAPI_API void WINAPI RegRspTradingAccountPasswordUpdate(CBRspTradingAccountPasswordUpdate cb)	///�ʽ��˻��������������Ӧ
{
	cbRspTradingAccountPasswordUpdate = cb;
}
TRADEAPI_API void WINAPI RegRspOrderInsert(CBRspOrderInsert cb)	///����¼��������Ӧ
{
	cbRspOrderInsert = cb;
}
TRADEAPI_API void WINAPI RegRspParkedOrderInsert(CBRspParkedOrderInsert cb)	///Ԥ��¼��������Ӧ
{
	cbRspParkedOrderInsert = cb;
}
TRADEAPI_API void WINAPI RegRspParkedOrderAction(CBRspParkedOrderAction cb)	///Ԥ�񳷵�¼��������Ӧ
{
	cbRspParkedOrderAction = cb;
}
TRADEAPI_API void WINAPI RegRspOrderAction(CBRspOrderAction cb)	///��������������Ӧ
{
	cbRspOrderAction = cb;
}
TRADEAPI_API void WINAPI RegRspQueryMaxOrderVolume(CBRspQueryMaxOrderVolume cb)	///��ѯ��󱨵�������Ӧ
{
	cbRspQueryMaxOrderVolume = cb;
}
TRADEAPI_API void WINAPI RegRspSettlementInfoConfirm(CBRspSettlementInfoConfirm cb)	///Ͷ���߽�����ȷ����Ӧ
{
	cbRspSettlementInfoConfirm = cb;
}
TRADEAPI_API void WINAPI RegRspRemoveParkedOrder(CBRspRemoveParkedOrder cb)	///ɾ��Ԥ����Ӧ
{
	cbRspRemoveParkedOrder = cb;
}
TRADEAPI_API void WINAPI RegRspRemoveParkedOrderAction(CBRspRemoveParkedOrderAction cb)	///ɾ��Ԥ�񳷵���Ӧ
{
	cbRspRemoveParkedOrderAction = cb;
}
TRADEAPI_API void WINAPI RegBatchOrderAction(CBRspBatchOrderAction cb)	///������������������Ӧ
{
	cbRspBatchOrderAction = cb;
}
TRADEAPI_API void WINAPI RegCombActionInsert(CBRspCombActionInsert cb)	///�������¼��������Ӧ
{
	cbRspCombActionInsert = cb;
}
TRADEAPI_API void WINAPI RegRspQryOrder(CBRspQryOrder cb)	///�����ѯ������Ӧ
{
	cbRspQryOrder = cb;
}
TRADEAPI_API void WINAPI RegRspQryTrade(CBRspQryTrade cb)	///�����ѯ�ɽ���Ӧ
{
	cbRspQryTrade = cb;
}
TRADEAPI_API void WINAPI RegRspQryInvestorPosition(CBRspQryInvestorPosition cb)	///�����ѯͶ���ֲ߳���Ӧ
{
	cbRspQryInvestorPosition = cb;
}
TRADEAPI_API void WINAPI RegRspQryTradingAccount(CBRspQryTradingAccount cb)	///�����ѯ�ʽ��˻���Ӧ
{
	cbRspQryTradingAccount = cb;
}
TRADEAPI_API void WINAPI RegRspQryInvestor(CBRspQryInvestor cb)	///�����ѯͶ������Ӧ
{
	cbRspQryInvestor = cb;
}
TRADEAPI_API void WINAPI RegRspQryTradingCode(CBRspQryTradingCode cb)	///�����ѯ���ױ�����Ӧ
{
	cbRspQryTradingCode = cb;
}
TRADEAPI_API void WINAPI RegRspQryInstrumentMarginRate(CBRspQryInstrumentMarginRate cb)	///�����ѯ��Լ��֤������Ӧ
{
	cbRspQryInstrumentMarginRate = cb;
}
TRADEAPI_API void WINAPI RegRspQryInstrumentCommissionRate(CBRspQryInstrumentCommissionRate cb)	///�����ѯ��Լ����������Ӧ
{
	cbRspQryInstrumentCommissionRate = cb;
}
TRADEAPI_API void WINAPI RegRspQryExchange(CBRspQryExchange cb)	///�����ѯ��������Ӧ
{
	cbRspQryExchange = cb;
}
TRADEAPI_API void WINAPI RegRspQryInstrument(CBRspQryInstrument cb)	///�����ѯ��Լ��Ӧ
{
	cbRspQryInstrument = cb;
}
TRADEAPI_API void WINAPI RegRspQryDepthMarketData(CBRspQryDepthMarketData cb)	///�����ѯ������Ӧ
{
	cbRspQryDepthMarketData = cb;
}
TRADEAPI_API void WINAPI RegRspQrySettlementInfo(CBRspQrySettlementInfo cb)	///�����ѯͶ���߽�������Ӧ
{
	cbRspQrySettlementInfo = cb;
}
TRADEAPI_API void WINAPI RegRspQryTransferBank(CBRspQryTransferBank cb)	///�����ѯת��������Ӧ
{
	cbRspQryTransferBank = cb;
}
TRADEAPI_API void WINAPI RegRspQryInvestorPositionDetail(CBRspQryInvestorPositionDetail cb)	///�����ѯͶ���ֲ߳���ϸ��Ӧ
{
	cbRspQryInvestorPositionDetail = cb;
}
TRADEAPI_API void WINAPI RegRspQryNotice(CBRspQryNotice cb)	///�����ѯ�ͻ�֪ͨ��Ӧ
{
	cbRspQryNotice = cb;
}
TRADEAPI_API void WINAPI RegRspQrySettlementInfoConfirm(CBRspQrySettlementInfoConfirm cb)	///�����ѯ������Ϣȷ����Ӧ
{
	cbRspQrySettlementInfoConfirm = cb;
}
TRADEAPI_API void WINAPI RegRspQryInvestorPositionCombineDetail(CBRspQryInvestorPositionCombineDetail cb)	///�����ѯͶ���ֲ߳���ϸ��Ӧ
{
	cbRspQryInvestorPositionCombineDetail = cb;
}
TRADEAPI_API void WINAPI RegRspQryCFMMCTradingAccountKey(CBRspQryCFMMCTradingAccountKey cb)	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
{
	cbRspQryCFMMCTradingAccountKey = cb;
}
TRADEAPI_API void WINAPI RegRspQryEWarrantOffset(CBRspQryEWarrantOffset cb)	///�����ѯ�ֵ��۵���Ϣ
{
	cbRspQryEWarrantOffset = cb;
}
TRADEAPI_API void WINAPI RegRspQryInvestorProductGroupMargin(CBRspQryInvestorProductGroupMargin cb)	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
{
	cbRspQryInvestorProductGroupMargin = cb;
}
TRADEAPI_API void WINAPI RegRspQryExchangeMarginRate(CBRspQryExchangeMarginRate cb)	///�����ѯ��������֤����
{
	cbRspQryExchangeMarginRate = cb;
}
TRADEAPI_API void WINAPI RegRspQryExchangeMarginRateAdjust(CBRspQryExchangeMarginRateAdjust cb)	///�����ѯ������������֤����
{
	cbRspQryExchangeMarginRateAdjust = cb;
}
TRADEAPI_API void WINAPI RegRspQryTransferSerial(CBRspQryTransferSerial cb)	///�����ѯת����ˮ��Ӧ
{
	cbRspQryTransferSerial = cb;
}
TRADEAPI_API void WINAPI RegRspQryAccountregister(CBRspQryAccountregister cb)	///�����ѯ����ǩԼ��ϵ��Ӧ
{
	cbRspQryAccountregister = cb;
}
TRADEAPI_API void WINAPI RegRspError(CBRspError cb)	///����Ӧ��
{
	cbRspError = cb;
}
TRADEAPI_API void WINAPI RegRtnOrder(CBRtnOrder cb)	///����֪ͨ
{
	cbRtnOrder = cb;
}
TRADEAPI_API void WINAPI RegRtnTrade(CBRtnTrade cb)	///�ɽ�֪ͨ
{
	cbRtnTrade = cb;
}
TRADEAPI_API void WINAPI RegErrRtnOrderInsert(CBErrRtnOrderInsert cb)	///����¼�����ر�
{
	cbErrRtnOrderInsert = cb;
}
TRADEAPI_API void WINAPI RegErrRtnOrderAction(CBErrRtnOrderAction cb)	///������������ر�
{
	cbErrRtnOrderAction = cb;
}
TRADEAPI_API void WINAPI RegRtnInstrumentStatus(CBRtnInstrumentStatus cb)	///��Լ����״̬֪ͨ
{
	cbRtnInstrumentStatus = cb;
}
TRADEAPI_API void WINAPI RegRtnTradingNotice(CBRtnTradingNotice cb)	///����֪ͨ
{
	cbRtnTradingNotice = cb;
}
TRADEAPI_API void WINAPI RegRtnErrorConditionalOrder(CBRtnErrorConditionalOrder cb)	///��ʾ������У�����
{
	cbRtnErrorConditionalOrder = cb;
}
TRADEAPI_API void WINAPI RegRspQryContractBank(CBRspQryContractBank cb)	///�����ѯǩԼ������Ӧ
{
	cbRspQryContractBank = cb;
}
TRADEAPI_API void WINAPI RegRspQryParkedOrder(CBRspQryParkedOrder cb)	///�����ѯԤ����Ӧ
{
	cbRspQryParkedOrder = cb;
}
TRADEAPI_API void WINAPI RegRspQryParkedOrderAction(CBRspQryParkedOrderAction cb)	///�����ѯԤ�񳷵���Ӧ
{
	cbRspQryParkedOrderAction = cb;
}
TRADEAPI_API void WINAPI RegRspQryTradingNotice(CBRspQryTradingNotice cb)	///�����ѯ����֪ͨ��Ӧ
{
	cbRspQryTradingNotice = cb;
}
TRADEAPI_API void WINAPI RegRspQryBrokerTradingParams(CBRspQryBrokerTradingParams cb)	///�����ѯ���͹�˾���ײ�����Ӧ
{
	cbRspQryBrokerTradingParams = cb;
}
TRADEAPI_API void WINAPI RegRspQryBrokerTradingAlgos(CBRspQryBrokerTradingAlgos cb)	///�����ѯ���͹�˾�����㷨��Ӧ
{
	cbRspQryBrokerTradingAlgos = cb;
}
TRADEAPI_API void WINAPI RegRtnFromBankToFutureByBank(CBRtnFromBankToFutureByBank cb)	///���з��������ʽ�ת�ڻ�֪ͨ
{
	cbRtnFromBankToFutureByBank = cb;
}
TRADEAPI_API void WINAPI RegRtnFromFutureToBankByBank(CBRtnFromFutureToBankByBank cb)	///���з����ڻ��ʽ�ת����֪ͨ
{
	cbRtnFromFutureToBankByBank = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromBankToFutureByBank(CBRtnRepealFromBankToFutureByBank cb)	///���з����������ת�ڻ�֪ͨ
{
	cbRtnRepealFromBankToFutureByBank = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromFutureToBankByBank(CBRtnRepealFromFutureToBankByBank cb)	///���з�������ڻ�ת����֪ͨ
{
	cbRtnRepealFromFutureToBankByBank = cb;
}
TRADEAPI_API void WINAPI RegRtnFromBankToFutureByFuture(CBRtnFromBankToFutureByFuture cb)	///�ڻ����������ʽ�ת�ڻ�֪ͨ
{
	cbRtnFromBankToFutureByFuture = cb;
}
TRADEAPI_API void WINAPI RegRtnFromFutureToBankByFuture(CBRtnFromFutureToBankByFuture cb)	///�ڻ������ڻ��ʽ�ת����֪ͨ
{
	cbRtnFromFutureToBankByFuture = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromBankToFutureByFutureManual(CBRtnRepealFromBankToFutureByFutureManual cb)	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
{
	cbRtnRepealFromBankToFutureByFutureManual = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromFutureToBankByFutureManual(CBRtnRepealFromFutureToBankByFutureManual cb)	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
{
	cbRtnRepealFromFutureToBankByFutureManual = cb;
}
TRADEAPI_API void WINAPI RegRtnQueryBankBalanceByFuture(CBRtnQueryBankBalanceByFuture cb)	///�ڻ������ѯ�������֪ͨ
{
	cbRtnQueryBankBalanceByFuture = cb;
}
TRADEAPI_API void WINAPI RegErrRtnBankToFutureByFuture(CBErrRtnBankToFutureByFuture cb)	///�ڻ����������ʽ�ת�ڻ�����ر�
{
	cbErrRtnBankToFutureByFuture = cb;
}
TRADEAPI_API void WINAPI RegErrRtnFutureToBankByFuture(CBErrRtnFutureToBankByFuture cb)	///�ڻ������ڻ��ʽ�ת���д���ر�
{
	cbErrRtnFutureToBankByFuture = cb;
}
TRADEAPI_API void WINAPI RegErrRtnRepealBankToFutureByFutureManual(CBErrRtnRepealBankToFutureByFutureManual cb)	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
{
	cbErrRtnRepealBankToFutureByFutureManual = cb;
}
TRADEAPI_API void WINAPI RegErrRtnRepealFutureToBankByFutureManual(CBErrRtnRepealFutureToBankByFutureManual cb)	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
{
	cbErrRtnRepealFutureToBankByFutureManual = cb;
}
TRADEAPI_API void WINAPI RegErrRtnQueryBankBalanceByFuture(CBErrRtnQueryBankBalanceByFuture cb)	///�ڻ������ѯ����������ر�
{
	cbErrRtnQueryBankBalanceByFuture = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromBankToFutureByFuture(CBRtnRepealFromBankToFutureByFuture cb)	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
{
	cbRtnRepealFromBankToFutureByFuture = cb;
}
TRADEAPI_API void WINAPI RegRtnRepealFromFutureToBankByFuture(CBRtnRepealFromFutureToBankByFuture cb)	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
{
	cbRtnRepealFromFutureToBankByFuture = cb;
}
TRADEAPI_API void WINAPI RegRspFromBankToFutureByFuture(CBRspFromBankToFutureByFuture cb)	///�ڻ����������ʽ�ת�ڻ�Ӧ��
{
	cbRspFromBankToFutureByFuture = cb;
}
TRADEAPI_API void WINAPI RegRspFromFutureToBankByFuture(CBRspFromFutureToBankByFuture cb)	///�ڻ������ڻ��ʽ�ת����Ӧ��
{
	cbRspFromFutureToBankByFuture = cb;
}
TRADEAPI_API void WINAPI RegRspQueryBankAccountMoneyByFuture(CBRspQueryBankAccountMoneyByFuture cb)	///�ڻ������ѯ�������Ӧ��
{
	cbRspQueryBankAccountMoneyByFuture = cb;
}

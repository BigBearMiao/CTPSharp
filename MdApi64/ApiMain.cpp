// MdApi.cpp : ���� DLL Ӧ�ó���ĵ���������
//
#include "stdafx.h"
#include "MdApi.h"
#include <iostream>
//#include <vector>		//��̬����,֧�ָ�ֵ
//using namespace std;

#include "..\api\amd64\ThostFtdcMdApi.h"

// UserApi����
CThostFtdcMdApi* pUserApi;

// ������
int iRequestID = 0;

//�ص�����
CBOnRspError cbOnRspError = 0;
CBOnHeartBeatWarning cbOnHeartBeatWarning = 0;

CBOnFrontConnected cbOnFrontConnected = 0;
CBOnFrontDisconnected cbOnFrontDisconnected = 0;
CBOnRspUserLogin cbOnRspUserLogin = 0;
CBOnRspUserLogout cbOnRspUserLogout = 0;
CBOnRspSubMarketData cbOnRspSubMarketData = 0;
CBOnRspUnSubMarketData cbOnRspUnSubMarketData = 0;
CBOnRtnDepthMarketData cbOnRtnDepthMarketData = 0;

//��ȡ�ӿڰ汾
MDAPI_API const char* GetApiVersion()
{
	return CThostFtdcMdApi::GetApiVersion();
}

//����
MDAPI_API void Connect(char* frontAddr, char *pszFlowPath)
{

	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	// ��ʼ��UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath);			// ����UserApi

	pUserApi->RegisterSpi(pUserSpi);						// ע���¼���
	pUserApi->RegisterFront(frontAddr);					// connect
	pUserApi->Init();
	//	pUserApi->Join();
}

//�Ͽ�����
MDAPI_API void DisConnect()
{
	pUserApi->Release();
}

//��ȡ��ǰ������:ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
MDAPI_API const char *GetTradingDay()
{
	return pUserApi->GetTradingDay();
}

//��¼
MDAPI_API void ReqUserLogin(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID, TThostFtdcPasswordType password)
{
	CThostFtdcReqUserLoginField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, investorID);
	strcpy_s(req.Password, password);
	pUserApi->ReqUserLogin(&req, requestID);
}

//�ǳ�����
MDAPI_API void ReqUserLogout(int requestID, TThostFtdcBrokerIDType brokerID, TThostFtdcInvestorIDType investorID)
{
	CThostFtdcUserLogoutField req;
	memset(&req, 0, sizeof(req));
	strcpy_s(req.BrokerID, brokerID);
	strcpy_s(req.UserID, investorID);
	pUserApi->ReqUserLogout(&req, requestID);
}
//��������
MDAPI_API void SubMarketData(char* instrumentsID[], int nCount)
{
	pUserApi->SubscribeMarketData(instrumentsID, nCount);
}

//�˶�����
MDAPI_API void UnSubscribeMarketData(char *ppInstrumentID[], int nCount)
{
	pUserApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

//============================================ �ص� ����ע�� ===========================================
MDAPI_API void WINAPI RegOnRspError(CBOnRspError cb)
{
	cbOnRspError = cb;
}
//����
MDAPI_API void WINAPI RegOnHeartBeatWarning(CBOnHeartBeatWarning cb)
{
	cbOnHeartBeatWarning = cb;
}

//����Ӧ��
MDAPI_API void WINAPI RegOnFrontConnected(CBOnFrontConnected cb)
{
	cbOnFrontConnected = cb;
}
//���ӶϿ�
MDAPI_API void WINAPI RegOnFrontDisconnected(CBOnFrontDisconnected cb)
{
	cbOnFrontDisconnected = cb;
}
//��¼����Ӧ��
MDAPI_API void WINAPI RegOnRspUserLogin(CBOnRspUserLogin cb)
{
	cbOnRspUserLogin = cb;
}
//�ǳ�����Ӧ��
MDAPI_API void WINAPI RegOnRspUserLogout(CBOnRspUserLogout cb)
{
	cbOnRspUserLogout = cb;
}
//��������Ӧ��
MDAPI_API void WINAPI RegOnRspSubMarketData(CBOnRspSubMarketData cb)
{
	cbOnRspSubMarketData = cb;
}

//�˶�����Ӧ��
MDAPI_API void WINAPI RegOnRspUnSubMarketData(CBOnRspUnSubMarketData cb)
{
	cbOnRspUnSubMarketData = cb;
}
//�������֪ͨ
MDAPI_API void WINAPI RegOnRtnDepthMarketData(CBOnRtnDepthMarketData cb)
{
	cbOnRtnDepthMarketData = cb;
}
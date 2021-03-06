#pragma once


#include "SkinUI.h"

class SKINUI_CLASS CSkinDialog : public CDialog,public ISkinControl
{
	DECLARE_DYNAMIC(CSkinDialog)

protected:
	ISkinControl				m_SkinControl;
	HDC							m_hMemDC;
	HBITMAP						m_hMemBmp, m_hOldBmp;
	bool						m_bExtrude;				//是否可以拉伸
	bool						m_bClip;

public:
	CSkinDialog(UINT nIDTemplate,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSkinDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	//接口函数
protected:
	//移除边框
	void RemoveBorder();
	//初始化
	virtual BOOL OnInitDialog();

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//窗口绘制
	virtual void DrawClientArea(CDC*pDC,int nWidth,int nHeight){}
	//
	void SetExtrude(bool bExtrude);

	//功能函数
public:
	//获取背景
	HDC GetBackDC(){ return m_hMemDC; }
	//剪辑子窗口
	void SetClipChild(bool bClip);

	//消息函数
public:
	//绘画消息
	afx_msg void OnPaint();
	//点击消息
	afx_msg LRESULT OnNcHitTest(CPoint point);
	//鼠标按下
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	//窗口尺寸
	afx_msg void OnSize(UINT nType, int cx, int cy);

	//静态函数
protected:
	//枚举函数
	static BOOL CALLBACK EnumChildProc(HWND hWndChild, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

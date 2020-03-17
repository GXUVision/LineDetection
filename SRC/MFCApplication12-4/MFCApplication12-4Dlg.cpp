
// MFCApplication12-4Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication12-4.h"
#include "MFCApplication12-4Dlg.h"
#include "afxdialogex.h"

#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp" 
#include <cv.h> 
#include <highgui.h> 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "windows.h"  
#include "WinCVMat.h" 

//#include "Base.h"                     
//#include "ImagePreprocess.h"
//#include "LineletExtaction.h"
//#include "PathExtaction.h"
//#include "LineDetection.h"
//#include "CannyPF.h"
//#include "ChainFromEdgeMap.h"
//#include "QuickSort.h"
#include "all.h"                         //封装的库的头文件；已经将该库的头文件放置MFCApplication12-4Dlg.cpp同级目录下

#pragma comment(lib,"WinCVMat_x64.lib")  //32位的是WinCVMat.lib，64位的是WinCVMat_x64.lib；_x64作为区别；

#pragma comment(lib, "LIBcreation.lib")  //封装的库；已经将该库文件放置MFCApplication12-4Dlg.cpp同级目录下，故“链接器-常规-附加库目录”中包含它；


#ifdef _DEBUG                 
#define new DEBUG_NEW

#pragma comment(lib,"opencv_core2413d.lib") //d.lib是debug模式使用 ，.lib是release模式使用；
#pragma comment(lib,"opencv_highgui2413d.lib") 
#pragma comment(lib,"opencv_imgproc2413d.lib") 
#pragma comment(lib,"opencv_features2d2413d.lib") 
#pragma comment(lib,"opencv_calib3d2413d.lib") 
#pragma comment(lib,"opencv_video2413d.lib") 
#pragma comment(lib,"opencv_videostab2413d.lib") 
#pragma comment(lib,"opencv_objdetect2413d.lib") 
#else 
#pragma comment(lib,"opencv_core2413.lib") 
#pragma comment(lib,"opencv_highgui2413.lib") 
#pragma comment(lib,"opencv_imgproc2413.lib") 
#pragma comment(lib,"opencv_features2d2413.lib") 
#pragma comment(lib,"opencv_calib3d2413.lib") 
#pragma comment(lib,"opencv_video2413.lib") 
#pragma comment(lib,"opencv_videostab2413.lib") 
#pragma comment(lib,"opencv_objdetect2413.lib")

#endif

using namespace cv; 
using namespace std;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication124Dlg 对话框



CMFCApplication124Dlg::CMFCApplication124Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication124Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication124Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlButton1);
	DDX_Control(pDX, IDC_PIC1, m_ctrlPic1);
	DDX_Control(pDX, IDC_BUTTON2, m_ctrlButton2);
	DDX_Control(pDX, IDC_BUTTON3, m_ctrlButton3);
	DDX_Control(pDX, IDC_BUTTON4, m_ctrlButton4);
	DDX_Control(pDX, IDC_PIC2, m_ctrlPic2);
	DDX_Control(pDX, IDC_PIC3, m_ctrlPic3);
	DDX_Control(pDX, IDC_PIC4, m_ctrlPic4);
	DDX_Control(pDX, IDC_PIC5, m_ctrlPic5);
	DDX_Control(pDX, IDC_BUTTON5, m_ctrlButton5);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlCombo1);
}

BEGIN_MESSAGE_MAP(CMFCApplication124Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication124Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication124Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication124Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication124Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication124Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCApplication124Dlg 消息处理程序

BOOL CMFCApplication124Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
		CString csDirPath;
	csDirPath = "./TestPic//*.bmp";
	HANDLE file;
	WIN32_FIND_DATA fileData;
	char line[1024];
	char fn[1000];
	//mbstowcs(fn,csDirPath.GetBuffer(),999);  
	file = FindFirstFile(csDirPath.GetBuffer(), &fileData);

	m_ctrlCombo1.InsertString(0, fileData.cFileName);

	bool bState = false;
	bState = FindNextFile(file, &fileData);

	int ii = 1;
	while (bState){
		//wcstombs(line,(const char*)fileData.cFileName,259);  
		m_ctrlCombo1.InsertString(ii, fileData.cFileName);
		ii++;
		bState = FindNextFile(file, &fileData);
	}
	m_ctrlCombo1.SetCurSel(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication124Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication124Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication124Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

Mat f_dst, f_dst1, f_dst2, f_dst3, f_dst4;   //全局变量，作为函数间的传递变量；分别存储原图，预处理图，线基元提取图，初始路径提取图，直线提取图；

void CMFCApplication124Dlg::OnBnClickedButton5()  //原图
{
	// TODO:  在此添加控件通知处理程序代码
	int PicNo = m_ctrlCombo1.GetCurSel();
	CString s;
	m_ctrlCombo1.GetLBText(PicNo, s);

	int len = WideCharToMultiByte(CP_ACP, 0, s, -1, NULL, 0, NULL, NULL);
	char* name = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, s, -1, name, len, NULL, NULL);
	name = str(".//TestPic//", name);
	src = imread(name, 1);
	f_dst = src;

	ShowCVMat(m_ctrlPic5, f_dst, 0, 255, 1);
}


void CMFCApplication124Dlg::OnBnClickedButton1()  //预处理图
{
	// TODO:  在此添加控件通知处理程序代码
	if (!f_dst.data)
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("图像加载失败,请先获取原图像"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
	else
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("预处理中"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
		f_dst1 = ImagePreprocess(f_dst);
		ShowCVMat(m_ctrlPic1, f_dst1, 0, 255, 1);
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("预处理完成"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}

}


void CMFCApplication124Dlg::OnBnClickedButton2()  //线基元提取图
{
	// TODO:  在此添加控件通知处理程序代码
	if (!f_dst1.data)
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("图像加载失败,请先获取预处理图像"));  
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}	
	else
	{	
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("边缘块提取中"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
		f_dst2 = LineletExtaction(f_dst1);
		ShowCVMat(m_ctrlPic2, f_dst2, 0, 255, 1);
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("边缘块提取完成"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
}


void CMFCApplication124Dlg::OnBnClickedButton3()  //初始路径提取图
{
	// TODO:  在此添加控件通知处理程序代码
	if (!f_dst2.data)
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("图像加载失败,请先获取线基元提取图像"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
	else
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("路径提取中"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
		f_dst3 = PathExtraction(f_dst2);
		ShowCVMat(m_ctrlPic3, f_dst3, 0, 255, 1);
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("路径提取完成"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
}


void CMFCApplication124Dlg::OnBnClickedButton4()  //直线提取图
{
	// TODO:  在此添加控件通知处理程序代码
	if (!f_dst3.data)
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("图像加载失败,请先获取初始路径提取图像"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
	else
	{
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("直线提取中"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
		f_dst4 = GetLine(f_dst3);
		ShowCVMat(m_ctrlPic4, f_dst4, 0, 255, 1);
		m_ctrlList1.ResetContent();
		m_ctrlList1.AddString(_T("直线提取完成"));
		m_ctrlList1.SetCurSel(m_ctrlList1.GetCount() - 1);
	}
}





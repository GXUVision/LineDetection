#ifndef Base_H
#define Base_H

//#include "CannyPF.h"
//#include "ChainFromEdgeMap.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shlwapi.h"
#include <math.h> 
#include <cxcore.h>
#include <cv.h>
#include <cvaux.h>
#include <fstream>
#include <vector>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/opencv_modules.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/opencv_modules.hpp"

using namespace cv;
using namespace std;

////////ͼ��Ԥ����ı���//////////////////////////////////////
extern Mat src1;
extern Mat src;
extern Mat dst;
extern Mat gray;
extern float VMGradient;

////////�߻�Ԫ��ȡ�ı���//////////////////////////////////////
extern vector<vector<int>> LB1; // �����ֵ�б�
extern vector<vector<int>> LB2; // �����ֵ�б�
extern vector<vector<int>> LB3; // �������б�
extern vector<vector<int>> LE;      // ����߻�Ԫ
extern vector<vector<int>> AdjMat;  //�ڽӾ���

////////·����ȡ�ı���//////////////////////////////////////
extern vector<vector<int>> result;  //�������·��
extern vector<vector<int>> resultLinePath; //���·����ɸѡ��ֱ��
extern vector<vector<int>> resultCurvePath; //���·����ɸѡ������
extern vector<vector<float>> LineLenth; //���Գ���


////////ֱ����ȡ�ı���//////////////////////////////////////
//extern vector<vector<int>> SinglePath;   //�����߻�Ԫ·��

extern vector<vector<int>> Path;         //����
extern vector<vector<int>> Path1;
extern vector<vector<int>> OtherPathTest;    //��ֻ����߻�Ԫ·��
//
extern vector<vector<int>> adjValue;//����ֵ
extern vector<vector<int>> adjValue1;//����ֵ
extern vector<vector<int>> adjValue2;//����ֵ
//extern vector<vector<int>> lineTransition;//��������ֵ

extern vector<vector<int>> LinePath;     //ֱ���߻�Ԫ·��
extern vector<vector<int>> CurvePath;     //ֱ���߻�Ԫ·��
extern vector<vector<float>> Distance;    //��������ϵĵ㵽�����ߵľ���
extern vector<vector<int>> Index;   //��������ϵĵ㵽�����ߵľ�����
extern vector<vector<int>> Length;
extern Point X1, X2;
//extern vector<bool> lineAngle;        //��ŽǶ��Ƿ���0,90,180





// ���ܣ�ƴ���ַ�����
// ���룺p1 - ��ƴ�ӵ��ַ�����p2 - ��ƴ�ӵ��ַ�����
// �����ƴ�Ӻõ��ַ�����
char *str(char *p1, char *p2);


// ���ܣ�����ά��ͨ�����鰴���б���Ϊ�ı��ļ�������������MATLAB�н�һ��������
// ���룺str_src - �ı��ļ�����PA - Դ���顣
// ���������д���ı��ļ���
// ˵�����ı��ļ���һ��Ϊ�����һ�У�һ�������ö��ŷָ�����ʽ���£�
//       ��һ��ͨ��1����һ��ͨ��2��...����һ��ͨ��K���ڶ���ͨ��1��...����N��ͨ��K��
int saveVectoText(char* str_src, vector<vector<Point3f>> PA);
int saveVectoText(char* str_src, vector<vector<int>> plain);
int saveVectoText(char* str_src, vector<vector<float>> plain);

int saveVectoText4c(char* str_src, vector<vector<int>> plain);
int saveVectoText4c(char* str_src, vector<vector<float>> plain);

// ���ܣ�����ת������Mat���͵ı���ת��ΪVector��
// ���룺src - ��ת����Mat���ݡ�
// �����src_vec - ת����Vector�� 
vector<vector<int>> mat2vec(Mat src);

// ���ܣ�����ת������Vector���͵ı���ת��ΪMat��
// ���룺 src_vec - ��ת����Vector���ݡ�
// ����� src - ת����Mat�� 
Mat vec2mat(vector<vector<int>> src_vec);
Mat vec2mat(vector<vector<float>> src_vec);


// ���ܣ������ɫ��
// ���룺 rng 
Scalar random_color(RNG& _rng);

// ���ܣ����߶ζ˵���Ƽ�ͷ�����߻�Ԫ���Ƴ�����
// ���룺 img - ���Ƶ�ͼ��pStart - ��ʼ�㡣pEnd - �յ㡣len - ��ͷ���ȡ�
//        alpha - ��ͷ����ϵ����color - ��ͷ��ɫ��thickness - ��ȡ� 
//       lineType - �߶ε����͡�ȡֵΪ8,4��CV_AA��8��ʾ�ڽ������ߣ�4��ʾ�ڽ������ߺ�CV_AA��ʾ����������ߡ�Ĭ��ֵΪ8�ڽӡ�
// ����� ���Ƽ�ͷ�� 
void drawArrow(Mat& img, Point pStart, Point pEnd, int len, int alpha, Scalar& color, int thickness, int lineType);


// ���ܣ���ֵ֮��ȡ��С��
// ���룺 first - ���Ƚϵ�ֵ1�� second - ���Ƚϵ�ֵ2��
// ����������Ƚ�ֵ����С����ֵ��
int Getmin(int first, int second);

#endif 
//Base.h����

//CannyPF.h��ʼ
#ifndef _CANNY_PY_H_
#define _CANNY_PY_H_
#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

class CannyPF
{
public:
	CannyPF(void);
	~CannyPF(void);

	void cannyPF(cv::Mat &image, int gausHalfSize, float VMGradient, cv::Mat &edgeMap);

};
#endif //_CANNY_PY_H_
//Canny.h����



//ChainFromEdgeMap.h��ʼ
#ifndef _EDGE_CHAIN_
#define _EDGE_CHAIN_
#pragma once

#include "opencv/cv.h"
#include "highgui.h"

using namespace std;
using namespace cv;

#ifndef mmax
#define mmax(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef mmin
#define mmin(a,b)            (((a) < (b)) ? (a) : (b))
#endif


class ChainFromEdgeMap
{
public:
	ChainFromEdgeMap();
	~ChainFromEdgeMap();

	void run(cv::Mat &image, cv::Mat &edgeMap, std::vector<std::vector<cv::Point> > &edgeChain);

	bool next(int &xSeed, int &ySeed);

private:
	cv::Mat gradientMap;
	cv::Mat maskImage;
	cv::Mat orientationMap;
};

#endif // _PLINKAGE_SUPERPIXEL_
//ChainFromEdgeMap.h����






//ImagePreprocess.h��ʼ

#ifndef ImagePreprocess_H
#define ImagePreprocess_H

//#include "Base.h"

// ���ܣ���ȡͼ��ı�Ե�����������㷨CannyPF��
// ���룺dst - �������ͼ��
// �����CannyImg - ��ȡ��ɵĵ�ͨ��ͼ��
// ˵����CannyPF�㷨��֤����ȡ��������α��
void Canny(/*Mat dst*/);


// ���ܣ��Ա�Ե���������޼�����֤���ߵĿ��Ϊ��һ���ء�
// ���룺dst - �������ͼ��
// �����tailor - �޼����ͼ��
void Tailor(/*Mat dst*/);

// ����:ͼ��Ԥ����
Mat ImagePreprocess(Mat src);
#endif 
//ImagePreprocess.h����




//LineDetection.h��ʼ
#ifndef LineDetection_H
#define LineDetection_H
//#include "Base.h"

// ���ܣ���������·���ϵĵ㵽�������߶εľ��룬���������򣬵õ���ǰ��·����������ֵ��
// ���룺result - ·�����ϡ�
// �����Distance - ����·���ľ���ֵ������������ʽ�Ӵ�С��Index - ����·���ľ���ֵ��ţ���Ŷ�Ӧ���ǵ�ǰ·�����߻�Ԫλ�ã���
void GetDistance(vector<vector<int>> result, vector<vector<float>> &Distance, vector<vector<int>> &Index);

//
// ���ܣ����������߻�Ԫ���ȡ�
// ���룺result - ·�����ϡ�
// �����Length - �����߻�Ԫ���ȡ�
void GetLinenetLength(vector<vector<int>> result, vector<vector<int>> &Length);


// ���ܣ����һ�����ߣ��������Ͼ�����ֵ�����߰�����������ֳ����Ρ�
// ���룺OtherPath- ����������߼��ϡ�
void linesplit(vector<vector<int>> &OtherPath);


// ���ܣ��жϲ����ɵ������Ƿ���Ͼ�����ֵ��
// ���룺OtherPath - �Ѿ����������߼��ϡ�
// ˵�����Բ��������߽��о�����ֵ�жϣ����������Ϊֱ�ߣ����������������еȴ���һ�β��
void LineExtraction(vector<vector<int>> &OtherPath);


// ���ܣ�����ѭ����֡�����������ֵ��������������������Σ��ж��Ƿ���Ͼ�����ֵ�����Ϲ�Ϊֱ�ߣ�����������������ѭ�����
// ���룺result - �������·�����ϡ�
void CurveDecomposition(vector<vector<int>> &result);
int CurveDecompositionTest(vector<vector<int>> &result, int num);

// ���ܣ�ȥ���ظ�·����
// ���룺LinePath - �������·�����ϡ�
// ˵�����ڽ��������߲��������֣�һ���߻�Ԫ�����ڶ���·�������ｫ�ظ��Ĳ���ɾ����
void RemoveRepeat(vector<vector<int>> &LinePath);

// ���ܣ���ȡֱ�ߡ�
// ���룺dst - �������ͼ��
// �����CannyImg - ��ȡ��ɵĵ�ͨ��ͼ��
// ˵����CannyPF�㷨��֤����ȡ��������α��
Mat GetLine(Mat src);

#endif 
//LineDetection.h����







//LineletExtacion.h��ʼ

#ifndef LineletExtaction_H
#define LineletExtaction_H

//#include "Base.h"

// ���ܣ��������ֵ���������б�ֱ��ע������
// ���룺dst - ����ͼ��
// �����LB1 - �����ֵ��ע����LB2 - �����ֵ��ע����LB3 - �����Ǳ�ע����
void label(Mat dst);

// ���ܣ����ݱ�ע������ȡ�߻�Ԫ��
// ���룺LB1 - �����ֵ��ע����LB2 - �����ֵ��ע����LB3 - �����Ǳ�ע����
// �����LE - �߻�Ԫ�������
//       LE[Num][0]��ʾ��Num���߻�Ԫ���ĺ����꣨X��,LE[Num][1]��ʾ��Num���߻�Ԫ���������꣨Y��
//       LE[Num][0]��ʾ��Num���߻�Ԫ�յ�ĺ����꣨X��,LE[Num][1]��ʾ��Num���߻�Ԫ�յ�������꣨Y��
void GetLinelet(vector<vector<int>> LB1, vector<vector<int>> LB2, vector<vector<int>> LB3);

// ����:�߻�Ԫ��ȡ
Mat LineletExtaction(Mat src);

#endif 
//LineletExtaction.h����







//PathExtaction.h��ʼ
#ifndef PathExtaction_H
#define PathExtaction_H

//#include "Base.h"

/* �����ڽӾ����������·�� */

// ���ܣ������߻�Ԫ��������ȡ�ڽӾ���
// ���룺LE - �߻�Ԫ�������
// �����AdjMat - �ڽӾ���
void GetAdjMax(vector<vector<int>> LE);

// ���ܣ�������������㷨�������ڽӾ����ȡ·��
// ���룺AdjMat - �ڽӾ���
// �����resultPath - ԭʼ·������
//      resultPath[Num]��ʾ��Num��·����ÿ��·���д洢�����߻�Ԫ��ţ���resultPath[Num][i]��ʾ��Num��·����i���߻�Ԫ�ı�š�
//˵����������������㷨�������ƣ��õ������ߴ������⣬��һ�����߱���Ϊ������������Ҫ�޲�
int adj_search_branch(vector<vector<int>> adj, vector<vector<int>> &result);

// ���ܣ���ȡԭʼ·������
// ���룺resultPath - ԭʼ·������
// �����result - ·������
void GetPath();

// ���ܣ�·����ȡ��
Mat PathExtraction(Mat src);

#endif
//PathExtaction.h����






//QuickSort.h��ʼ
#if !defined(_QUICK_SORT_H_)
#define _QUICK_SORT_H_
#include "stdio.h"
template <class TD, class TI>		/* class TD - the type of sorted data, class TI - the type of indices */
class QuickSort
{
public:
	/* sort everything inbetween `low' <-> `high' */
	static void SortDescent(TD *pData, long low, long high, TI* pIdxes)
	{
		long i = low;
		long j = high;
		TD y = 0;
		TI idx;

		/* compare value */
		TD z = pData[(low + high) / 2];

		/* partition */
		do {
			/* find member below ... */
			while (pData[i] > z) i++;

			/* find element above ... */
			while (pData[j] < z) j--;

			if (i <= j) {
				/* swap two elements */
				y = pData[i];
				pData[i] = pData[j];
				pData[j] = y;

				idx = (pIdxes)[i];
				(pIdxes)[i] = (pIdxes)[j];
				(pIdxes)[j] = idx;

				i++;
				j--;
			}
		} while (i <= j);

		/* recurse */
		if (low < j)
			SortDescent(pData, low, j, pIdxes);

		if (i < high)
			SortDescent(pData, i, high, pIdxes);
	};
};

#endif // !defined(_QUICK_SORT_H_)
//QuickSort.h����
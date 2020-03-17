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

////////图像预处理的变量//////////////////////////////////////
extern Mat src1;
extern Mat src;
extern Mat dst;
extern Mat gray;
extern float VMGradient;

////////线基元提取的变量//////////////////////////////////////
extern vector<vector<int>> LB1; // 邻域差值判别
extern vector<vector<int>> LB2; // 邻域差值判别
extern vector<vector<int>> LB3; // 特征角判别
extern vector<vector<int>> LE;      // 存放线基元
extern vector<vector<int>> AdjMat;  //邻接矩阵

////////路径提取的变量//////////////////////////////////////
extern vector<vector<int>> result;  //存放线条路径
extern vector<vector<int>> resultLinePath; //存放路径中筛选的直线
extern vector<vector<int>> resultCurvePath; //存放路径中筛选的曲线
extern vector<vector<float>> LineLenth; //绝对长度


////////直线提取的变量//////////////////////////////////////
//extern vector<vector<int>> SinglePath;   //单个线基元路径

extern vector<vector<int>> Path;         //折线
extern vector<vector<int>> Path1;
extern vector<vector<int>> OtherPathTest;    //拆分缓存线基元路径
//
extern vector<vector<int>> adjValue;//距离值
extern vector<vector<int>> adjValue1;//距离值
extern vector<vector<int>> adjValue2;//距离值
//extern vector<vector<int>> lineTransition;//正负跳变值

extern vector<vector<int>> LinePath;     //直线线基元路径
extern vector<vector<int>> CurvePath;     //直线线基元路径
extern vector<vector<float>> Distance;    //存放线条上的点到连接线的距离
extern vector<vector<int>> Index;   //存放线条上的点到连接线的距离编号
extern vector<vector<int>> Length;
extern Point X1, X2;
//extern vector<bool> lineAngle;        //存放角度是否是0,90,180





// 功能：拼接字符串。
// 输入：p1 - 待拼接的字符串。p2 - 待拼接的字符串。
// 输出：拼接好的字符串。
char *str(char *p1, char *p2);


// 功能：将二维多通道数组按照行保存为文本文件。这样便于在MATLAB中进一步分析。
// 输入：str_src - 文本文件名。PA - 源数组。
// 输出：数据写入文本文件。
// 说明：文本文件的一行为数组的一行，一行数据用逗号分隔，格式如下：
//       第一列通道1，第一列通道2，...，第一列通道K，第二列通道1，...，第N列通道K。
int saveVectoText(char* str_src, vector<vector<Point3f>> PA);
int saveVectoText(char* str_src, vector<vector<int>> plain);
int saveVectoText(char* str_src, vector<vector<float>> plain);

int saveVectoText4c(char* str_src, vector<vector<int>> plain);
int saveVectoText4c(char* str_src, vector<vector<float>> plain);

// 功能：类型转换。将Mat类型的变量转换为Vector。
// 输入：src - 待转换的Mat数据。
// 输出：src_vec - 转换的Vector。 
vector<vector<int>> mat2vec(Mat src);

// 功能：类型转换。将Vector类型的变量转换为Mat。
// 输入： src_vec - 待转换的Vector数据。
// 输出： src - 转换的Mat。 
Mat vec2mat(vector<vector<int>> src_vec);
Mat vec2mat(vector<vector<float>> src_vec);


// 功能：随机颜色。
// 输入： rng 
Scalar random_color(RNG& _rng);

// 功能：在线段端点绘制箭头。将线基元绘制出来。
// 输入： img - 绘制的图像。pStart - 起始点。pEnd - 终点。len - 箭头长度。
//        alpha - 箭头方向系数。color - 箭头颜色。thickness - 宽度。 
//       lineType - 线段的类型。取值为8,4，CV_AA。8表示邻接连接线，4表示邻接连接线和CV_AA表示反锯齿连接线。默认值为8邻接。
// 输出： 绘制箭头。 
void drawArrow(Mat& img, Point pStart, Point pEnd, int len, int alpha, Scalar& color, int thickness, int lineType);


// 功能：两值之间取最小。
// 输入： first - 带比较的值1。 second - 带比较的值2。
// 输出：两个比较值中最小的数值。
int Getmin(int first, int second);

#endif 
//Base.h结束

//CannyPF.h开始
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
//Canny.h结束



//ChainFromEdgeMap.h开始
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
//ChainFromEdgeMap.h结束






//ImagePreprocess.h开始

#ifndef ImagePreprocess_H
#define ImagePreprocess_H

//#include "Base.h"

// 功能：提取图像的边缘轮廓。引用算法CannyPF。
// 输入：dst - 待处理的图像。
// 输出：CannyImg - 提取完成的单通道图像。
// 说明：CannyPF算法验证了提取轮廓的真伪。
void Canny(/*Mat dst*/);


// 功能：对边缘轮廓进行修剪，保证曲线的宽度为单一像素。
// 输入：dst - 待处理的图像。
// 输出：tailor - 修剪完的图像。
void Tailor(/*Mat dst*/);

// 功能:图像预处理
Mat ImagePreprocess(Mat src);
#endif 
//ImagePreprocess.h结束




//LineDetection.h开始
#ifndef LineDetection_H
#define LineDetection_H
//#include "Base.h"

// 功能：计算所有路径上的点到其理想线段的距离，并进行排序，得到当前的路径的最大距离值。
// 输入：result - 路径集合。
// 输出：Distance - 所有路径的距离值（已排序，排序方式从大到小）Index - 所有路径的距离值编号（编号对应的是当前路径的线基元位置）。
void GetDistance(vector<vector<int>> result, vector<vector<float>> &Distance, vector<vector<int>> &Index);

//
// 功能：计算所有线基元长度。
// 输入：result - 路径集合。
// 输出：Length - 所有线基元长度。
void GetLinenetLength(vector<vector<int>> result, vector<vector<int>> &Length);


// 功能：拆分一次曲线，将不符合距离阈值的曲线按照最大距离点拆分成两段。
// 输入：OtherPath- 待处理的曲线集合。
void linesplit(vector<vector<int>> &OtherPath);


// 功能：判断拆分完成的曲线是否符合距离阈值。
// 输入：OtherPath - 已经拆分完的曲线集合。
// 说明：对拆分完的曲线进行距离阈值判断，符合则归类为直线，不符合留在容器中等待下一次拆分
void LineExtraction(vector<vector<int>> &OtherPath);


// 功能：曲线循环拆分。将不符合阈值的曲线以最大距离点拆成两段，判断是否符合距离阈值，符合归为直线，不符合留在容器中循环拆分
// 输入：result - 待处理的路经集合。
void CurveDecomposition(vector<vector<int>> &result);
int CurveDecompositionTest(vector<vector<int>> &result, int num);

// 功能：去除重复路径。
// 输入：LinePath - 待处理的路经集合。
// 说明：在将所有曲线拆分完后会出现，一个线基元存在于多条路径，这里将重复的部分删除。
void RemoveRepeat(vector<vector<int>> &LinePath);

// 功能：提取直线。
// 输入：dst - 待处理的图像。
// 输出：CannyImg - 提取完成的单通道图像。
// 说明：CannyPF算法验证了提取轮廓的真伪。
Mat GetLine(Mat src);

#endif 
//LineDetection.h结束







//LineletExtacion.h开始

#ifndef LineletExtaction_H
#define LineletExtaction_H

//#include "Base.h"

// 功能：用邻域差值和特征角判别分别标注轮廓。
// 输入：dst - 轮廓图像。
// 输出：LB1 - 邻域差值标注矩阵。LB2 - 邻域差值标注矩阵。LB3 - 特征角标注矩阵。
void label(Mat dst);

// 功能：根据标注矩阵提取线基元。
// 输入：LB1 - 邻域差值标注矩阵。LB2 - 邻域差值标注矩阵。LB3 - 特征角标注矩阵。
// 输出：LE - 线基元坐标矩阵。
//       LE[Num][0]表示第Num个线基元起点的横坐标（X）,LE[Num][1]表示第Num个线基元起点的纵坐标（Y）
//       LE[Num][0]表示第Num个线基元终点的横坐标（X）,LE[Num][1]表示第Num个线基元终点的纵坐标（Y）
void GetLinelet(vector<vector<int>> LB1, vector<vector<int>> LB2, vector<vector<int>> LB3);

// 功能:线基元提取
Mat LineletExtaction(Mat src);

#endif 
//LineletExtaction.h结束







//PathExtaction.h开始
#ifndef PathExtaction_H
#define PathExtaction_H

//#include "Base.h"

/* 输入邻接矩阵，输出所有路径 */

// 功能：根据线基元坐标矩阵获取邻接矩阵。
// 输入：LE - 线基元坐标矩阵。
// 输出：AdjMat - 邻接矩阵。
void GetAdjMax(vector<vector<int>> LE);

// 功能：深度优先搜索算法。根据邻接矩阵获取路径
// 输入：AdjMat - 邻接矩阵。
// 输出：resultPath - 原始路径矩阵。
//      resultPath[Num]表示第Num条路径。每条路径中存储的是线基元编号，即resultPath[Num][i]表示第Num条路径第i个线基元的编号。
//说明：由于深度优先算法不够完善，得到的曲线存在问题，即一条曲线被分为两条，所以需要修补
int adj_search_branch(vector<vector<int>> adj, vector<vector<int>> &result);

// 功能：获取原始路径矩阵。
// 输入：resultPath - 原始路径矩阵。
// 输出：result - 路径矩阵。
void GetPath();

// 功能：路径提取。
Mat PathExtraction(Mat src);

#endif
//PathExtaction.h结束






//QuickSort.h开始
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
//QuickSort.h结束
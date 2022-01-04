#include "stdafx.h"
#include "坦克大战系列Dlg.h"

void C坦克大战系列Dlg::CG_Draw(int k)
{
	//采用15帧
	static int is_start = 0;
	static int x_d = 10;
	static int y_d = 20;


	
	//使用opencv Capture技术
	/*
	static CvCapture* pCapture = NULL;
	IplImage* pFrame = NULL;
	if(k == 0 && !is_start)
	{
		pCapture = cvCreateFileCapture("cg.mov");
	}

	pFrame = cvQueryFrame(pCapture);
	if(NULL == pFrame)// 循环播放
	{
		cvReleaseCapture(&pCapture);
		pCapture = cvCreateFileCapture("cg.mov");
		pFrame = cvQueryFrame(pCapture);
	}
	pFrame = cvQueryFrame(pCapture);
	if(NULL == pFrame)// 循环播放
	{
		cvReleaseCapture(&pCapture);
		pCapture = cvCreateFileCapture("cg.mov");
		pFrame = cvQueryFrame(pCapture);
	}


	IplImage* mirror;
	//= cvCreateImage(cvSize(pFrame->width,pFrame->height),pFrame->depth,pFrame->nChannels);
	mirror = cvCloneImage(pFrame);
	cvFlip(pFrame, mirror, 0); // 必须要使用两张图像





	HDC hDC = ::CreateCompatibleDC(0);
	BYTE tmp[sizeof(BITMAPINFO)+255*4];
	BITMAPINFO* bmi = (BITMAPINFO*)tmp;
	HBITMAP hBmp;
	int i;
	memset(bmi,0,sizeof(BITMAPINFO));
	bmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi->bmiHeader.biWidth = mirror->width;
	bmi->bmiHeader.biHeight = mirror->height;
	bmi->bmiHeader.biPlanes = 1;
	bmi->bmiHeader.biBitCount = mirror->nChannels * mirror->depth;
	bmi->bmiHeader.biCompression = BI_RGB;
	bmi->bmiHeader.biSizeImage = mirror->width*mirror->height*1;
	bmi->bmiHeader.biClrImportant =0 ;
	switch(mirror->nChannels * mirror->depth)
	{
		case 8 :
		for(i=0 ; i < 256 ; i++)
		{
			bmi->bmiColors[i].rgbBlue = i;
			bmi->bmiColors[i].rgbGreen= i;
			bmi->bmiColors[i].rgbRed= i;
		}
		break;
		case 32:
		case 24:
			((DWORD*) bmi->bmiColors)[0] = 0x00FF0000;  
			((DWORD*) bmi->bmiColors)[1] = 0x0000FF00;
			((DWORD*) bmi->bmiColors)[2] = 0x000000FF;
		break;
	}
	hBmp = ::CreateDIBSection(hDC,bmi,DIB_RGB_COLORS,NULL,0,0); 
	SetDIBits(hDC,hBmp,0,mirror->height,mirror->imageData,bmi,DIB_RGB_COLORS); 
	::DeleteDC(hDC);
	



	tempDC.SelectObject(hBmp);
	::SetStretchBltMode(spDC->m_hDC, HALFTONE);

	
	//old_font = spDC->SelectObject(&ftitle);

	spDC->StretchBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &tempDC, 0, 0, mirror->width, mirror->height, SRCCOPY);

	spDC->SetBkMode(TRANSPARENT);

	cvReleaseImage(&mirror);
	//cvReleaseImage(&pFrame);

	*/
	
	//不使用opencv做视频：
	CString pic_name;
	pic_name.Format("CG//%d.jpg", k);
	CImage img;
	img.Load(pic_name);
	img.StretchBlt(spDC->m_hDC, CRect(CPoint(0, 0), CPoint(1900, 1080)), CRect(CPoint(0, 0), CPoint(1080, 608)), SRCCOPY);


	int p_x = 490;
	spDC->SetTextColor(RGB(0, 0, 0));
	spDC->SelectObject(&ftitle);
	spDC->TextOutA(867 + x_d, 200 + y_d, "坦克大战");
	spDC->SelectObject(&fbig);
	spDC->TextOutA(p_x - 4 + x_d, 330 + y_d, "    资料片1 奥托卡尔乌斯-泥泞中的老虎");
	spDC->TextOutA(p_x - 4 + x_d, 430 + y_d, "       第一次进入游戏请按P加载教程");
	spDC->TextOutA(p_x - 4 + x_d, 530 + y_d, "开始之前请按E N H 选择难度(easy normal hard)");
	spDC->TextOutA(p_x - 4 + x_d, 630 + y_d, " 为了避免出现铁锅炖萌新 第一次不建议玩困难");
	spDC->SelectObject(&ftitle);
	spDC->TextOutA(506 + x_d, 730 + y_d, "  准备好了按Enter开始");



	spDC->SetTextColor(RGB(255, 255, 255));
	spDC->SelectObject(&ftitle);
	spDC->TextOutA(870 + x_d, 200 + y_d, "坦克大战");
	spDC->SelectObject(&fbig);
	spDC->TextOutA(p_x + x_d, 330 + y_d, "    资料片1 奥托卡尔乌斯-泥泞中的老虎");
	spDC->TextOutA(p_x + x_d, 430 + y_d, "       第一次进入游戏请按P加载教程");
	spDC->TextOutA(p_x + x_d, 530 + y_d, "开始之前请按E N H 选择难度(easy normal hard)");
	spDC->TextOutA(p_x + x_d, 630 + y_d, " 为了避免出现铁锅炖萌新 第一次不建议玩困难");
	spDC->SelectObject(&ftitle);
	spDC->TextOutA(510 + x_d, 730 + y_d, "  准备好了按Enter开始");

	spDC->SetTextColor(RGB(0, 0, 0));
	spDC->SelectObject(&f);


	//加logo
	pictureDC.SelectObject(&logo);
	spDC->TransparentBlt(650, 120, 201, 232, &pictureDC, 0, 0, 402, 464, RGB(255, 255, 255)); 




	//加上视角风格
	pictureDC.SelectObject(&main_hor_bkg);
	BLENDFUNCTION blendFunction;
	memset( &blendFunction, 0, sizeof(blendFunction) );
	blendFunction.BlendOp = AC_SRC_OVER;
	blendFunction.BlendFlags = 0;
	blendFunction.SourceConstantAlpha = 96;
	supportDC.AlphaBlend(0, 0, 1900, 1040, &pictureDC, 0,0, 1500, 1000, blendFunction);

	


	//pDC->BitBlt(0, 0, 1500, 1000, &blackBackDC, 0, 0, SRCCOPY);




#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1267, 693, spDC, 0, 0, 1900, 1040, SRCCOPY);
#else
	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, spDC, x_d, y_d, SRCCOPY);
#endif





	//DeleteObject(hBmp);

	
	is_start = 1;

}
//61

void C坦克大战系列Dlg::Openning_Draw(int k)
{

	
	supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, RGB(0 ,0, 0));

	static char info1[50] = "All that is gold does not glitter";
	static char info2[50] = "Not all those who wander are lost";
	static char info3[50] = "The old that is strong does not wither";
	static char info4[50] = "Deep roots are not reached by the frost";
	//static char info5[30] = "DrawnBreaks Work Studio";

	static int len1 = strlen(info1);
	static int len2 = len1 + strlen(info2);
	static int len3 = len2 + strlen(info3);
	static int len4 = len3 + strlen(info4);

	//int len5 = len4 + strlen(info5);
	static int index1 = 0;
	static int index2 = 0;
	static int index3 = 0;
	static int index4 = 0;

	static CString sw1 = "";
	static CString sw2 = "";
	static CString sw3 = "";
	static CString sw4 = "";
	static CString sw5 = "";

	int c_k = k;

	if(c_k < len1)
	{
		sw1 += info1[c_k];
		index1 = c_k * 100 / len1;

	}
	else if(c_k < len2)
	{
		sw2 += info2[c_k - len1];
		index2 = (c_k - len1) * 100 / (len2 - len1); 
	}
	else if(c_k < len3)
	{
		sw3 += info3[c_k - len2];
		index3 = (c_k - len2) * 100 / (len3 - len2);
	}
	else if(c_k < len4)
	{
		sw4 += info4[c_k - len3];
		index4 = (c_k - len3) * 100 / (len4 - len3);
	}
	/*
	else if(c_k < len5)
		sw5 += info5[c_k - len4];
		*/


	supportDC.SetTextColor(RGB(128 * index1 / 100, 101 * index1 / 100, 7 * index1 / 100));
	supportDC.TextOutA(215, 200, sw1);
	supportDC.SetTextColor(RGB(255 * index1 / 100, 201 * index1 / 100, 14 * index1 / 100));
	supportDC.TextOutA(220, 200, sw1);

	supportDC.SetTextColor(RGB(128 * index2 / 100, 128 * index2 / 100, 128 * index2 /100));
	supportDC.TextOutA(215, 300, sw2);
	supportDC.SetTextColor(RGB(255 * index2 / 100, 255 * index2 / 100, 255 * index2 /100));
	supportDC.TextOutA(220, 300, sw2);

	supportDC.SetTextColor(RGB(128 * index3 / 100, 128 * index3 / 100, 0));
	supportDC.TextOutA(215, 400, sw3);
	supportDC.SetTextColor(RGB(255 * index3 / 100, 255 * index3 / 100, 0));
	supportDC.TextOutA(220, 400, sw3);

	supportDC.SetTextColor(RGB(34 * index4 / 100, 100 * index4 / 100, 128 * index4 / 100));
	supportDC.TextOutA(215, 500, sw4);
	supportDC.SetTextColor(RGB(68 * index4 / 100, 199 * index4 / 100, 255 * index4 / 100));
	supportDC.TextOutA(220, 500, sw4);

	/*
	supportDC.SetTextColor(RGB(255, 201, 14));
	supportDC.TextOutA(300, 600, sw5);
	*/

	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);


}


void C坦克大战系列Dlg::Ending_Draw(int k)
{


	supportDC.SelectObject(&ftitle);
	supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, RGB(0 ,0, 0));

	
	char ending_infor[37][60] = {
		"Conductor         FlyingPig.DawnBreaks",
		"Game Design       FlyingPig.DawnBreaks",
		"Story Design      FlyingPig.DawnBreaks",
		"Logic Design      FlyingPig.DawnBreaks",
		"Algorithm Design  FlyingPig.DawnBreaks", //五句
		"Program Struct    FlyingPig.DawnBreaks",
		"Coding            FlyingPig.DawnBreaks",
		"Debug and Tester  FlyingPig.DawnBreaks",
		"Pictures&Painting FlyingPig.DawnBreaks",
		"Sounds            FlyingPig.DawnBreaks",//10 
		"Dub(in process)   FlyingPig.DawnBreaks",
		"Music(use others) FlyingPig.DawnBreaks",
		"       January the 3rd  2020          ",
		"          Thx For Playing             ",//终止

		"第十四句",//十五句
		"第十五句",
		"第十六句",
		"第十七句",
		"第十八句",
		"第十九句",//二十句
		"第二十句",
		"第二十一句",
		"第二十二句",
		"第二十三句",
		"第二十四句",//二十五句
		"第二十五句",
		"第二十六句",
		"第二十七句",
		"第二十八句",
		"第二十九句",//三十句
		"第三十句",
		"第三十一句",
		"第三十二句",
		"第三十三句",
		"第三十四句",//三十五句
		"第三十五句",
		"第三十六句"}; //完成
	
	int current_sentence = k / 50;
	int current_process = k % 50;

	int c_r = 0;
	int c_g = 0;
	int c_b = 0;

	if(current_sentence % 3 == 0)
	{
		c_r = 245;
		c_g = 89;
		c_b = 97;
	}
	else if(current_sentence % 3 == 1)
	{
		c_r = 238;
		c_g = 249;
		c_b = 111;
	}
	else
	{
		c_r = 58;
		c_g = 186;
		c_b = 254;
	}

	
	if(current_process < 25)
	{
		c_r = c_r * current_process / 24;
		c_g = c_g * current_process / 24;
		c_b = c_b * current_process / 24;
	}
	else
	{
		c_r = c_r * (49 - current_process) / 24;
		c_g = c_g * (49 - current_process) / 24;
		c_b = c_b * (49 - current_process) / 24;
	}
	
	

	
	//动画
	/*
	static CvCapture* pCapture = cvCreateFileCapture("ed_r2.mov");
	static IplImage* pFrame;

	pFrame = cvQueryFrame(pCapture);
	pFrame = cvQueryFrame(pCapture);
	pFrame = cvQueryFrame(pCapture);

	if(pFrame != NULL)
	{
		//翻转处理
		IplImage* mirror;
		//= cvCreateImage(cvSize(pFrame->width,pFrame->height),pFrame->depth,pFrame->nChannels);
		mirror = cvCloneImage(pFrame);
		cvFlip(pFrame, mirror, 0); // 必须要使用两张图像

		HDC hDC = ::CreateCompatibleDC(0);
		BYTE tmp[sizeof(BITMAPINFO)+255*4];
		BITMAPINFO* bmi = (BITMAPINFO*)tmp;
		HBITMAP hBmp;
		int i;
		memset(bmi,0,sizeof(BITMAPINFO));
		bmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi->bmiHeader.biWidth = mirror->width;
		bmi->bmiHeader.biHeight = mirror->height;
		bmi->bmiHeader.biPlanes = 1;
		bmi->bmiHeader.biBitCount = mirror->nChannels * mirror->depth;
		bmi->bmiHeader.biCompression = BI_RGB;
		bmi->bmiHeader.biSizeImage = mirror->width*mirror->height*1;
		bmi->bmiHeader.biClrImportant =0 ;
		switch(mirror->nChannels * mirror->depth)
		{
			case 8 :
			for(i=0 ; i < 256 ; i++)
			{
				bmi->bmiColors[i].rgbBlue = i;
				bmi->bmiColors[i].rgbGreen= i;
				bmi->bmiColors[i].rgbRed= i;
			}
			break;
			case 32:
			case 24:
				((DWORD*) bmi->bmiColors)[0] = 0x00FF0000;  
				((DWORD*) bmi->bmiColors)[1] = 0x0000FF00;
				((DWORD*) bmi->bmiColors)[2] = 0x000000FF;
			break;
		}
		hBmp = ::CreateDIBSection(hDC,bmi,DIB_RGB_COLORS,NULL,0,0); 
		SetDIBits(hDC,hBmp,0,mirror->height,mirror->imageData,bmi,DIB_RGB_COLORS); 
		::DeleteDC(hDC);




		tempDC.SelectObject(hBmp);
		::SetStretchBltMode(spDC->m_hDC, HALFTONE);

		int p_x = 490;
		//old_font = spDC->SelectObject(&ftitle);

		supportDC.StretchBlt(300, 100, 1200, 800, &tempDC, 0, 0, mirror->width, mirror->height, SRCCOPY);
		//spDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &tempDC, 0, 0, SRCCOPY);
		//spDC->SetBkMode(TRANSPARENT);

		cvReleaseImage(&mirror);
		

	}
	else if(pFrame == NULL || k == 700)
	{
		cvReleaseCapture(&pCapture);
	}

	*/
	
	supportDC.FillSolidRect(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, RGB(0, 0, 0));
	supportDC.SetTextColor(RGB(c_r / 2, c_g / 2, c_b / 2 ));
	supportDC.TextOutA(195, 450, ending_infor[current_sentence]);

	supportDC.SetTextColor(RGB(c_r, c_g, c_b));
	supportDC.TextOutA(200, 450, ending_infor[current_sentence]);



#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1267, 693, &supportDC, 0, 0, 1900, 1040, SRCCOPY);
#else
	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);
#endif
	//第二个方案 滚轮的 

}
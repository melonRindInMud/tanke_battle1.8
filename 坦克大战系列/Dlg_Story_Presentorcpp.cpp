#include "stdafx.h"
#include "坦克大战系列Dlg.h"



void C坦克大战系列Dlg::Story_Information_Presentor(int stage)
{
	CString filename;
	filename.Format("story%d.txt",stage);
	int s_x = 448;
	int s_y = 60;
	int print_l = 1;
	FILE* file = fopen(filename, "r");
	if(!file)
	{
		AfxMessageBox("剧本" + filename + "打开失败");
	}
	char info [200];

	supportDC.SetTextColor(RGB(0, 0, 0));
	while(!feof(file))
	{
		fgets(info, 200, file);
		supportDC.TextOutA(s_x, s_y + 32 * (print_l ++), info);
	}
	supportDC.SetTextColor(RGB(255, 255, 255));
	fseek(file, 0, SEEK_SET);
	print_l = 1;
	s_x += 2;
	while(!feof(file))
	{
		fgets(info, 200, file);
		supportDC.TextOutA(s_x, s_y + 32 * (print_l ++), info);

	}
#ifdef LOW_DENSITY
	pDC->StretchBlt(0, 0, 1266, 693, &supportDC, 0, 0, 1900, 1080, SRCCOPY);
#else
	pDC->BitBlt(0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, &supportDC, 0, 0, SRCCOPY);
#endif
}

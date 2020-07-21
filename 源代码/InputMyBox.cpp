#include "inputMyBox.h"

InputMyBox::InputMyBox() {};

InputMyBox::~InputMyBox() {};

//末尾添加字符
void Append(wchar_t c, wstring &p,int x1,int y1,int x2,int y2)
{
	wcout << "c = " << c << " p = " << p << endl;
	if (c != 8)
	{
		wstring str;
		wstringstream ss;
		ss << c;
		ss >> str;
		wcout << "str = " << str << endl;
		p += str;
	}
	else
	{
		clearrectangle(x1+10, y1+10, x2-5, y2-5);
		cout << "清空" << endl;
		p = _T("");
	}
}

void InputMyBox::flash(int num,unsigned long long cnt) {

	int d = 61;					//文本框位置公差
	int x1 = 194, x2 = 310;
	int y1 = 106, y2 = 141;

	cout << "cnt = " << cnt << " fps = " << fps << endl;

	if (cnt % fps > fps / 2) {
		setlinecolor(RED);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
		line(x1 - 2, y1 + (num - 1) * d, x1 - 2, y2 + (num - 1) * d);
	}
	else {
		clearrectangle(x1 - 3, y1 , x1 - 1 , y2 + 4 * d);
	}
}

void InputMyBox::set(TicketHall* h,wstring p1, wstring p2, wstring p3, wstring p4, wstring p5) {
	
	wstringstream ss;
	ss << p1;
	ss >> h->cost_staff;
	ss.str();
	ss.clear();
	
	ss << p2;
	ss >> h->cost_costom;
	ss.str();
	ss.clear();

	ss << p3;
	ss >> h->efficiency;
	ss.str();
	ss.clear();

	ss << p4;
	ss >> h->pedestrian_volume;
	ss.str();
	ss.clear();

	ss << p5;
	ss >> h->duration;

	ss.str();
	ss.clear();

	cout << "h->coststaff = " << h->cost_staff << "duration = " << h->duration << endl;;
}

void InputMyBox::textBox(TicketHall *h) {
	initgraph(455, 444);

	IMAGE img;
	loadimage(&img, _T(".\\textBox.png"), 455, 444);
	//先把图片放在工程项目下，使用L+"绝对路径"
	putimage(0, 0, &img);


	wstring p1 = _T("120");
	wstring p2 = _T("200");
	wstring p3 = _T("100");
	wstring p4 = _T("10");
	wstring p5 = _T("5");

	HWND hq = FindWindowW(NULL, L"售票大厅4");
	MessageBox(hq, L"三分法动态模拟收缩区间的过程。\n本题支出函数常规为凹函数，若参数不当有可能为凹函数的递增区间。\n建议先使用默认参数。", L"三分算法", MB_OK);

	setfillcolor(YELLOW);
	setbkcolor(YELLOW);
	fillroundrect(330, 400, 400, 430, 10, 10);
	

	int x = 210, y11 = 117, y22 = y11 + 61, y33 = y22 + 61, y44 = y33 + 61, y55 = y44 + 61;

	

	// 设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 22;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	settextcolor(BLACK);
	outtextxy(340, 405, _T("确定"));
	setbkcolor(RGB(173, 185, 202));
	

	int m_fps = fps = 20;
	int flag = 0;				//文本框光标选择
	int d = 61;					//文本框位置公差
	int x1 = 195, x2 = 310;
	int y1 = 105, y2 = 140;

	MOUSEMSG k = {};

	wstring fuck = _T("123");

	clock_t start, now1,now2,now3,now4 = clock(), finish;
	start = clock();
	double tottime;
	unsigned long long cnt = 0;

	while(true) {
		if(MouseHit())
			k = GetMouseMsg();

		now1 = clock();
		tottime = (double)(now1 - now4) / CLOCKS_PER_SEC;
		cout << "\n (1) 此程序的运行时间为" << tottime << "秒！" << endl;

		outtextxy(x, y11, &p1[0]);
		outtextxy(x, y22, &p2[0]);
		outtextxy(x, y33, &p3[0]);
		outtextxy(x, y44, &p4[0]);
		outtextxy(x, y55, &p5[0]);

		wchar_t	key;
		cnt++;
	
		//outtextxy(0, 0, &fuck[0]);
		//fuck.append(_T("1"));

		now2 = clock();
		tottime = (double)(now2 - now1) / CLOCKS_PER_SEC;
		cout << "\n (1) 此程序的运行时间为" << tottime << "秒！" << endl;

		if (k.uMsg == WM_LBUTTONDOWN) {
			if (k.x >= x1 && k.x <= x2 && k.y >= y1 && k.y <= y2) {
				flag = 1;

			}
			if (k.x >= x1 && k.x <= x2 && k.y >= y1 + d && k.y <= y2 + d) {
				flag = 2;
			}
			if (k.x >= x1 && k.x <= x2 && k.y >= y1 + 2 * d && k.y <= y2 + 2 * d) {
				flag = 3;
			}
			if (k.x >= x1 && k.x <= x2 && k.y >= y1 + 3 * d && k.y <= y2 + 3 * d) {
				flag = 4;
			}
			if (k.x >= x1 && k.x <= x2 && k.y >= y1 + 4 * d && k.y <= y2 + 4 * d) {
				flag = 5;
			}

			//退出
			if (k.x >= 330 && k.x <= 400 && k.y >= 400 && k.y <= 430) {
				set(h,p1, p2, p3, p4, p5);
				closegraph();
				return ;
			}
		}

		now3 = clock();
		tottime = (double)(now3 - now2) / CLOCKS_PER_SEC;
		cout << "\n (2) 此程序的运行时间为" << tottime << "秒！" << endl;

		if (flag) {
			//光标需要闪烁
			cout <<"flag = "<< flag << endl;
			key = inputKey();
			cout << "key = " << key << endl;
			flash(flag, cnt);
			if (key) {
				
				if (flag == 1) {
					
					Append(key,p1,x1,y1,x2,y2);
					wcout << "key = " << key << " p1 = " << p1 << endl;
				}
				else if (flag == 2) {
					Append(key,p2, x1, y1 + d, x2, y2 + d);
				}
				else if (flag == 3) {
					Append(key,p3, x1, y1 + 2 * d, x2, y2 + 2 * d);
				}
				else if (flag == 4) {
					Append(key,p4, x1, y1 + 3 * d, x2, y2 + 3 * d);
				}
				else if (flag == 5) {
					Append(key,p5, x1, y1 + 4 * d, x2, y2 + 4 * d);
				}
				/*flag = 0;*/
			}
		}

		now4 = clock();
		tottime = (double)(now4 - now3) / CLOCKS_PER_SEC;
		cout << "\n (3) 此程序的运行时间为" << tottime << "秒！" << endl;

	}



	getchar();
}

// 获取用户输入（仅接受数字和退格键）
wchar_t InputMyBox::inputKey()
{
	wchar_t c = 0;

	if (_kbhit())
	{
		c = _getwch();

		if (!(c >= '0' && c <= '9') && c != 8)
			c = 0;
	}
	return c;
}


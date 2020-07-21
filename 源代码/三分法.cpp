#include "ticketHall.h"

void print(int key,int x,int y) {
	wstringstream ss;
	wstring str;
	ss << key;
	ss >> str;
	
	outtextxy(x,y, &str[0]);
}

wstring toString(int key) {
	wstringstream ss;
	wstring str;
	ss << key;
	ss >> str;
	return str;
}

void init(long long maxn,long long minn) {
	int width = 1500, height = 800;
	initgraph(width, height);
	setbkcolor(WHITE);
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	fillrectangle(0, 0, width, height);
	line(0, height - 100, width, height - 100);
	line(100, 0, 100, height);
	setfillcolor(RED);
	setorigin(100, 700);
	settextcolor(BLACK);
	

	setaspectratio(1,-1);
	circle(0, 0, 4);
	setorigin(100, 600);
	setfillcolor(RED);
}

void initt(long long maxn, long long minn) {
	int width = 1500, height = 800;
	setorigin(0, 0);
	setaspectratio(1, 1);
	
	setbkcolor(WHITE);
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	fillrectangle(0, 0, width, height);
	settextcolor(BLACK);

	for (int i = 0; i <= 20; i++) {
		wstring temp = toString(i);
		outtextxy(100 + i * 75, 720, &temp[0]);
	}

	for (int hei = minn; hei < maxn; hei += (maxn - minn) / 6) {
		int k = (maxn - minn) / 600;
		wstring temp = toString(hei); 
		
		outtextxy(30, -(hei - minn) / k + 600, &temp[0]);
	}

	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 5);
	line(0, height - 100, width, height - 100);
	line(100, 0, 100, height);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	setfillcolor(RED);
	setorigin(100, 700);
	


	setaspectratio(1, -1);
	circle(0, 0, 4);
	setorigin(100, 600);
	setfillcolor(RED);
}

int TicketHall::solveSanFen() {
	
	long long maxn = -1, minn = LONG_MAX;

	int l = 1, r = 18;
	while (l < r) {

		int lm = l + (r - l) / 3, rm = r - (r - l) / 3;
		long long vall = getCost(lm), valr = getCost(rm);
		cout << "l = " << l << " vall = " << vall << "r = " << r << " valr = " << valr << endl;

		maxn = max(max(maxn, vall), valr);
		minn = min(min(minn, vall), valr);
		if (vall <= valr)
			r = rm - 1;
		else
			l = lm + 1;
	}
	//-------------------------------------
	cout << " maxn = " << maxn << " minn = " << minn << endl;
	
	init(maxn,minn);
	
	int xasp = 75;
	l = 1, r = 18;
	vector<pair<int, int>> V;
	
	

	while (l < r) {
		//用vector保存之前的点和横线
		initt(maxn, minn);
		line(l*xasp, -100, l*xasp, 600),line(r*xasp, -100, r*xasp, 600);
		/*int lm = (l + r) >> 1, rm = (lm + r) >> 1;
		long long vall = getCost(lm), valr = getCost(rm);*/
		int lm = l + (r - l) / 3, rm = r - (r - l) / 3;
		long long vall = getCost(lm), valr = getCost(rm);

		cout << " lm = " << lm << " rm = " << rm << endl;
		cout << " vall = " << vall << " valr = " << valr << endl;
		
		V.push_back({ lm * xasp, 500 * (vall - minn) / max(1,(maxn - minn)) });
		V.push_back({ rm * xasp, 500 * (valr - minn) / max(1,(maxn - minn)) });
		
		for (pair<int, int> PII : V) {
			fillcircle(PII.first, PII.second,6);
		}
		fillcircle(lm * xasp, 500 * (vall - minn) / max(1, (maxn - minn)), 12);
		fillcircle(rm * xasp, 500 * (valr - minn) / max(1, (maxn - minn)), 12);
		setlinecolor(BLUE);
			
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 5);
		line(xasp * lm, 500 * (vall - minn) / max(1, (maxn - minn)), xasp * lm, -100);
		line(xasp * rm, 500 * (valr - minn) / max(1, (maxn - minn)), xasp * rm, -100);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);

		setaspectratio(1, 1);
		outtextxy(-90, -550, L"支出成本(元)");
		outtextxy(1300, 140, L"窗口数量(个)");
		setaspectratio(1, -1);

		if (vall <= valr)
			r = rm - 1;
		else
			l = lm + 1;
		Sleep(2000);
	}

	initt(maxn, minn);
	int lasty,nowy;
	for (pair<int, int> PII : V) {
		fillcircle(PII.first, PII.second, 6);
	}
	setlinecolor(RED);
	
	for (int i = 2; i <= 19; i++) {
		lasty = getCost(i - 1);
		nowy = getCost(i);
		fillcircle((i - 1) * 75, 500 * (lasty - minn) / max((maxn - minn),1),2);
		line((i - 1) * 75, 500 * (lasty - minn) / max((maxn - minn), 1), i * 75, 500 * (nowy - minn) / max((maxn - minn), 1));
		wstring str = toString(lasty);
		setaspectratio(1, 1);
		outtextxy( (i - 1) * 75, - 500 * (lasty - minn) / max((maxn - minn), 1) - 25,&str[0]);
		outtextxy(-90, -550, L"支出成本(元)");
		outtextxy(1300, 140, L"窗口数量(个)");

		settextcolor(BLUE);
		str = toString(minn);
		outtextxy(700, -240, L"开放     个窗口支出最小，支出最小为                    元。按回车键返回。");
		outtextxy(965, -240, &str[0]);
		str = toString(r);

		outtextxy(734, -240, &str[0]);
		settextcolor(BLACK);

		setaspectratio(1, -1);
	}
	setlinecolor(BLACK);
	
	
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 5);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	

	getchar();
	return r;
}


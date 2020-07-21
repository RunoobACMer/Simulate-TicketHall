#include "ticketHall.h"
#include "inputMyBox.h"

TicketHall::TicketHall(int _cost_staff, int _cost_costom) {
	cost_staff = _cost_staff;
	cost_costom = _cost_costom;
}

wstring toString2(int key) {
	wstringstream ss;
	wstring str;
	ss << key;
	ss >> str;
	return str;
}



long long TicketHall::getCost(int _number_window) {
	long long sum = 0;
	int people_wait;
	if (efficiency <= pedestrian_volume)
		people_wait = 0;
	else
		people_wait = ceil((double)efficiency / pedestrian_volume) - _number_window;
	people_wait = max(0, people_wait);

	cout << "sum = " << sum << " people_wati = " << people_wait << endl;
	//�˿͵ȴ��ɱ�
	sum += duration * people_wait * cost_costom;
	cout << "�˿͵ȴ��ɱ�  = " << sum << endl;
	//Ա���ķ���
	sum += duration * _number_window * cost_staff;
	cout << "��ӶԱ���ɱ�  = " << duration * _number_window * cost_staff << endl;
	cout << "sum = " << sum << endl;
	return sum;
}



int TicketHall::timeConversion(int hour) {
	int second = hour * 3600;
	return second;
}

TicketHall::~TicketHall() {}



int TicketHall::GUImenu()
{

	initgraph(1000, 600);

	IMAGE img;
	loadimage(&img, _T(".\\1.png"), 1000, 600);
	//�Ȱ�ͼƬ���ڹ�����Ŀ�£�ʹ��L+"����·��"
	putimage(0, 0, &img);

	setbkcolor(CYAN);
	settextcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 33;                      // ��������߶�Ϊ 33
	wcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
	settextstyle(&f);                     // ����������ʽ


	setfillcolor(CYAN);

	int x1 = 130, y1 = 345;
	int x2 = 430, y2 = 345;
	int x3 = 800, y3 = 540;

	fillroundrect(x1, y1, x1 + 200, y1 + 85, 10, 10);
	outtextxy(x1 + 23, y1 + 28, _T("���ַ����"));

	fillroundrect(x2, y2, x2 + 200, y2 + 85, 10, 10);
	outtextxy(x2 + 37, y2 + 28, _T("ģ���Ŷ�"));

	setcolor(BROWN);
	f.lfHeight = 33;
	settextstyle(&f);
	fillroundrect(x3, y3, x3 + 150, y3 + 50, 10, 10);
	outtextxy(x3+10, y3+6, _T("�˳�ϵͳ"));


	MOUSEMSG k;
	while (true)
	{
		k = GetMouseMsg();

		if (k.x >= x1 && k.y >= y1 && k.x <= x1 + 200 && k.y <= y1 + 85)
		{
			if (k.uMsg == WM_LBUTTONDOWN)
			{
				//���ַ�
				closegraph();

				/*InputMyBox box;
				box.textBox();*/
				return 1;
			}
		}

		if (k.x >= x2 && k.y >= y2 && k.x <= x2 + 200 && k.y <= y2 + 85)
		{
			if (k.uMsg == WM_LBUTTONDOWN)
			{
				//�˻�
				closegraph();
				/*InputMyBox box;
				box.textBox();
				set(par1, par2, par3, par4, par5);
				cout << cost_staff << ' ' << cost_costom << ' ' << efficiency << ' ' << pedestrian_volume << ' ' << duration << endl;*/
				return 2;
			}
		}

		if (k.x >= x3 && k.y >= y3 && k.x <= x3 + 150 && k.y <= y3 + 50)
		{
			if (k.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				return 3;
			}
		}

	}

	closegraph();
}

void TicketHall::set(int a1, int a2, int a3, int a4, int a5) {
	cout << "a1 = " << a1 << " a2 = " << a2 << " a3 = " << a3 << " a4 = " << a4 << " a5 = " << a5 << endl;
	cost_staff = a1;
	cost_costom = a2;

	
	efficiency = a3;
	pedestrian_volume = a4; 

	duration = a5;
}

void button(int x,int y,int width,int height,wstring str) {
	setfillcolor(YELLOW);
	settextcolor(BLACK);
	setbkcolor(YELLOW);
	fillrectangle(x, y, x + width, y + height);
	outtextxy(x + 5, y + 10, &str[0]);
}

class peo {
public:
	int y;
	void move() {

	}
};

void drawHall(int x) {
	IMAGE img2;
	loadimage(&img2, _T(".//seller.png"), x, 40);
	setlinecolor(BLACK);
	
	MOUSEMSG k;
	int cnt = 0;
	while (true) {
		k = GetMouseMsg();
		
		setfillcolor(WHITE);
		fillrectangle(0, 0, 800, 480);
		line(x - 10, 160, x - 10, 480);
		putimage(x - 70, 50, &img2);
		setfillcolor(CYAN);
		button(x - 60, 20, 40, 30, _T("�Ŷ�"));
		button(x, 20, 40, 30, _T("�뿪"));

		if (k.uMsg == WM_LBUTTONDOWN) {
			if (k.x >= x - 60 && k.y >= 20 && k.x <= x - 20 && k.y <= 50) {
				cnt++;
				for (int i = 480; i >= 130; i--) {
					setfillcolor(WHITE);
					fillrectangle(0, 0, 800, 480);
					line(x - 10, 160, x - 10, 480);
					putimage(x - 70, 50, &img2);
					setfillcolor(CYAN);
					fillcircle(x - 40, i, 20);
					button(x - 60, 20, 40, 30, _T("�Ŷ�"));
					button(x, 20, 40, 30, _T("�뿪"));
					Sleep(20);
				}

				for (int i = x - 10; i <= x + 20; i++) {
					setfillcolor(WHITE);
					fillrectangle(0, 0, 800, 480);
					line(x - 10, 160, x - 10, 480);
					putimage(x - 70, 50, &img2);
					setfillcolor(CYAN);
					fillcircle(i, 130, 20);
					button(x - 60, 20, 40, 30, _T("�Ŷ�"));
					button(x, 20, 40, 30, _T("�뿪"));
					Sleep(20);
				}

				for (int i = 130; i <= 480; i++) {
					setfillcolor(WHITE);
					fillrectangle(0, 0, 800, 480);
					line(x - 10, 160, x - 10, 480);
					putimage(x - 70, 50, &img2);
					setfillcolor(CYAN);
					fillcircle(x + 20, i, 20);
					button(x - 60, 20, 40, 30, _T("�Ŷ�"));
					button(x, 20, 40, 30, _T("�뿪"));
					Sleep(20);
				}
			}
		}
	}
}

int in = -1, out = 0;
int return_flag = 0;

DWORD WINAPI peoQueue(LPVOID p) {
	int pos = *((int*)p);
	int x = 0;
	int last = out;

	// �ƶ�����ʼλ��
	for (x = 480; x >= 50 * pos + 130; x--) {
		setlinecolor(WHITE);
		setfillcolor(CYAN);
		fillcircle(120 - 40, x, 20);
		if (return_flag) {
			cout << "return while running to pos" << endl;
			return 0;
		}
		Sleep(20);
	}

	// ÿ�����뿪����ǰ���������뿪
	while (true) {
		if (last == out) {
			if (return_flag)
				return 0;
			Sleep(20);
			continue;
		}
		last++;
		if (x >= 125 && x <= 135) {

			setfillcolor(WHITE);
			fillcircle(80, 130, 22);
			setfillcolor(CYAN);
			for (int i = 120 - 10; i <= 120 + 20; i++) {
				fillcircle(i, 130, 20);
				if (return_flag) {
					cout << "return while leaving horize" << endl;
					return 0;
				}
				Sleep(20);
			}

			for (int i = 130; i <= 540; i++) {
				fillcircle(120 + 20, i, 20);
				if (return_flag) {
					cout << "return while leaving" << endl;
					return 0;
				}
				Sleep(20);
			}
			break;
		}
		else {
			int des = x - 50;
			for (; x > des; x--) {
				fillcircle(120 - 40, x, 20);
				if (return_flag) {
					return 0;
				}
				Sleep(20);
			}
		}
	}
	return 0;
}

void drawHallMulThread() {
	IMAGE img2, img3;
	MOUSEMSG k;
	return_flag = 0;
	in = -1, out = 0;

	loadimage(&img2, _T(".//seller.png"), 120, 40);
	loadimage(&img3, _T(".//˵��2.png"), 550, 450);
	setlinecolor(BLACK);

	setfillcolor(WHITE);
	fillrectangle(0, 0, 800, 480);
	line(120 - 10, 160, 120 - 10, 480);
	putimage(120 - 70, 50, &img2);
	putimage(230, 10, &img3);
	//putimage(180, 10, 595, 584, &img3, 0, 0, 0);
	setfillcolor(CYAN);
	button(120 - 60, 20, 40, 30, _T("�Ŷ�"));
	button(120, 20, 40, 30, _T("�뿪"));
	button(700, 450, 40, 30, _T("����"));

	//getchar();

	while (true) {
		k = GetMouseMsg();

		if (k.uMsg == WM_LBUTTONDOWN) {
			if (k.x >= 120 - 60 && k.y >= 20 && k.x <= 120 - 20 && k.y <= 50) {
				// ��������Ŷ�
				in++;
				int pos = in - out;
				CreateThread(NULL, 0, peoQueue, &pos, 0, NULL);
				
			}
			else if (k.x >= 120 && k.y >= 20 && k.x <= 120 + 40 && k.y <= 50) {
				// ��������뿪
				if (out >= in + 1)
					continue;
				out++;
			}
			if (k.x >= 700 && k.y >= 450 && k.x <= 740 && k.y <= 480) {
				// ������˷���
				return_flag = 1;
				Sleep(100);
				return;
			}
		}
	}
}

void TicketHall::simulate() {
	initgraph(800, 480);
	
	//drawHall(120);

	drawHallMulThread();
	
}


#pragma once

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <time.h>
#include "ticketHall.h"


using namespace std;

class InputMyBox {
private:
	int x = 100, y = 200;		//基准文本框位置
	int fps = 300;			//光标闪烁次数
	friend class TicketHall;

public:
	InputMyBox();

	void textBox(TicketHall* h);

	wchar_t inputKey();

	void flash(int num, unsigned long long cnt);

	void set(TicketHall *h,wstring p1, wstring p2, wstring p3, wstring p4, wstring p5);

	
	~InputMyBox();
};
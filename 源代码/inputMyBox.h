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
	int x = 100, y = 200;		//��׼�ı���λ��
	int fps = 300;			//�����˸����
	friend class TicketHall;

public:
	InputMyBox();

	void textBox(TicketHall* h);

	wchar_t inputKey();

	void flash(int num, unsigned long long cnt);

	void set(TicketHall *h,wstring p1, wstring p2, wstring p3, wstring p4, wstring p5);

	
	~InputMyBox();
};
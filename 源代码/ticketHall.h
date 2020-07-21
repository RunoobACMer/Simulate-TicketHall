#pragma once

#include <iostream>
#include <vector>
#include <graphics.h>
#include <conio.h>
#include <queue>
#include <time.h>
#include <processthreadsapi.h>
#include "inputMyBox.h"

using namespace std;

static int par1;
static int par2;
static int par3;
static int par4;
static int par5;

class TicketHall {
private:

	//Ա���ɱ�(Ԫ/��)
	//�˿͵ȴ��ɱ�(Ԫ/��)
	int cost_staff = 0;
	int cost_costom = 0;

	//Ա������˿�Ч��(��/��)
	//������(��/��)
	int efficiency = 0;
	int pedestrian_volume = 0;

	//�߷��ڳ���ʱ��(��)
	//��Ѵ�������
	int duration = 0;
	int number_window = 4;

	//��Ԫ�ࣺ�������
	friend class InputMyBox;


public:

	TicketHall() {};

	TicketHall(int _cost_staff, int _cost_costom);

	int GUImenu();

	int timeConversion(int hour);

	long long getCost(int _number_window);

	int solveSanFen();

	void set(int a1, int a2, int a3, int a4, int a5);

	void simulate();

	~TicketHall();
};


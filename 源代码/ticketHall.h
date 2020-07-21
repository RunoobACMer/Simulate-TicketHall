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

	//员工成本(元/秒)
	//顾客等待成本(元/秒)
	int cost_staff = 0;
	int cost_costom = 0;

	//员工服务顾客效率(秒/人)
	//人流量(秒/人)
	int efficiency = 0;
	int pedestrian_volume = 0;

	//高峰期持续时间(秒)
	//最佳窗口数量
	int duration = 0;
	int number_window = 4;

	//友元类：输入框类
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


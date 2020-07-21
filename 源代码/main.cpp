#include "ticketHall.h"
#include "InputMyBox.h"

int main() {
	TicketHall a(0, 0);
	while (true) {
		int flag = a.GUImenu();
		if (flag == 1) {
			//三分算法
			InputMyBox box;
			box.textBox(&a);
			a.solveSanFen(); 
		}
		else if (flag == 2) {
			//模拟队列
			a.simulate();
		}
		else {
			//退出程序
			getchar();
			return 0;
		}
	}
	
}
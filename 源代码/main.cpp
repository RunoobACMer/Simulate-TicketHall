#include "ticketHall.h"
#include "InputMyBox.h"

int main() {
	TicketHall a(0, 0);
	while (true) {
		int flag = a.GUImenu();
		if (flag == 1) {
			//�����㷨
			InputMyBox box;
			box.textBox(&a);
			a.solveSanFen(); 
		}
		else if (flag == 2) {
			//ģ�����
			a.simulate();
		}
		else {
			//�˳�����
			getchar();
			return 0;
		}
	}
	
}
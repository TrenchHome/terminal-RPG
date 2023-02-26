#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <curses.h>
#include "Master.h"
#include "startmenu.h"
#include "Picture.h"
using namespace std;
int main() {
	initscr();
	screen();
	ifstream infile("record.txt");
	while (!infile.eof()) {
		char tmp_name[100];
		int tmp_type, tmp_lv, tmp_exp, tmp_sel;
		infile >> tmp_name >> tmp_lv >> tmp_exp >> tmp_sel;
		if (tmp_sel == -1)
			RolePond[nmb_of_role++] = new Role(tmp_name, tmp_lv, tmp_exp);
		else if (tmp_sel >=0 && tmp_sel <=3)
			RolePond[nmb_of_role++] = new Master(tmp_name, tmp_lv, tmp_exp, tmp_sel);
	}
	if(nmb_of_role!=0) nmb_of_role--;
	infile.close();
	startmenu();
	refresh();
	endwin();
	return 0;
}
 


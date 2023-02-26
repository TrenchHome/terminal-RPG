#include "Master.h"
#define x 4
#define y 10
#define x2 18
#define y2 40
void transfer(Role** play1) {
	int sel=0;
	if((*play1)->selection==-1) {
		if ((*play1)->level >= 5) {
			show_all_Skill();
			mvprintw(x2,y2+18,"Selection one skill!!");
			mvprintw(x2+1,y2+18,"Your choice: ");
			echo();
			scanw("%d",&sel);
			*play1 = new Master(**play1, sel);
			mvprintw(x2+5,y,"Successfully Become a Mater!!");
			mvprintw(x2+6,y," => Press Enter to leave...\n");
			scanw("\r");
		}
		else 
			// mvprintw(x2+5,y,"Ni Hai Thai NERN La!!!");
			mvprintw(x2+5,y,"We are not qualified to be a Master.");
			mvprintw(x2+6,y," => Press Enter to leave...\n");
			scanw("\r");
	}
	else {
		mvprintw(x2+5,y,"Alreadly Master.");	
			mvprintw(x2+6,y," => Press Enter to leave...\n");
			scanw("\r");
	}
}
 


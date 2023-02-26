#ifndef ROLE_H
#define ROLE_H
#define x 4
#define y 10
#define x2 18
#define y2 40
#define y3 50
#include <iostream>
#include <cstring>
#include "Picture.h"
#include "drama.h"
using namespace std;
class Role {
	public:
		char name[100];
		int selection, level, hp, damage, exp;
		Role(int lv=1, int sel=-1);
		Role(char*, int lv=1, int exp=0, int sel=-1);
		void hit(Role&);
		virtual void show_Role_data(void);
		virtual bool battle(Role&);
		int cal_max_hp(void);
		int cal_damage(void);
		void check_level(void);
};
/*******Constructor********/
Role::Role(int lv, int sel) :level(lv), exp(0), selection(sel) {
	strcpy(name, "Default");
	hp = cal_max_hp();
	damage = cal_damage();
}
Role::Role(char* str, int lv, int exp, int sel):level(lv), exp(exp), selection(sel){
	strcpy(name, str);
	hp = cal_max_hp();
	damage = cal_damage();
}
/*******public function********/
void Role::hit(Role& obj) {obj.hp -= damage;}
void Role::show_Role_data() {
	check_level();
	if(selection==-1)
		mvprintw(x-1,y2,"--<<Role>>--\n");
	else if(selection!=-1)
		mvprintw(x-1,y2,"--<<Master>>--\n");
	mvprintw(x,y2," name: %s\n",name);
	mvprintw(x+1,y2," level: %d\n",level);
	mvprintw(x+2,y2," hp: %d\n",hp);
	mvprintw(x+3,y2," damage: %d\n",damage);
	mvprintw(x+4,y2," exp: %d/ %d\n",exp, level*50+50);
}
bool Role::battle(Role& play2) {
	drama();
	hp = cal_max_hp();
	play2.hp = play2.cal_max_hp();
	int next_step=0;
	while (hp!=0 && play2.hp!=0) {
		mvprintw(x2,y,"Which step does %s  want to do ?\n",name);
		mvprintw(x2+1,y,"1. Normal Attack!!\n");
		mvprintw(x2+2,y,"2. Escape..\n");
		mvprintw(x2+3,y,"Your choice: ");
		echo();
		scanw("%d",&next_step);
		switch(next_step) {
			case 1:
				clear();
				hit(play2);
				mvprintw(x,y,"You choose the Normal Attack!!"); 
				mvprintw(x-1,y3,"%s inflicts %d damage to %s ", name , damage,play2.name);
				mvprintw(x,y3,"Now, %s's HP is %d .",name , hp );
				mvprintw(x+1,y3,"Now, %s's HP is %d .",play2.name , play2.hp);
				break;
			case 2:
				mvprintw(x2+5,y,"escape");
				mvprintw(x2+6,y,"Press Enter to leave...\n");
				scanw("\r");
				return 0;
			default:
				mvprintw(x2+5,y,"enter 1~2");
				mvprintw(x2+6,y,"Press Enter to leave...\n");
				scanw("\r");
				break;
		}
		if (play2.hp<=0) {
			clear();
			mvprintw(x2+5, y,"%s win !!\n", name);
			exp += 100;
			mvprintw(x2+6,y,"Press Enter to leave...\n");
			win();
			return 1;
		}
		next_step=0;

		mvprintw(x+10,y3,"%s choose the Punch!!",play2.name);
		play2.hit(*this);
		mvprintw(x+11,y3,"%s inflicts %d damage to %s",play2.name, play2.damage,name); 
		mvprintw(x+12,y3,"Now, %s's HP is %d .",name , hp);
		mvprintw(x+13,y3,"Now, %s's HP is %d .",play2.name , play2.hp );
		refresh();
		/***********victory judge*****************/
		if(hp<=0) {
			clear();
			mvprintw(x2+5,y,"%s lose this game .",name);
			mvprintw(x2+6,y,"Press Enter to leave...\n");
			gameover();
			return 1;
		}
	}
	return 1;
}
void Role::check_level(void) {
	while(exp >= level*50+50) {
		exp -= level*50+50;
		level++;
	}
	hp = cal_max_hp();
	damage = cal_damage();
}
int Role::cal_max_hp() {return level*100;}
int Role::cal_damage() {return level*2+10;}
#endif



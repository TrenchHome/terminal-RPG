#ifndef MASTER_H
#define MASTER_H
#define x 4
#define y 10
#define x2 18
#define y2 40
#include <iostream>
#include <cstring>
#include "Role.h"
#include "Picture.h"
using namespace std;
/****class Skill****/
class Skill {
	public:
		int damage, hp_change;
		char name[100];
		Skill(int, int, char*);
		void use(Role&, Role&);
};
Skill::Skill(int d, int hp_c, char* infro) :damage(d), hp_change(hp_c) {strcpy(name, infro);}
void Skill::use(Role& o1, Role& o2) {
	o1.hp += hp_change;
	if(o1.hp > o1.cal_max_hp()) o1.hp = o1.cal_max_hp();
	o2.hp -= damage;
}
/*****Initial Skill*****/
char cpunch[] = "punch";
char chealing[] = "headling";
char csteal[] = "steal";
char cmad_punch[] = "mad_punch";
Skill punch(40, 0, cpunch); //high damage.
Skill healing(0, 80, chealing); //high hp_add.
Skill steal(20, 30, csteal); //both hp_add and damage.
Skill mad_punch(50, -10, cmad_punch); //pretty high damage
Skill list[4] = {punch, healing, steal, mad_punch};
void show_all_Skill() {
	for (int i=0;i<4;i++) 
		mvprintw(x+i, y2+18,"Skill %d %s: %d %d",i,list[i].name,list[i].damage,list[i].hp_change);
}
/****class Master****/
class Master :public Role{
	public:
		Skill skill;
		Master(int lv=5, int sel=0);
		Master(char* name, int lv=5, int exp=0, int sel=0);
		Master(Role& o, int sel=0);
		virtual void show_Role_data();
		virtual bool battle(Role&);
};
Master::Master(int lv, int sel) :Role(lv, sel), skill(list[sel]) {}
Master::Master(char* name, int lv, int exp, int sel) :Role(name, lv, exp, sel), skill(list[sel]) {}
Master::Master(Role& o, int sel) :Role(o.name, o.level, 0, sel), skill(list[sel]) {}
void Master::show_Role_data() {
	Role::show_Role_data();
	mvprintw(x+5, y2," Skill: %s", skill.name);
}
bool Master::battle(Role& play2) {
	drama();
	hp = cal_max_hp();
	play2.hp = play2.cal_max_hp();
	int next_step=0;
	clear();
	while (hp!=0 && play2.hp!=0) {
		mvprintw(x2,y,"Which step does %s want to do?",name);
		mvprintw(x2+1,y,"1. Normal Attack!!");
		mvprintw(x2+2,y,"2. %s",skill.name);
		mvprintw(x2+3,y,"3. Escape..");
		mvprintw(x2+4,y,"Please enter: ");
		echo;
		next_step=0;
		scanw("%d", &next_step);
		switch(next_step) {
			case 1:
				clear();
				hit(play2);
				mvprintw(x,y,"You choose the Normal Attack!!");
			       	mvprintw(x-1,y3,"%s inflicts %d damage to %s)",name,damage,play2.name);  
				mvprintw(x,y3,"Now, %s's HP is %d",play2.name,play2.hp); 
				mvprintw(x+1,y3,"Now, %s's HP is %d",name,hp);
				break;
			case 2:
				clear();
				mvprintw(x,y,"You choose the %s",skill.name);
				skill.use(*this, play2);
				mvprintw(x-1,y3,"%s use %s to inflict %d damage to %s",name,skill.name,skill.damage,play2.name);
				mvprintw(x,y3,"Now ,%s's HP is %d",play2.name, play2.hp);	
				mvprintw(x+1,y3,"Now ,%s's HP is %d",name,hp);
				break;
			case 3:
				clear();
				mvprintw(x2+5,y,"escape");
				mvprintw(x2+6,y,"Press Enter to leave...\n");
				scanw("\r");
				return 0;
			default:
				break;
		}
		if (play2.hp<=0) {
			clear();
			mvprintw(x2+5,y,"%s win !!",name);
			mvprintw(x2+6,y,"Press Enter to leave...\n");
			exp += 100;
			win();
			return 1;
		}
		/**/
		mvprintw(x+10,y3,"%s choose the Punch!!",play2.name);
		play2.hit(*this);
		mvprintw(x+11,y3,"%s inflicts %d damage to %s",name,play2.damage,name);
		mvprintw(x+12,y3,"Now ,%s's HP is %d",name,hp);
		mvprintw(x+13,y3,"Now ,%s's HP is %d",play2.name,play2.hp);
		/**/
		/***********victory judge*****************/
		if(hp<=0) {
			clear();
			mvprintw(x2+5,y,"%s lose the game.",play2.name);
			mvprintw(x2+6,y,"Press Enter to leave...\n");
			gameover();
			return 1;
		}
	}
	return 1;
}
#endif


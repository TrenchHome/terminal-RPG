#ifndef STARTMENU_H
#define STARTMENU_H
#define x 4
#define y 10
#define x2 18
#define y2 40
#include <iostream>
#include <fstream>
#include "Master.h"
#include "Rate.h"
#include <curses.h>
#include <string>
#include "Transfer.h"
using namespace std;
const int max_nmb_of_role = 5;
int nmb_of_role =0;
Role* RolePond[5];
char cBoss1[] = "Boss1";
Master Boss1(cBoss1, 4, 0, 0);

void show_all_Role() {
	mvprintw(x,y,"Existing characters are: \n");
	for (int i = 0; i < nmb_of_role ; i++)
		mvprintw(x+1+i ,y ,"     %d   %s",i+1, RolePond[i]->name);
}

bool startmenu() {
	int choice=0;
	while(1) {
		int role_choice =0;

		clear();

		mvprintw(x,y,"<---- Options ---->");
		mvprintw(x+1,y,"[1] List all characters");
		mvprintw(x+2,y,"[2] Battle with monsters");
		mvprintw(x+3,y,"[3] Create a new character");
		mvprintw(x+4,y,"[4] Promote");
		mvprintw(x+5,y,"[5] Save");
		mvprintw(x+6,y,"[6] Leaderboard");
		mvprintw(x+7,y,"[7] Quit");
		mvprintw(x+8,y,"-------------------");
		mvprintw(x+9,y,"Your choice: ");
		echo();
		scanw("%d",&choice);

		clear();
		switch(choice) {
			case 1:
				show_all_Role();
				mvprintw(x2,y,"Enter the index for details (or enter -1 to leave) :");
				mvprintw(x2+1,y,"Your choice: ");
				echo();
				scanw("%d",&role_choice);

				while(role_choice != -1) {
					show_all_Role();
					if (role_choice > 0 && role_choice <= nmb_of_role)
						RolePond[role_choice-1]->show_Role_data();
					else 
						mvprintw(0,y,"\n[Warning] Invalid index !!\n");
					mvprintw(x2,y,"Enter the index for details (or enter -1 to leave) :");
					mvprintw(x2+1,y,"Your choice: ");
					echo();
					scanw("%d",&role_choice);
					clear();
//					mvprintw(11,15," ");
				}
				break;
			case 2:
				clear();
				show_all_Role();

				mvprintw(x2,y,"Choose a character for battle !\n");
				mvprintw(x2+1,y,"Your choice: ");
				echo();
				scanw("%d",&role_choice);
				if (role_choice>=1 && role_choice <= nmb_of_role) {
					RolePond[role_choice-1]->battle(Boss1);
				}
				else {
					mvprintw(x2+4,y,"[Warning] Invaild choice of character !!\n");
					mvprintw(x2+5,y," => Press Enter to continue...\n");
					scanw("\r");
				}
				break;
			case 3:
				clear();

				if(nmb_of_role ==0) {
					char role_name[20];
					mvprintw(x,y,"Welcome, new player!\n");
					mvprintw(x+1,y,"Please give the name of the new character: ");
					echo();
					scanw("%s",role_name);
					RolePond[nmb_of_role++] = new Role(role_name);
					clear();
					mvprintw(x,y,"The new character is created successfully !!\n");
					mvprintw(x+1,y," => Press Enter to continue...\n");
					scanw("\r");
				}
				else if (nmb_of_role == max_nmb_of_role) {
					mvprintw(x2+5,y,"Sorry, the maximum number of characters is reached.\n");
					mvprintw(x2+6,y," => Press Enter to continue...\n");
					scanw("\r");
				}
				else if (nmb_of_role>0 && nmb_of_role<max_nmb_of_role) {
					char role_name[20];
					mvprintw(x+1,y,"Please give the name of the new character: ");
					echo();
					scanw("%s", role_name);
					RolePond[nmb_of_role++] = new Role(role_name);
					clear();
					mvprintw(x,y,"The new character is created successfully !!\n");
					mvprintw(x+1,y," => Press Enter to continue...\n");
					scanw("\r");
				}
				break;
			case 4:
				clear();
				show_all_Role();
				mvprintw(x2,y,"Choose one to evolve to a Master: ");
				mvprintw(x2+1,y,"Your Choice: ");
				echo();
				scanw("%d",&role_choice);
				if (role_choice>=1 && role_choice <= nmb_of_role) {
					transfer(&RolePond[role_choice-1]);
				}
				else {
					clear();
					mvprintw(x2+5,y,"No this role\n");
					mvprintw(x2+6,y,"Press Enter to leave...\n");
					scanw("\r");
				}
				break;
			case 5: 
				clear();
				{
				ofstream ouf("record.txt");
				for (int i=0;i<nmb_of_role;i++) {
					ouf 	<< RolePond[i]->name << ' '
						<< RolePond[i]->level << ' '
						<< RolePond[i]->exp << ' '
						<< RolePond[i]->selection << endl;
				}
				ouf.close();
				mvprintw(x2+5, y,"Successfully save the record!!\n");
					mvprintw(x2+6,y,"Press Enter to leave...\n");
					scanw("\r");
			       }
			       break;
			case 6:
			        clear();
			      	rating(RolePond,nmb_of_role) ;
				mvprintw(x2+6,y,"Press Enter to leave...\n");
				scanw("\r");
				echo();
				break;

			case 7:
				clear();
				mvprintw(x,y,"Quit.\n");
				return 0;
			default:
				clear();
				mvprintw(x2+5,y,"[Warning] Invaild option !!\n\n");
				mvprintw(x2+6,y," => Press Enter to continue...\n");
				scanw("\r");
				break;
		}
	
	}
}
 
 
#endif

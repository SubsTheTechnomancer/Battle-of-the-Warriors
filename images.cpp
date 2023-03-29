//#include "graphics.h"
//#include "winbgim.h"
#include<windows.h>

void renderscreen(char pic[]){
    readimagefile(pic,0,0,getmaxx(),getmaxy());
}

char menuscreen[] = "tileset\\title\\title.jpg";

char playerchoice[2][50] = {"tileset\\choose_player\\player1.jpg",
                            "tileset\\choose_player\\player2.jpg"};

char atk_menu[] = "tileset\\battle_bg\\atk_menu.jpg";

char credits[] = "tileset\\title\\credits.jpg";

char rules[] = "tileset\\title\\rules.jpg";

char arrow[3][50] = {"tileset\\battle_bg\\arrow1.jpg",
                     "tileset\\battle_bg\\arrow2.jpg",
                     "tileset\\battle_bg\\arrow3.jpg"};

char titlearrow[3][50] = {"tileset\\title\\titlearrow1.jpg",
                        "tileset\\title\\titlearrow2.jpg",
                        "tileset\\title\\titlearrow3.jpg"};

char charrow[5][50] = {"tileset\\choose_player\\arrow1.jpg",
                        "tileset\\choose_player\\arrow2.jpg",
                        "tileset\\choose_player\\arrow3.jpg",
                        "tileset\\choose_player\\arrow4.jpg",
                        "tileset\\choose_player\\arrow5.jpg"};

char atk_type[] = "tileset\\battle_bg\\atk_type.jpg";

char knight[2][50] = {"tileset\\knight1.gif","tileset\\knight2.gif"};
char mage[2][50] = {"tileset\\mage1.gif","tileset\\mage2.gif"};
char robin[2][50] = {"tileset\\robin1.jpg","tileset\\robin2.jpg"};
char dragoon[2][50] = {"tileset\\dragoon1.jpg","tileset\\dragoon2.jpg"};
char assassin[2][50] = {"tileset\\assassin1.gif","tileset\\assassin2.gif"};

char moves[5][2][50] = {
                        {"tileset\\battle_bg\\knight_main.jpg",
                         "tileset\\battle_bg\\knight_spec.jpg"},
                        {"tileset\\battle_bg\\mage_main.jpg",
                         "tileset\\battle_bg\\mage_spec.jpg"},
                        {"tileset\\battle_bg\\archer_main.jpg",
                         "tileset\\battle_bg\\archer_spec.jpg"},
                        {"tileset\\battle_bg\\dragoon_main.jpg",
                         "tileset\\battle_bg\\dragoon_spec.jpg"},
                        {"tileset\\battle_bg\\assassin_main.jpg",
                         "tileset\\battle_bg\\assassin_spec.jpg"}
                       };


 void menu(){
    readimagefile(atk_menu,0,300,getmaxx(),getmaxy());
 }

 void menuarrow(int pos){
    readimagefile(arrow[pos-1],0,300,65,getmaxy());
 }

 void play(int no, int clas){
    if(clas == 1)
        readimagefile(knight[no],100+300*no,100,250,250);
    else if(clas == 2)
        readimagefile(mage[no],100+300*no,100,250,250);
    else if(clas == 3)
        readimagefile(robin[no],100+300*no,100,250,250);
    else if(clas == 4)
        readimagefile(dragoon[no],100+300*no,100,250,250);
    else if(clas == 5)
        readimagefile(assassin[no],100+300*no,100,250,250);
 }

void atk_list(bool inside, bool type, int clas){
    if(!inside)
        readimagefile(atk_type,65,310,265,getmaxy()-10);
    else
        readimagefile(moves[clas-1][type],65,310,265,getmaxy()-10);
}

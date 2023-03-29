#include<conio.h>
#include "graphics.h"
#include "winbgim.h"
#include<stdio.h>
#include<iostream>
#include "images.cpp"

using namespace std;

bool knspec = false;
bool drgspec = false;
int mgspec = 0;
int kturn = 0, dturn = 0, mturn = 0;

struct player{
        int hp;
        int mp;
        int clas;
        int str;
        int stab;
        int slash;
        int proj;
};
void battle(player,player);


void itoa(int num, char str[]){

    int temp = num;
    int n = 0;

    while(temp != 0){
        temp /= 10;
        n++;
    }

    for(int j = n-1; j >= 0; j--){
        int rem = num%10;
        str[j] = rem+48;
        num /= 10;
    }

    str[n] = '\0';

}


void attack(player &p1,player &p2,bool type,int sub,char hp[],bool &isdmg){

    itoa(1,hp);
    isdmg = true;
    char mghp[5];
    char ashp[5];

    if(kturn == 1)
        kturn = -1;
    else if(kturn == -1)
        kturn = 1;

    if(dturn == 1)
        dturn = -1;
    else if(dturn == -1)
        dturn = 1;

    if(mturn == 1)
        mturn = -1;
    else if(mturn == -1)
        mturn = 1;

    if(drgspec==true && dturn == 1){
        type=false;
        sub=1;
        drgspec=false;
    }


    if(!type){
        if(sub==1){
            if(p1.clas == 1){
                p2.hp -= p1.str - p2.slash;
                itoa(p1.str - p2.slash,hp);
                isdmg = true;
            }
            else if(p1.clas == 2){
                p2.hp -= p1.str - p2.proj;
                itoa(p1.str - p2.proj,hp);
                isdmg = true;
                outtext(hp);
            }
            else if(p1.clas == 3){
                p2.hp -= p1.str - p2.proj;
                itoa(p1.str - p2.proj,hp);
                isdmg = true;
            }
            else if(p1.clas == 4){
                p2.hp -= p1.str;
                itoa(p1.str,hp);
                isdmg = true;
            }
            else if(p1.clas == 5){
                p2.hp -= p1.str - p2.proj;
                itoa(p1.str - p2.proj,hp);
                isdmg = true;
            }
        }
        else if(sub==2){
            if(p1.clas == 1){
                p2.hp -= p1.str - p2.stab;
                itoa(p1.str - p2.stab,hp);
                isdmg = true;
            }
            else if(p1.clas == 2){
                p2.hp -= p1.str - p2.slash;
                itoa(p1.str - p2.slash,hp);
                isdmg = true;
            }
            else if(p1.clas == 3){
                p2.hp -= p1.str - p2.proj;
                itoa(p1.str - p2.proj,hp);
                isdmg = true;
            }
            else if(p1.clas == 4){
                p1.mp++;
                itoa(1,hp);
                isdmg = false;
            }
            else if(p1.clas == 5){
                p2.hp -= p1.str - p2.stab;
                itoa(p1.str - p2.stab,hp);
                isdmg = true;
            }
        }
        else if(sub==3){
            p1.mp++;
            itoa(1,hp);
            isdmg = false;
        }
    }
    else{
        if((p1.clas != 5 && p1.mp != 0) || (p1.clas == 5 && !(p1.mp <= 1))){
        if(sub==1){
            if(p1.clas == 1){
                p1.str += 20;
                p1.mp--;
                itoa(20,hp);
                isdmg = false;
                kturn = 1;
                knspec = true;
            }
            else if(p1.clas == 2){
                p1.hp += 50;
                p1.mp--;
                itoa(50,hp);
                isdmg = false;
            }
            else if(p1.clas == 3){
                p2.hp -= 2*(p1.str-p2.stab);
                p1.mp--;
                itoa(2*(p1.str-p2.stab),hp);
                isdmg = true;
            }
            else if(p1.clas == 4){
                p1.hp+=50;
                p1.mp--;
                itoa(50,hp);
                dturn = 1;
                drgspec=true;
                isdmg=false;
            }
            else if(p1.clas==5){
                p2.hp -= 100;
                p1.mp -= 2;
                itoa(100,hp);
                isdmg = true;
            }
        }
        else if(sub == 2){
            if(p1.clas == 1){
                p2.hp -= 85;
                p1.mp--;
                itoa(85,hp);
                isdmg = true;
            }
            else if(p1.clas == 2){
                mturn = 1;
                mgspec++;
                p1.mp--;
            }
            else if(p1.clas == 3){
                p2.hp -= 2*(p1.str-p2.slash);
                p1.mp--;
                itoa(2*(p1.str-p2.stab),hp);
                isdmg = true;
            }
            else if(p1.clas == 5){
                p2.hp -= 60;
                p1.hp += 40;
                p1.mp -= 2;
                itoa(40,ashp);
                setcolor(GREEN);
                outtextxy(310,220,ashp);
                itoa(60,hp);
                isdmg = true;
            }
        }
        else if(sub == 3){
            if(p1.clas == 3){
                p2.hp -= 2*(p1.str-p2.proj);
                p1.mp--;
                itoa(2*(p1.str-p2.stab),hp);
                isdmg = true;
            }
        }
        }
    }

    if(mgspec < 3 && mgspec > 0 && mturn == 1){
        p2.hp -= 15;
        itoa(15,mghp);
        setcolor(MAGENTA);
        outtextxy(310,220,mghp);
        mgspec++;
    }

}

int titlescreen(){
    int pos = 1;
    char ch;

    renderscreen(menuscreen);

    for(;;){

        readimagefile(titlearrow[pos-1],160,165,243,412);

        ch = getch();

        if(ch == 'W' || ch == 'w'){
            if(pos != 1){
                    pos--;
            }
        }

        if(ch == 'S' || ch == 's'){
            if(pos != 3){
                    pos++;
            }
        }

        if(ch == 'E' || ch == 'e'){
            return pos;
        }

    }
}

void chooseplayer(player &p1, player &p2){

    int pos = 1;
    char ch;
    renderscreen(playerchoice[0]);
    for(;;){
        readimagefile(charrow[pos-1],200,50,285,444);

        ch = getch();

        if(ch == 'W' || ch == 'w'){
            if(pos != 1){
                    pos--;
            }
        }

        if(ch == 'S' || ch == 's'){
            if(pos != 5){
                    pos++;
            }
        }

        if(ch == 'E' || ch == 'e'){
            if(pos == 1){
                p1.clas = 1;
                p1.hp = 250;
                p1.mp = 3;
                p1.str = 60;
                p1.stab = 25;
                p1.slash = 20;
                p1.proj = 10;
            }
            else if(pos == 2){
                p1.clas = 2;
                p1.hp = 250;
                p1.mp = 3;
                p1.str = 55;
                p1.stab = 20;
                p1.slash = 20;
                p1.proj = 25;
            }
            else if(pos == 3){
                p1.clas = 3;
                p1.hp = 250;
                p1.mp = 3;
                p1.str = 50;
                p1.stab = 10;
                p1.slash = 20;
                p1.proj = 25;
            }
            else if(pos == 4){
                p1.clas = 4;
                p1.hp = 250;
                p1.mp = 3;
                p1.str = 50;
                p1.stab = 25;
                p1.slash = 15;
                p1.proj = 10;
            }
            else if(pos == 5){
                p1.clas = 5;
                p1.hp = 250;
                p1.mp = 3;
                p1.str = 50;
                p1.stab = 15;
                p1.slash = 15;
                p1.proj = 20;
            }
            break;
        }

    }

    renderscreen(playerchoice[1]);

    for(;;){
        readimagefile(charrow[pos-1],200,50,285,444);

        ch = getch();

        if(ch == 'W' || ch == 'w'){
            if(pos != 1){
                    pos--;
            }
        }

        if(ch == 'S' || ch == 's'){
            if(pos != 5){
                    pos++;
            }
        }

        if(ch == 'E' || ch == 'e'){
            if(pos == 1){
                p2.clas = 1;
                p2.hp = 250;
                p2.mp = 3;
                p2.str = 60;
                p2.stab = 25;
                p2.slash = 20;
                p2.proj = 10;
            }
            else if(pos == 2){
                p2.clas = 2;
                p2.hp = 250;
                p2.mp = 3;
                p2.str = 55;
                p2.stab = 20;
                p2.slash = 20;
                p2.proj = 25;
            }
            else if(pos == 3){
                p2.clas = 3;
                p2.hp = 250;
                p2.mp = 3;
                p2.str = 50;
                p2.stab = 10;
                p2.slash = 20;
                p2.proj = 25;
            }
            else if(pos == 4){
                p2.clas = 4;
                p2.hp = 250;
                p2.mp = 3;
                p2.str = 50;
                p2.stab = 25;
                p2.slash = 15;
                p2.proj = 10;
            }
            else if(pos == 5){
                p2.clas = 5;
                p2.hp = 250;
                p2.mp = 3;
                p2.str = 50;
                p2.stab = 15;
                p2.slash = 15;
                p2.proj = 20;
            }
            break;
        }
    }

}

int main(){
    initwindow(640,480,"Game");
    player p1, p2;

    int choice;

    do{

    choice = titlescreen();

    if(choice == 1){
        renderscreen(rules);
        getch();
        chooseplayer(p1,p2);
        battle(p1,p2);
    }
    else if(choice == 2){
        renderscreen(credits);
        getch();
    }
    else if(choice == 3)
        return 0;

    }while(1);

}

void battle(player p1, player p2){
    char ch;
    int pos = 1;
    bool turn = true;
    char hp1[5], hp2[5];
    bool isdmg;

    while(1){
        cleardevice();
        menu();

        play(0,p1.clas);
        play(1,p2.clas);

        if(turn)
            outtextxy(300,50,"Player 1");
        else
            outtextxy(300,50,"Player 2");

        setfillstyle(SOLID_FILL,LIGHTRED);
        if(turn){
            if(!(p1.hp < 0))
                bar(370,350,370 + p1.hp,370);
        }
        else{
            if(!(p2.hp < 0))
                bar(370,350,370 + p2.hp,370);
        }

        if(p1.mp > 3) p1.mp = 3;
        if(p2.mp > 3) p2.mp = 3;

        setfillstyle(SOLID_FILL,LIGHTGREEN);
        if(turn)
            bar(370,420,370+85*p1.mp,440);
        else
            bar(370,420,370+85*p2.mp,440);

        bool type = 0;
        int sub = 1;


        if(!turn && p2.hp <= 0){
            outtextxy(275,200,"Player 1 Wins");
            delay(3000);
            knspec = false;
            drgspec = false;
            mgspec = 0;
            kturn = dturn = mturn = 0;
            break;
        }
        else if(turn && p1.hp <= 0){
            outtextxy(275,200,"Player 2 Wins");
            delay(3000);
            knspec = false;
            drgspec = false;
            mgspec = 0;
            kturn = dturn = mturn = 0;
            break;
        }


        for(;;){

            atk_list(0,type,(turn ? p1.clas : p2.clas));
            menuarrow(pos);

            ch = getch();

            if(ch == 'S' || ch == 's'){
                if(pos != 2)
                    pos++;
            }

            if(ch == 'W' || ch == 'w'){
                if(pos != 1)
                    pos--;
            }

            if(ch == 'E'||ch=='e'){

                if(pos == 1)
                    type = 0;
                else
                    type = 1;

                for(;;){

                    atk_list(1,type,(turn ? p1.clas : p2.clas));
                    menuarrow(pos);

                    ch = getch();

                    if(ch == 'S' || ch == 's'){
                        if(pos != 3)
                            pos++;
                    }

                    if(ch == 'W' || ch == 'w'){
                        if(pos != 1)
                            pos--;
                    }

                    if(ch == 'X'||ch=='x')
                        break;

                    if(ch == 'E' || ch == 'e'){
                            sub = pos;
                            goto att;
                    }

                }

            }

        }

        att:

        if(turn){
            attack(p1,p2,type,sub,hp2,isdmg);
            if(isdmg)
                setcolor(RED);
            else
                setcolor(GREEN);
            outtextxy(310,200,hp2);
            setcolor(WHITE);
        }
        else if(!turn){
            attack(p2,p1,type,sub,hp1,isdmg);
            if(isdmg)
                setcolor(RED);
            else
                setcolor(GREEN);
            outtextxy(310,200,hp1);
            setcolor(WHITE);
        }

        if(ch == 'X' || ch == 'x')
            break;

        delay(1000);

        turn = !turn;
    }
}

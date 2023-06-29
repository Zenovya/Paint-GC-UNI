/*********************************************************/
/*	    UNIVERSIDAD NACIONAL DE INGENIERIA           */
/*	 Facultad de Electrotecnia y Computacion         */
/*                                                       */
/*	            Geometria Computacional              */
/*                                                       */
/*      Grupo: Erick Jeronimo Landero Bracamontes        */
/*		       Jose Luis Lovo Rodriguez          */
/*             Rafael Humberto Poveda Poveda             */
/*                                                       */
/*********************************************************/
/*                  *Version 1.0*                        */
/****************************/
/*        Librerias         */
/****************************/
#include <STDLIB.H>
#include <STDIO.H>
#include <CONIO.H>
#include <GRAPHICS.H>
#include <MOUSE.H>
#include <DOS.H>
#include "PYTHON.h"

/****************************/
/* Prototipado de Funciones */
/****************************/
void Presentacion(void),
PantallaPrincipal(void),
Mouse(void),
Coordenadas(void),
Redraw(int,int,int,int),
PaletaC(int),
SColor(int,int,int);
/****************************/
/*        Macros            */
/****************************/
#define Cuadrado 1
#define Circulo 2
#define Triangulo 3
#define Linea 4
#define Estrella 5
#define ZOOM 6
/****************************/
/*    Variables Globales    */
/****************************/
int driver = DETECT, modo;
int x, y;
int Color;
String Cx[2];
String Cy[2];
/************************************************************************************************************************/
/* MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN */
/************************************************************************************************************************/
void main(){
    initgraph(&driver,&modo,"c:\\TC20\\BIN");
    
    Presentacion();
    PantallaPrincipal();
    Mouse();

closegraph();
exit(1);
}
/************************************************************************************************************************/
/* MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN */
/************************************************************************************************************************/

/************************************************************************************************************************/
/* FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES        FUNCIONES */
/************************************************************************************************************************/
void Presentacion()
{
    setfillstyle (SOLID_FILL ,BLUE);
	bar3d(200,20,155,200,25,1);
	delay(50);
	bar3d(210,200,330,160,25,1);
	delay(50);
	bar3d(280,160,330,80,25,1);
	delay(50);
	bar3d(220,20,340,65,25,1);
	delay(50);
	bar3d(270,145,220,65,0,1);
	delay(50);
	bar3d(340,20,390,200,25,1);
	delay(50);
	bar3d(390,160,410,200,25,1);
	delay(50);
	bar3d(410,70,450,200,25,1);
	delay(50);
	bar3d(410,20,450,60,25,1);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,0,2);
    outtextxy(132,210,"UNIVERSIDAD NACIONAL DE INGENIERIA");
    outtextxy(110,230,"Facultad de electrotecnia y computacion");
    setcolor(YELLOW);
    outtextxy(127,260,"Proyecto de Geometria Computacional");
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(155,290,"Docente: Ing Grevin Alexander Silva");
    outtextxy(100,320,"Presentado por:");
    outtextxy(115,340,"Erick Jeronimo Landero Bracamontes");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(455,345,"2021-0089U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(115,360,"Jose Luis Lovo Rodriguez");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(350,365,"2021-0103U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(115,380,"Rafael Humberto Poveda Poveda");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(410,385,"2021-0272U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(230,420,"Grupo: 2M1 - CO.");
getch();
cleardevice();
}
void PantallaPrincipal()
{
    cleardevice();

    /*Cuadros*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,640,480);
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,0,640,25);
    bar(0,455,640,480);
    bar(170,25,640,53);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(0,25,170,53);
    bar(0,53,640,110);
    setfillstyle(SOLID_FILL,WHITE);
    bar(10,120,630,445);

    /*Interfaz*/
    setcolor(BLACK);
    rectangle(9,119,631,446);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    /*Contornos*/
    line(0,24,171,24);
    line(171,24,171,53);
    line(171,53,640,53);
    line(0,111,640,111);
    line(0,454,640,454);
    /*Separadores*/
    line(85,24,85,58);
    line(85,62,85,107);
    line(277,62,277,107);
    line(367,62,367,107);
        /*Abajo*/
    line(135,455,135,480);
    line(277,455,277,480);
    line(430,455,430,480);
        /*ZOOM*/
    line(500,468,610,468);
    setfillstyle(SOLID_FILL,BLACK);
    bar(554,463,556,473);
        /*Arriba*/
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setfillstyle(SOLID_FILL,WHITE);
    rectangle(586,10,594,18);
    bar(583,14,589,20);
    rectangle(582,13,590,21);

    /*Texto*/
    settextstyle(SMALL_FONT,0,6);
    outtextxy(25,2,"UNI - Paint");
    outtextxy(24,3,"UNI - Paint");
    settextstyle(SMALL_FONT,0,7);
    outtextxy(550,4,"-");
    outtextxy(618,1,"x");
    settextstyle(SMALL_FONT,0,5);
    outtextxy(15,30,"Archivo");
    outtextxy(108,30,"Inicio");
    outtextxy(185,30,"Ver");
    settextstyle(SMALL_FONT,0,4);
	outtextxy(13,97,"Seleccionar");
    outtextxy(298,97,"Borrador");
    outtextxy(383,97,"Color");
        /*Abajo*/
    outtextxy(15,463,"(+)");
    outtextxy(150,463,"[] 640 x 480 pixeles");
    outtextxy(440,463,"100%");
    outtextxy(330,463,"2M1 - CO");
    settextstyle(DEFAULT_FONT,0,1);
    outtextxy(478,465,"-");
    outtextxy(625,465,"+");

    /*Iconos*/
        /*Dibujo*/
	setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(11,6,20,20);
    setfillstyle(SOLID_FILL,BLACK);
    bar(15,2,16,3);
    rectangle(11,6,20,20);
	setfillstyle(SOLID_FILL,RED);
    bar(11,11,15,17);
    rectangle(11,11,15,17);
    putpixel(12,5,BLACK);
    putpixel(13,4,BLACK);
    putpixel(14,4,BLACK);
    putpixel(17,4,BLACK);
    putpixel(18,4,BLACK);
    putpixel(19,5,BLACK);

        /*Seleccionar*/
    setlinestyle(DOTTED_LINE,0,THICK_WIDTH);
    rectangle(15,64,71,96);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        /*Borrador*/
    setfillstyle(SOLID_FILL,LIGHTRED);
    bar3d(325,85,300,95,20,1);
    floodfill(328,90,BLACK);
    floodfill(325,75,BLACK);
        /*Colores*/
		PaletaC(Color);
    /*Figuras*/
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        /*Cuadrado*/
    rectangle(98,70,124,96);
        /*Circulo*/
    circle(145,83,14);
        /*Triangulo*/
    line(163,96,176,70);
    line(164,96,177,70);
    line(162,96,175,70);
    line(176,70,191,96);
    line(175,70,190,96);
    line(177,70,192,96);
    line(190,96,163,96);
    line(190,95,163,95);
    line(190,97,163,97);
        /*Linea*/
    line(197,70,213,96);
    line(196,70,212,96);
    line(198,70,214,96);
}
void Mouse()
{   
    int AuxColor;
    bool DrawFree = TRUE;
    bool Pincel = FALSE;
    msituar(1,getmaxx()/2,getmaxy()/2);

    do{
        x = mxpos(1);
        y = mypos(1);
        mver();
        Coordenadas();
        AuxColor = getpixel(629,444);
        /*Animaciones*/
        if(minlimit(1,615,8,629,22) == 1){
            setcolor(RED);
            settextstyle(SMALL_FONT,0,7);
            outtextxy(618,1,"x");
            outtextxy(617,1,"x");
            outtextxy(619,1,"x");
            delay(300);
            setfillstyle(SOLID_FILL,WHITE);
            bar(615,8,631,22);
            setcolor(BLACK);
            outtextxy(618,1,"x");
        }
        if(minlimit(1,576,1,601,25) == 1){
            mocultar();
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(576,1,601,25);
            setlinestyle(SOLID_LINE,0,NORM_WIDTH);
            rectangle(586,10,594,18);
            bar(583,14,589,20);
            rectangle(582,13,590,21);
            delay(300);
            setfillstyle(SOLID_FILL,WHITE);
            bar(576,1,601,25);
            setlinestyle(SOLID_LINE,0,NORM_WIDTH);
            rectangle(586,10,594,18);
            bar(583,14,589,20);
            rectangle(582,13,590,21);
        }
        if(minlimit(1,541,1,567,25) == 1){
            mocultar();
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(541,1,567,25);
            settextstyle(SMALL_FONT,0,7);
            outtextxy(550,4,"-");
            delay(300);
            setfillstyle(SOLID_FILL,WHITE);
            bar(541,1,567,25);
            outtextxy(550,4,"-");
        }
        if(minlimit(1,1,1,130,22) == 1){
            setcolor(BLUE);
            settextstyle(SMALL_FONT,0,6);
            outtextxy(25,2,"UNI - Paint");
            outtextxy(24,3,"UNI - Paint");
            delay(300);
            setcolor(BLACK);
            settextstyle(SMALL_FONT,0,6);
            outtextxy(25,2,"UNI - Paint");
            outtextxy(24,3,"UNI - Paint");
        }
        /*Botones*/
        if(mclick() == 1 && minlimit(1,615,8,629,22) == 1){
        mocultar();
        setcolor(RED);
        settextstyle(SMALL_FONT,0,7);
        outtextxy(618,1,"x");
        outtextxy(617,1,"x");
        outtextxy(619,1,"x");
        delay(500);
        exit(1);
        }
        if(mclick() == 1 && minlimit(1,1,1,130,22) == 1){
        mocultar();
        settextstyle(SMALL_FONT,0,5);
		outtextxy(232,1,"UNIVERSIDAD NACIONAL DE INGENIERIA");
        outtextxy(215,13,"Facultad de Electrotecnia y Computacion");
        outtextxy(265,25,"Geometria Computacional");
        delay(1000);
        setfillstyle(SOLID_FILL,WHITE);
        bar(214,1,510,40);
        outtextxy(225,1,"Erick Jeronimo Landero Bracamontes");
        outtextxy(225,13,"Jose Luis Lovo Rodriguez");
        outtextxy(225,24,"Rafael Humberto Poveda Poveda");
        delay(1000);
        bar(220,1,500,40);
        }
        if(mclick() == 1 && minlimit(1,x,463,x+2,473) == 1){
            AuxColor = WHITE;
            mocultar();
                while (mclick() == 1)
                {   
                    mlimit(1,500,y,610,y);
                    x = mxpos(1);
                    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
                    line(500,468,610,468);
                    
                    Redraw(ZOOM,x,y,AuxColor);
                    mlimitMax();
                }
        }
        if(mclick() == 1 && minlimit(1,94,66,128,100) == 1){
            DrawFree = FALSE;
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(94,66,128,100);
            delay(100);
            setcolor(LIGHTGRAY);
            rectangle(94,66,128,100);

            if(mclick() == 1 && minlimit(1,10,120,630,445) == 1 && DrawFree == FALSE){
                while (mclick() == 1)
                {
                    mlimit(1,12,123,588,402);
                    mocultar();
                    x = mxpos(1);
                    y = mypos(1);

                    Redraw(Cuadrado,x,y,AuxColor);
                    DrawFree = TRUE;
                    mver();
                    mlimitMax();
                }
            }
        }
        if(mclick() == 1 && minlimit(1,128,66,161,100) == 1){
            DrawFree = FALSE;
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(128,66,161,100);
            delay(100);
            setcolor(LIGHTGRAY);
            rectangle(128,66,161,100);

            if(mclick() == 1 && minlimit(1,10,120,630,445) == 1 && DrawFree == FALSE){
                while (mclick() == 1)
                {
					mlimit(1,33,143,607,422);
                    mocultar();
                    x = mxpos(1);
                    y = mypos(1);

                    Redraw(Circulo,x,y,AuxColor);
                    DrawFree = TRUE;
                    mver();
                    mlimitMax();
                }
                
            }
        }
        if(mclick() == 1 && minlimit(1,161,66,194,100) == 1){
            DrawFree = FALSE;
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(161,66,194,100);
            delay(100);
            setcolor(LIGHTGRAY);
            rectangle(161,66,194,100);

            if(mclick() == 1 && minlimit(1,10,120,630,445) == 1 && DrawFree == FALSE){
                while (mclick() == 1)
                {
                    mlimit(1,12,162,588,442);
                    mocultar();
                    x = mxpos(1);
                    y = mypos(1);
                    Redraw(Triangulo,x,y,AuxColor);
                    DrawFree = TRUE;
                    mver();
                    mlimitMax();
                }
            }
        }
        if(mclick() == 1 && minlimit(1,194,66,225,100) == 1){
            DrawFree = FALSE;
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(194,66,225,100);
            delay(100);
            setcolor(LIGHTGRAY);
            rectangle(194,66,225,100);

            if(mclick() == 1 && minlimit(1,10,120,630,445) == 1 && DrawFree == FALSE){
                while (mclick() == 1)
                {
                    mlimit(1,30,150,500,400);
                    mocultar();
                    x = mxpos(1);
                    y = mypos(1);
                    Redraw(Linea,x,y,AuxColor);
                    DrawFree = TRUE;
                    mver();
                    mlimitMax();   
                }
            }
        }
        if(mclick() == 1 && minlimit(1,295,66,350,108) == 1 || mclick() == 2 && minlimit(1,295,66,350,108) == 1){
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(295,66,350,108);
            delay(100);
            setcolor(LIGHTGRAY);
            rectangle(295,66,350,108);

            if(mclick() == 1 && minlimit(1,295,66,350,108) == 1){
                mlimit(1,11,122,608,423);
                msituar(1,getmaxx()/2,getmaxy()/2);
                while (mclick() != 2)
                {
                    mocultar();
                    x = mxpos(1);
                    y = mypos(1);
                    setcolor(BLACK);
                    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    rectangle(x-1,y-1,x+21,y+21);
                    setfillstyle(SOLID_FILL,WHITE);
                    bar(x,y,x+20,y+20);
                    delay(20);
                    setcolor(WHITE);
                    rectangle(x-1,y-1,x+21,y+21);
                    setfillstyle(SOLID_FILL,WHITE);
                    bar(x,y,x+20,y+20);
                    mver();
                }
                mlimitMax(); 
            }
            if(mclick() == 2 && minlimit(1,295,66,350,108) == 1){
                mocultar();
                delay(100);
                setfillstyle(SOLID_FILL,WHITE);
                bar(9,120,630,445);
                setcolor(BLACK);
                setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                rectangle(9,119,631,446);
                mver();
                msituar(1,getmaxx()/2,getmaxy()/2);
            }
        }
        /*Boton Seleccionar*/
        /*Dibujo Libre + Borrador Libre*/
        if(DrawFree == TRUE){
            if(mclick() == 1 && minlimit(1,10,120,625,440) == 1){
            mlimit(1,10,120,625,440);
            while (mclick() == 1)
            {   
                mocultar();
                x = mxpos(1);
                y = mypos(1);
                setfillstyle(SOLID_FILL,Color);
                bar(x,y,x+5,y+5);
                mver();
            }
            mlimitMax();
        }else if(mclick() == 2 && minlimit(1,11,122,608,423) == 1){
            mlimit(1,11,121,609,424);
            while (mclick() == 2)
            {   
                mocultar();
                x = mxpos(1);
                y = mypos(1);
                setcolor(BLACK);
                setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                rectangle(x-1,y-1,x+21,y+21);
                setfillstyle(SOLID_FILL,WHITE);
                bar(x,y,x+20,y+20);
                delay(20);
                setcolor(WHITE);
                rectangle(x-1,y-1,x+21,y+21);
                setfillstyle(SOLID_FILL,WHITE);
                bar(x,y,x+20,y+20);
                mver();
            }
            mlimitMax();
        }
        }
        /*Colores*/
        if(mclick() == 1 && minlimit(1,423,61,622,108) == 1){
            while (mclick() == 1)
            {
                x = mxpos(1);
                y = mypos(1);
                Color = getpixel(x,y);
                PaletaC(Color);
            }
        }
        if(mclick() == 1 && minlimit(1,379,64,411,96) == 1){
            DrawFree = FALSE;
            mocultar();
            setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
            rectangle(379,64,411,96);
            delay(100);
            setcolor(WHITE);
            rectangle(379,64,411,96);
            Pincel = TRUE;
        }
        if(Pincel == TRUE){
            if(mclick() == 1 && minlimit(1,10,120,630,445) == 1){
                mlimit(1,10,120,630,445);
                mocultar();
                x = mxpos(1);
                y = mypos(1);
                SColor(Color,x,y);
                mver();
                DrawFree = TRUE;
                Pincel = FALSE;
                mlimitMax();
                setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                setcolor(Color);
                rectangle(379,64,411,96);
            }
        }
    } while (1);
}
void Coordenadas(){
    setcolor(BLACK);
    itoa(x,Cx,10);
    itoa(y,Cy,10);

    settextstyle(SMALL_FONT,0,4);
    outtextxy(32,463,Cx);
    outtextxy(52,463,",");
    outtextxy(58,463,Cy);
    delay(50);
    setfillstyle(SOLID_FILL,WHITE);  
    bar(30,460,80,475);
}
void Redraw(int tipo, int x, int y, int Color){
    switch (tipo)
    {
    case Cuadrado:
        setcolor(BLACK);
        setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        rectangle(x,y,x+40,y+40);
        setcolor(Color);
        rectangle(x,y,x+40,y+40);
        
        if(mclick() != 1){
            setcolor(BLACK);
            rectangle(x,y,x+40,y+40);
        }
    break;

    case Circulo:
        setcolor(BLACK);
        setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        circle(x,y,20);
        setfillstyle(SOLID_FILL,Color);
        bar(x-21,y-21,x+21,y+21);

        if(mclick() != 1){
            setcolor(BLACK);
            setlinestyle(SOLID_LINE,0,THICK_WIDTH);
            circle(x,y,20);
        }
    break;

    case Triangulo:
        setcolor(BLACK);
        setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        line(x,y,x+20,y-40);
        line(x+20,y-40,x+40,y);
        line(x,y,x+40,y);

        setcolor(Color);
        line(x,y,x+20,y-40);
        line(x+20,y-40,x+40,y);
        line(x,y,x+40,y);

        if(mclick() != 1){
            setcolor(BLACK);
            setlinestyle(SOLID_LINE,0,THICK_WIDTH);
            line(x,y,x+20,y-40);
            line(x+20,y-40,x+40,y);
            line(x,y,x+40,y);
        }
    break;

    case Linea:
        setcolor(BLACK);
        setlinestyle(SOLID_LINE,0,THICK_WIDTH);
        line(x,y,x+60,y+20);
        line(x,y,x+61,y+21);

        setcolor(Color);
        line(x,y,x+60,y+20);
        line(x,y,x+61,y+21);

        if(mclick() != 1){
            setcolor(BLACK);
            setlinestyle(SOLID_LINE,0,THICK_WIDTH);
            line(x,y,x+60,y+20);
            line(x,y,x+61,y+21);
        }
    break;

    case Estrella:

    break;

    case ZOOM:
        setfillstyle(SOLID_FILL,BLACK);
        bar(x,463,x+2,473);
        setfillstyle(SOLID_FILL,WHITE);
        bar(x-1,463,x+2,473);

        if(mclick() != 1){
            setfillstyle(SOLID_FILL,BLACK);
            bar(x,463,x+2,473);
        }
    break;
    }
}
void PaletaC(int Color){
    int x = 50;
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
    setfillstyle(SOLID_FILL,BLACK);
    rectangle(374+x,62,396+x,84);
    bar(375+x,63,395+x,83);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(399+x,62,421+x,84);
    bar(400+x,63,420+x,83);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(424+x,62,446+x,84);
    bar(425+x,63,445+x,83);
    setfillstyle(SOLID_FILL,CYAN);
    rectangle(449+x,62,471+x,84);
    bar(450+x,63,470+x,83);
    setfillstyle(SOLID_FILL,RED);
    rectangle(474+x,62,496+x,84);
    bar(475+x,63,495+x,83);
    setfillstyle(SOLID_FILL,MAGENTA);
    rectangle(499+x,62,521+x,84);
    bar(500+x,63,520+x,83);
    setfillstyle(SOLID_FILL,BROWN);
    rectangle(524+x,62,546+x,84);
    bar(525+x,63,545+x,83);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    rectangle(549+x,62,571+x,84);
    bar(550+x,63,570+x,83);
    /***********************************/
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(374+x,85,396+x,107);
    bar(375+x,86,395+x,106);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    rectangle(399+x,85,421+x,107);
    bar(400+x,86,420+x,106);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    rectangle(424+x,85,446+x,107);
    bar(425+x,86,445+x,106);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    rectangle(449+x,85,471+x,107);
    bar(450+x,86,470+x,106);
    setfillstyle(SOLID_FILL,LIGHTRED);
    rectangle(474+x,85,496+x,107);
    bar(475+x,86,495+x,106);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    rectangle(499+x,85,521+x,107);
    bar(500+x,86,520+x,106);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(524+x,85,546+x,107);
    bar(525+x,86,545+x,106);
    setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(549+x,85,571+x,107);
    bar(550+x,86,570+x,106);

    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setfillstyle(SOLID_FILL,Color);
    rectangle(379,64,411,96);
    bar(380,65,410,95);
}
void SColor(int Color, int x, int y){
    setfillstyle(SOLID_FILL,Color);
	floodfill(x,y,BLACK);
}
/************************************************************************************************************************/
/* FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES        FUNCIONES */
/************************************************************************************************************************/

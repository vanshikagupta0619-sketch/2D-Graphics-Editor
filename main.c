#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY'_'
#define PIXEL '*'

char picture[HEIGHT][WIDTH];

void clearPicture()
{
    int i,j;

for(i=0;i<HEIGHT;i++)
{
for(j=0;i<HEIGHT;i++)
{
picture[i][j]=EMPTY;
}
}
}
void displayPicture()
{
    int i,j;
for(i=0;i<HEIGHT;i++)
{
for(j=0;j<WIDTH;j++)
{
printf("%c",picture[i][j]);
}
printf("\n");
}
}
void setPixel(int x,int y)
{
    if(x>=0&&x<WIDTH&&y>=0&&y<HEIGHT)
{
picture[y][x]=PIXEL;
}
}
void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1);
int dy=abs(y2-y1);
int sx=(x1<x2)?1:-1;
int sy=(y1<y2)?1:-1;
int err=dx-dy;
while(1)
{
setPixel(x1,y1);
if(x1==x2&&y1==y2)
{
break;
}
int e2=2*err;
if(e2>-dy)
{
err-=dy;
x1+=sy;
}
}
}
void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1,y1,x2,y1);
drawLine(x2,y1,x2,y2);
drawLine(x2,y2,x1,y2);
drawLine(x1,y2,x1,y1);
}
void drawCircle(int cx,int cy,int radius)
{
    int x,y;
for(y=0;y<HEIGHT;y++)
{
for(x=0;x<WIDTH;x++)
{
int dx=x-cx;
int dy=y-cy;
int distSq=dx*dx+dy*dy;
int radiusSq=radius*radius;
if(abs(distSq-radiusSq)<=radius)
{
setPixel(x,y);
}
}
}
}
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    drawLine(x1,y1,x2,y2);
drawLine(x2,y2,x3,y3);
drawLine(x3,y3,x1,y1);
}
    

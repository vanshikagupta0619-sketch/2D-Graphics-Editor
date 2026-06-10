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
int main()
{
    int choice;
clearPicture();
printf("2D graphics editor\n");
printf("canvas size:%d x %d\n",WIDTH,HEIGHT);
printf("use coordinates x y.\n");
printf("x range:0 to %d\n",WIDTH-1);
printf("y range 0 to %d\n",HEIGHT-1);
while(1)
    {
printf("\nMenu\n");
printf("1.Draw line\n");
printf("2.Draw rectangle\n");
printf("3.draw circle\n");
printf("4.Draw triangle\n");
printf("5.Display picture\n");
printf("0.Exit\n");
printf("Enter choice:");
scanf("%d", &choice);
if (choice==1)
{
int x1,y1,x2,y2;
printf("enter x1 y1 x2 y2:");
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
drawLine(x1,y1,x2,y2);
}
else if(choice==2)
{
int x1,y1,x2,y2;
printf("enter top-left xy and bottom-right xy:");
scanf("%d %d %d d",&x1,&y1,&x2,&y2);
drawRectangle(x1,y1,x2,y2);
}
else if(choice==3)
    int cx,cy,radius;
printf("enter center x y and radius:");
scanf("%d %d %d",&cx,&cy,&radius);
drawCircle(cx,cy,radius);
}
else if(choice==4)
{
int x1,y1,x2,y2,x3,y3;
printf("enter x1,y1,x2,y2,x3,y3");
scanf("%d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
drawTraingle(x1,y1,x2,y2,x3,y3);
}
else if(choice==5)
{
printf("the picture is:\n");
displayPicture();
}
else if(choice==0)
{
printf("exiting program.\n");
break;
}
else
{
printf("invalid choice\n");
}
}
return 0;
}
    
    

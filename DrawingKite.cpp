#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;
  int c=0;


void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f); // Yellow
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {

	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
	if(c==0)
    {
        c++;
        x1=80; y1=400; x2=110; y2=300;
        draw_line(x1,x2,y1,y2);

    }
    else if(c==1)
    {
        c++;
        x1=50; y1=300; x2=110; y2=300;
        draw_line(x1,x2,y1,y2);

    }
    else if(c==2)
    {
        c++;
        x1=50; y1=300; x2=80; y2=100;
        draw_line(x1,x2,y1,y2);

    }
     else if(c==3)
    {
        c++;
        x1=80; y1=100; x2=110; y2=300;
        draw_line(x1,x2,y1,y2);

    }
    else if(c==4)
    {
        c++;
        x1=80; y1=400; x2=80; y2=100;
        draw_line(x1,x2,y1,y2);

    }

}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
	draw_line(x1, x2, y1, y2);
	glFlush();
}

int main(int argc, char **argv) {

	//printf( "Enter (x1, y1, x2, y2)\n");
	//scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	x1=50; y1=300; x2=80; y2=400;
	glutDisplayFunc(myDisplay);

	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

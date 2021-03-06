#include <GL/glut.h>
#include <stdio.h>
int r,h,k;
void init()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat specular[]={1.0,1.0,1.0,1.0};
    GLfloat light_position[]={1.0,1.0,0.0,0.0};
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0,GL_POSITION, light_position);

   glShadeModel(GL_FLAT);
   float color[]={0.0f,1.0f,0.0f,1.0f};
   glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,color);
    glEnable(GL_DEPTH_TEST);
    glOrtho(-100.0,100.0,-100.0,100.0,-100.0,100.0);
}
void sphere()
{
   printf("\nEnter the radius of sphere: ");
   scanf("%d",&r);
   glColor3f(1.0f,0.0f,0.0f); 
   glutWireSphere(r, 50, 50);
   glFlush();
}
void cone()
{
   printf("\nEnter the base radius of cone: ");
   scanf("%d",&r);
   printf("\nEnter the height of cone: ");
   scanf("%d",&h);
   glColor3f(0.0f,1.0f,0.0f); 
   glutWireCone(r,h, 50, 50);
   glFlush();
}
void cube()
{
   printf("\nEnter the side of cube: ");
   scanf("%d",&r);
   glColor3f(0.0f,0.0f,1.0f); 
   glutWireCube(r);
   glFlush();
}
void display(void)
{	
glRotatef( 20, 1.0, 0.0, 0.0 );
glRotatef( -20, 0.0, 1.0, 0.0 );
while(1)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   printf("1.Sphere\n2.Cone\n3.Cube\n0.Exit");
   printf("\nEnter Your Choice : ");
   scanf("%d",&k);
   if(k==1)
      sphere();
   else if(k==2)
      cone();
   else if(k==3)
      cube();
   else if(k==0)
      break;
   else
      printf("Wrong Choice\n");
}
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("3D");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// Radius of sphere - 40
// Radius of cone - 40, height of cone - 40
// Side of cube - 40
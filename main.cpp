#include <iostream> // Visual Studio & MacOS用
#include <GLUT/GLUT.h> // MacOS用 (Visual Studio利用の場合この行を削除する)

// #include <Windows.h> // Visual Studio用
// #include <GL\glew.h> // Visual Studio用
// #include <GL\freeglut.h> // Visual Studio用

//球体を作成する関数
void createSphere(float x, float y, float z){
    glTranslatef(x, y, z); //座標
    glutSolidSphere(0.1 /*半径*/, 20.0, 20.0);
}

//線を作成する関数
void createLine(float startX, float startY, float startZ, float endX, float endY, float endZ){
    glBegin(GL_LINES);
        glVertex3f(startX , startY, startZ); //スタート座標
        glVertex3f(endX , endY, endZ); //終了座標
    glEnd();
}

//軸を作成する関数
void createAxis(){
    glColor3f(1, 0, 0); //色を赤に変更
    createLine(-10.0, 0, 0, 10.0, 0, 0);
    
    glColor3f(0, 0, 1); //色を青に変更
    createLine(0, -10.0, 0, 0, 10.0, 0);
    
    glColor3f(1, 1, 1); //色を白に変更
}

//画面に映る関数
void display( void ) {
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
   
    glPushMatrix();
    
    createAxis();
    
    createLine(-0.1, 0.1, 0, -0.3, 0.1, 0);
    createSphere(0.3, 0.3, 0);
    
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

//プログラムの開始位置
int main(int argc , char ** argv) {
    glutInit(&argc , argv);
    glutInitWindowPosition(500 , 100);
    glutInitWindowSize(800 , 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("We love TCC!");
    
    glutDisplayFunc(display); //画面に映る関数をここで呼び出す

    glutMainLoop();
    return 0;
}

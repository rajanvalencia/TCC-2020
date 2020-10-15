#include <iostream> // Visual Studio & MacOS用
#include <GLUT/GLUT.h> // MacOS用 (Visual Studio利用の場合この行を削除する)

// #include <Windows.h> // Visual Studio用
// #include <GL\glew.h> // Visual Studio用
// #include <GL\freeglut.h> // Visual Studio用

//球体を作成する関数
void createSphere(float x, float y, float z){
    glTranslatef(x, y, z); //座標
    glutSolidSphere(0.2 /*半径*/, 20.0, 20.0);
}

//線を作成する関数
void createLine(float startX, float startY, float endX, float endY){
    glBegin(GL_LINES);
        glVertex2f(startX , startY); //スタート座標
        glVertex2f(endX , endY); //終了座標
    glEnd();
}

//画面に映る関数
void display( void ) {
    
    createLine(-10.0, 0, 10.0, 0);
    createLine(0, -10.0, 0, 10.0);
    createSphere(0, 0, 0);

    glFlush();
}

//プログラムの開始位置
int main(int argc , char ** argv) {
    glutInit(&argc , argv);
    glutInitWindowPosition(1000 , 100);
    glutInitWindowSize(800 , 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    glutCreateWindow("We love TCC!");
    
    glutDisplayFunc(display); //画面に映る関数をここで呼び出す

    glutMainLoop();
    return 0;
}

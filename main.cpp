#include <iostream> // Visual Studio & MacOS用
#include <GLUT/GLUT.h> // MacOS用 (Visual Studio利用の場合この行を削除する)

// #include <Windows.h> // Visual Studio用
// #include <GL\glew.h> // Visual Studio用
// #include <GL\freeglut.h> // Visual Studio用

int WindowWidth = 1024;    //生成するウィンドウの幅
int WindowHeight = 1024;    //生成するウィンドウの高さ
int k = 2, n = 2;  //kはアリティ nは次元
float moveX = 0, moveY = 0, moveZ = 1.0;

//球体を作成する関数
void createSphere(float x, float y, float z){
    glPushMatrix();
    glTranslatef(x, y, z); //座標
    glutSolidSphere(0.05 /*半径*/, 20.0, 20.0);
    glPopMatrix();
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
    createLine(-1000.0, 0, 0, 1000.0, 0, 0); //x軸
    
    glColor3f(0, 0, 1); //色を青に変更
    createLine(0, -1000.0, 0, 0, 1000.0, 0); //y軸
    
    glColor3f(1, 1, 1); //色を白に変更
}

//2次元のサイクルを作成する関数
void create2dCycle(float x, float y, float z){
    float distance = 0.2;
    createSphere(x, y, z); //左の球体
    createSphere(x + distance, y + distance, z); //上の球体
    createSphere(x + 2 * distance, y, z); //右の球体
    createSphere(x + distance, y - distance, z); //下の球体
    
    createLine(x, y, z, x + distance, y + distance, z); //左上の線
    createLine(x + distance, y + distance, z, x + 2 * distance, y, z); //右上の線
    createLine(x + 2 * distance, y, z, x + distance, y - distance, z); //右下上の線
    createLine(x + distance, y - distance, z, x, y, z); //左下の線
}

//2次元のサイクルとサイクルのつながりを作成する関数
void create2dConnection(float x, float y, float z){
    
}

//2次元のTCCを作成する関数
void create2dTCC(float x, float y, float z){
}

//画面に映る関数
void display( void ) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //バッファの消去x
    
    glPushMatrix();
    
    glTranslatef(moveX, moveY, moveZ);
    createAxis(); //軸を作成
    create2dTCC(0, 0, 0);
    
    glPopMatrix();
    
    glFlush();
}

//キーボードで操作する関数
void keyboardFunctions(unsigned char key, int a, int b){
    float distance_to_move = 0.1;

    glutPostRedisplay();
}

//初期設定の関数
void initialize(void) {
    glViewport(0, 0, WindowWidth, WindowHeight);
    glEnable(GL_DEPTH_TEST); //デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
    gluPerspective(30.0, (double)WindowWidth / (double)WindowHeight, 0.1, 1200); //透視投影法の視体積gluPerspactive(縦角度,横角度, 一番近いｚ軸, 一番遠いｚ軸);
    gluLookAt(0.0, 0.0, 10.0,                   //視点の位置
              0.0, 0.0, 0.0,  //視点の位置からの視点の中心
              0.0, 1.0, 0.0);                 //視点の上
}

//プログラムの開始位置
int main(int argc, char ** argv) {
    glutInit(&argc , argv);
    glutInitWindowPosition(500 , 100);
    glutInitWindowSize(WindowWidth, WindowHeight);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("We love TCC!");
    initialize(); //初期設定
    glutDisplayFunc(display); //画面に映る関数をここで呼び出す
    glutKeyboardFunc(keyboardFunctions);
    glutMainLoop();
    return 0;
}

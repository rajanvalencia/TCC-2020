#include <iostream> // Visual Studio & MacOS用
#include <GLUT/GLUT.h> // MacOS用 (Visual Studio利用の場合この行を削除する)

// #include <Windows.h> // Visual Studio用
// #include <GL\glew.h> // Visual Studio用
// #include <GL\freeglut.h> // Visual Studio用

int WindowWidth = 1024;    //生成するウィンドウの幅
int WindowHeight = 1024;    //生成するウィンドウの高さ
int k = 1, n = 2;  //kはアリティ nは次元

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
    
}

//2次元のサイクルとサイクルのつながりを作成する関数
void create2dConnection(float x, float y, float z){
    
}

//2次元のTCCを作成する関数
void create2dTCC(){
    
}

//画面に映る関数
void display( void ) {
    
    glPushMatrix();
    
    createAxis(); //軸を作成
    
    createLine(-0.1, 0.1, 0, -0.3, 0.1, 0); //線を作成
    
    createLine(0.1, 0.1, 0, 0.3, 0.1, 0); //線を作成
    createSphere(0.3, 0.3, 0); //球体を作成
    
    createSphere(0.3, 0, 0); //球体を作成
    
    glPopMatrix();

    glFlush();
}

//初期設定の関数
void initialize(void) {
    glViewport(0, 0, WindowWidth, WindowHeight);
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //色の初期化
    glEnable(GL_DEPTH_TEST); //デプスバッファを使用：glutInitDisplayMode() で GLUT_DEPTH を指定する
    
    gluPerspective(30.0, (double)WindowWidth / (double)WindowHeight, 0.1f, 100.0f); //透視投影法の視体積gluPerspactive(縦角度,横角度, 一番近いｚ軸, 一番遠いｚ軸);
    gluLookAt(0.0, 0.0, -4,  //視点の位置
              0.0, 0.0, 0.0,  //視点の位置からの視点の中心
              0.0, -1.0, 0.0);//視点の上
    glLoadIdentity();
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
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}

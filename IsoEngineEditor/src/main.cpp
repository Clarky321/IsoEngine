#include <IsoEngineCore/Window.h>

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const char* TITLE = "IsometricEngine";

    // �������� ���������� ������ Window
    Window window(WIDTH, HEIGHT, TITLE);

    // ������� ���� ����������
    while (!window.shouldClose()) {
        // ���������� ����
        window.update();
    }

    return 0;
}
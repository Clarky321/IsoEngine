#include <IsoEngineCore/Window.h>

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const char* TITLE = "IsometricEngine";

    // Создание экземпляра класса Window
    Window window(WIDTH, HEIGHT, TITLE);

    // Главный цикл приложения
    while (!window.shouldClose()) {
        // Обновление окна
        window.update();
    }

    return 0;
}
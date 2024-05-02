#include "IsoEngineCore/Window.h"

Window::Window(int width, int height, const char* title) {
    // Инициализация GLFW
    if (!glfwInit()) {
        // Обработка ошибки инициализации
        // Например, вывод сообщения в консоль или запись в журнал
    }

    // Создание окна
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        // Обработка ошибки создания окна
        // Например, вывод сообщения в консоль или запись в журнал
        glfwTerminate();
    }

    // Установка окна как текущего контекста OpenGL
    glfwMakeContextCurrent(window);
}

Window::~Window() {
    // Уничтожение окна
    glfwDestroyWindow(window);

    // Завершение работы GLFW
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::update() const {
    // Обновление окна
    glfwSwapBuffers(window);

    // Проверка событий (например, нажатия клавиш, перемещения мыши)
    glfwPollEvents();
}
#include "IsoEngineCore/Window.h"

Window::Window(int width, int height, const char* title) {
    // ������������� GLFW
    if (!glfwInit()) {
        // ��������� ������ �������������
        // ��������, ����� ��������� � ������� ��� ������ � ������
    }

    // �������� ����
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        // ��������� ������ �������� ����
        // ��������, ����� ��������� � ������� ��� ������ � ������
        glfwTerminate();
    }

    // ��������� ���� ��� �������� ��������� OpenGL
    glfwMakeContextCurrent(window);
}

Window::~Window() {
    // ����������� ����
    glfwDestroyWindow(window);

    // ���������� ������ GLFW
    glfwTerminate();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::update() const {
    // ���������� ����
    glfwSwapBuffers(window);

    // �������� ������� (��������, ������� ������, ����������� ����)
    glfwPollEvents();
}
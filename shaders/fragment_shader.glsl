#version 330 core

in vec3 FragPos; // Позиция фрагмента в мировых координатах
in vec3 Normal; // Нормаль фрагмента

out vec4 FragColor; // Цвет фрагмента

uniform vec3 lightPos; // Позиция источника света
uniform vec3 lightColor; // Цвет источника света
uniform vec3 objectColor; // Цвет объекта

void main()
{
    // Нормализация нормали и направления света
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    // Рассчет интенсивности диффузного освещения
    float diff = max(dot(norm, lightDir), 0.0);

    // Рассчет диффузной составляющей
    vec3 diffuse = diff * lightColor * objectColor;

    // Конечный цвет фрагмента
    FragColor = vec4(diffuse, 1.0);
}
#version 330 core

layout (location = 0) in vec3 aPos; // Позиция вершины
layout (location = 1) in vec3 aNormal; // Нормаль

out vec3 FragPos; // Позиция фрагмента в мировых координатах
out vec3 Normal; // Нормаль фрагмента

uniform mat4 projection; // Матрица проекции
uniform mat4 view; // Матрица вида
uniform mat4 model; // Матрица модели

void main()
{
    // Преобразование позиции вершины в мировые координаты
    vec4 worldPos = model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;

    // Перевод нормали в мировое пространство
    Normal = mat3(transpose(inverse(model))) * aNormal;

    // Преобразование вершины в координаты отображения
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
# Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.12)

# Определение названия проекта IsoEngineCore
set(ENGINE_PROJECT_NAME IsoEngineCore)

# Список публичных заголовочных файлов
set(ENGINE_PUBLIC_INCLUDES
	includes/IsoEngineCore/test.h
	includes/IsoEngineCore/Window.h
)

# Список приватных исходных файлов
set(ENGINE_PRIVATE_SOURCES
	src/IsoEngineCore/test.cpp
	src/IsoEngineCore/Window.cpp
)

# Общий список исходных файлов
set(ENGINE_ALL_SOURCE
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

# Создание статической библиотеки с названием IsoEngineCore
add_library(${ENGINE_PROJECT_NAME} STATIC ${ENGINE_ALL_SOURCE})

# Группировка файлов в структуру проекта в IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_ALL_SOURCE})

# Добавление путей к заголовочным файлам для внешних пользователей и для компиляции
target_include_directories(${ENGINE_PROJECT_NAME}
	PUBLIC
		includes
	PRIVATE
		src
)

# Установка стандарта C++ для компиляции
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

# ------------------------------------------------------------------------------------- #

# Добавление подмодуля GLAD и его сборка
add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
# Линковка с библиотекой GLAD
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glad)

# Добавление подмодуля GLFW и его сборка
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
# Линковка с библиотекой GLFW
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glfw)

# Добавление подмодуля GLM и его сборка
add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
# Линковка с библиотекой GLM
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glm)

# Добавление подмодуля SPDLOG и его сборка
add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
# Линковка с библиотекой SPDLOG
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC spdlog)

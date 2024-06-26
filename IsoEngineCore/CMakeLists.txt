# Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.12)

# Определение названия проекта IsoEngineCore
set(ENGINE_PROJECT_NAME IsoEngineCore)

# Список публичных заголовочных файлов
set(ENGINE_PUBLIC_INCLUDES
	includes/IsoEngineCore/Log.h
	
	includes/IsoEngineCore/Window.h
	includes/IsoEngineCore/Events.h
	
	includes/IsoEngineCore/Shader.h
	includes/IsoEngineCore/Texture.h
)

# Список приватных исходных файлов
set(ENGINE_PRIVATE_SOURCES
	src/IsoEngineCore/Window.cpp
	src/IsoEngineCore/Events.cpp
	
	src/IsoEngineCore/Shader.cpp
	src/IsoEngineCore/Texture.cpp
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
#add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
# Линковка с библиотекой GLAD
#target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glad)

# Добавление подмодуля GLEW и его сборка
add_subdirectory(../external/glew ${CMAKE_CURRENT_BINARY_DIR}/glew)
# Линковка с библиотекой GLEW
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC libglew_static)

# Добавление подмодуля GLFW и его сборка
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
# Линковка с библиотекой GLFW
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glfw)

# Добавление подмодуля GLM и его сборка
add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
# Линковка с библиотекой GLM
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC glm)

# Добавление подмодуля SOIL и его сборка
add_subdirectory(../external/soil ${CMAKE_CURRENT_BINARY_DIR}/soil)
# Линковка с библиотекой SOIL
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC soil)

# Добавление подмодуля SPDLOG и его сборка
add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
# Линковка с библиотекой SPDLOG
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC spdlog)

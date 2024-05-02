cmake_minimum_required(VERSION 3.12)

project(soil)

# Определение пути к исходным файлам
set(SOIL_SOURCE_FILES
    src/image_dxt.c
    src/image_helper.c
    src/soil.c
    src/stb_image_aug.c
)

# Определение пути к заголовочным файлам
set(SOIL_HEADER_FILES
    includes/SOIL/image_dxt.h
    includes/SOIL/image_helper.h
    includes/SOIL/SOIL.h
    includes/SOIL/stb_image_aug.h
    includes/SOIL/stbi_dds_aug.h
    includes/SOIL/stbi_dds_aug_c.h
)

# Создание статической библиотеки
add_library(soil STATIC ${SOIL_SOURCE_FILES} ${SOIL_HEADER_FILES})

target_include_directories(soil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
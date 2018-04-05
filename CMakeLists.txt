cmake_minimum_required(VERSION 3.9)
project(FdFarr C)

set(CMAKE_C_STANDARD 99)
include_directories(${CMAKE_SOURCE_DIR}/libft)
include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(FdFarr inc/fdf.h
        src/main.c
        src/read_fdf.c
        src/ft_strnsplit.c
        src/render.c
        src/adjust_map.c
        src/transformations.c
        src/hookers.c
        src/transformations_2.c
        src/image.c src src/ft_hextoi.c)

add_library(libft STATIC IMPORTED) # Создание статической библиотеки
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(FdFarr libft)  # Линковка программы с библиотекой
find_library(_mlx mlx)
find_library(_m m)
find_library(_openGL OpenGL)
find_library(_appkit AppKit)
target_link_libraries(FdFarr ${_mlx})
target_link_libraries(FdFarr ${_m})
target_link_libraries(FdFarr ${_openGL})
target_link_libraries(FdFarr ${_appkit})
set(TARGETS maps/smallest.fdf)
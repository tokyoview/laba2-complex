cmake_minimum_required(VERSION 3.1) #Проверка версии CMake.

set(PROJECT_NAME Laba2-Complex) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(application Laba2-Complex) #Переменная с именем приложения
set(library ComplexLibrary) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/lib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории

add_subdirectory(bin) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(lib)
add_subdirectory(gtest)
add_subdirectory(test)
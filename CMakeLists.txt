# =============================================================================
#  CMakeLists.txt — Proyecto "4 en Raya"
# =============================================================================
#  Este archivo configura la compilación del proyecto utilizando CMake.
#  Su objetivo es mantener una estructura clara, escalable y fácil de extender.
#
#  Estructura de carpetas esperada:
#      src/
#          Datos/
#          Negocio/
#          Presentacion/
#      include/
# =============================================================================


cmake_minimum_required(VERSION 3.15) # Versión mínima recomendada de CMake
project(4enRaya VERSION 1.0 LANGUAGES CXX) # Nombre y versión del proyecto


# =============================================================================
# CONFIGURACIÓN DEL COMPILADOR Y ESTÁNDAR C++
# =============================================================================


# Se define el estándar de C++ a utilizar. Aquí se usa C++17.
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) #Si el compilador no soporta C++17, falla (REQUIRED).

# Opcional: enlazado estático para generar un ejecutable "portable"
#Esto hace que, El ejecutable funciona en cualquier PC Windows sin instalar MinGW.

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")


# =============================================================================
# GESTIÓN DE ARCHIVOS FUENTE
# =============================================================================


# Esta sección automatiza la verificación de archivos fuente. 
# Solo se compilan aquellos que EXISTEN físicamente en el proyecto.
#
# Proposito: 
#  - Evita errores por rutas mal escritas.
#  - Permite agregar archivos sin romper el CMake.


message(STATUS "=== VERIFICACIÓN DE ARCHIVOS FUENTE ===") #impresion en consolo para organizar salida. 

set(SOURCE_FILES "") #Guardados de archivos que existan fisicamente. 


# -------------------------------------------------------------------------
# LISTA CENTRALIZADA DE ARCHIVOS .cpp A INCLUIR EN EL PROYECTO
# -------------------------------------------------------------------------
# INSTRUCCIONES PARA AGREGAR UN NUEVO ARCHIVO:
#
# 1. Crear el archivo dentro de la carpeta correspondiente: 
#        src/Datos/, src/Negocio/, src/Presentacion/
# 2. Añadir aquí su ruta exacta con formato "src/Carpeta/Archivo.cpp"
# 3. El sistema verificará automáticamente si existe.
#
# Sugerencia de organización:
#    - Datos → estructuras, modelos, almacenamiento (datos del juego, ejm.Partidas guardadas)
#    - Negocio → lógica del juego, reglas, controladores (lógica central)
#    - Presentacion → interfaz de usuario, menú, impresión en pantalla (Interfaz grafica o consola)
# -------------------------------------------------------------------------

set(FILES_TO_CHECK
    # Archivo principal

    "src/main.cpp"

    # ========================
    # MÓDULO: Datos
    # ========================
    

    # ========================
    # MÓDULO: Negocio
    # ========================

    "src/Negocio/Tablero.cpp"
s
    # ========================
    # MÓDULO: Presentación
    # ========================
   


)



# =============================================================================
# VERIFICACIÓN AUTOMÁTICA DE ARCHIVOS
# =============================================================================
# Recorre la lista y solo incluye los archivos que realmente existen.
# Esto ayuda a evitar errores de compilación por nombres mal escritos.

foreach(file ${FILES_TO_CHECK})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        message(STATUS "✓ ENCONTRADO: ${file}")
        list(APPEND SOURCE_FILES ${file})
    else()
        message(WARNING "⚠️  NO ENCONTRADO: ${file}")
        message(STATUS  "   Verifica:")
        message(STATUS  "   - Nombre exacto del archivo (sensible a mayúsc/minúsc)")
        message(STATUS  "   - Ubicación dentro de src/")
        message(STATUS  "   - Extensión .cpp correcta")
    endif()
endforeach()

message(STATUS "Total de archivos a compilar: ${SOURCE_FILES}")
message(STATUS "==============================================")


# =============================================================================
# CONFIGURACIÓN DEL EJECUTABLE
# =============================================================================


add_executable(4enRaya ${SOURCE_FILES}) #Creacion de ejecutable con base a los archivos verificados. 

# Se incluyen todos los headers dentro de include/ de forma recursiva.
# Así no se requiere modificar CMake al agregar un nuevo .h
# EL hecho de esto es que los header no se utilizan para compilar.
#   - Los headerss solo se incluyen.


# =============================================================================
# INCLUSION DE HEADERS
# =============================================================================


target_include_directories(4enRaya PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# =============================================================================
# PROPIEDADES DEL EJECUTABLE
# =============================================================================


set_target_properties(4enRaya PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin # Carpeta de salida bin/ (Guarda el ejecutable)
    OUTPUT_NAME "4enRaya" # Nombre del ejecutable final
)


# =============================================================================
# CONFIGURACIÓN DE COMPILACIÓN SEGÚN MODO (Debug/Release)
# =============================================================================

# Debug → para desarrollo, con información de depuración
# Release → para entregar al usuario final, con optimizaciones
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(4enRaya PRIVATE -Wall -g -O0)
    message(STATUS "Modo: Debug — información detallada para depuración")
else()
    target_compile_options(4enRaya PRIVATE -O2)
    message(STATUS "Modo: Release — rendimiento optimizado")
endif()


# =============================================================================
# MENSAJE FINAL (modificable)
# =============================================================================
message(STATUS "-> Configuración del proyecto completada.")
message(STATUS "-> Ejecutable generado en: bin/4enRaya.exe")
message(STATUS "-> Para agregar nuevos archivos, edita FILES_TO_CHECK en este archivo.")
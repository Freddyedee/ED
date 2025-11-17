# =============================================================================
# CONFIGURACIÓN BÁSICA DEL PROYECTO 4 EN RAYA
# =============================================================================

cmake_minimum_required(VERSION 3.15)
project(4enRaya VERSION 1.0 LANGUAGES CXX)

# =============================================================================
# CONFIGURACIÓN DEL COMPILADOR Y ESTÁNDAR C++
# =============================================================================

# Usar C++17 como estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enlazado estático para mejor portabilidad (evita dependencias de DLLs)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# =============================================================================
# GESTIÓN DE ARCHIVOS FUENTE
# =============================================================================

message(STATUS "=== VERIFICACIÓN DE ARCHIVOS FUENTE ===")

set(SOURCE_FILES "")

# -----------------------------------------------------------------------------
# LISTA DE ARCHIVOS .cpp - ¡MODIFICA ESTA LISTA AL AGREGAR NUEVOS ARCHIVOS!
# -----------------------------------------------------------------------------
# INSTRUCCIONES:
# 1. Para agregar un nuevo archivo .cpp, añádelo a esta lista
# 2. Mantén la estructura: "src/CARPETA/NombreArchivo.cpp"
# 3. Las carpetas posibles son: Datos, Negocio, Presentacion
# -----------------------------------------------------------------------------

set(FILES_TO_CHECK
    # Archivo principal
    "src/main.cpp"
    
    # ========================
    # ARCHIVOS DE DATOS
    # ========================
    "src/Datos/Tablero.cpp"
    "src/Datos/Jugador.cpp"
    # EJEMPLO: Agregar nuevo archivo en Datos:
    # "src/Datos/Partida.cpp"
    
    # ========================
    # ARCHIVOS DE NEGOCIO
    # ========================
    "src/Negocio/LogicaJuego.cpp"
    # EJEMPLO: Agregar nuevo archivo en Negocio:
    # "src/Negocio/ControladorJuego.cpp"
    
    # ========================
    # ARCHIVOS DE PRESENTACION
    # ========================
    # EJEMPLO: Agregar archivos de interfaz de usuario:
    # "src/Presentacion/InterfazUsuario.cpp"
    # "src/Presentacion/VistaTablero.cpp"
)

# =============================================================================
# VERIFICACIÓN AUTOMÁTICA DE ARCHIVOS 
# =============================================================================

foreach(file ${FILES_TO_CHECK})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        message(STATUS "✓ ENCONTRADO: ${file}")
        list(APPEND SOURCE_FILES ${file})
    else()
        message(STATUS "⚠️  NO ENCONTRADO: ${file}")
        message(STATUS "   Si este archivo debería existir, verifica:")
        message(STATUS "   1. El nombre del archivo (mayúsculas/minúsculas)")
        message(STATUS "   2. La ubicación en la carpeta src/")
        message(STATUS "   3. La extensión .cpp (no .CPP)")
    endif()
endforeach()

message(STATUS "Total de archivos a compilar: ${SOURCE_FILES}")
message(STATUS "==============================================")

# =============================================================================
# CONFIGURACIÓN DEL EJECUTABLE
# =============================================================================

# Crear el ejecutable con todos los archivos fuente encontrados
add_executable(4enRaya ${SOURCE_FILES})

# Configurar directorios de inclusión para los headers
# NOTA: Todos los archivos .h en include/ y sus subcarpetas son incluidos automáticamente
target_include_directories(4enRaya PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# =============================================================================
# PROPIEDADES DEL EJECUTABLE
# =============================================================================

# El ejecutable se generará en la carpeta bin/
set_target_properties(4enRaya PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    OUTPUT_NAME "4enRaya"
)

# =============================================================================
# CONFIGURACIONES DE COMPILACIÓN
# =============================================================================

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Configuración para DEBUG: más información, sin optimización
    target_compile_options(4enRaya PRIVATE -Wall -g -O0)
    message(STATUS "Modo: Debug - Con información para depuración")
else()
    # Configuración para RELEASE: optimizado para rendimiento
    target_compile_options(4enRaya PRIVATE -O2)
    message(STATUS "Modo: Release - Optimizado para rendimiento")
endif()

# =============================================================================
# MENSAJE FINAL DE CONFIGURACIÓN (modificar)
# =============================================================================

message(STATUS "✅ Configuración de 4enRaya completada exitosamente!")
message(STATUS "📁 Ejecutable: bin/4enRaya.exe")
message(STATUS "🔧 Para agregar nuevos archivos, edita la lista FILES_TO_CHECK")
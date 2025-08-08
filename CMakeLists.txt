cmake_minimum_required(VERSION 3.14)
project(omci_library LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(omci_library
        main.cpp
        OmciMessage.cpp
        OmciEncoder.cpp
        me/AniG.cpp
)

target_include_directories(omci_library PRIVATE
        ${PROJECT_SOURCE_DIR}
)

add_executable(test_anig
        tests/AniGTest.cpp
        tests/OntGTest.cpp
        me/AniG.cpp
        me/OntG.cpp
        OmciMessage.cpp
        OmciEncoder.cpp
        EntityFactory.cpp
        ManagedEntity.h
)

target_include_directories(test_anig PRIVATE
        ${PROJECT_SOURCE_DIR}
)

target_link_libraries(test_anig
        gtest
        gtest_main
        pthread
)

add_test(NAME AniGTest COMMAND test_anig)

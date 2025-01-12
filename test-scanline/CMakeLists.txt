cmake_minimum_required(VERSION 3.12)

project(ScanLines)


add_executable(scanline scan_line.c test_line.c)

target_include_directories(Scanlines PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
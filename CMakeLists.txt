cmake_minimum_required(VERSION 3.17)
project(dynamicRankingsWithAttributes C)

set(CMAKE_C_STANDARD 99)

add_executable(dynamicRankingsWithAttributes simulation.c
        include/setting.c
        include/setting.h
        include/inputOutput.c
        include/inputOutput.h
        include/rules/dynDHondt.c
        include/rules/dynDHondt.h include/rules/lazyDHondt.c include/rules/lazyDHondt.h)

target_link_libraries(dynamicRankingsWithAttributes m)
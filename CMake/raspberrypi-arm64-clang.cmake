set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_FLAGS "--target=aarch64-linux-gnu")
set(CMAKE_CXX_FLAGS "--target=aarch64-linux-gnu")

set(CMAKE_SYSROOT /usr/local/sysroot/aarch64-linux-gnu)

set(CMAKE_FIND_ROOT_PATH /usr/local/sysroot/aarch64-linux-gnu)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_EXE_LINKER_FLAGS "--target=aarch64-linux-gnu")

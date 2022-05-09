project(memcheck-dynamic-hybrid-g LANGUAGES C CXX CUDA)

add_library(memcheck-dynamic-hybrid-g-lib SHARED libmain.cpp .cuda.cu)

set_target_properties(memcheck-dynamic-hybrid-g-lib PROPERTIES CUDA_ARCHITECTURES "75")
set_target_properties(memcheck-dynamic-hybrid-g-lib PROPERTIES CXX_STANDARD 17)
set_target_properties(memcheck-dynamic-hybrid-g-lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(memcheck-dynamic-hybrid-g-lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<IF:$<CONFIG:Debug>,${CMAKE_SOURCE_DIR}/bin/Debug,${CMAKE_SOURCE_DIR}/bin/Release>)
target_compile_options(memcheck-dynamic-hybrid-g-lib PUBLIC
	$<$<COMPILE_LANGUAGE:CUDA>:-G>
)

find_package(CUDAToolkit)

target_link_libraries(memcheck-dynamic-hybrid-g-lib CUDA::cudart_static)

add_executable(memcheck-dynamic-hybrid-g main.cpp)
target_link_libraries(memcheck-dynamic-hybrid-g memcheck-dynamic-hybrid-g-lib)
set_target_properties(memcheck-dynamic-hybrid-g PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<IF:$<CONFIG:Debug>,${CMAKE_SOURCE_DIR}/bin/Debug,${CMAKE_SOURCE_DIR}/bin/Release>)
project(memcheck-hybrid-g LANGUAGES C CXX CUDA)
add_executable(memcheck-hybrid-g main.cpp .cuda.cu)
set_target_properties(memcheck-hybrid-g PROPERTIES CUDA_ARCHITECTURES "75")
set_target_properties(memcheck-hybrid-g PROPERTIES CXX_STANDARD 17)
set_target_properties(memcheck-hybrid-g PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(memcheck-hybrid-g PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<IF:$<CONFIG:Debug>,${CMAKE_SOURCE_DIR}/bin/Debug,${CMAKE_SOURCE_DIR}/bin/Release>)
target_compile_options(memcheck-hybrid-g PUBLIC
	$<$<COMPILE_LANGUAGE:CUDA>:-G>
)

find_package(CUDAToolkit)

target_link_libraries(memcheck-hybrid-g CUDA::cudart_static)
project(memcheck LANGUAGES C CXX CUDA)
add_executable(memcheck memcheck_demo.cu)
set_target_properties(memcheck PROPERTIES CUDA_ARCHITECTURES "75")
set_target_properties(memcheck PROPERTIES CXX_STANDARD 17)
set_target_properties(memcheck PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(memcheck PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<IF:$<CONFIG:Debug>,${CMAKE_SOURCE_DIR}/bin/Debug,${CMAKE_SOURCE_DIR}/bin/Release>)

project(memcheck-g LANGUAGES C CXX CUDA)
add_executable(memcheck-g memcheck_demo.cu)
set_target_properties(memcheck-g PROPERTIES CUDA_ARCHITECTURES "75")
set_target_properties(memcheck-g PROPERTIES CXX_STANDARD 17)
set_target_properties(memcheck-g PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(memcheck-g PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<IF:$<CONFIG:Debug>,${CMAKE_SOURCE_DIR}/bin/Debug,${CMAKE_SOURCE_DIR}/bin/Release>)
target_compile_options(memcheck-g PUBLIC
	$<$<COMPILE_LANGUAGE:CUDA>:-G>
)
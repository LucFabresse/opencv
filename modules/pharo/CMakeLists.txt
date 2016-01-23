# ----------------------------------------------------------------------------
#  CMake file for pharo support
# ----------------------------------------------------------------------------

if(ANDROID OR WINRT OR NOT PYTHON_DEFAULT_AVAILABLE)
  ocv_module_disable(pharo)
endif()

set(the_description "Pharo OpenCV binding")

set(MODULE_NAME pharo)
set(MODULE_INSTALL_SUBDIR pharo)
set(PHARO_MODULE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PHARO_MODULE_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# ocv_add_module(${MODULE_NAME} BINDINGS python)
ocv_add_module(${MODULE_NAME})

# ocv_module_include_directories( "${PYTHON_SOURCE_DIR}/src" )

set(script_gen_pharo "${PHARO_MODULE_SOURCE_DIR}/gen2Pharo.py")
set(script_hdr_parser "${PHARO_MODULE_SOURCE_DIR}/../python/src2/hdr_parser.py")
set(output_dir	"${PHARO_MODULE_BUILD_DIR}") 
set(headers_file "${PHARO_MODULE_BUILD_DIR}/../python3/headers.txt")

set(output_file_declarations "${output_dir}/allDecls.st")

message(STATUS "LUC: ${script_gen_pharo} ${script_hdr_parser} ${output_dir} ${headers_file}")

add_custom_command(
   OUTPUT "${output_file_declarations}"
   COMMAND ${PYTHON_EXECUTABLE} "${script_gen_pharo}" "${script_hdr_parser}" "${output_dir}" "${headers_file}"
   DEPENDS ${script_gen_pharo}
	DEPENDS ${script_hdr_parser}
	COMMENT "Generating Pharo allDecls.st")

# ${the_module} == opencv_pharo
# add_dependencies(${the_module} opencv_python3 opencv_python2)

# execute_process(COMMAND ${PYTHON_EXECUTABLE} "${script_gen_pharo}" "${script_hdr_parser}" "${output_dir}" "${headers_file}"
# WORKING_DIRECTORY "${output_dir}")
	
add_custom_target(${the_module} ALL
	DEPENDS opencv_python3 ${output_file_declarations}
)

# NOT FINISHED
# During cmake, auto download Pharo VM+Image such as:
#ICV: Downloading ippicv_macosx_20141027.tgz...

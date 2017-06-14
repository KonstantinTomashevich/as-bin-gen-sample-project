set (TARGET_NAME SampleProject)
define_source_files (RECURSE GLOB_H_PATTERNS "*.hpp" EXCLUDE_PATTERNS "AngelScriptBindings/[^;]+;")
setup_main_executable ()
add_test (NAME test_generated_bindings COMMAND SampleProject --test)

set (COLONIZATION_HEADERS_LIST )
set (IS_FIRST_ITEM 1)
foreach (HEADER ${H_FILES})
    if (NOT IS_FIRST_ITEM)
        set (START ",\n    ")
    else ()
        set (IS_FIRST_ITEM 0)
        set (START "    ")
    endif ()
    set (COLONIZATION_HEADERS_LIST "${COLONIZATION_HEADERS_LIST}${START}\"${HEADER}\"")
endforeach ()
configure_file (${CMAKE_SOURCE_DIR}/ASBindGenConfiguration.lua.cmake ${CMAKE_SOURCE_DIR}/ASBindGenConfiguration.lua)

add_custom_target (SampleProjectASBindGen
                    COMMAND ${LUA} ${AS_BIND_GEN_SCRIPT} "ASBindGenConfiguration.lua" "${CMAKE_BINARY_DIR}/ASBindGen.log"
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    COMMENT "Generating Angel Script bindings for Colonization via ASBindGen..."
                    VERBATIM)
add_dependencies (SampleProject SampleProjectASBindGen)

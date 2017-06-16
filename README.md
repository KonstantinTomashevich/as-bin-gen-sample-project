# ASBindGen Sample Project
ASBindGen sample project. Illustrates simple bindings generation and use.

## CMake project configuration
Step 1. Clone `ASBindGen` from GitHub, if `ASBINDGEN_PATH` not specified.

```cmake
# Setup dependencies.
set (DEPENDENCIES_DIR "dependencies")
file (MAKE_DIRECTORY ${DEPENDENCIES_DIR})

# Setup ASBindGen.
if (NOT ASBINDGEN_PATH)
    set (AS_BIND_GEN_REPO_OWNER "KonstantinTomashevich")
    set (AS_BIND_GEN_REPO_NAME "as-bind-gen")
    if (EXISTS "${CMAKE_SOURCE_DIR}/${DEPENDENCIES_DIR}/${AS_BIND_GEN_REPO_NAME}")
        message (STATUS "Updating ASBindGen dependency...")
        execute_process (COMMAND "git" "pull" "origin" "master"
                         OUTPUT_VARIABLE OUTPUT
                         RESULT_VARIABLE RESULT
                         WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/${DEPENDENCIES_DIR}/${AS_BIND_GEN_REPO_NAME}")
        if (NOT RESULT EQUAL 0)
            message (FATAL_ERROR "Can not update ASBindGen!")
        endif ()
    else ()
        message (STATUS "Cloning ASBindGen dependency...")
        execute_process (COMMAND "git" "clone" "https://github.com/${AS_BIND_GEN_REPO_OWNER}/${AS_BIND_GEN_REPO_NAME}.git"
                         OUTPUT_VARIABLE OUTPUT
                         RESULT_VARIABLE RESULT
                         WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/${DEPENDENCIES_DIR}")
        if (NOT RESULT EQUAL 0)
            message (FATAL_ERROR "Can not clone ASBindGen!")
        endif ()
    endif ()
    set (AS_BIND_GEN_SCRIPT "./${DEPENDENCIES_DIR}/${AS_BIND_GEN_REPO_NAME}/Main.lua")
else ()
    set (AS_BIND_GEN_SCRIPT "dependencies/as-bind-gen/Main.lua")
endif ()
```
Step 2. Generate `ASBindGen` configuration file from [CMake template file](https://github.com/KonstantinTomashevich/as-bin-gen-sample-project/blob/master/ASBindGenConfiguration.lua.cmake).

```cmake
set (SAMPLE_PROJECT_HEADERS_LIST )
set (IS_FIRST_ITEM 1)
foreach (HEADER ${H_FILES})
    if (NOT IS_FIRST_ITEM)
        set (START ",\n    ")
    else ()
        set (IS_FIRST_ITEM 0)
        set (START "    ")
    endif ()
    set (SAMPLE_PROJECT_HEADERS_LIST "${SAMPLE_PROJECT_HEADERS_LIST}${START}\"${HEADER}\"")
endforeach ()
configure_file (${CMAKE_SOURCE_DIR}/ASBindGenConfiguration.lua.cmake ${CMAKE_SOURCE_DIR}/ASBindGenConfiguration.lua)
```
Step 3. Add `ASBindGen` custom target.

```cmake
add_custom_target (SampleProjectASBindGen
                    COMMAND ${LUA} ${AS_BIND_GEN_SCRIPT} "ASBindGenConfiguration.lua" "${CMAKE_BINARY_DIR}/ASBindGen.log"
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    COMMENT "Generating Angel Script bindings for Colonization via ASBindGen..."
                    VERBATIM)
add_dependencies (SampleProject SampleProjectASBindGen)
```
## C++ side
Step 1. Add `ASBindGen` bindings template files: [Bindings.hpp.template](https://github.com/KonstantinTomashevich/as-bin-gen-sample-project/blob/master/sources/SampleProject/Bindings.hpp.template) and [Bindings.cpp.template](https://github.com/KonstantinTomashevich/as-bin-gen-sample-project/blob/master/sources/SampleProject/Bindings.cpp.template).

Step 2. Add external class `Object` (it is `Urho3D::Object`) declaration for `ASBindGen`.

```c++
//@ASBindGen ExternalClass Name=Object ExcludeSubclassRegistration
//@ASBindGen    Urho3D::RegisterObject <${templateName}> (engine, ${bindingName});
```
Step 3. Add `ASBindGen` command-comments to headers. For example, [SampleContainer.hpp](https://github.com/KonstantinTomashevich/as-bin-gen-sample-project/blob/master/sources/SampleProject/SampleContainer.hpp).
## AngelScript side
Test generated bindings in [small script file](https://github.com/KonstantinTomashevich/as-bin-gen-sample-project/blob/master/bin/Data/TestScript.as).

add_executable(Engine src/main.cpp)

 
set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-3.0.2")
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")
set(SFML_BIN_DIR "${SFML_ROOT}/bin")  # où sont les DLL

target_include_directories(Engine PRIVATE ${SFML_INCLUDE_DIR})

if(WIN32)
 
    target_link_libraries(Engine 
        "${SFML_LIBRARY_DIR}/sfml-graphics.lib"
        "${SFML_LIBRARY_DIR}/sfml-window.lib"
        "${SFML_LIBRARY_DIR}/sfml-system.lib"
    )

 
    set(SFML_DLLS
        "${SFML_BIN_DIR}/sfml-graphics-3.dll"
        "${SFML_BIN_DIR}/sfml-window-3.dll"
        "${SFML_BIN_DIR}/sfml-system-3.dll"
    )

 
    foreach(DLL ${SFML_DLLS})
        add_custom_command(TARGET Engine POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${DLL}"
            "$<TARGET_FILE_DIR:Engine>"
        )
    endforeach()
endif()

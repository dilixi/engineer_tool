# 设置项目名称和最低CMake版本
cmake_minimum_required(VERSION 3.10)
project(lvgl_esp32)

# 设置编译生成共享库
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(LVGL_DIR ${CMAKE_SOURCE_DIR}/lvgl) 
set(LVGL_DRIVERS_DIR ${CMAKE_SOURCE_DIR}/lv_drivers) 
 
    
# 自动递归查找所有源文件
file(GLOB_RECURSE LVGL_SOURCES
    "${LVGL_DIR}/src/*.c"
    "${LVGL_DIR}/src/core/*.c"
    "${LVGL_DIR}/src/draw/*.c"
    "${LVGL_DIR}/src/extra/*.c"
    "${LVGL_DIR}/src/font/*.c"
    "${LVGL_DIR}/src/gpu/*.c"
    "${LVGL_DIR}/src/hal/*.c"
    "${LVGL_DIR}/src/misc/*.c"
    "${LVGL_DIR}/src/widgets/*.c"
    "${LVGL_DIR}/src/extra/layouts/*.c"
    "${LVGL_DIR}/src/extra/layouts/flex/*.c"
    "${LVGL_DIR}/src/extra/layouts/grid/*.c"
    "${LVGL_DIR}/src/extra/themes/*.c"
    "${LVGL_DIR}/src/extra/themes/basic/*.c"
    "${LVGL_DIR}/src/extra/themes/default/*.c"
    "${LVGL_DIR}/src/extra/widgets/*.c"
    "${LVGL_DIR}/src/extra/widgets/calendar/*.c"
    "${LVGL_DIR}/src/extra/widgets/colorwheel/*.c"
    "${LVGL_DIR}/src/extra/widgets/imgbtn/*.c"
    "${LVGL_DIR}/src/extra/widgets/keyboard/*.c"
    "${LVGL_DIR}/src/extra/widgets/led/*.c"
    "${LVGL_DIR}/src/extra/widgets/list/*.c"
    "${LVGL_DIR}/src/extra/widgets/msgbox/*.c"
    "${LVGL_DIR}/src/extra/widgets/spinbox/*.c"
    "${LVGL_DIR}/src/extra/widgets/spinner/*.c"
    "${LVGL_DIR}/src/extra/widgets/tabview/*.c"
    "${LVGL_DIR}/src/extra/widgets/tileview/*.c"
    "${LVGL_DIR}/src/extra/widgets/win/*.c" 
)

# 添加头文件路径
include_directories(
    ${LVGL_DIR}/src
    ${LVGL_DIR}/src/core
    ${LVGL_DIR}/src/draw
    ${LVGL_DIR}/src/extra
    ${LVGL_DIR}/src/font
    ${LVGL_DIR}/src/gpu
    ${LVGL_DIR}/src/hal
    ${LVGL_DIR}/src/misc
    ${LVGL_DIR}/src/widgets
    ${LVGL_DIR}/src/extra/layouts
    ${LVGL_DIR}/src/extra/layouts/flex
    ${LVGL_DIR}/src/extra/layouts/grid
    ${LVGL_DIR}/src/extra/themes
    ${LVGL_DIR}/src/extra/themes/basic
    ${LVGL_DIR}/src/extra/themes/default
    ${LVGL_DIR}/src/extra/widgets/calendar
    ${LVGL_DIR}/src/extra/widgets/colorwheel
    ${LVGL_DIR}/src/extra/widgets/imgbtn
    ${LVGL_DIR}/src/extra/widgets/keyboard
    ${LVGL_DIR}/src/extra/widgets/led
    ${LVGL_DIR}/src/extra/widgets/list
    ${LVGL_DIR}/src/extra/widgets/msgbox
    ${LVGL_DIR}/src/extra/widgets/spinbox
    ${LVGL_DIR}/src/extra/widgets/spinner
    ${LVGL_DIR}/src/extra/widgets/tabview
    ${LVGL_DIR}/src/extra/widgets/tileview 
    ${LVGL_DIR}/src/extra/widgets/win 
)
 
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/lib)   
set(TOOL_DIR ${CMAKE_SOURCE_DIR}/tools)   
 
file(GLOB_RECURSE APP_SOURCES
    "${MAIN_DIR}/*.c"
    "${MAIN_DIR}/*.cpp"
    "${MAIN_DIR}/fonts/*.c" 
    #"${LVGL_DIR}/demos/*.c"
    "${LVGL_DRIVERS_DIR}/display/fbdev.c"
    "${MAIN_DIR}/app_ui/*.cpp"
    "${MAIN_DIR}/images/*.c" 
    "${TOOL_DIR}/lv_i18n/lv_i18n.c" 
    "${MAIN_DIR}/libpngdec/*.c" 
    "${MAIN_DIR}/cJSON/*.c"  
)
 
# 添加头文件路径
include_directories(
    "."
    "${LVGL_DIR}"
    "${MAIN_DIR}/"
    "${MAIN_DIR}/fonts/"   
    "${LVGL_DRIVERS_DIR}/"
    "${MAIN_DIR}/app_ui"
    "${MAIN_DIR}/images" 
    "${TOOL_DIR}/lv_i18n" 
    "${MAIN_DIR}/libpngdec" 
    "${MAIN_DIR}/cJSON"
)  
  
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=default")
 
# 创建最终的共享库，并链接静态库和源文件
add_library(lvgl SHARED ${APP_SOURCES} ${LVGL_SOURCES} ${PAHO_MQTT_SRC})
  
add_definitions(-DLV_LVGL_H_INCLUDE_SIMPLE=1) 

# 添加包含和库路径
set(MBEDTLS_DIR ${CMAKE_SOURCE_DIR}/mbedtls)

include_directories(${MBEDTLS_DIR}/include)
link_directories(${MBEDTLS_DIR}/lib) 

# 指定完整路径的库文件
set(MBEDTLS_LIBS
    ${MBEDTLS_DIR}/lib/libmbedtls.a
    ${MBEDTLS_DIR}/lib/libmbedx509.a
    ${MBEDTLS_DIR}/lib/libmbedcrypto.a
)
 
target_link_libraries(lvgl ${MBEDTLS_LIBS}) 

# 设置生成库文件的名称
set_target_properties(lvgl PROPERTIES OUTPUT_NAME "lvgl")
set_target_properties(lvgl PROPERTIES SUFFIX ".so")
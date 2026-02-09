include("E:/giao dien/test4/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/test4-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtserialport;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "E:/giao dien/test4/build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/test4.exe"
    GENERATE_QT_CONF
)

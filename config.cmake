#
# Build environment
#


# QCefWidget Version
SET(QCEF_VERSION_MAJOR 1)
SET(QCEF_VERSION_MINOR 0)
SET(QCEF_VERSION_PATCH 3)


# The Qt SDK path
set(QT_SDK_DIR "C:/install/qt5/5.15.2/msvc2019")


# The root dir of the CEF SDK
set(CEF_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dep/cef_binary_109.1.18+gf1c41e4+chromium-109.0.5414.120_windows32")
#set(CEF_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dep/cef_binary_76.1.13+gf19c584+chromium-76.0.3809.132_windows32")
#set(CEF_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dep/cef_binary_3.3626.1895.g7001d56_windows32")

# CEF version
SET(CEF_VERSION_MAJOR 109)
SET(CEF_VERSION_MINOR 1)
SET(CEF_VERSION_PATCH 18)

SET(QCEF_WING_EXE "CefWebRender")
SET(QCEF_WIDGET_DLL "CefWebCore")
SET(QCEF_WIDGET_SDK_OUT_DIR "${CMAKE_SOURCE_DIR}/out")


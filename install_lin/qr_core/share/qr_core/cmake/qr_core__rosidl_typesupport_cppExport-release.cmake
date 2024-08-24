#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "qr_core::qr_core__rosidl_typesupport_cpp" for configuration "Release"
set_property(TARGET qr_core::qr_core__rosidl_typesupport_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(qr_core::qr_core__rosidl_typesupport_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libqr_core__rosidl_typesupport_cpp.so"
  IMPORTED_SONAME_RELEASE "libqr_core__rosidl_typesupport_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS qr_core::qr_core__rosidl_typesupport_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_qr_core::qr_core__rosidl_typesupport_cpp "${_IMPORT_PREFIX}/lib/libqr_core__rosidl_typesupport_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

include_guard(GLOBAL)

find_package(bson-1.0 QUIET CONFIG)
find_package(mongoc-1.0 QUIET CONFIG)
if(bson-1.0_FOUND AND mongoc-1.0_FOUND)
  message(STATUS "Using config version for bson + mongoc")
  add_library(bson ALIAS mongo::bson_static)
  add_library(mongoc ALIAS mongo::mongoc_static)
else()
  find_package(bson REQUIRED)
  find_package(mongoc REQUIRED)
endif()


option(USERVER_DOWNLOAD_PACKAGE_CLICKHOUSECPP "Download and setup clickhouse-cpp" ${USERVER_DOWNLOAD_PACKAGES})

find_package(lz4 REQUIRED)

if (NOT USERVER_FORCE_DOWNLOAD_PACKAGES)
  if (USERVER_DOWNLOAD_PACKAGE_CLICKHOUSECPP)
    find_package(clickhouse-cpp QUIET)
  else()
    find_package(clickhouse-cpp REQUIRED)
  endif()

  if (clickhouse-cpp_FOUND)
    target_compile_options(clickhouse-cpp INTERFACE -Wno-pedantic)
    return()
  endif()
endif()

include(DownloadUsingCPM)
include(SetupAbseil)

CPMAddPackage(
    NAME clickhouse-cpp
    VERSION 2.5.1
    GITHUB_REPOSITORY ClickHouse/clickhouse-cpp
    SYSTEM
    OPTIONS
    "WITH_SYSTEM_ABSEIL ON"
    "WITH_SYSTEM_LZ4 ON"
    "DEBUG_DEPENDENCIES OFF"
)

add_library(clickhouse-cpp ALIAS clickhouse-cpp-lib)
target_compile_options(clickhouse-cpp-lib PUBLIC -Wno-pedantic)

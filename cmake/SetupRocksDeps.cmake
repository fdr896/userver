include_guard(GLOBAL)

option(USERVER_DOWNLOAD_PACKAGE_ROCKS "Download and setup RocksDB if no RocksDB matching version was found" ${USERVER_DOWNLOAD_PACKAGES})

set(USERVER_ROCKSDB_VERSION "8.9.1")

if(NOT USERVER_FORCE_DOWNLOAD_PACKAGES)
  if(USERVER_DOWNLOAD_PACKAGE_ROCKS)
    find_package(RocksDB QUIET)
  else()
    find_package(RocksDB REQUIRED)
  endif()

  if(TARGET RocksDB::rocksdb)
    return()
  endif()
  if(TARGET rocksdb)
    add_library(RocksDB::rocksdb ALIAS rocksdb)
    return()
  endif()
endif()

find_package(libgflags REQUIRED)
find_package(libsnappy REQUIRED)
find_package(libz REQUIRED)
find_package(libzip REQUIRED)
find_package(libzstd REQUIRED)

include(DownloadUsingCPM)

CPMAddPackage(
  NAME rocksdb
  GITHUB_REPOSITORY facebook/rocksdb
  GIT_TAG v8.11.3
  OPTIONS
  "ROCKSDB_BUILD_SHARED OFF"
  "WITH_TESTS OFF"
  "WITH_BENCHMARK_TOOLS OFF"
  "WITH_TOOLS OFF"
  "USE_RTTI ON"
)
add_library(RocksDB::rocksdb ALIAS rocksdb)

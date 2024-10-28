set(ROCKSDB_BUILD_SHARED OFF)
set(WITH_TESTS OFF)
set(WITH_BENCHMARK_TOOLS OFF)
set(WITH_TOOLS OFF)
set(USE_RTTI ON)

_userver_module_begin(
    NAME RocksDB
    VERSION 8.9.1
    DEBIAN_NAMES librocksdb-dev
    FORMULA_NAMES rocksdb
    PKG_CONFIG_NAMES rocksdb
)

_userver_module_find_include(
    NAMES rocksdb/db.h
)

_userver_module_find_library(
    NAMES librocksdb.a
)

_userver_module_end()

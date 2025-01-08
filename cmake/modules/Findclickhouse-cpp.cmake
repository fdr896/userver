_userver_module_begin(
    NAME clickhouse-cpp
    FORMULA_NAMES clickhouse-cpp
)

_userver_module_find_include(
    NAMES clickhouse/block.h
    PATH_SUFFIXES
      clickhouse-cpp
      yandex/clickhouse-cpp
)

_userver_module_find_library(
    NAMES libclickhouse-cpp-lib.a clickhouse-cpp-lib
    PATH_SUFFIXES
      clickhouse-cpp
      yandex/clickhouse-cpp
)

_userver_module_find_library(
    NAMES libcityhash.a
    PATHS /opt/homebrew/opt/clickhouse-cpp/libexec/lib
)

_userver_module_end()

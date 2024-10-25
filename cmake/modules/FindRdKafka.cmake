set(RDKAFKA_BUILD_STATIC ON)
set(RDKAFKA_BUILD_EXAMPLES OFF)
set(RDKAFKA_BUILD_TESTS OFF)
set(WITH_SSL ON)
set(WITH_SASL ON)
set(WITH_CURL ON)
set(WITH_ZLIB ON)
set(WITH_ZSTD ON)
set(WITH_LIBDL OFF)
set(ENABLE_LZ4_EXT ON)

_userver_module_begin(
    NAME RdKafka
    VERSION 2.3.0
    DEBIAN_NAMES librdkafka-dev
    FORMULA_NAMES librdkafka
    PACMAN_NAMES librdkafka
    PKG_CONFIG_NAMES rdkafka
)

_userver_module_find_include(
    NAMES librdkafka/rdkafka.h
)

_userver_module_find_library(
    NAMES librdkafka.a
)

_userver_module_end()

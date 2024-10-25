_userver_module_begin(
    NAME lz4
    VERSION 1.9.2
    DEBIAN_NAMES liblz4-dev
    PKG_CONFIG_NAMES liblz4
)

_userver_module_find_include(
    NAMES lz4.h
)

_userver_module_find_library(
    NAMES liblz4.a
)

_userver_module_end()

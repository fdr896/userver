# userver does not use Abseil directly, but some libraries need it.

include(DownloadUsingCPM)

CPMAddPackage(
    NAME abseil-cpp
    VERSION 20240722.0
    GIT_TAG 20240722.0
    GITHUB_REPOSITORY abseil/abseil-cpp
    SYSTEM
    OPTIONS
    "ABSL_PROPAGATE_CXX_STD ON"
    "ABSL_INTERNAL_AT_LEAST_CXX20 OFF"
    "ABSL_ENABLE_INSTALL ON"
)

mark_targets_as_system("${abseil-cpp_SOURCE_DIR}")
write_package_stub(absl)

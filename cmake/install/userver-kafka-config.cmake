include_guard(GLOBAL)

if(userver_kafka_FOUND)
  return()
endif()

find_package(userver REQUIRED COMPONENTS
  core
)

if(USERVER_CONAN)
  find_package(RdKafka REQUIRED CONFIG)
else()
  include("${USERVER_CMAKE_DIR}/modules/Findlz4.cmake")
  include("${USERVER_CMAKE_DIR}/modules/FindSASL2.cmake")
  include("${USERVER_CMAKE_DIR}/modules/FindRdKafka.cmake")
endif()

set(userver_kafka_FOUND TRUE)

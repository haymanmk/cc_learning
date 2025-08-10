# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Add executables")
add_executable(shared_ptr shared_ptr.cc)
add_executable(weak_ptr weak_ptr.cc)

# install in build folder
message(STATUS "Install executables")
install(TARGETS shared_ptr weak_ptr
        DESTINATION "build"
        PERMISSIONS OWNER_READ OWNER_WRITE  OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
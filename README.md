# 1. Clean and reconfigure CMake (safe to run)
cd omci_library
rm -rf cmake-build-debug
cmake -S . -B cmake-build-debug

# 2. Build test target explicitly
cmake --build cmake-build-debug --target test_anig

# 3. Verify executable exists
ls cmake-build-debug/test_anig

# 4. Run tests
cd cmake-build-debug
ctest --output-on-failure
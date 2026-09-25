# Building DeviceMonitor

## Requirements

- CMake 3.25+
- C++20 compiler
- Qt 6.7+
- Ninja

## Linux

### Configure

cmake --preset debug

### Build

cmake --build --preset debug

### Tests

ctest --preset debug --output-on-failure

## Sanitizers

cmake --preset sanitize
cmake --build --preset sanitize
ctest --preset sanitize

## Windows

...

## Qt configuration


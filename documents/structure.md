# Project structure

## Folders

* **bin**: output executables go here (for the app, tests and spikes)
* **build**: containing all the object files (removed by clean)
* **doc**: documentation files
* **include**: all project header files, all necessary third-party header files (which are not in /usr/local/include)
* **lib**: any library that get compiled by the project, third party or any needed in development
* **spike**: smaller classes or files to test technologies or ideas
* **src**: the application and application's source files
* **test**: all test code files

## Files

* **Makefile**: Makefile
* **README.md**: Readme file in markdown syntax

[CMake introduction: project structure](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html)

- project
  - .gitignore
  - README.md
  - LICENCE.md
  - CMakeLists.txt
  - cmake
    - FindSomeLib.cmake
    - something_else.cmake
  - include
    - project
      - lib.hpp
  - src
    - CMakeLists.txt
    - lib.cpp
  - apps
    - CMakeLists.txt
    - app.cpp
  - tests
    - CMakeLists.txt
    - testlib.cpp
  - docs
    - CMakeLists.txt
  - extern
    - googletest
  - scripts
    - helper.py

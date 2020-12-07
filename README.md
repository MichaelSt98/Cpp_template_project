# C++ concepts project

See the [Documentation](https://michaelst98.github.io/Cpp_template_project/)!

## Idea

**This project serves as sample/concept project for further projects** \emoji :thumbsup:

## Related documents

* <a href="main.pdf" target="_blank"><b>Notes</b></a>
* [Markdown cheatsheet](documents/Markdown.md)
* [Project structure](documents/structure.md)
* [Unit testing](documents/Unit-Tests.md)

## Structure

### Folders

* **bin**: output executables go here (for the app, tests and spikes)
* **build**: containing all the object files (removed by clean)
* **doc**: documentation files
* **ideas**: smaller classes or files to test technologies or ideas
* **include**: all project header files, all necessary third-party header files (which are not in /usr/local/include)
* **lib**: any library that get compiled by the project, third party or any needed in development
* **resources**: resources
* **src**: the application and application's source files
* **test**: all test code files

## Content (Concepts)

### Programming concepts 

* Classes
    * Inheritance
* Templates 
* ...

### Documentation

The documentation is intrinsically implemented using [doxygen](https://www.doxygen.nl/index.html). 
In order to do that:

* specify path to doxygen binary in the Makefile
* execute *make doc* 

The *README.md* file is used for the Mainpage of the documentation. 
Set the settings for doxygen in *doc/Doxyfile*.

### Makefile

Following targets are implemented:

* **all** default make
* **remake**
* **clean**
* **cleaner**
* **resources**
* **sources**
* **directories**
* **ideas**
* **tester**
* **doc**

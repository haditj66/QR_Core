# What is QR?
  - An acronym for **Q**t-**R**OS
  - In hindsight, not the best acroym as it's not really related to Qt, but the name stuck so we're going with it

# What is QR_Core?
  - TLDR: CMake extensions and code generation tools for abstracting project building within our new team's software architecture environment
  - A core ROS2/QT project that all other "QR" projects will depend on. It has all cmake files that will be common to all "QR" projects.
  - It will also give code generation utilities in the form of cmake functions.

# Why does QR_Core exist?

First, we devised a workflow needed for LUCI-ROS development based on an event-driven architecture.

1. Create a C++ project for some modular functionality (functionX).
2. Unit test functionX.
3. Create interface data types for functionX.
4. Wrap functionX in ROS functionality.
5. Integration testing functionX with functionY from another module.

We are currently using Qt, C++, ROS, etc. technologies. Each of these require a suite of development tools to work with. These tools are scattered and not integrated with each other.

These tools include:
  - CMake: a build system for C++
  - Colcon: A C++ package management tool
  - Qt C++ Framework
  - OS's: Windows, Linux
  - IDE's: QtCreator, CLION

QR_Core creates a single environment that integrates all the scattered tools with cross platform compatibility. QR_Core abstracts these tools from the developers so they don't have to learn about the integration process or other nuances specific to each tool.

# Basic QR_Core based project structure 
A simple illustration of a "QR_Core" module, vs a regular "module" (or projects containing subprojects)

<p><img src="doc/qr_core_modules0.drawio.png"></p>

[Link to DrawIO diagram](https://drive.google.com/file/d/19_254mHf4ZNGt5-cRjytHBCTdEuoW6eN/view?usp=sharing)

# Quickstart
  - See section QRCore Tutorial 1 in [Hadi's OneNote Notes](https://1drv.ms/u/s!ApEzxR-IU_EYlrl8ZrkMNE2u3l0BJA?e=bKl6Xr)

## Requirements
 - See ROS VM setup guide. (todo: rename and link [rostmp](https://github.com/Instapath/rostmp) repo, should be DevEnv Setup guide or something)



# References
  - [Hadi's OneNote Notes](https://1drv.ms/u/s!ApEzxR-IU_EYlrl8ZrkMNE2u3l0BJA?e=bKl6Xr)














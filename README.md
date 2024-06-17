# LoginAppProject

This is a login simulation project using CMake, CPR, and Vcpkg. The project demonstrates how to perform a login operation using HTTP POST requests and handle responses, including displaying user information upon successful login.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
  - [Windows](#windows)
- [Running the Application](#running-the-application)

## Prerequisites

- **CMake** 3.10 or higher
- **Vcpkg** for dependency management
- **Git** for version control
- **C++17** compatible compiler

## Project Structure

- `CMakeLists.txt`: CMake configuration file.
- `src/`: Source files for the project.
- `include/`: Header files for the project.
- `vcpkg.json`: Vcpkg configuration file listing dependencies.
- `README.md`: Project documentation.

## Building the Project

### Windows

1. **Clone the repository:**

 git clone https://github.com/yourusername/LoginAppProject.git
 cd LoginAppProject

2. **Install dependencies using Vcpkg:**

.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install --triplet=x64-windows

3. **Configure and build the project using CMake:**

mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=..\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake --build .

4. **Run the executable:**

.\Debug\LoginAppProject.exe

### Running the Application

This is a login simulation.
Enter the username: test
Enter the password: test
Attempting to connect...
Connected.
Login successful.
User Information:
+=========================+
Name: John Smith
Credit Card Number: 1234-5678-2300-9000
E-Mail: email@email.com
Phone Number: 2323345
Address: 21 street
+=========================+
Do you want to see the HTML response? (for testing purposes) (y/n): y
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<!-- HTML content -->
</html>




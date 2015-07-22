# How to build Tesseract with OpenCL

## Building Tesseract on VS 2010 with OpenCL

1.	Open the Tesseract Visual Studio 2010 solution file under \\tesseract-ocr\vs2010\tesseract.sln

2.	Select the required build configuration (LIB\_DEBUG / LIB\_RELEASE / DLL\_DEBUG / DLL\_RELEASE)

3.	Set up the OpenCL paths in “tesseract” project:
  * Right click on “tesseract” project and select Properties
  * Header file paths : Go to Configuration Properties -> C/C++ -> General -> Additional Include Directories. Add the directory path where OpenCL header files are located on the given machine. E.g: On a machine with [AMD APP SDK](http://developer.amd.com/tools-and-sdks/heterogeneous-computing/amd-accelerated-parallel-processing-app-sdk/downloads/) installed, this path will be $(AMDAPPSDKROOT)include.
  * Library file path : Go to Configuration Properties -> Linker -> General -> Additional Library Directories. Add the directory path where OpenCL library file, OpenCL.lib is located on the given machine. E.g: On a machine with [AMD APP SDK](http://developer.amd.com/tools-and-sdks/heterogeneous-computing/amd-accelerated-parallel-processing-app-sdk/downloads/) installed, this path will be $(AMDAPPSDKROOT)lib\x86.
  * Library reference : Go to Configuration Properties -> Linker -> Input -> Additional Dependencies. Add OpenCL.lib to the list of dependent libraries.
  * Preprocessor definition : Go to Configuration Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions. Add USE\_OPENCL to the list of preprocessor definitions list.

4.	Repeat the same steps as point 3 above to set OpenCL paths for “libtesseract” project

5.	Build and run the solution.

## Building Tesseract on Linux with OpenCL
  1. Make sure you have installed OpenCL sdk and libtiff-dev
  1. The OpenCL header and library paths are currently defined by the variables OPENCL\_HDR\_PATH and OPENCL\_LIB in configure.ac. These have to be set to the appropriate paths depending on the OpenCL installation.
  1. To build on Linux use
```
./configure --enable-opencl
```
or if you want to specified opencl include (`/opt/AMDAPP/include/`)  and library (`/opt/AMDAPP/lib/x86_64/`) paths:
```
export LIBRARY_PATH=/opt/AMDAPP/lib/x86_64/:$LIBRARY_PATH
CPPFLAGS+=-I/opt/AMDAPP/include/ ./configure --enable-opencl 
```
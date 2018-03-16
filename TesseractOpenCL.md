# Tesseract and OpenCL

OpenCL is an API which allows portable usage of GPU computing resources.
It is support for Linux, macOS and Windows.

Modern graphic cards can do some computations which are needed for Tesseract very fast.
By using that compute power, Tesseract ideally can be made faster.

# How to build Tesseract with OpenCL

**Important note**: OpenCL support in Tesseract is still considered experimental. There are some major bugs associated with it (see issue [837](https://github.com/tesseract-ocr/tesseract/issues/837)). Building Tesseract with OpenCL support is not recommended (for any version of Tesseract), unless you are a developer and want to improve the OpenCL code.

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

# Using Tesseract with OpenCL
Normally Tesseract works with *OpenCL Installable Client Drivers* (ICD).
It tests for available OpenCL drivers at runtime, so a Tesseract binary can work with different GPU hardware on different computers. All you have to do is installing the OpenCL driver for your GPU hardware. There also exists a generic OpenCL driver which uses the CPU instead of a GPU. More than one OpenCL driver can be enabled for a computer system.

When Tesseract with OpenCL support is started the first time, it looks for the available OpenCL drivers and runs benchmarks for each of them. In addition, the same benchmarks are run using the native CPU (without OpenCL). The benchmark results are saved in a file `tesseract_opencl_profile_devices.dat` in the current directory for future runs. Tesseract calculates a weighted performance index from all benchmark results and choses the fastest method for its calculations. Delete the file to force a rebuild. The generated GPU code for each OpenCL driver is also saved in individual files named `kernel-` plus the name of the driver plus `.bin`, for example `kernel-Intel(R)_HD_Graphics_IvyBridge_M_GT2.bin`. Delete those files after an update of your OpenCL software to force a rebuild.

It is possible to override the automatic choice by setting the environment variable `TESSERACT_OPENCL_DEVICE`, for example `TESSERACT_OPENCL_DEVICE=1` selects the first OpenCL device. As the native CPU has also a device number (always the highest number) in Tesseract, use of OpenCL can be disabled by setting that number.

## Installable Client Drivers for OpenCL (ICD)
These Debian packages provide such drivers:
* amd-opencl-icd – AMD Radeon GPU
* beignet-opencl-icd – Intel GPU
* mesa-opencl-icd – AMD GPU
* nvidia-egl-icd – NVIDIA GPU
* nvidia-legacy-304xx-opencl-icd – NVIDIA GPU
* nvidia-legacy-340xx-opencl-icd – NVIDIA GPU
* nvidia-opencl-icd – NVIDIA GPU
* [pocl-opencl-icd](http://portablecl.org/) – native CPU

It is possible to enable debug messages for some drivers by setting environment variables ([example](http://portablecl.org/docs/html/)).

## OpenCL devices (examples)

### Linux (x86)
* Intel(R) HD Graphics IvyBridge M GT2
* pthread-Intel(R) Core(TM) i7-3520M CPU @ 2.90GHz
* pthread-Intel(R) Xeon(R) CPU           E5620  @ 2.40GHz

### macOS

### Windows
* pthread-Intel(R) Core(TM) i5 CPU         650  @ 3.20GHz

## Performance
Only some parts of the OCR process are handled by OpenCL, so using OpenCL does not necessarily result in much faster OCR. More precise measurements have to be done.

## Known problems
OpenCL is still experimental, so expect possible crashes, wrong OCR results or bad instead of improved performance.
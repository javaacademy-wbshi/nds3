# NDS v.3 

## Introduction

NDS (Nominal Device Support) is a library that allows to write device supports for a variety of 
 control systems (CS) by hiding the details of the chosen CS and focusing on device functionalities.

NDS provides the following features:

- organizes your device in a tree-like structure, containing one or 
  more devices, channels, attributes (PVs), state machine, etc.
- provides the data pull mode (passive scanning on EPICS, polling on Tango) and the push mode (Interrupt
  on EPICS, push on Tango)
- your code uses standard C++ types and Unix EPOCH timing to communicate with the library
- on EPICS there is no need to supply separate db files (but you still can if you want)
- supplies an hierarchical state machine
- supplies a specialized data acquisition module
- guaranteed binary compatibility between minor versions allow to easily upgrade existing installations
  without recompiling the device support

## Compilation

### Using make

    make
    sudo make install

### Using qmake

    mkdir build_folder
    cd build_folder
    qmake-qt4 ../nds3_library.pro
    make

or

    mkdir build_folder
    cd build_folder
    qmake ../nds3_library.pro
    make

### Using cmake

    mkdir build_folder
    cd build_folder
    cmake ..
    make



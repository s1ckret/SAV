# SAV
SAV or Sorting Algorithms Visualization it is software that helps to see what is going on inside of sorting algorithm.

## Dependencies
Make sure you have installed:
   - OpenGL
   - git
   - make
   - cmake
   
## How to build
First of all run those commands:
``` shell
git clone https://github.com/S1ckret/SAV.git
cd SAV
git submodule update --init
```

### Windows
You can open folder ```SAV``` in MVS 2019 and build it.
Choose build target - _SAVexe_.
Make sure to __copy__ ``` res ``` folder in folder with generated binary.
_Sorry for inconvenience :)_

### Linux

``` shell
mkdir build
cd build
cmake ..
make SAVexe

# Copy res folder (Will be added to make file later)
cp -r ../SAV/res ./
```


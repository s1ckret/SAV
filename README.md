
# SAV
SAV or Sorting Algorithms Visualization it is software that helps to see what is going on inside of sorting algorithm.

> [Demo on YouTube](https://youtu.be/6ctR5VJL6_Q)

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

## SAV API
### How to init system
You have to create your own derived classes from IDataController and IDataRenderer. They can be empty as in example. Next step is init `m_dataCtrl` and `m_dataRndr` in `void Sandbox::InitUser()` method. Be sure to generate data before passing `m_dataCtrl` to `xxxDataRenderer` constructor.

### How can I add own sorts ?
You have to create class for your sort in `Sandbox/src/Sorts` folder and inherate it from `class ISort`. In constructor set `m_name` to whatever you want for proper displaying in menu. Then override `void Begin()` function. Put this line in the end:
	```m_dataRndr->DisplaySorted( );```
It is __necessary__ for correct menu working. 

After that in `class Sandbox` add your sort to collection.
```SortsController::Get().AddSort(std::make_shared<__YOUR_SORT_HERE__>(m_dataCtrl, m_dataRndr));```

### What instruments do I have ?
You have methods from `xxxDataController` and `xxxDataRenderer`.
#### Built-in virtual methods in IDataController
 - `void Generate(unsigned int size)` - Generates array with element count of @size.
 - `void Shuffle()` - Shuffles array.
 -  `bool CmpGreater(const int &lhs, const int &rhs)` - Increases comparison counter, make comparison: lhs > rhs.
 - `bool CmpLess(const int &lhs, const int &rhs)` - Increases comparison counter, make comparison: lhs < rhs.
 - `bool CmpEqual(const int &lhs, const int &rhs)` - Increases comparison counter, make comparison: lhs == rhs.
 - `void Swap(int &lhs, int &rhs)` - Increases _swap_ counter, swaps two integers.
 - `void Assign(int &lhs, const int &rhs)` - Increases _assignment_ counter, assigns rhs to lhs.
 - `int *Allocate(int count)` - Increases _'bytes allocated'_ counter, allocate memory for @count integers and set to zero.
 - `void Free(int *ptr)` - Frees allocated memory.

#### Built-in virtual methods in IDataRenderer
- 


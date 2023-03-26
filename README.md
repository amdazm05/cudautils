### These are just utilities that one would like to have
|Utility      | What it does | Status     |
| :---        |    :----:   |          ---: |
| fileoperations    | reads and writes to files , also maintains a map for the files read and written       |  completed   |
| threadpool   | used for creating pools of threads for various concurrent operations| completed |
| timer   | supports both steady and system timers | completed |
| memory pool   | for dynamic preallocations | completed |
| coroutines | A boiler plate for starting with coroutines | WIP |
| scheduler | schedules tasks , or runs them for a set period | WIP |

### Running tests
All tests will show up as executables .(Will be making a testing framework too soon don't know when )
```
mkdir build 
cd build 
cmake ..
make 
```
### Using the utilities
```
add_subdirectory(${PATH}/utilities.cc)
```

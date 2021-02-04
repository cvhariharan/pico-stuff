### Steps to build
- Clone [pico-sdk](https://github.com/raspberrypi/pico-sdk) so that the pico-sdk and pico-stuff directories are on the same level.  
- Navigate to the project you want to build (for eg. pwm) and create a build folder.
```
mkdir build
cd build
```
- Set the `PICO_SDK_PATH`
```
export PICO_SDK_PATH=../../../pico-sdk
```
- Run `cmake`
```
cmake ..
```
- `cmake` will generate a `Makefile` in the build directory which you can use to build the project.
```
make -j4
```
- Copy the uf2 file generated to pico
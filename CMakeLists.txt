cmake_minimum_required (VERSION 2.8.11)
project (Vector)
set(CMAKE_CXX "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++11 -O3 -march=native -pg")

# Commentaire
include_directories(src)

add_executable(testMat test/testMat.cpp)
add_executable(hauteurs test/hauteurs.cpp src/Height.cpp src/Dvector.cpp)
add_executable(vect test/vect.cpp src/Dvector.cpp)
add_executable(prodScal test/testProdScal.cpp src/Dvector.cpp)
add_executable(operateurs test/operateurs.cpp src/Dvector.cpp)
add_executable(resize test/resize.cpp src/Dvector.cpp)
add_executable(testTime test/testTime.cpp src/Dvector.cpp)
add_executable(testGerstner test/testGerstner.cpp src/GerstnerWave.cpp src/WaveModel.cpp src/Dvector.cpp )
add_executable(testGWM test/testGerstnerWaveModel.cpp src/GerstnerWaveModel.cpp src/WaveModel.cpp src/Dvector.cpp src/GerstnerWave )
add_executable(testPhilipsWave test/testPhilipsWave.cpp src/PhilipsWave.cpp src/WaveModel.cpp src/Dvector.cpp)
add_executable(testPWM test/testPhilipsWaveModel.cpp src/PhilipsWaveModel.cpp src/WaveModel.cpp src/Dvector.cpp src/PhilipsWave.cpp src/Utils.cpp)
add_executable(testFft test/testFft.cpp src/Utils.cpp src/Dvector.cpp src/Height.cpp)
add_executable(testFft2D test/testFft2D.cpp src/Utils.cpp src/Dvector.cpp src/Height.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )
add_executable(exe src/main.cpp src/Dvector.cpp src/camera.cpp src/Height.cpp src/Utils.cpp src/WaveModel.cpp src/PhilipsWaveModel.cpp src/GerstnerWaveModel.cpp src/PhilipsWave.cpp src/GerstnerWave.cpp src/window.cpp src/ocean.cpp)
target_link_libraries(exe ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

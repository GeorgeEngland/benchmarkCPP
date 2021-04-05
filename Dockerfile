# Get the base Ubuntu image from Docker Hub
FROM gcc:latest
LABEL Name=productioncpp Version=0.0.1

# Update apps on the base image
RUN apt-get -y update && apt-get install -y git
RUN git clone https://github.com/google/benchmark.git
RUN git clone https://github.com/google/googletest.git benchmark/googletest
WORKDIR /benchmark
RUN apt-get -y update && apt-get install -y cmake 
RUN cmake -E make_directory "build"
WORKDIR /benchmark/build
RUN cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON -DCMAKE_BUILD_TYPE=Release ../ 
WORKDIR /benchmark
RUN cmake --build "build" --config Release
WORKDIR  /
# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/dockertest1

# Specify the working directory
WORKDIR /usr/src/dockertest1

# Use g++ to compile the Test.cpp source file
RUN g++ ./src/grid.cpp ./test/solution.cpp ./test/benchmarkFunctions.cpp -std=c++17 -O2 -isystem benchmark/include \
    -Lbenchmark/build/src -lbenchmark -lpthread -fopenmp -o mybenchmark

# Run the output program from the previous step
CMD ["./mybenchmark", "--benchmark_filter=BM_G"]


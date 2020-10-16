### SimpleDemoToUseJIT

### Prerequisites(use apt install)

- cmake>=3.16

- clang-10

- llvm-10

### Clone the Repository

`git clone https://github.com/csuchenhao/SimpleDemoToUseJIT.git`

### Build the Code

```
clang precompiled/equal.cpp -emit-llvm -c -o equal.bc
mkdir build
cd build
cmake ..
make
./SimpleDemoToUseJIT
```



### `Run`

`./SimpleDemoToUseJIT`



### 
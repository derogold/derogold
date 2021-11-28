<img src="https://i.imgur.com/4FlvRAt.png" width="200">

### Installing

We offer binary images of the latest releases here: https://github.com/derogold/derogold/releases

If you would like to compile yourself, read on.

### How To Compile

#### Build Optimization

The CMake build system will, by default, create optimized *native* builds for your particular system type when you build the software. Using this method, the binaries created provide a better experience and all together faster performance.

However, if you wish to create *portable* binaries that can be shared between systems, specify `-DARCH=default` in your CMake arguments during the build process. Note that *portable* binaries will have a noticable difference in performance than *native* binaries. For this reason, it is always best to build for your particular system if possible.

#### Linux

##### Prerequisites

You will need the following packages: [Boost](https://www.boost.org/), [OpenSSL](https://www.openssl.org/), cmake (3.8 or higher), make, and git.

You will also need either GCC/G++, or Clang.

If you are using GCC, you will need GCC-7.0 or higher.

If you are using Clang, you will need Clang 6.0 or higher. You will also need libstdc++\-6.0 or higher.

##### Ubuntu, using GCC

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `sudo apt update`
- `sudo apt install -y build-essential g++-9 gcc-9 git libboost-all-dev python-pip libssl-dev cmake`
- `export CC=gcc-9`
- `export CXX=g++-9`
- `git clone -b master --single-branch https://github.com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./DeroGoldd --version`

##### Ubuntu, using Clang

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -`

You need to modify the below command for your version of ubuntu - see https://apt.llvm.org/

* Ubuntu 18.04 (Bionic)
- `sudo add-apt-repository "deb https://apt.llvm.org/bionic/ llvm-toolchain-bionic 6.0 main"`

* Ubuntu 19.04 (Disco)
- `sudo add-apt-repository "deb https://apt.llvm.org/disco/ llvm-toolchain-disco 6.0 main"`

* Ubuntu 20.04 (Focal)
- `sudo add-apt-repository "deb https://apt.llvm.org/focal/ llvm-toolchain-focal 6.0 main"`

- `sudo apt update`
- `sudo apt install -y build-essential clang-6.0 libstdc++-7-dev git libboost-all-dev python-pip libssl-dev`
- `sudo pip install cmake`
- `export CC=clang-6.0`
- `export CXX=clang++-6.0`
- `git clone -b master --single-branch https://github.com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./DeroGoldd --version`

##### Generic Linux

Ensure you have the dependencies listed above.

If you want to use clang, ensure you set the environment variables `CC` and `CXX`.
See the ubuntu instructions for an example.

- `git clone -b master --single-branch https://github.com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./DeroGoldd --version`

#### OSX/Apple, using Clang

##### Prerequisites

- Install XCode, XCode Command Line Tools / Developer Tools.

##### Building

- `which brew || /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
- `brew install --force cmake boost llvm@8 openssl`
- `brew link --overwrite llvm@8`
- `ln -s /usr/local/opt/llvm@8 /usr/local/opt/llvm`
- `export CC=/usr/local/opt/llvm@8/bin/clang`
- `export CXX=/usr/local/opt/llvm@8/bin/clang++`
- `git clone -b master --single-branch https://github.com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./DeroGoldd --version`

#### Windows with VS2019

##### Prerequisites

You can build for 32-bit or 64-bit Windows. **If you're not sure, pick 64-bit.**

- Download the [Build Tools for Visual Studio 2019](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16) Installer
- When it opens up select **C++ build tools**, it automatically selects the needed parts
- Install Boost (1.69 works the latest is 1.70 and doesn't work). Select the appropriate version for your system:
  - [Boost 64-bit](https://sourceforge.net/projects/boost/files/boost-binaries/1.77.0/boost_1_77_0-msvc-14.1-64.exe/download)
  - [Boost 32-bit](https://bintray.com/boostorg/release/download_file?file_path=1.69.0%2Fbinaries%2Fboost_1_69_0-msvc-14.1-32.exe)
- Install the latest full version of OpenSSL (currently OpenSSL 3.0.0). Select the appropriate version for your system:
  - [OpenSSL 64-bit](https://slproweb.com/download/Win64OpenSSL-3_0_0.exe)
  - [OpenSSL 32-bit](https://slproweb.com/download/Win32OpenSSL-1_1_1i.exe)

##### Building

For 64-bit:
- From the start menu, open 'x64 Native Tools Command Prompt for vs2019'.
- `cd <your_derogold_directory>`
- `mkdir build`
- `cd build`
- `set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%`
- `cmake -G "Visual Studio 16 2019" -A x64 .. -DBOOST_ROOT=C:/local/boost_1_77_0`

If you have errors on this step about not being able to find the following static libraries, you may need to update your cmake. Open 'Visual Studio Installer' and click 'Update'.

- `MSBuild DeroGold.sln /p:Configuration=Release /p:PlatformToolset=v142 /m`

For 32-bit:
- `cd <your_derogold_directory>`
- `mkdir build`
- `cd build`
- `set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%`
- `cmake -G "Visual Studio 16 2019" -A Win32 .. -DBOOST_ROOT=C:/local/boost_1_69_0`

If you have errors on this step about not being able to find the following static libraries, you may need to update your cmake. Open 'Visual Studio Installer' and click 'Update'.

- `MSBuild DeroGold.sln /p:Configuration=Release /p:Platform=Win32 /p:PlatformToolset=v141 /m`

The binaries will be in the `src/Release` folder when you are complete.

- `cd src`
- `cd Release`
- `DeroGoldd.exe --version`

#### AARCH64/ARM64 (non-Raspberry)
When building on latest Armbian supported for your board, follow linux GCC instructions above.

##### Raspberry PI boards

Make sure you use a full 64-bit image (kernel + userspace). Some of the earlier Raspbian builds were not full 64-bit
The images below are known to be full 64-bit images for your Raspberry PI board 

- https://github.com/Crazyhead90/pi64/releases
- https://fedoraproject.org/wiki/Architectures/ARM/Raspberry_Pi#aarch64_supported_images_for_Raspberry_Pi_3
- https://archlinuxarm.org/platforms/armv8/broadcom/raspberry-pi-3

Once you have a 64 bit image installed, setup proceeds the same as any Linux distribution. Ensure you have at least 1GB of ram, or the build is likely to fail. You may need to setup swap space and / or compile with `-j1` with `make`.

##### Building

- `git clone -b master --single-branch https://github.com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make` 

The binaries will be in the `src` directory when you are complete.

- `cd src`
- `./DeroGoldd --version`

##### Building with LevelDB
No need to add a flag anymore, both RocksDB and LevelDB backends are build. You can switch between them by using DeroGoldd command line option at the runtime.

#### Thanks
Cryptonote Developers, Bytecoin Developers, Monero Developers, Forknote Project, TurtleCoin Developers

### Copypasta for license when editing files

Hi DeroGold contributor, thanks for forking and sending back Pull Requests. Extensive docs about contributing are in the works or elsewhere. For now this is the bit we need to get into all the files we touch. Please add it to the top of the files, see [src/CryptoNoteConfig.h] for an example.

```
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2020, The TurtleCoin Developers
// Copyright (c) 2018-2021, The WRKZCoin Developers
// Copyright (c) 2019-2021, uPlexa
// Copyright (c) 2018-2021, The DeroGold Developers
//
// Please see the included LICENSE file for more information.
```

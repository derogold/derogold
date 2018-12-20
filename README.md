![image](https://i.imgur.com/g344WtY.png)

hello this the derogoldencoin page for derogolden pleased to enjoy coin

dig with script on here and make purse

thanks to enjoy))


### installing

our offered binary images the for latest releases this place: https://github.com/hassan-oldover/derogoldencoin/releases

conditionally to you are a will appreciation to compile yourself, read in. 
 
### with a method to compile

#### linux

##### prerequisites

you are a would do the needed following packages: boost, cmake (3. 8 or higher), create, and git. 
 
you are a would do also needed either gcc/g++, or clang. 
 
conditionally to you are am using gcc, you are a would do needed gcc-7. 0 or higher. 
 
conditionally to you are am using clang, you are a would do needed clang 6. 0 or higher.  You are a would do also needed libstdc++\-6. 0 or higher. 
 
##### ubuntu, using gcc

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `sudo apt-get update`
- `sudo apt-get install aptitude -y`
- `sudo aptitude install -y build-essential g++-8 gcc-8 git libboost-all-dev python-pip`
- `sudo pip install cmake`
- `export cc=gcc-8`
- `export cxx=g++-8`
- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`

##### ubuntu, using clang

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `wget -o - https://apt. llvm. org/llvm-snapshot. gpg. key | sudo apt-key addition -`

you are a needed to the modify short command of yours version for ubuntu - look https://apt. llvm. org/

* ubuntu 14. 04 (trusty)
- `sudo add-apt-repository "deb https://apt. llvm. org/trusty/ llvm-toolchain-trusty 6. 0 main"`

* ubuntu 16. 04 (xenial)
- `sudo add-apt-repository "deb https://apt. llvm. org/xenial/ llvm-toolchain-xenial 6. 0 main"`

* ubuntu 18. 04 (bionic)
- `sudo add-apt-repository "deb https://apt. llvm. org/bionic/ llvm-toolchain-bionic 6. 0 main"`

- `sudo apt-get update`
- `sudo apt-get install aptitude -y`
- `sudo aptitude install -y -o aptitude::problemresolver::solutioncost='100*canceled-actions,200*removals' build-essential clang-6. 0 libstdc++-7-dev git libboost-all-dev python-pip`
- `sudo pip install cmake`
- `export cc=clang-6. 0`
- `export cxx=clang++-6. 0`
- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`

##### generic linux

ensure you are a the take dependencies list above. 
 
conditionally to you are a in need of to used clang, ensure you are a the set environment variables `cc` and `cxx`. 
 the look ubuntu instructions of an example. 
 
- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`

#### osx/apple, using gcc

##### prerequisites

- install xcode and developer tools. 
 
##### construction

- `which brew || /usr/bin/ruby -e "$(curl -fssl https://raw. githubusercontent. com/homebrew/install/master/install)"`
- `brew install --force cmake boost llvm gcc@8`
- `export cc=gcc-8`
- `export cxx=g++-8`
- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`

#### osx/apple, using clang

##### prerequisites

- install xcode and developer tools. 
 
##### construction

- `which brew || /usr/bin/ruby -e "$(curl -fssl https://raw. githubusercontent. com/homebrew/install/master/install)"`
- `brew install --force cmake boost llvm`
- `export cc=/usr/local/opt/llvm/bin/clang`
- `export cxx=/usr/local/opt/llvm/bin/clang++`
- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`


#### windows

##### prerequisites

- install [visual studio 2017 community edition](https://www. visualstudio. com/thank-you-downloading-visual-studio/?sku=community&rel=15&page=inlineinstall)
- what time installing visual studio, it is **required** this you are a install **desktop develop taking c++**
- the install latest version for [boost](https://bintray. com/boostorg/release/download_file?file_path=1. 68. 0%2fbinaries%2fboost_1_68_0-msvc-14. 1-64. exe) - currently boost 1. 68. 
 
##### construction

- the originate started menu, opened 'x64 native tools command prompt of vs2017'. 
 - `cd <your_dero_gold_directory>`
- `mkdir build`
- `cd build`
- `set path="c:\program files (x86)\microsoft visual studio\2017\community\common7\ide\commonextensions\microsoft\cmake\cmake\bin";%path%`
- `cmake -g "visual studio 15 2017 win64".  -dboost_root=c:/local/boost_1_68_0`

conditionally to you are a take errors in that stepped around don't being abrue to the found following static libraries, you are a may needed to update yours cmake.  Opened 'visual studio installer' and click 'update'. 
 
- `msbuild derogold. sln /p:configuration=release /m`
 the
binaries would do be the on `src/release` folder what time you are am completed. 
 
- `cd src`
- `cd release`
- `derogoldd. exe --version`

#### raspberry pi 3 b+ the
following images am know to worked.  Yours operation system image **must** be 64 bite. 
 
##### know working images

- https://github. com/crazyhead90/pi64/releases
- https://fedoraproject. org/wiki/architectures/arm/raspberry_pi#aarch64_supported_images_for_raspberry_pi_3
- https://archlinuxarm. org/platforms/armv8/broadcom/raspberry-pi-3

once you are a take that 64 bite image installed, setup the proceeds same to anytime linux distribution.  Ensure you are a take upon least 2gb for ram, the or built is likely to fail.  You are a may needed to setup swap space. 
 
##### construction

- `git clone -b master --single-branch https://github. com/derogold/derogold`
- `cd derogold`
- `mkdir build`
- `cd build`
- `cmake. `
- `make`
 the
binaries would do be the on `src` folder what time you are am completed. 
 
- `cd src`
- `. /derogoldd --version`

#### Thanks
Cryptonote Developers, Bytecoin Developers, Monero Developers, Forknote Project, TurtleCoin Community

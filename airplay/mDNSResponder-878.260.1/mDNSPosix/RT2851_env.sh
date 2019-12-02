export PATH=/opt/android-ndk-toolchain-r21/bin/:$PATH

export CC="arm-linux-androideabi-gcc  --sysroot=/opt/android-ndk-toolchain-r21/sysroot/"
export CXX="arm-linux-androideabi-g++  --sysroot=/opt/android-ndk-toolchain-r21/sysroot/"
export LD="arm-linux-androideabi-ld"
export CPP="arm-linux-androideabi-cpp --sysroot=/opt/android-ndk-toolchain-r21/sysroot/"
export RANLIB="arm-linux-androideabi-ranlib"
export AR="arm-linux-androideabi-ar"
export AS="arm-linux-androideabi-as"
export NM="arm-linux-androideabi-nm"
export STRIP="arm-linux-androideabi-strip"
export OBJCOPY="arm-linux-androideabi-objcopy"
export GCC=$CC
export GPLUS=$CXX

rm -rf ./install/*
mkdir ./install/lib
mkdir ./install/bin
mkdir ./install/include

cd mDNSResponder-878.260.1/mDNSPosix/
rm -rf ./objects
rm -rf ./build
source RT2851_env.sh
make VERBOSE=1 os=linux
make os=linux install
cd -


cd AirPlay/AirPlaySDK/PlatformPOSIX
make  os=linux debug=1  verbose=1
cd -

#cd AirPlay/AirPlaySDK/AccessorySDK/PlatformPOSIX
#make os=linux debug=1 mfi=1  arch=ARMv7 libtommath=1 openssl=0 install
#make install
#cd -


 
cp mDNSResponder-878.260.1/mDNSPosix/build/prod/mdnsd install/
mv install/airplaydemo  install/bin/
mv install/airplayutil install/bin/
mv install/mdnsd install/bin/

pwdpath=$(pwd)
export LD_LIBRARY_PATH=${pwdpath}/install/lib:${LD_LIBRARY_PATH}

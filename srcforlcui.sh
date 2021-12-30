# Install the dependencies
sudo apt-get install libpng-dev libjpeg-dev libxml2-dev libfreetype6-dev libx11-dev
# Clone this repository
git clone https://github.com/lc-soft/LCUI.git
# Go into the repository
cd LCUI
# Generate automake configure script
./autogen.sh
# Check the build environment and configure automake scripts
./configure
# Build
make
# If you want to install LCUI
sudo make install

# Go into test directory
#cd test
# Run helloworld application
#./helloworld

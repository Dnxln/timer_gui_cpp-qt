cd Desktop/

mkdir test

cd test

git clone https://github.com/Dnxln/timer_gui_cpp-qt

cd timer_gui_cpp-qt/

sudo apt update
sudo apt install build-essential cmake qtbase5-dev qt5-qmake qtbase5-dev-tools

mkdir build

cd build

cmake ..

make

./AppLauncher  (o comunque nome eseguibile con cui si crea)

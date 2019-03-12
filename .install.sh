sudo apt-get install libncurses5-dev libncursesw5-dev
sudo mv fmod/inc/*.h /usr/local/include/
sudo mv fmod/lib/*.so /usr/local/lib/
sudo mv fmod/lib/*.so.* /usr/local/lib/
sudo ldconfig -v

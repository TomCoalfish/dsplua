gcc -Iinclude -O2 -march=native -mavx2 -o test audio_template.cpp audiosystem.c PolyBLEP.cpp -lstdc++ -lm -lkfr_dft -lkfr_io -lportaudio -lportmidi -lpthread

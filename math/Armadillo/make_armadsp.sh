swig -lua -c++ -Iinclude/arma-dsp arma-dsp/armadsp.i
gcc -Iinclude/arma-dsp  -DMKL_ILP64  -m64  -I/opt/intel/oneapi/mkl/2022.0.2/include -O2 -fPIC -march=native -mavx2 -shared -o armadsp.so arma-dsp/armadsp_wrap.cxx lib/libarmadsp.a -lstdc++ -lm -lluajit -larmadillo  -L/opt/intel/oneapi/mkl/2022.0.2/lib/intel64 -Wl,--no-as-needed -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -ldl

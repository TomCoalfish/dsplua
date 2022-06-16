/*

    FFT Interpolation class
    Copyright (C) 2002-2003 Jussi Laako

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#include <cstdio>
#ifdef USE_INTEL_MATH
    #include <mathimf.h>
#else
    #include <math.h>
#endif
#include <float.h>

#include "dsp/FFTInterpolator.hh"


clFFTInterpolator::clFFTInterpolator ()
{
}


clFFTInterpolator::~clFFTInterpolator ()
{
    if (bInitialized) Uninitialize();
}


void clFFTInterpolator::Uninitialize ()
{
    IntBuf.Free();
    clFFTMultiRate::Uninitialize();
}


void clFFTInterpolator::Put (const float *fpSrcData, long lSrcCount)
{
    long lWorkCount;
    float *fpIntBuf;

    lWorkCount = lSrcCount * lFactor;
    fpIntBuf = (float *) IntBuf.Size(lWorkCount * sizeof(float));
    DSP.Interpolate(fpIntBuf, fpSrcData, lFactor, lSrcCount);
    Filter.Put(fpIntBuf, lWorkCount);
}


void clFFTInterpolator::Put (const double *dpSrcData, long lSrcCount)
{
    long lWorkCount;
    double *dpIntBuf;

    lWorkCount = lSrcCount * lFactor;
    dpIntBuf = (double *) IntBuf.Size(lWorkCount * sizeof(double));
    DSP.Interpolate(dpIntBuf, dpSrcData, lFactor, lSrcCount);
    Filter.Put(dpIntBuf, lWorkCount);
}


bool clFFTInterpolator::Get (float *fpDestData, long lDestCount)
{
    return Filter.Get(fpDestData, lDestCount);
}


bool clFFTInterpolator::Get (double *dpDestData, long lDestCount)
{
    return Filter.Get(dpDestData, lDestCount);
}

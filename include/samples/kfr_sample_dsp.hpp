#pragma once 

#include "kfr_sample.hpp"
#include "Kfr/kfrcore.hpp"
#include "AudioFFT/AudioFFT.h"
#include "AudioFFT/FFTConvolver.h"

template<typename T> using complex = kfr::complex<T>;
template<typename T> using complex_vector = kfr::univector<complex<T>>;

namespace SoundAlchemy
{
    template<typename T>
    complex_vector<T> dft_forward(complex_vector<T> input)
    {        
        return DSP::run_dft(input);        
    }
    template<typename T>
    complex_vector<T> dft_inverse(complex_vector<T> input)
    {        
        return  DSP::run_idft(input);     
    }
    template<typename T>
    complex_vector<T> rdft_forward(sample_vector<T> input)
    {        
        return run_realdft(input);     
    }
    template<typename T>
    sample_vector<T> rdft_inverse(complex_vector<T> in)
    {        
        return run_irealdft(in);        
    }

    template<typename T>
    sample_vector<T> dct_forward(sample_vector<T> in)
    {        
        DSP::DCTPlan<T> dct(in.size());
        kfr::univector<T> out(in.size());
        dct.execute(out,in,false);
        return out;
    }
    template<typename T>
    sample_vector<T> dct_inverse(sample_vector<T> in)
    {        
        DSP::DCTPlan<T> dct(in.size());
        kfr::univector<T> out(in.size());
        dct.execute(out,in,true);
        return out;
    }
    template<typename T>
    sample_vector<T> convolve(sample_vector<T> a, sample_vector<T> b)
    {                
        return kfr::convolve(a,b);        
    }
    template<typename T>
    sample_vector<T> correlate(sample_vector<T> a, sample_vector<T> b)
    {                
        return kfr::correlate(a,b);        
    }
    template<typename T>
    sample_vector<T> autocorrelate(sample_vector<T> a)
    {                
        return kfr::autocorrelate(a);        
    }
    template<typename T>
    sample_vector<T> convolve_filter(size_t block_size,sample_vector<T> impulse, sample_vector<T> x)
    {        
        sample_vector<T> out(x.size());
        DSP::ConvolveFilter<T> filter(impulse,block_size);        
        filter.apply(x,out);
        return out;
    }
    template<typename T>
    sample_vector<T> dcremove(T cutoff, sample_vector<T> in)
    {        
        return DSP::dcremove(in,cutoff);     
    }

    template<typename T>
    sample_vector<T> sinewave(size_t n, T freq, T sample_rate, T phase=(T)0) {        
        return DSP::sinewave(n,freq,sample_rate,phase);        
    }
    template<typename T>
    sample_vector<T> squarewave(size_t n, T freq, T sample_rate, T phase=(T)0) {        
        return DSP::squarewave(n,freq,sample_rate,phase);        
    }
    template<typename T>
    sample_vector<T> trianglewave(size_t n, T freq, T sample_rate, T phase=(T)0) {        
        return DSP::trianglewave(n,freq,sample_rate,phase);        
    }
    template<typename T>
    sample_vector<T> sawtoothewave(size_t n, T freq, T sample_rate, T phase=(T)0) {        
        return DSP::squarewave(n,freq,sample_rate,phase);        
    }    

    template<typename T>
    sample_vector<T> load_wav(const char * filename)
    {
        return DSP::load_wav<T>(filename);        
    }
    template<typename T>
    sample_vector<T> load_mp3(const char * filename)
    {
        return DSP::load_mp3<T>(filename);        
    }
    template<typename T>
    sample_vector<T> load_flac(const char * filename)
    {
        return DSP::load_flac<T>(filename);        
    }
    template<typename T>
    void save_wav(sample_vector<T>  in, const char * filename, size_t channels, int sample_type, double sample_rate, bool use_w64=false)
    {        
        DSP::write_wav(in,filename,channels,sample_type,sample_rate,use_w64);
        
    }

    template<typename T>
    void plot(sample_vector<T> in, std::string& name = "", std::string& options = "") {
        kfr::plot_show(name,in,options);
    }


    template<typename T> 
    struct KfrBesselFilter
    {
        DSP::BesselLowPassFilter<T>  *lowpass_filter;
        DSP::BesselHighPassFilter<T> *highpass_filter;
        DSP::BesselBandPassFilter<T> *bandpass_filter;
        DSP::BesselBandStopFilter<T> *bandstop_filter;
        
        KfrBesselFilter(int order,float cutoff,float hi, float sample_rate) 
        {
            lowpass_filter = new DSP::BesselLowPassFilter<T>(order,cutoff,sample_rate);            
            highpass_filter = new DSP::BesselHighPassFilter<T>(order,cutoff,sample_rate);            
            bandpass_filter = new DSP::BesselBandPassFilter<T>(order,cutoff,hi,sample_rate);
            bandstop_filter = new DSP::BesselBandStopFilter<T>(order,cutoff,hi,sample_rate);
            
        }
        ~KfrBesselFilter() {
            if(lowpass_filter) delete lowpass_filter;
            if(highpass_filter) delete highpass_filter;
            if(bandpass_filter) delete bandpass_filter;
            if(bandstop_filter) delete bandstop_filter;
        }

        /* can't change right now
        void setLowpassCutoff(float c) {
            lowpass_filter->setCutoff(c);
        }
        void setHighpassCutoff(float c) {
            highpass_filter->setCutoff(c);
        }
        void setBandpassCutoff(float c, float h) {
            bandpass_filter->setCutoff(c,h);
        }
        void setBandstopCutoff(float c, float h) {
            bandstop_filter->setCutoff(c);
        }
        */
        sample_vector<T> lowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass->apply(in,out);            
            return out;
        }
        
        sample_vector<T> highpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highpass->apply(in,out);
            return out;
        }
        
        sample_vector<T> bandpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandpass->apply(in,out);
            return out;        
        }
        
        sample_vector<T> bandstop(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandstop->apply(in,out);
            return out;        
        }
    };

    template<typename T> 
    struct KfrButterworthFilter
    {
        DSP::ButterworthLowPassFilter<T>  *lowpass_filter;
        DSP::ButterworthHighPassFilter<T> *highpass_filter;
        DSP::ButterworthBandPassFilter<T> *bandpass_filter;
        DSP::ButterworthBandStopFilter<T> *bandstop_filter;
        
        KfrButterworthFilter(int order,float cutoff,float hi, float sample_rate) 
        {
            lowpass_filter = new DSP::ButterworthLowPassFilter<T>(order,cutoff,sample_rate);            
            highpass_filter = new DSP::ButterworthHighPassFilter<T>(order,cutoff,sample_rate);            
            bandpass_filter = new DSP::ButterworthBandPassFilter<T>(order,cutoff,hi,sample_rate);
            bandstop_filter = new DSP::ButterworthBandStopFilter<T>(order,cutoff,hi,sample_rate);
            
        }
        ~KfrButterworthFilter() {
            if(lowpass_filter) delete lowpass_filter;
            if(highpass_filter) delete highpass_filter;
            if(bandpass_filter) delete bandpass_filter;
            if(bandstop_filter) delete bandstop_filter;
        }

        /* can't right now
        void setLowpassCutoff(float c) {
            lowpass_filter->setCutoff(c);
        }
        void setHighpassCutoff(float c) {
            highpass_filter->setCutoff(c);
        }
        void setBandpassCutoff(float c, float h) {
            bandpass_filter->setCutoff(c,h);
        }
        void setBandstopCutoff(float c, float h) {
            bandstop_filter->setCutoff(c);
        }
        */
        sample_vector<T> lowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass->apply(in,out);            
            return out;
        }
        
        sample_vector<T> highpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highpass->apply(in,out);
            return out;
        }
        
        sample_vector<T> bandpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandpass->apply(in,out);
            return out;        
        }
        
        sample_vector<T> bandstop(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandstop->apply(in,out);
            return out;        
        }
    };


    template<typename T> 
    struct KfrChebyshev1Filter
    {
        DSP::Chebyshev1LowPassFilter<T>  *lowpass_filter;
        DSP::Chebyshev1HighPassFilter<T> *highpass_filter;
        DSP::Chebyshev1BandPassFilter<T> *bandpass_filter;
        DSP::Chebyshev1BandStopFilter<T> *bandstop_filter;
        
        KfrChebyshev1Filter(int order,float cutoff,float hi, float sample_rate) 
        {
            lowpass_filter = new DSP::Chebyshev1LowPassFilter<T>(order,cutoff,sample_rate);            
            highpass_filter = new DSP::Chebyshev1HighPassFilter<T>(order,cutoff,sample_rate);            
            bandpass_filter = new DSP::Chebyshev1BandPassFilter<T>(order,cutoff,hi,sample_rate);
            bandstop_filter = new DSP::Chebyshev1BandStopFilter<T>(order,cutoff,hi,sample_rate);
            
        }
        ~KfrChebyshev1Filter() {
            if(lowpass_filter) delete lowpass_filter;
            if(highpass_filter) delete highpass_filter;
            if(bandpass_filter) delete bandpass_filter;
            if(bandstop_filter) delete bandstop_filter;
        }

        /* nope
        void setLowpassCutoff(float c) {
            lowpass_filter->setCutoff(c);
        }
        void setHighpassCutoff(float c) {
            highpass_filter->setCutoff(c);
        }
        void setBandpassCutoff(float c, float h) {
            bandpass_filter->setCutoff(c,h);
        }
        void setBandstopCutoff(float c, float h) {
            bandstop_filter->setCutoff(c);
        }
        */
       
        sample_vector<T> lowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass->apply(in,out);            
            return out;
        }
        
        sample_vector<T> highpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highpass->apply(in,out);
            return out;
        }
        
        sample_vector<T> bandpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandpass->apply(in,out);
            return out;        
        }
        
        sample_vector<T> bandstop(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandstop->apply(in,out);
            return out;        
        }
    };

    template<typename T> 
    struct KfrChebyshev2Filter
    {
        DSP::Chebyshev2LowPassFilter<T>  *lowpass_filter;
        DSP::Chebyshev2HighPassFilter<T> *highpass_filter;
        DSP::Chebyshev2BandPassFilter<T> *bandpass_filter;
        DSP::Chebyshev2BandStopFilter<T> *bandstop_filter;
        
        KfrChebyshev2Filter(int order,float cutoff,float hi, float sample_rate) 
        {
            lowpass_filter = new DSP::Chebyshev2LowPassFilter<T>(order,cutoff,sample_rate);            
            highpass_filter = new DSP::Chebyshev2HighPassFilter<T>(order,cutoff,sample_rate);            
            bandpass_filter = new DSP::Chebyshev2BandPassFilter<T>(order,cutoff,hi,sample_rate);
            bandstop_filter = new DSP::Chebyshev2BandStopFilter<T>(order,cutoff,hi,sample_rate);
            
        }
        ~KfrChebyshev2Filter() {
            if(lowpass_filter) delete lowpass_filter;
            if(highpass_filter) delete highpass_filter;
            if(bandpass_filter) delete bandpass_filter;
            if(bandstop_filter) delete bandstop_filter;
        }

        /* can't change it right now
        void setLowpassCutoff(float c) {
            lowpass_filter->setCutoff(c);
        }
        void setHighpassCutoff(float c) {
            highpass_filter->setCutoff(c);
        }
        void setBandpassCutoff(float c, float h) {
            bandpass_filter->setCutoff(c,h);
        }
        void setBandstopCutoff(float c, float h) {
            bandstop_filter->setCutoff(c);
        }
        */

        sample_vector<T> lowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass->apply(in,out);            
            return out;
        }
        
        sample_vector<T> highpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highpass->apply(in,out);
            return out;
        }
        
        sample_vector<T> bandpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandpass->apply(in,out);
            return out;        
        }
        
        sample_vector<T> bandstop(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandstop->apply(in,out);
            return out;        
        }
    };


    template<typename T>
    struct KfrBiquadFilter
    {
        DSP::NotchFilter<T> * notch_filter;
        DSP::LowPassFilter<T> * lowpass_filter;
        DSP::HighPassFilter<T> * highpass_filter;
        DSP::AllPassFilter<T> * allpass_filter;
        DSP::BandPassFilter<T> * bandpass_filter;
        DSP::PeakFilter<T> * peak_filter;
        DSP::LowShelfFilter<T> * lowshelf_filter;
        DSP::HighShelfFilter<T> * highshelf_filter;

        
        // gain is only used for peak
        // q is only used for 1st order the others are preset        
        KfrBiquadFilter(int order, float cutoff,  float sampleRate, float gain = 1,float q = 0.707) {            
            notch_filter    = new DSP::NotchFilter<T>(order,cutoff,sampleRate,q);
            lowpass_filter  = new DSP::LowPassFilter<T>(order,cutoff,sampleRate,q);
            highpass_filter = new DSP::HighPassFilter<T>(order,cutoff,sampleRate,q);
            allpass_filter = new DSP::AllPassFilter<T>(order,cutoff,sampleRate,q);
            bandpass_filter = new DSP::BandPassFilter<T>(order,cutoff,sampleRate,q);
            peak_filter = new DSP::PeakFilter<T>(order,cutoff,sampleRate,gain,q);
            lowshelf_filter = new DSP::LowShelfFilter<T>(order,cutoff,sampleRate,q);
            highshelf_filter = new DSP::HighShelfFilter<T>(order,cutoff,sampleRate,q);
        }   
        ~KfrBiquadFilter() 
        {
            if(notch_filter) delete notch_filter;
            if(lowpass_filter) delete lowpass_filter;
            if(highpass_filter) delete highpass_filter;
            if(allpass_filter) delete allpass_filter;
            if(bandpass_filter) delete bandpass_filter;
            if(peak_filter) delete peak_filter;
            if(lowshelf_filter) delete lowshelf_filter;
            if(highshelf_filter) delete highshelf_filter;
        }

        /* can't change it right now
        void setLowpassCutoff(T c) {            
            lowpass_filter->setCutoff(c);
        }
        void setHighpassCutoff(T c) {
            highpass_filter->setCutoff(c);
        }
        void setAllpassCutoff(T c) {
            allpass_filter->setCutoff(c);
        }
        void setNotchCutoff(T c) {
             notch_filter->setCutoff(c);
        }
        void setPeakCutoff(T c) {
            peak_filter->setCutoff(c);
        }
        void BandPassCutoff(T c) {
            bandpass_filter->setCutoff(c);
        }
        void setLowshelfCutoff(T c) {
            lowshelf_filter->setCutoff(c);
        }
        void setHighshelfCutoff(T c) {
            highshelf_filter->setCutoff(c);
        }
        */
        sample_vector<T> lowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass_filter->apply(in,out);            
            return out;
        }
        void dolowpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());
            std::copy(in.begin(),in.end(),out.begin());
            lowpass_filter->apply(in);                        
        }
        
        sample_vector<T> highpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highpass_filter->apply(in,out);
            return out;
        }
        
        sample_vector<T> bandpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            bandpass_filter->apply(in,out);
            return out;        
        }
        sample_vector<T> allpass(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            allpass_filter->apply(in,out);
            return out;
        }
        sample_vector<T> notch(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            notch_filter->apply(in,out);
            return out;
        }
        sample_vector<T> peak(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            peak_filter->apply(in,out);
            return out;        
        }
        sample_vector<T> lowshelf(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            lowshelf_filter->apply(in,out);
            return out;
        }
        sample_vector<T> highshelf(sample_vector<T> in)
        {
            kfr::univector<T> out(in.size());                    
            highshelf_filter->apply(in,out);
            return out;
        }
    };
    /*
    tempalte<typename T>
    struct KfrButterworthFilter
    {

        DSP::ButterworthLowPassFilter<T>  *lowpass;
        DSP::ButterworthHighPassFilter<T> *highpass;
        DSP::ButterworthBandPassFilter<T> *bandpass;
        DSP::ButterworthBandStopFilter<T> *bandstop;

        void setCutoff(float c) {
            lowpass->setCutoff(c);
            highpass->setCutoff(c);
            bandpass->setCutoff(c);
            bandstop->setCutoff(c);
        }

        template<typename T> 
        sample_vector<T> butterworth_lowpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
        {
            kfr::univector<T> out(in.size());        
            DSP::ButterworthLowPassFilter<T> filter(order,cutoff,sample_rate);
            filter.apply(in,out);
            return out;                
        }
        template<typename T> 
        sample_vector<T> butterworth_highpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
        {
            kfr::univector<T> out(in.size());        
            DSP::ButterworthHighPassFilter<T> filter(order,cutoff,sample_rate);
            filter.apply(in,out);
            return out;                
        }
        template<typename T> 
        sample_vector<T> butterworth_bandpass(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
        {
            kfr::univector<T> out(in.size());        
            DSP::ButterworthBandPassFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
            filter.apply(in,out);
            return out;                
        }
        template<typename T> 
        sample_vector<T> butterworth_bandstop(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
        {
            kfr::univector<T> out(in.size());        
            DSP::ButterworthBandStopFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
            filter.apply(in,out);
            return out;                
        }
    }

    template<typename T> 
    sample_vector<T> chebyshev1_lowpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev1LowPassFilter<T> filter(order,cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev1_highpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev1HighPassFilter<T> filter(order,cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev1_bandpass(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev1BandPassFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev1_bandstop(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev1BandStopFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }

    template<typename T> 
    sample_vector<T> chebyshev2_lowpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev2LowPassFilter<T> filter(order,cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev2_highpass(sample_vector<T> in,int order, T cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev2HighPassFilter<T> filter(order,cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev2_bandpass(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev2BandPassFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }
    template<typename T> 
    sample_vector<T> chebyshev2_bandstop(sample_vector<T> in,int order, T lo_cutoff, T hi_cutoff, T sample_rate)
    {
        kfr::univector<T> out(in.size());        
        DSP::Chebyshev2BandStopFilter<T> filter(order,lo_cutoff,hi_cutoff,sample_rate);
        filter.apply(in,out);
        return out;                
    }

    template<typename T>
    sample_vector<T> lowpass_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        return DSP::lowpassfilter(in,freq,q);     
    }
    template<typename T>
    sample_vector<T> lowpass2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        kfr::biquad_params<T> f1 = DSP::lowpass_params(freq,T(0.54119610));
        kfr::biquad_params<T> f2 = DSP::lowpass_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        DSP::BiQuadParams<T> fv;
        fv.bq.push_back(f1);
        fv.bq.push_back(f2);
        filter.init(fv); 
        sample_vector<T> out(in.size());
        filter.apply(in,out);        
        return out;
    }
    template<typename T>
    sample_vector<T> lowpass3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::lowpass_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::lowpass_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::lowpass_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);                
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> lowpass4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::lowpass_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::lowpass_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::lowpass_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::lowpass_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> highpass_filter(sample_vector<T> in, T freq, T q = 0.707)
    {
        return DSP::highpassfilter(in,freq,q);
    }
    template<typename T>
    sample_vector<T> highpass2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highpass_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::highpass_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> highpass3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highpass_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::highpass_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::highpass_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> highpass4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highpass_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::highpass_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::highpass_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::highpass_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> bandpass_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        return DSP::bandpassfilter(in,freq,q);        
    }
    template<typename T>
    sample_vector<T> bandpass2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::bandpass_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::bandpass_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> bandpass3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::bandpass_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::bandpass_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::bandpass_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> bandpass4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::bandpass_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::bandpass_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::bandpass_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::bandpass_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }

    template<typename T>
    sample_vector<T> notch1_filter(sample_vector<T> in, T freq, T q = 0.707)
    {
        return DSP::notchfilter(in,freq,q);        
    }
    template<typename T>
    sample_vector<T> notch2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::notch_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::notch_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> notch3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::notch_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::notch_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::notch_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> notch4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::notch_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::notch_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::notch_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::notch_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    
    template<typename T>
    sample_vector<T> allpass1_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        return DSP::allpassfilter(in,freq,q);
    }
    template<typename T>
    sample_vector<T> allpass2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::allpass_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::allpass_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> allpass3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::allpass_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::allpass_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::allpass_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> allpass4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::allpass_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::allpass_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::allpass_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::allpass_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }

    template<typename T>
    sample_vector<T> peak1_filter(sample_vector<T> in, T freq, T q = 0.707, T gain=1)
    {
        return DSP::peakfilter(in,freq,q,gain);
    }
    template<typename T>
    sample_vector<T> peak2_filter(sample_vector<T> in, T freq, T q = 0.707, T gain=1)
    {        
        DSP::BiQuadParams<T> f1 = DSP::peak_params(freq,T(0.54119610),gain);
        DSP::BiQuadParams<T> f2 = DSP::peak_params(freq,T(1.3065460),gain);
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> peak3_filter(sample_vector<T> in, T freq, T q = 0.707, T gain=1)
    {        
        DSP::BiQuadParams<T> f1 = DSP::allpass_params(freq,T(0.51763809),gain);
        DSP::BiQuadParams<T> f2 = DSP::allpass_params(freq,T(0.70710678),gain);
        DSP::BiQuadParams<T> f3 = DSP::allpass_params(freq,T(1.9318517),gain);
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> peak4_filter(sample_vector<T> in, T freq, T q = 0.707, T gain=1)
    {        
        DSP::BiQuadParams<T> f1 = DSP::peak_params(freq,T(0.50979558),gain);
        DSP::BiQuadParams<T> f2 = DSP::peak_params(freq,T(0.60134489),gain);
        DSP::BiQuadParams<T> f3 = DSP::peak_params(freq,T(0.89997622),gain);
        DSP::BiQuadParams<T> f4 = DSP::peak_params(freq,T(2.5629154),gain);
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> lowshelf1_filter(sample_vector<T> in, T freq, T q = 0.707)
    {
        return DSP::lowshelffilter(in,freq,q);        
    }
    template<typename T>
    sample_vector<T> lowshelf2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::lowshelf_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::lowshelf_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> lowshelf3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::lowshelf_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::lowshelf_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::lowshelf_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> lowshelf4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::lowshelf_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::lowshelf_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::lowshelf_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::lowshelf_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }

template<typename T>
    sample_vector<T> highshelf1_filter(sample_vector<T> in, T freq, T q = 0.707)
    {
        return DSP::highshelffilter(in,freq,q);
    }
    template<typename T>
    sample_vector<T> highshelf2_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highshelf_params(freq,T(0.54119610));
        DSP::BiQuadParams<T> f2 = DSP::highshelf_params(freq,T(1.3065460));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;    
    }    
    template<typename T>
    sample_vector<T> highshelf3_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highshelf_params(freq,T(0.51763809));
        DSP::BiQuadParams<T> f2 = DSP::highshelf_params(freq,T(0.70710678));
        DSP::BiQuadParams<T> f3 = DSP::highshelf_params(freq,T(1.9318517));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    template<typename T>
    sample_vector<T> highshelf4_filter(sample_vector<T> in, T freq, T q = 0.707)
    {        
        DSP::BiQuadParams<T> f1 = DSP::highshelf_params(freq,T(0.50979558));
        DSP::BiQuadParams<T> f2 = DSP::highshelf_params(freq,T(0.60134489));
        DSP::BiQuadParams<T> f3 = DSP::highshelf_params(freq,T(0.89997622));
        DSP::BiQuadParams<T> f4 = DSP::highshelf_params(freq,T(2.5629154));
        DSP::Biquad<T> filter;
        sample_vector<DSP::BiQuadParams<T>> fv = {f1,f2,f3,f4};
        filter.init(fv);
        kfr::univector<T> output(in.size());
        filter.apply(in,output);        
        return output;
    }
    */

    enum class QualityType : int
    {
        draft   = 4,
        low     = 6,
        normal  = 8,
        high    = 10,
        perfect = 12,
    };
    template<typename T> 
    sample_vector<T> resample(QualityType quality,sample_vector<T> input, T input_rate, T output_rate)
    {        
        sample_vector<T> output;
        return DSP::resample(input,(kfr::sample_rate_conversion_quality)quality,output_rate,input_rate);        
    }
    
   
    enum WindowType 
    {
        rectangular     = 1,
        triangular      = 2,
        bartlett        = 3,
        cosine          = 4,
        hann            = 5,
        bartlett_hann   = 6,
        hamming         = 7,
        bohman          = 8,
        blackman        = 9,
        blackman_harris = 10,
        kaiser          = 11,
        flattop         = 12,
        gaussian        = 13,
        lanczos         = 14,
    };
 
    template<typename T>
    kfr::expression_pointer<T> make_window(WindowType type, size_t s, const T x = -1)
    {
        switch(type)
        {
        case hann: return DSP::make_window_hann_ptr<T>(s);
        case hamming: return DSP::make_window_hamming_ptr<T>(s);
        case blackman: return DSP::make_window_blackman_ptr<T>(s);
        case blackman_harris: return DSP::make_window_blackman_ptr<T>(s);
        case gaussian: return DSP::make_window_gaussian_ptr<T>(s);
        case triangular: return DSP::make_window_triangular_ptr<T>(s);
        case bartlett: return DSP::make_window_bartlett_ptr<T>(s);
        case cosine: return DSP::make_window_cosine_ptr<T>(s);
        case bartlett_hann: return DSP::make_window_bartlett_hann_ptr<T>(s);
        case bohman: return DSP::make_window_bohman_ptr<T>(s);
        case lanczos: return DSP::make_window_lanczos_ptr<T>(s);
        case flattop: return DSP::make_window_flattop_ptr<T>(s);
        case rectangular: return DSP::make_window_rectangular_ptr<T>(s);
        case kaiser: return DSP::make_window_kaiser_ptr<T>(s);
        }
    }
    template<typename T>
    sample_vector<T> window(WindowType type,size_t s, const T x = -1) {
        return sample_vector<T>(make_window<T>(type,s));
    }

    template<typename T>
    sample_vector<T> fir_lowpass(sample_vector<T> in, size_t num_taps, WindowType type, bool normalize = true)
    {
        kfr::expression_pointer<T> window = make_window<T>(type,num_taps);        
        return DSP::fir_lowpass(in,num_taps,window,normalize);        
    }
    template<typename T>
    sample_vector<T> fir_highpass(sample_vector<T> in, size_t num_taps, WindowType type, bool normalize = true)
    {
        kfr::expression_pointer<T> window = make_window<T>(type,num_taps);        
        return DSP::fir_highpass(in,num_taps,window,normalize);        
    }
    template<typename T>
    sample_vector<T> fir_bandpass(sample_vector<T> in, size_t num_taps, WindowType type, bool normalize = true)
    {
        kfr::expression_pointer<T> window = make_window<T>(type,num_taps);
        return DSP::fir_bandpass(in,num_taps,window,normalize);        
    }
    template<typename T>
    sample_vector<T> fir_bandstop(sample_vector<T> in, size_t num_taps, WindowType type, bool normalize = true)
    {
        kfr::expression_pointer<T> window = make_window<T>(type,num_taps);
        return DSP::fir_bandstop(in,num_taps,window,normalize);        
    }
    
    template<typename T>
    complex_vector<T> audio_fft_forward(sample_vector<float> in)
    {
        audiofft::AudioFFT fft;
        size_t s = in.size();
        if(s % 2 != 0)
        {
            s = (size_t)std::pow(2,std::log((double)s)+1.0);
        }
        sample_vector<float> temp(s);
        sample_vector<float> real(s);
        sample_vector<float> imag(s);
        zeros(temp);
        zeros(real);
        zeros(imag);
        memcpy(temp.data(),in.data(),in.size()*sizeof(float));
        fft.init(in.size());
        fft.fft(temp.data(),real.data(),imag.data());
        complex_vector<T> out(s);
        for(size_t i = 0; i < s; i++)
        {
            out[i].real(real[i]);
            out[i].imag(imag[i]);
        }
        return out;
    }

    template<typename T>
    sample_vector<float> audio_fft_inverse(complex_vector<float> in)
    {
        audiofft::AudioFFT fft;
        size_t s = in.size();
        if(s % 2 != 0)
        {
            s = (size_t)std::pow(2,std::log((double)s)+1.0);
        }
        sample_vector<float> temp(s);
        sample_vector<float> real(s);
        sample_vector<float> imag(s);
        zeros(temp);
        zeros(real);
        zeros(imag);
        for(size_t i = 0; i < in.size(); i++)
        {
            real[i] = in[i].real();
            imag[i] = in[i].imag();
        }
        fft.init(in.size());
        fft.ifft(temp.data(),real.data(),imag.data());        
        return temp;
    }

    template<typename T>
    sample_vector<float> audio_convolve(sample_vector<float> in, size_t block_size, sample_vector<T> ir)
    {
        sample_vector<float> out(in.size());
        fftconvolver::FFTConvolver conv;
        conv.init(block_size,ir.data(),ir.size());
        conv.process(in.data(),out.data(),in.size());
        return out;
    }
    
    template<typename T>
    // r = frac
    // x = [i]
    // y = [i+1]
    T linear_interpolate(T x, T y, T r)
    {        
        return r +*x (1.0-r)*y;
        
    }
    template<typename T>
    T cubic_interpolate(T finpos, T xm1, T x0, T x1, T x2)
    {
        //T xm1 = x [inpos - 1];
        //T x0  = x [inpos + 0];
        //T x1  = x [inpos + 1];
        //T x2  = x [inpos + 2];
        T a = (3 * (x0-x1) - xm1 + x2) / 2;
        T b = 2*x1 + xm1 - (5*x0 + x2) / 2;
        T c = (x1 - xm1) / 2;
        return (((a * finpos) + b) * finpos + c) * finpos + x0;
    }
    // original
    template<typename T>
    // x = frac
    // y0 = [i-1]
    // y1 = [i]
    // y2 = [i+1]
    // y3 = [i+2]
    T hermite1(T x, T y0, T y1, T y2, T y3)
    {
        // 4-point, 3rd-order Hermite (x-form)
        T c0 = y1;
        T c1 = 0.5f * (y2 - y0);
        T c2 = y0 - 2.5f * y1 + 2.f * y2 - 0.5f * y3;
        T c3 = 1.5f * (y1 - y2) + 0.5f * (y3 - y0);
        return ((c3 * x + c2) * x + c1) * x + c0;
    }

    // james mccartney
    template<typename T>
    // x = frac
    // y0 = [i-1]
    // y1 = [i]
    // y2 = [i+1]
    // y3 = [i+2]
    T hermite2(T x, T y0, T y1, T y2, T y3)
    {
        // 4-point, 3rd-order Hermite (x-form)
        T c0 = y1;
        T c1 = 0.5f * (y2 - y0);
        T c3 = 1.5f * (y1 - y2) + 0.5f * (y3 - y0);
        T c2 = y0 - y1 + c1 - c3;
        return ((c3 * x + c2) * x + c1) * x + c0;
    }

    // james mccartney
    template<typename T>
    // x = frac
    // y0 = [i-1]
    // y1 = [i]
    // y2 = [i+1]
    // y3 = [i+2]
    T hermite3(T x, T y0, T y1, T y2, T y3)
    {
            // 4-point, 3rd-order Hermite (x-form)
            T c0 = y1;
            T c1 = 0.5f * (y2 - y0);
            T y0my1 = y0 - y1;
            T c3 = (y1 - y2) + 0.5f * (y3 - y0my1 - y2);
            T c2 = y0my1 + c1 - c3;

            return ((c3 * x + c2) * x + c1) * x + c0;
    }

    // laurent de soras
    template<typename T>
    // x[i-1]
    // x[i]
    // x[i+1]
    // x[i+2]    
    inline T hermite4(T frac_pos, T xm1, T x0, T x1, T x2)
    {
        const T    c     = (x1 - xm1) * 0.5f;
        const T    v     = x0 - x1;
        const T    w     = c + v;
        const T    a     = w + v + (x2 - x0) * 0.5f;
        const T    b_neg = w + a;

        return ((((a * frac_pos) - b_neg) * frac_pos + c) * frac_pos + x0);
    }

    /// Sndfile   
    /// Resampler
    /// SpeexResampler

    template<typename T>
    sample_vector<T> upsample2x(sample_vector<T> in)
    {
        sample_vector<T> out(in.size()*2);
        zeros(out);
        for(size_t i = 0; i < in.size(); i++)
            out[i*2] = in[i];
        return out;
    }
    template<typename T>
    sample_vector<T> upsample4x(sample_vector<T> in)
    {
        sample_vector<T> out(in.size()*4);
        zeros(out);
        for(size_t i = 0; i < in.size(); i++)
            out[i*4] = in[i];
        return out;
    }
    template<typename T>
    sample_vector<T> downsample2x(sample_vector<T> in)
    {
        sample_vector<T> out(in.size()/2);
        zeros(out);
        for(size_t i = 0; i < in.size()/2; i++)
            out[i] = in[i*2];
        return out;
    }
    template<typename T>
    sample_vector<T> downsample4x(sample_vector<T> in)
    {
        sample_vector<T> out(in.size()/4);
        zeros(out);
        for(size_t i = 0; i < in.size()/4; i++)
            out[i] = in[i*4];
        return out;
    }

    
}
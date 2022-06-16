// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
#include "des_filter.h"
#include "make_filter.h"

spuce::make_filter LPF;
spuce::make_filter* pLPF = &LPF;

void lpf_init(int pts) { pLPF->init(pts); }
void reset() { pLPF->reset(); }
void lpf_sel(const char* sel) { pLPF->sel_filter(sel); }
void band_sel(const char* sel) { pLPF->sel_band(sel); }
void set_center(int len) { pLPF->set_center_freq(len); }
void set_filter_type(int t) { pLPF->set_filter_type(t); }
int  get_filter_type() { return pLPF->get_filter_type(); }
double horiz_swipe(int len, bool in_passband) {  return (pLPF->horiz_swipe(len, in_passband));}
int get_order() { return (pLPF->get_order()); }
bool is_bpf() { return (pLPF->is_bpf()); }
void vertical_swipe(int len, bool in_passband, bool above_stop) {  pLPF->vertical_swipe(len, in_passband, above_stop);}
double update_w(double* w) {  double x = pLPF->update(w);   return (x); }
double get_mag(double w) {	return pLPF->get_mag(w);}

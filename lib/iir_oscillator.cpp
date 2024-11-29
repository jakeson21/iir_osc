
#include <iir_oscillator.h>
#include <cmath>

template <typename T>
IIR_CoupledResonator<T>::IIR_CoupledResonator()
{
    this->sin_prev = 0;
    this->cos_prev = 1;
    this->rsin_theta = 0;
    this->rcos_theta = 0;
    this->SampRateHz = 0;
    this->FreqHz = 0;
    this->dPhase = 0;
}

template <typename T>
IIR_CoupledResonator<T>::IIR_CoupledResonator(T inSampRateHz, T inFreqHz)
: SampRateHz(inSampRateHz),
  FreqHz(inFreqHz),
  sin_prev(0),
  cos_prev(0),
  rsin_theta(0),
  rcos_theta(0),
  dPhase(0)
{
    this->Init(SampRateHz, FreqHz);
}

template <typename T>
void IIR_CoupledResonator<T>::Init(T inSampRateHz, T inFreqHz)
{
    this->SampRateHz = inSampRateHz;
    this->UpdateFreq(inFreqHz);
    this->sin_prev = 0;
    this->cos_prev = 1;
}

template <typename T>
void IIR_CoupledResonator<T>::UpdateFreq(T inFreqHz)
{
    this->FreqHz = inFreqHz;
    this->dPhase = this->FreqHz*2.0*M_PI/this->SampRateHz;
    this->rsin_theta = std::sin(this->dPhase);
    this->rcos_theta = std::cos(this->dPhase);
}

template <typename T>
typename IIR_CoupledResonator<T>::ReturnType IIR_CoupledResonator<T>::Step()
{
    IIR_CoupledResonator<T>::ReturnType ret;
    ret.y = this->sin_prev;
    ret.x = this->cos_prev;
    T xs, xc;
    xs = this->cos_prev*this->rsin_theta + this->sin_prev*this->rcos_theta;
    xc = this->cos_prev*this->rcos_theta - this->sin_prev*this->rsin_theta;
    this->sin_prev = xs;
    this->cos_prev = xc;
    return ret;
}

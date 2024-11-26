
#include <iir_oscillator.h>
#include <cmath>

IIR_CoupledResonator::IIR_CoupledResonator()
{
    this->sin_prev = 0;
    this->cos_prev = 1;
    this->rsin_theta = 0;
    this->rcos_theta = 0;
    this->SampRateHz = 0;
    this->FreqHz = 0;
    this->dPhase = 0;
}

IIR_CoupledResonator::IIR_CoupledResonator(double inSampRateHz, double inFreqHz)
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

void IIR_CoupledResonator::Init(double inSampRateHz, double inFreqHz)
{
    this->SampRateHz = inSampRateHz;
    this->UpdateFreq(inFreqHz);
    this->sin_prev = 0;
    this->cos_prev = 1;
}

void IIR_CoupledResonator::UpdateFreq(double inFreqHz)
{
    this->FreqHz = inFreqHz;
    this->dPhase = this->FreqHz*2.0*M_PI/this->SampRateHz;
    this->rsin_theta = std::sin(this->dPhase);
    this->rcos_theta = std::cos(this->dPhase);
}

void IIR_CoupledResonator::step(double& sinOut, double& cosOut)
{
    sinOut = this->sin_prev;
    cosOut = this->cos_prev;
    double xs, xc;
    xs = this->cos_prev*this->rsin_theta + this->sin_prev*this->rcos_theta;
    xc = this->cos_prev*this->rcos_theta - this->sin_prev*this->rsin_theta;
    this->sin_prev = xs;
    this->cos_prev = xc;
}

// IIR Resonator Parameters

class IIR_CoupledResonator {

public:

    IIR_CoupledResonator();
    IIR_CoupledResonator(double inSampRateHz, double inFreqHz);

    void Init(double inSampRateHz, double inFreqHz);
    void UpdateFreq(double inFreqHz);
    void step(double& sinOut, double& cosOut);

protected:

    double sin_prev;
    double cos_prev;
    double rsin_theta;
    double rcos_theta;
    double SampRateHz;
    double FreqHz;
    double dPhase;
};
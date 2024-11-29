// IIR Resonator Parameters

template <typename T>
class IIR_CoupledResonator {
public:

    IIR_CoupledResonator();
    IIR_CoupledResonator(T inSampRateHz, T inFreqHz);

    void Init(T inSampRateHz, T inFreqHz);
    void UpdateFreq(T inFreqHz);

    struct ReturnType {
        T x;
        T y;
    };

    ReturnType Step();

protected:

    T sin_prev;
    T cos_prev;
    T rsin_theta;
    T rcos_theta;
    T SampRateHz;
    T FreqHz;
    T dPhase;
};

template class IIR_CoupledResonator<double>;
template class IIR_CoupledResonator<float>;

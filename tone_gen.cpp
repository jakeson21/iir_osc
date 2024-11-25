#include <string>
#include <iostream>

#include <iir_oscillator.h>
#include <thread>

IIR_CoupledResonator Osc;

int main()
{
    double xs, xc;

    double Freq_Hz = 48;

    double Fs_Hz = 48000;

    Osc.Init(Fs_Hz, Freq_Hz);

    size_t N = 48000;

    for (size_t n=0; n<N; n++)
    {
        Osc.step(xs, xc);

        std::cout << xc << " " << xs << std::endl;

        if ((n+1)%1000 == 0)
        {
            Freq_Hz *= 1.1;

            Osc.UpdateFreq(Freq_Hz);
            
        }
    }

    return 0;
}

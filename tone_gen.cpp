#include <string>
#include <iostream>

#include <iir_oscillator.h>
#include <thread>

IIR_CoupledResonator Osc;

int main()
{
    double xs, xc;

    Osc.Init(48000, 48);

    for (size_t n=0; n<1000; n++)
    {

        Osc.step(xs, xc);

        std::cout << xs << " " << xc << std::endl;
    }

    return 0;
}

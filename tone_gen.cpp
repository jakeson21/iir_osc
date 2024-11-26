#include <string>
#include <iostream>
#include <thread>

#include <stdio.h>
#include <unistd.h>

#include <lib/iir_oscillator.h>

IIR_CoupledResonator Osc;

int main(int argc, char *argv[])
{
    double Freq_Hz = 48;
    double Fs_Hz = 48000;
    size_t N = 48000;

    int opt;

    // put ':' in the starting of the 
    // string so that program can  
    //distinguish between '?' and ':'  
    while((opt = getopt(argc, argv, ":r:f:n:")) != -1)
    {
        switch(opt)
        {
            case 'r': // sample rate
                // printf("Samplerate: %s\n", optarg);
                Fs_Hz = atof(optarg);
                break;
            case 'f': // frequency
                // printf("Frequency: %s\n", optarg);
                Freq_Hz = atof(optarg);
                break;
            case 'n': // sample count
                // printf("Sample Count: %s\n", optarg);
                N = atof(optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
            default:
                fprintf(stderr, "Usage: %s [-r samp_rate] [-f freq] [-n num_samps]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // optind is for the extra arguments
    // which are not parsed
    for(; optind < argc; optind++){ 
        printf("extra arguments: %s\n", argv[optind]);
    }

    double xs, xc;

    Osc.Init(Fs_Hz, Freq_Hz);


    for (size_t n=0; n<N; n++)
    {
        Osc.step(xs, xc);

        std::cout << xc << " " << xs << std::endl;

        if ((n+1)%1000 == 0)
        {
            Freq_Hz += 1;

            Osc.UpdateFreq(Freq_Hz);
        }
    }

    return 0;
}

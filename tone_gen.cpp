#include <string>
#include <iostream>
#include <thread>
#include <iostream>
#include <fstream>

#include <stdio.h>
#include <unistd.h>
#include <math.h>       /* fmod */

#include <lib/iir_oscillator.h>

IIR_CoupledResonator<float> Osc;

int main(int argc, char *argv[])
{
    double Freq_Hz = 48; // frequency
    double Fs_Hz = 48000; // samples rate
    int64_t N = 48000; // num samps to generate
    int64_t NSave = 0; // Num samples to save

    int opt;

    // put ':' in the starting of the 
    // string so that program can  
    //distinguish between '?' and ':'  
    while((opt = getopt(argc, argv, ":r:f:n:N:")) != -1)
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
            case 'N':
                NSave = atof(optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
            default:
                fprintf(stderr, "Usage: %s [-r samp_rate] [-f freq] [-n num_samps] [-N num_to_save]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (NSave==0) NSave = N;
    if (NSave > N) NSave = N;

    // optind is for the extra arguments
    // which are not parsed
    for(; optind < argc; optind++){ 
        printf("extra arguments: %s\n", argv[optind]);
    }

    Osc.Init(Fs_Hz, Freq_Hz);

    std::string fname("output.dat");

    std::ofstream wf(fname, std::ios::out | std::ios::binary);
    if (!wf) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }

    size_t dtype = 0;

    for (; N>0; --N)
    {
        auto ret = Osc.Step();

        if (N<=NSave)
        {
            wf.write((char * ) &ret, sizeof(ret));
        }

        if ((N+1)%2400 == 0)
        {
            Freq_Hz += 2;

            Freq_Hz = fmod(Freq_Hz, Fs_Hz/4);

            Osc.UpdateFreq(Freq_Hz);
        }

        if (N==1) dtype = sizeof(ret.x);
    }

    wf.close();

    std::cout << fname << "\t" << dtype << "\t" << Freq_Hz << "\t" << NSave << std::endl;

    return 0;
}

#include <iostream>
#include <pcap.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    cout << endl;
    if (argc != 2){
        cout << "*****Attention error! Missing parameter [LOCATION].*****" << endl << endl;
        cout << "For help, call the function [-help] (program.exe -help) or restart the program." << endl;
        return 0;
    }

    string file = argv[1];

    if (file == "-help"){
        cout << "The program is designed to read the pcap file and output package data from it." << endl
             << "Using: programma.exe [parameter]" << endl
             << "Parameter: C:\\Users\\pc\\Desktop\\example.pcap" << endl;
        return 0;
    }


    char errbuff[PCAP_ERRBUF_SIZE];

    pcap_t * pcap = pcap_open_offline(file.c_str(), errbuff);

    if (pcap == NULL){
        cout << "*****MISSING LOCATION*****" << endl;
        cout << "Unable to access the file. Verify that the file path is correct." << endl;
        return 0;
    }

    struct pcap_pkthdr *header;

    const u_char *data;

    int packetCount = 0;
    ofstream out;
    out.open("file.txt", ios::out);
    if (out.is_open()){
        while (int returnValue = pcap_next_ex(pcap, &header, &data) >= 0)
        {
            cout << "Packet #" << ++packetCount << endl;
            out << "Packet #" << packetCount << endl;
            cout << "Packet size: " << header->len << endl;
            out << "Packet size: " << header->len << endl;
            if (header->len != header->caplen){
                cout <<"Warning! Capture size different than packet size: " << header->len << endl;
            }
            if (header->len != header->caplen){
                out <<"Warning! Capture size different than packet size: " << header->len << endl;
            }
            cout << "Time: " << ctime(&header->ts.tv_sec) << endl ;
            out << "Time: " << ctime(&header->ts.tv_sec)  << endl ;
            out << endl << endl;
            cout << endl << endl;
        }
    }
    else {
        cout << "*****Error opening text file for reading result*****";
    }
    cout << "*****Program completed successfully*****" << endl;
    cout << "Data written to file: " << argv [1] << "\\file.txt" << endl;
    out.close();
    return 0;
}


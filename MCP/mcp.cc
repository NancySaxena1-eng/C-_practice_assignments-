

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::ios;
static void show_usage(int argc,char* argv[])
{
	std::cerr << "Usage: " << argv[0] << " <option(s)> SOURCES"
        << "Options:\n"
        << "\t-s,\t\for source file, there can be only one source file and file must exists\n"
        << "\t-t, \t\for target file, make sure the files do not exists\n"
        << std::endl;

}

static void file_error(std::string filename){

    std::cerr << "Error, opening  the file " 
        << filename 
        << std::endl; 

}

int main(int argc, char* argv[]){

    if ((argc % 2 == 0)) {
        show_usage(argc, argv);
        exit(1);
    }

    std::vector <std::string> target;
    std::vector <std::string> sources;
    int count = 0;
    int count1 = 0;
    int index = 1;
    bool seenTorS = false;
    while (index < (argc - 1)) {
        std::string arg = argv[index];
        if (arg == "-s"){
            sources.push_back(argv[index + 1]);
            seenTorS = true;
            count++;		
        }
        else if(arg == "-t"){
            target.push_back(argv[index + 1]);
            seenTorS = true;
        }
        else {
            if (!seenTorS) {
                show_usage(argc, argv);
                exit(1);
            } else {
                seenTorS = false;
            }
        }
        index++;
    }

    if (!(target.size() >= 1)){
        show_usage(argc, argv);
        exit(1);

    }
    if (!(sources.size() == 1)){
        show_usage(argc, argv);
        exit(1);

    }


    for (int i =0 ; i < target.size() ; i++){
        std::ifstream ifile(target.at(i));


        if(ifile){
            std::cerr << "Error, filename already exists:filename-> " << target.at(i)     
                << std::endl;           
            show_usage(argc, argv);             
            exit(1);

        }
        for (int j= i + 1; j <target.size();j++){
            std::ifstream ifile(target.at(i));
            if(ifile){
std::cerr << "Error, filename already exists:filename-> " << target.at(i);
              exit(1) ;
            }

            if (target.at(i) == target.at(j)){

                std::cerr << "Error, filename duplicated " << target.at(i) << std::endl; 
                show_usage(argc, argv);
                exit(1);
            }




        }

    }
    ifstream infile;
    infile.open(sources.at(0), ios::binary | ios::in);
    if (infile.fail()){

        file_error(sources.at(0));
        show_usage(argc, argv);
        exit(1);

    }
    ofstream outfile;
    int i = 0;
    while(i < target.size()) {
        ofstream outfile;
        outfile.open(target.at(i), ios::binary | ios::out);
        if (outfile.fail()){

            std::cerr << "Error in opening the target file" << std::endl;
            exit(1);

        } else {
            string line;
            if(infile && outfile){

                while(getline(infile,line)){
                    outfile << line << "\n";
                }

            } else{

                std::cerr << "Error: files could not be copied " <<std::endl;
            }

        }
        infile.clear();
        infile.seekg(ios::beg);
        outfile.close();
        i++;
    }
    infile.close();
    return 0;

}

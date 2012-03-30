#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "IniParser.hpp"

int main(int argc, char * argv[])
{
    char ini_name[1000];
    if (argc<2) {
        sprintf(ini_name,"twisted.ini");
    } else {
        sprintf(ini_name,"%s",argv[1]);
    }

    IniParser ini(ini_name);
    ini.dump(stdout);

    return 0 ;
}

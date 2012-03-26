#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "IniParser.hpp"

int main(int argc, char * argv[])
{
    char *ini_name;
    if (argc<2) {
        ini_name = "twisted.ini";
    } else {
        ini_name = argv[1] ;
    }

    IniParser ini(ini_name);
    iniparser_dump(ini.dic, stdout);

    return 0 ;
}

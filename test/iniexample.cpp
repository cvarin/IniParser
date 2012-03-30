#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "IniParser.hpp"

void create_example_ini_file(void);
int  parse_ini_file(const char * ini_name);

int main(int argc, char * argv[])
{
    int     status ;

    if (argc<2) {
        create_example_ini_file();
        status = parse_ini_file("example.ini");
    } else {
        status = parse_ini_file(argv[1]);
    }
    return status ;
}

void create_example_ini_file(void)
{
    FILE    *   ini ;

    ini = fopen("example.ini", "w");
    fprintf(ini,
    "#\n"
    "# This is an example of ini file\n"
    "#\n"
    "\n"
    "[Pizza]\n"
    "\n"
    "Ham       = yes ;\n"
    "Mushrooms = TRUE ;\n"
    "Capres    = 0 ;\n"
    "Cheese    = Non ;\n"
    "\n"
    "\n"
    "[Wine]\n"
    "\n"
    "Grape     = Cabernet Sauvignon ;\n"
    "Year      = 1989 ;\n"
    "Country   = Spain ;\n"
    "Alcohol   = 12.5  ;\n"
    "\n");
    fclose(ini);
}


int parse_ini_file(const char * ini_name)
{
    /* Some temporary variables to hold query results */
    int             b ;
    int             i ;
    double          d ;
    char        *   s ;

    IniParser ini(ini_name);
    ini.dump(stderr);

    /* Get pizza attributes */
    printf("Pizza:\n");

    b = ini.getboolean("pizza:ham", -1);
    printf("Ham:       [%d]\n", b);
    b = ini.getboolean("pizza:mushrooms", -1);
    printf("Mushrooms: [%d]\n", b);
    b = ini.getboolean("pizza:capres", -1);
    printf("Capres:    [%d]\n", b);
    b = ini.getboolean("pizza:cheese", -1);
    printf("Cheese:    [%d]\n", b);

    /* Get wine attributes */
    printf("Wine:\n");
    s = ini.getstring("wine:grape", NULL);
    printf("Grape:     [%s]\n", s ? s : "UNDEF");
    
    i = ini.getint("wine:year", -1);
    printf("Year:      [%d]\n", i);

    s = ini.getstring("wine:country", NULL);
    printf("Country:   [%s]\n", s ? s : "UNDEF");
    
    d = ini.getdouble("wine:alcohol", -1.0);
    printf("Alcohol:   [%g]\n", d);

    return 0 ;
}



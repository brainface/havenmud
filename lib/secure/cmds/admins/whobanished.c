//      /bin/adm/_whobanished.c
//      from the Dead Souls Mudlib
//      lists all names banished from usage
//      originally written by Shadowwolf@Dead Souls 
//      rewritten for the new Dead Souls security system by Descartes of Borg
//      930809

#include <lib.h>
#include <daemons.h>

int cmd(string str) {
    string *noms;

    if(!archp(previous_object())) return 0;
    noms = (string *)BANISH_D->GetBanishedNames();
    noms = sort_array(noms, 1);
    this_player()->eventPrint("These names are currently banished:");
    this_player()->more(explode(format_page(noms, 4), "\n"));
    return 1;
}

string GetHelp(string help) {
    write("Syntax: <whobanished>\n\n"
      "Without an argument, this command lists all names currently\n"
      "listed as being banished.\n"
    );
}

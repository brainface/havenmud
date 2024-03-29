//      /bin/adm/_whoallowed.c
//      from the Dead Souls Mudlib
//      shows who can get in from registered sites
//      created by Shadowwolf@Dead Souls 93????
//      rewritten for the new security system by Descartes of Borg 930812

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {
    string *noms;

    if(!sizeof(noms = (string *)BANISH_D->GetGuests())) {
      write("No one is currently allowed to login from a restricted site.\n");
      return 1;
    }
    write("These names may be used by people from restricted sites:\n");
    write(format_page(noms, 5)+"\n");
    return 1;
}
void help() {
    write("Syntax: <whoallowed ([name])>\n\n"
      "Lists the names of players who may be allowed into the game\n"
      "from sites which must register characters in order to play.\n"
    );
}

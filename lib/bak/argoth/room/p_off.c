#include <lib.h>
#include "../argoth.h"
inherit LIB_POST_OFFICE;
static void create() {
    post_office::create();
SetClimate("indoors");
SetAmbientLight(50);
    SetTown("Karak");
    SetShort("Argoth's Post Office");
  SetDomain("Crystal Reaches");
    SetLong("Argoth's Post Office is a large building where citizens come "
    "to read and send mail by typing <mail> and following the instructions.");
    SetObviousExits("out");
    SetExits( ([
    "out" : ARGOTH_ROOM + "rd3.c",
]) );
    SetSmell( ([
    "default" : "There is a faint smell of paper and ink.",
]) );
}

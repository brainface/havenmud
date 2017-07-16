//Selket@Haven
//2006
#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("in front of a small hut");
  SetLong(
    "In this out of the way corner of the city stands a small "
    "hut made of enormous granite blocks. The old foundations sink "
    "into the mud near the filthy streets, giving the the hut "
    "a misshapen, lopsided appearance. The windows facing the "
    "street are kept scrubbed clean but any view inside is obscured "
    "by thick curtains, as if what is within should stay hidden "
    "from the public eye. "
    );
  SetSmell("The entire village smells of offal. ");
  SetListen("The raucous sounds of the village are unending.");
  SetItems( ([
    ({ "hut" }) :
       (: GetLong :),
    ({ "blocks", "granite", "foundations" }) :
    "The hut is old and made of heavy stones.",
    ({ "mud", "street", "streets" }) : "The streets are very muddy.",
    ({ "windows", "curtains" }) : "One cannot see inside.",
    ]) );
  SetItemAdjectives( ([
    "hut" : ({ "small" }),
    "foundations" : ({ "old" }),
    "streets" : ({ "filthy" }),
    "blocks" : ({ "enormous" }),
    ]) );
  SetEnters( ([
   "hut" : U_ROOM + "hut",
    ]) );
  SetExits( ([
    "west" : U_ROOM + "road05",
    "south" : U_ROOM + "road07",
    ]) );
  }

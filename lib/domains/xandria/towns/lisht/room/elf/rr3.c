#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

int GateExit();

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "south" : LISHT_ROOM "elf/ra1",
    "east"  : LISHT_ROOM "elf/rr2",
    ]) );
  AddExit("west", LISHT_ROOM "gnoll/gate", (: GateExit :) );
  SetShort("in front of the Wall of Lisht");
  SetLong(
    "The Wall of Lisht seperates the slaves from the actual citizens of Lisht. Its thick "
    "stone walls could easily withstand any form of siege engine. One point of access is "
    "a thick iron gate that can easily be dropped to prevent access. Farther to the east "
    "lie the floodplains of Lisht, the heart of the Dynasty's food production. The River "
    "Road leads off to the south from here."
    );
  SetSmell("The smell of the floodplains is faint here.");
  SetItems( ([
    "wall" : "The Wall of Lisht is a massive stone affair.",
    "gate" : "The gate is a large iron beast that could be used to prevent access to the "
             "city.",
    ]) );
}

string GetLong() {
  string LLL = ::GetLong();
  if (query_night()) {
    LLL += " The large iron gate is closed at night.";
  }
  else LLL += " The large iron gate stands open during the daylight.";
  return LLL;
}

int GateExit() {
  object who = this_player();
  if (!query_night()) { return 1; }
  send_messages( ({ "bump" }),
    "$agent_name $agent_verb into the stout iron gates while trying to go west.",
    who, 0, this_object());
  return 0;
}

#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

int GateExit();

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : LISHT_ROOM "gnoll/pr1",
    "south" : LISHT_ROOM "gnoll/wr1",
    ]) );
  AddExit("east", LISHT_ROOM "elf/rr3", (: GateExit :) );
  SetShort("at the Wall of Lisht");
  SetLong(
    "The Wall of Lisht protects the citizens of Lisht from the slaves and any other "
    "harm. The huge stone wall rises high into the sky and it is thick enough to stop "
    "nearly any form of siege engine. To the west, the Pharaoh's Road leads to the "
    "palace. To the south leads a wide passage known as the Wall Road, which leads to "
    "the barracks of the Dynasty's military might."
    );
  SetItems( ([
    "gate" : "The massive gate is wrought of impenetrable iron.",
  ]) );
  SetSmell("The city has a pleasant aroma.");
  SetInventory( ([
    LISHT_OBJ "cippus" : 1,
    LISHT_NPC "guard" :2,
  ]) );
}

int GateExit() {
  object who = this_player();
  if (!query_night()) { return 1; }
  send_messages( ({ "bump" }),
    "$agent_name $agent_verb into the stout iron gates while trying to go west.",
    who, 0, this_object());
  return 0;
}

string GetLong() {
  string LLL = ::GetLong();
  if (query_night()) {
    LLL += " The large iron gate is closed at night.";
  }
  else LLL += " The large iron gate stands open during the daylight.";
  return LLL;
}

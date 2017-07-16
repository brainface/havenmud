#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;
int PreExit(string dir);
 
static void create() {
  room::create();
  SetTown("Grymxoria");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("the Church of Saahagoth");
  SetLong(
    "A large antechamber in the mother church of Saahagoth. "
    "The room is long and narrow leading from a large curving "
    "stair case down, to a equally large staircase that leads up "
    "to the basilica. A small door leads off to each side."
  );
  SetItems( ([
    ({ "stairs", "stair cases", "down stairs", "up stairs" }) :
    "A large curved staircase leading off from this antechamber"
  ]) );
  SetInventory(  ([
    G_NPC + "vyper" : 1,
    G_NPC + "mitra" : 1,
  ])  );
  SetExits( ([ 
    "up" : G_ROOM + "church1d",
    "down" : G_ROOM + "church2b"
  ]) );
  AddExit("east", G_ROOM "church3c", (: PreExit :) );
  AddExit("west", G_ROOM "church1c", (: PreExit :) );
}

int PreExit(string dir) {
   if ( (this_player()->ClassMember("cleric")) &&
	  (this_player()->GetReligion(1) == "Saahagoth") ||
          (creatorp(this_player())) )  return 1;
   else {
      write("You don't feel pure enough to go that way.");
      return 0;
    }
}

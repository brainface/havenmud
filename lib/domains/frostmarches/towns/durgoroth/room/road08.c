#include <lib.h>
#include <domains.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

int PreExit();
static void create() {
  ::create();
  SetClimate("sub-arctic"); 
  SetShort("the entrance to the killing pit");
  SetLong("A large partially circular clearing has"
          " been created here. Blood and gore lie"
          " everywhere mixing with the earth to"
          " create a verifiable bone yard of chaos"
          " and slaughter. The rubble that rings the"
          " pit has been splattered with blood and"
          " entrails heightening the already"
          " horrific scenery. To the west a building"
          " can be seen. To the east, the pit opens"
          " up into a vast field of death.");
  SetItems( ([
          ({ "clearing", "rubble", "bone yard", "pit" }) :
             (: GetLong :),
          ({ "gore", "blood", "entrails", "limbs", "bones" }) :
             "Everywhere blood, gore, bones, and entrails"
             " corrupt the area.",
          ({ "building", "ruins" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. They appear"
             " to have been blasted apart from the insides"
             " scattering masonry wood and metal all around."
             " To the west a fairly intact building is visible.",
           ]) );
  SetSmell( ([ 
          "default" : "The stench of one thousand rotting"
                      " corpses fills the air.", 
          ]) );
  SetListen( ([ 
          "default" : "Shouts and jeers can be heard.", 
          ]) );
  SetExits( ([
          "west" : DURG_ROOM "road07",
          ]) );
  SetInventory( ([
          DURG_NPC "foodseller"    : 1,
          DURG_NPC "toughcitizen"  : 1,
          DURG_NPC "toughcitizen2" : 1,
          DURG_NPC "fighter"       : 1,
          ]) );
  AddExit("east", FROSTMARCHES_VIRTUAL + "durg_pit/0,0", (: PreExit :));
}

int PreExit() {
  if (this_player()->id("durg_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

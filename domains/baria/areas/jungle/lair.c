/*  The dragon's lair */
#include <lib.h>
#include <domains.h>
#define OUT  "/domains/baria/virtual/jungle/-8,6"
inherit LIB_ROOM;
int DragonBait(string dir);

static void create() {
  room::create();
  SetShort("a hidden lair");
  SetClimate("underground");
  SetProperty("login", "/domains/baria/virtual/jungle/-8,6");
  SetProperty("no teleport", 1);
  SetLong("This lair is a large and imposing affair. The ground "
          "is littered with corpses of all race and profession, "
          "leading the casual observer to believe that this is "
          "a place meaning death in no uncertain terms.");
  SetItems( ([
      ({ "corpse", "corpses" }) : "There are all badly decomposed "
                                  "adventurers.",
    ]) );
  SetExits( ([
    "out" : OUT,
     ]) );
  AddExit("south", BARIA_VIRTUAL + "tunnel/2,15", (: DragonBait :) );
  AddExit("down", "off_lair", (: DragonBait :) );
  SetDoor("south", "/domains/baria/towns/baria/obj/tunnel_door_2");
  SetInventory( ([
                  BARIA_AREAS + "jungle/black_dragon" : 1,
    ]) );
  SetSmell("default", "The room smells of rotten flesh.");
  }

int DragonBait(string dir) {
  if (present("dragon", this_object())) {
    send_messages( ({ "eye", "prevent" }),
      "$agent_name $agent_verb $target_name evilly and "
      "$agent_verb $target_objective from going that way.",
      present("dragon", this_object()), this_player(), this_object() );
    return 0;
    }
  return 1;
 }

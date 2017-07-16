#include <lib.h>
inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("Mud Upkeep");
   SetLong("This room is for the Mud Upkeep board.");
   SetExits( ([
              "north" : "player_idea",
              "northwest" : "spells",
              "west" : "/domains/heaven/room/spell_idea",
          ]) );
   SetInventory( ([
                  "/realms/amelia/room/mudupkeepnotesboard" : 1,
              ]) );
}

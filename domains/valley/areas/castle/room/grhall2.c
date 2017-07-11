#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(40);
   SetShort("Great Hall");
   SetLong("Beams of wood help support the structure, so that rocks alone "
           "might not be responsible for the safety of those "
           "under this roof.  The stonework of the walls was simple, "
           "with fairly uniform blocks stacked high and pasted together "
           "with a grayish mortar.  Animal skins from various conquests "
           "of the castle's Lord have been spread out on the wall, "
           "and paintings of his relatives, and likely himself, have "
           "also been posted on the stones.  To the east, the room "
           "continues in all its grandness.  Torches light the room from "
           "positions on the walls.");
   SetItems( ([
                ({ "great hall","hall","castle","structure" }) : 
                   (: GetLong :),
                ({ "stone walls","stonework","stone","stones",
                   "stone wall","wall","walls","uniform blocks",
                   "fairly uniform blocks","grayish mortar",
                   "beams of wood","roof","animal skins","paintings",
                   "fairly uniform block","uniform block","block",
                   "blocks","rock","rocks","wooden beams","beams",
                   "wood","beam","wooden beam","beam of wood",
                   "animal skin","skin","skins","painting","mortar",
                   "torches","torch" }) :
                   "The walls are made of stones, fit together with a "
                   "mortar of grayish color, with wooden beams aiding in "
                   "the support of the roof.  Animal skins and paintings "
                   "cover the walls decoratively.  Torches are placed "
                   "at similar intervals along the wall, lighting the "
                   "Great Hall.",
           ]) );
   SetExits( ([
                "east" : VC_ROOM + "/grhall1",
           ]) );
   SetInventory( ([
                    VC_NPC + "/guest" : random(4)+2,
                    VC_NPC + "/lord" : 1,
                    VC_NPC + "/musician" : 1+random(2),
                    VC_NPC + "/guard_l" : 3,
               ]) );
}

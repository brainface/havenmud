#include <lib.h>
#include <domains.h>
#include <std.h>
#include "../durgoroth.h"
inherit LIB_ROOM;

int PreEnter();
static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetShort("the boneyard of Durgoroth");
  SetLong("The rotting remains of hundreds of daemons"
          " have been strewn all about. An altar of"
          " bone has been set up in the center of"
          " the boneyard. All around a wall of rubble"
          " has been precariously constructed in order"
          " to contain the dead and dying within the"
          " confines of the boneyard. The only exit"
          " is to the north.");
  SetItems( ([
          ({ "altar", "bone altar" }) :
             "The altar has been constructed of bone"
             " and shows signs of recent use. Fresh"
             " blood stains and a few rotting pieces"
             " of muscle tissue remain. There appears"
             " to be a stairwell leading down behind it.",
          ({ "boneyard", "graveyard", "cemetery" }) :
             (: GetLong :),
          ({ "corpse", "corpses", "remains" }) :
             "Hundreds of rotting corpses have been"
             " tossed around the area. No signs of"
             " burial or pyres are present, implying"
             " a complete lack of respect for the dead.",
          ]) );
  SetSmell( ([ 
          "default" : "The smell of rotting flesh lingers.", 
          ]) );
  SetTown("Durgoroth");
  SetInventory( ([ 
    STD_OBJ "reztotem" : 1,
    DURG_NPC "necromancer" : 1,    
          ]) );
  SetExits( ([
    "north" : DURG_ROOM "road09",
    ]) );
//  AddExit("down", "/domains/frostmarches/areas/catacombs/room/stair1", (: PreEnter :)),
  SetObviousExits("north");
}


int PreEnter() {
    int lvl = this_player()->GetLevel();
    if (creatorp(this_player())) return 1;  
    if ((this_player()->GetOwner() != "") && lvl >= 50 ) return 1;
    
    this_player()->eventPrint("You do not think it is wise go down there"
                              " just yet.");                       

    return 0;
}

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("outside west gate");
  SetLong( "An imposing gate stands open to the east granting access to "
           "the village within the stockade.  To the west a well paved "
           "road stretches into the distance through a lightly populated "
           "forest of trees.  However, you note that grass and weeds "
           "have overgrown much of it." );

  SetItems( ([ "gate" : "An imposing gate stands open to the east "
                        "granting access to the village within the stockade.",
               "stockade" : "Logs the width of a man's chest stretch 20 feet "
                            "or more above your head.",
               "logs" : "The logs are in excellent condition.",
               "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  "
                        "However, grass and small weeds are starting to "
                        "grow over parts of it.",
               "trees" : "Tall full leaved trees speckle the surroundings "
                         "to the west."]) );

  SetExits( ([
               "west" : GWONISH + "room/path2",
               "east" : CRYSTAL_REACHES_TOWNS + "lloryk/room/westgate",
    ]) );

  SetSmell( ([ "default" : "The open air of the plains mixes with a fresh "
               "cut wood smell."]) );
  SetListen( ([ "default" : "The faint sounds of people at work comes from "
                "beyond the gate."]) );
  SetObviousExits("west, east");

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(3),
                 GWONISH + "npc/r_animal" : random(4)]));
}


int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}


 

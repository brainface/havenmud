#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("tropical");
  SetShort("on the switchbacks");
  SetLong( "The road slopes downward in a continual ramp that winds its way "
           "down the cliff in a series of switchbacks eventually turning out "
           "either northeast at the top or west at the bottom." );

  SetItems( ([ "road" : "The road is of excellent workmanship, in contrast "
                        "to the rough appearance of most of the region.  It "
                        "descends the cliff in a series of switchbacks.",
               "switchbacks" : "The switchbacks descend the cliff in a series "
                               "of ramps.",
               "cliff" : "The cliff is a but part of long palisades.  The "
                         "view here is quite spectacular with a gigantic "
                         "swamp starting some two hundred feet beneath you "
                         "and what appears to be a very large body of water "
                         "further to the west.",
               "palisades" : "The palisades stretch far to the southeast "
                             "growing taller the further south they are.  "
                             "They then turn west and slowly slope down "
                             "to the sea.",
               "swamp" : "A huge dark swamp that extends far to the south, "
                         "begins beneath you.",
               ({"sea", "water","body of water"}) :
                        "Fog shrouds much of what appears to be a gigantic "
                        "body of water."]) );

  SetExits( ([ "northeast" : GWONISH + "room/path6",
               "west" : GWONISH + "room/path8" ]) );

  SetSmell( ([ "default" : "The natural decay of the forest spices the air "
                           "pleasantly."]) );
  SetListen( ([ "default" : "You are close enough to the swamp now that "
                            "many of its sounds reach you.",
                "swamp" : "The sounds of birds and insects sing front he "
                          "swamp."]) );
  SetObviousExits("northeast, west");

  SetInventory(([GWONISH + "npc/r_npc" : CheckNPC(5),
                 GWONISH + "npc/r_animal" : (random(3) + 1) ]));
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}

 

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

int CheckBlock(string dir);
int CheckNPC(int chance);

static void create()
{
  room::create();
  SetClimate("outdoors");
  SetShort("a rocky trail");
  SetLong( "The trail leads up through a series of increasingly large "
           "boulders.  It eventually curves around from the east to the "
           "southeast and reaches the top of the pile.  Due to the size of "
           "the boulders, visibility is very limited once on the trail." );

  SetProperty("no bump",1);
  SetItems( ([
	"mud" : "The only mud here is that which was tracked in by "
                       "feet.",
               "water" : "The swamp and sea are not visible from here, but "
                         "an occasional puddle of rainwater remains in "
                         "cavities in the rocks.",
               "trail" : "The trail leads up from the swamp/tidal area into "
                         "a pile up of ancient boulders.  Occasionally muddy "
                         "footprints can be seen along the path.",
               "footprints" : "The humanoid looking footprints are longer "
                              "and skinnier than most humanoids and there "
                              "are scratches along the toes as well.",
               ({"rocks","boulders"}) :
                         "The rocks increase in size the deeper into the "
                         "pile the trail runs.  Most of the edges have been "
                         "rounded off, giving the rocks an ancient "
                         "appearance."]) );

  SetExits( ([ "east" : GWONISH + "room/swamp22"]) );
  AddExit("southeast", GWONISH + "room/swamp24", (: CheckBlock :));

  SetInventory(([GWONISH + "npc/lizardmanguard" : 4,
                 GWONISH + "npc/r_swamp" : random(3)]));

  SetSmell( ([ "default" : "A thick briny smell fills your nose."]) );
  SetListen( ([ "default" : "The endless roar of the surf vibrates the "
                   "rocks around you." ]) );
  SetObviousExits("east, southeast");
}

int CheckBlock(string dir)
{
  object *guards;
  if (sizeof(guards = filter(all_inventory(), (: $1->id("guard") && living($1) :) ))) {
    message("system",
      "The lizardman blocks your exit.",this_player());
  return 0;
  }
  return 1;
}

int CheckNPC(int chance)
{
  if(!random(chance)) return 1;
  else
    return 0;
}


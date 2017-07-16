#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
  room::create();

  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a small goblin barracks");
  SetLong("This small room looks like it houses quite a few goblins. "
     "A small hole in the wall leads to another room in this barracks "
     "to the east, and another hole leads back out to the tunnels. Small "
     "cots scatter this room and even more bedding appears on the floors. "
     "The dirty stone walls are covered with drawings of goblins in "
     "battles, obscured slightly by clumps of muck and filth from the "
     "sewers.");
  SetListen( ([
     "default" : "Loud shouting can be heard from the eastern room."
     ]) );
  SetSmell( ([
     "default" : "The odor of smelly goblins nearly suffocates you."
     ]) );
  SetItems( ([
     ({"hole","holes"}) : "The small hole that leads out to the tunnels "
       "is covered with a large ragged cloth, while the hole on the "
       "eastern wall is slightly smaller and has no covering at all.",
     ({"cot","cots","bedding"}) : "Small worn cots are lined against "
       "the walls and in the center of the room, while other dirty rags "
       "and clothes make even more bedding on the floor.",
     ({"wall","walls"}) : "The walls of the barracks are made of the "
       "same stone as the tunnels outside and are covered with crude "
       "drawings of goblins engaged in battles with other goblins and "
     "other races. The drawings are partially covered with clumps of "
       "muck from the sewers.",
     ({"stone","stones"}) : "These large stones are dark and make up "
       "the walls and floors of the tunnels.",
     ]) );
  SetInventory( ([
     AVERATH_NPC "fgoblin" : 2,
     AVERATH_NPC "sgoblin" : 2,
     ]) );
  SetExits( ([
     "east" : AVERATH_ISLAND "goblin_dir/gbarrack2",
     "out" : AVERATH_UNDERGROUND "1,-1,-2",
     ]) );
}

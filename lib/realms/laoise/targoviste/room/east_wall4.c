// Targoviste
// Laoise
// August 2004

#include <lib.h>
#include <domains.h>
#include "../targoviste.h"
inherit LIB_ROOM;

static void create() 
{
  room::create();
  SetDayLight(-20);
  SetTown("Targoviste");
  SetShort("the outer bailey of Targoviste");
  SetLong(
    "A wall rises to the west of here, reaching a height about "
    "half that of the inner wall, which can be seen above and "
    "behind it. Cut in to this wall is an arched entrance, "
    "above which perches a gargoyle, glaring balefully down "
    "at any who approach. Also atop the wall are iron spikes "
    "projecting upwards, joined by a horizontal metal bar. "
    "To the north the shorter wall turns sharply, continuing "
    "west and meeting the wall of the inner keep. Directly north "
    "is the main path of Targoviste while to the south the "
    "outer bailey continues. "
  );
  SetItems( ([ 
    "gargoyle" : "This gargoyle perches on the edge of the "
    "wall, set in a space free of the iron spikes that top "
    "the rest of the wall. Carved of dark grey stone the "
    "gargoyle has the body of a lion, crouched with its paws "
    "hanging over the edge. Above its head are a pair of wings, "
    "fully extended and flared behind its body. Its face is "
    "that of a man with a full beard, and its sharp teeth can "
    "be barely discerned through the snarl that twists its mouth.",
    "cemetery" : "A spooky cemetery. oooOooooOooo.",
    ({ "wall", "walls" }) :
    "Both are formed of the same black granite, "
    "hewn in to blocks that are tightly joined together.",


  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The air is strangely silent here.",
  ]) );
  SetSmell( ([
    "default" : "There is a faint smell of fresh earth.",
  ]) );
  SetExits( ([ 
    "north" : TARG_ROOM "east_wall3",
    "south" : TARG_ROOM "east_wall5",
  ]) );
  SetEnters( ([
    "cemetery" : TARG_ROOM "cemetery1",
  ]) );
}

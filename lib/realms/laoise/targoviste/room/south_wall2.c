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
    "A wall rises to the north, reaching to approximately "
    "half the height of the wall of the inner keep, which "
    "is visible above it. Along the top of this wall are "
    "iron spikes, linked together by a bar running horizontally. "
    "Directly north an arched entrance is cut in to the wall, "
    "which continues to the east. West of the opening "
    "the wall turns to the north, ending against the wall "
    "of the inner keep. Perched atop this corner in the wall "
    "is an enormous gargoyle whose baleful glare appears to "
    "watch over the doorway."
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
    "cemetery" : "A spooky cemetery. oooOoooOooo",

  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The air here is strangely still and silent.",
  ]) );
  SetSmell( ([
    "default" : "A faint smell of fresh-turned earth is present.",
  ]) );
  SetExits( ([ 
    "east" : TARG_ROOM "south_wall1",
    "west" : TARG_ROOM "south_wall3",
  ]) );
  SetEnters( ([
    "cemetery" : TARG_ROOM "cemetery3",
  ]) );
}

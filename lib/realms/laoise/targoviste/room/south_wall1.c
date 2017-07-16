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
    "To the south looms the enormous outer wall of Targoviste. "
    "High above rise the Estergrym Mountains, reaching in "
    "to the darkened sky and overshadowing the city. Towards "
    "the center of the stronghold the cathedral of Aberach "
    "can be seen. Slightly closer is the wall of the inner "
    "keep. Closer yet is a wall which attains approximately "
    "half the height of the inner wall and is topped by a line "
    "of iron spikes. To the north this near wall turns sharply "
    "and a huge gargoyle rests atop this corner, its forboding "
    "glower suffusing the area."
  );
  SetItems( ([ 
    "gargoyle" : "This gargoyle is in the form of a rampaging "
    "beast. It has the flat muzzle of a lion but the lean body "
    "of a wolf. Wings similar to those of a raven rise from its "
    "back, stretching out behind its body and flaring towards "
    "the sky. Its eyes seems to glow slightly and fill the area "
    "with an aura of evil.",

  ]));
  SetItemAdjectives( ([


  ]) );
  SetListen( ([ 
    "default" : "The air is very still here.",
  ]) );
  SetSmell( ([
    "default" : "Fresh earth lightly scents the air.",
  ]) );
  SetExits( ([ 
    "west" : TARG_ROOM "south_wall2",
    "northeast" : TARG_ROOM "east_wall5",
  ]) );
}

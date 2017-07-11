#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("near a tunnel");
    SetDomain("Crystal Reaches");
    SetLong(
      "A dark tunnel has been carved into the hillside "
      "here. It doesn't appear to be of natural making, "
      "for it lacks a chaotic form. No grass grows near "
      "the tunnel's mouth, and a faint path can barely be "
      "seen going from the mouth of the tunnel to the west.  "  
      "A cold, damp breeze comes from the tunnel."
    );
    SetItems( ([
      ({"mouth", "opening"})  :  (: GetLong :),
      ({"grass", "grasses"})  :
      "The brown grass is a wild grass native to the area.",
      ({"rock", "rocks"})  :
      "Jagged rocks imbedded in the hillsides little these hills and "
      "can be found in great abundance.",
      ({"top", "tops"})  :
      "The tops of the hills and rounded.",
      "path"  :
      "A faint path leads to the north.",
      ({"cave", "tunnel"})  :
      "The black tunnel leads down into the hillside.  It seems to have "
      "been made by humans which live somewhere nearby.",
      "hillside"   :
      "A black tunnel has been built into the rocky hillside.",
    ]) );
    SetItemAdjectives( ([
      "hillside"    :  ({"steep", "tall", "rocky"}),
      "rock"    :  ({"scattered", "big", "small"}),
      "top"    :  "rounded", 
      "cave"    :  ({"dark", "irregular"}),
    ]) );
    SetSmell( ([
      "default"  :  "There is little smell.",
    ]) );
    SetListen( ([
      "default"  :  "Grass whispers at it waves in the breeze.",
    ]) );
    SetEnters( ([ 
     ( "tunnel" ) :  ROOMS + "/mine",
     ]) );
    SetExits( ([
      "southeast"   :   ROOMS + "/hill.c",
      "north"  :  ROOMS + "/gang.c",
    ]) );
}

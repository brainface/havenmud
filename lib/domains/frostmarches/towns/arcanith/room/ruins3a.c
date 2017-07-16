/*  The enterance to the cemetery  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("road along western wall");
  SetClimate("temperate");
  
  SetDayLight(-15);
  SetNightLight(10);
  SetExits( ([
    "east"   : ROOM "/ruins3",
    "north"  : ROOM "/cemetary",
  ]) );

  SetDayLong("The road continues on to the west, while being illuminated by "
             "the wall.  To the north lies the ancient graveyard of the "
             "city.  The road to the west is blocked by fallen rubble.");

  SetNightLong("The road continues on to the west and lies in the glow of "
               "wall.  There is a graveyard to the north.  It seems darker "
               "than the rest of the area.  The road to the west is covered "
               "by fallen rubble.");

  SetItems( ([
    ({ "decayed road", "road to the west", "western road", "road" })  :
       "The road to the west ends in a pile of debris.  The road is decayed "
       "because of cracks formed by weeds.",
    ({ "broken wall", "wall" })  :
       "The wall to the south is broken and dim.  The wall still glows, but "
       "not as brightly.",
    ({ "pile of debris", "pile", "debris", "rubble", "fallen debris" })  :
       "Debris from the broken wall blocks the western road.",
    ({ "graveyard to the north", "graveyard", "cemetary" })  :
       "The graveyard to the north is cloaked in fog and heavy shadow.  "
       "It seems that very little light can enter the graveyard.",
    ({ "thick fog", "fog" })  :
       "A thick fog fills the graveyard to the north.  It seems like light "
       "cannot enter the graveyard.",
    ({ "shadows of the cemetary", "shadow of the cemetary", "heavy shadow",
       "heavy shadow", "shadow", "shadows" })  :
       "The graveyard is cloaked in heavy shadow, and seems to repel light.",
    ({ "dim light", "silver light", "light", "glow" })   :
       "The wall radiates a dim light.  It's as if the shadows of the "
       "cemetary smother the light.",
  ]) );

  SetSmell( ([
    "default"  :  "The smell of death and decay hangs heavy in the air.",
  ]) );

  SetListen( ([
    "default"  :  "The sound of moaning wind comes from the graveyard.",
  ]) );

  SetInventory( ([
    NPC "/armour_equipper" : 1,
  ]) );

}

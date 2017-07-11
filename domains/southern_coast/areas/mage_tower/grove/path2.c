/*  The section of the path right before the tower */
#define TOWER_OPEN 1
#include "../mage_tower.h"
inherit LIB_GROVE;
int PreEnter(string);

static void create() {
  ::create();
  SetClimate("arctic");
  SetShort("a clearing before the tower");
  SetExits( ([
    "south" : "path1",
    ]) );
  SetLong("The path ends here. Reaching into the sky is "
          "the huge and black tower of legend. The tower "
          "seems to daunt mere mortals, daring them to "
          "enter through the massive blackened metal doors "
          "that stand like a stoic guardian of evil. To the "
          "south lies the path leading back into Haven Town, "
          "seeming to beg the weary traveller to come home. ");
  SetItems( ([
    "tower" : "The tower is a massive black stone object "
              "without seams which seems to leap into the sky "
              "like a hideous spite against the Gods.",
   ({ "door", "doors" }) : "The doors are metal, but which kind has "
              "long since become unidentifiable.",
    ]) );
  SetItemAdjectives( ([
    "door" : ({ "blackened", "metal", "massive" }),
    ]) );
  SetSmell( ([
     "default" : "The smell of death is intense here.",
    ]) );
  SetListen( ([
    "default" : "Oddly, it is deeply silent here.",
    ]) );
  AddEnter("tower", TOWER_ROOM "1-1", (: PreEnter :) );
  SetInventory( ([
    TOWER_NPC "wraith" : 3,
    ]) );
}

int PreEnter(string thing) {
  if (TOWER_OPEN) {
    return 1;
   }
  else {
    message("system", "The idea of that repels you.", this_player() );
    return 0;
 }
 }

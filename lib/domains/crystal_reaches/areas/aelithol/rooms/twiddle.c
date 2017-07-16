// Edited by Laoise to make the doors enterable, but blocked.
// Since they are in the descriptions. Also cleaned up the items.
#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
int PreEnter();

    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("an opulent section");
    SetDomain("Crystal Reaches");
    SetLong(
      "Many of the burrows here belong to the oldest and most "
      "renown of all the halfling families of the area. "
      "The Twiddletoe family is said to have been here since the "
      "valley was first populated many ages ago. Its burrows "
      "have many round doors which show the hidden size and "
      "luxury that is to behold within."
    );
    SetItems( ([
      ({"door", "doors"})  :
      "Little round doors lead into the burrows.  Many of the largest "
      "burrows have several doors.",       
      ({"gardens", "garden"})  :
      "The beautiful gardens of the Twiddletoe family are the most "
      "well kept and perfect of all the gardens.",
      ({"burrow", "burrows"})  :
      "The Twiddletoes' burrows have many entrances and luxurious "
      "gardens around the premises.  The burrows have multiple doors "
      "that hint at their supposedly amazing size.",
      ({"hill", "hills"})  :
       "The halflings have made burrows in the ancient hills.",
    ]) );
    SetItemAdjectives( ([
      "door"    :  ({"little", "round"}),
      "gardens"    :  ({"aesthetic", "large", "well-kept", "perfect"}),
      "burrows"    :  ({"hillside", "luxurious", "amazing", "large"}),
      "hill"    :  ({"ancient", "steep"}),
    ]) );
    SetSmell( ([
      "default"  :  "Strong food smells fill the air.",
    ]) );
    SetListen( ([
      "default"  :  "It is silent.",
    ]) );
    SetInventory(([
       NPCS + "/rich" : 1 
    ]));
    SetExits( ([
      "north"  :  ROOMS + "/village2.c",
    ]) );
  AddEnter("door", "/no/enter/", (: PreEnter :));
}

int PreEnter(string dir) {
    write("A magical force prevents you from entering the door.");
    return 0;
}

void init() {
  ::init();
  add_action("peer", "peer");
}

int peer(string blah) {
  if(blah == ("door")) {
    eventPrint("You don't seem to be able to peer that way.");
  return 1;
  }
  if(blah == ("doors")) {
    eventPrint("You don't seem to be able to peer that way.");
  return 1;  
  }
}

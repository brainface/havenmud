/*  Kobold Chief's Room  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a decorated cave");

  SetLong("Within the den is a throne fit only for a kobold chief.  The "
          "Kobold chief's room is decorated with the plundered loot from his "
          "many victims.  Rusty weapons lay scattered in one corner.  Moss "
          "piled up with a blanket over it in another.  Along the walls are a "
          "few of the scalps that the chief has gotten for himself are tacked "
          "up.");

  SetSmell( ([
    "default"  :  "The smell of damp dog seems greatest here.",
  ]) );

  SetListen( ([
    "default"  :  "More yapping echoes off of the walls around you.",
  ]) );

  SetExits( ([
    "south"  :  ROOMLV1 + "/kobold1",
  ]) );
  SetObviousExits("south");

  SetItems( ([
    ({ "decorated den", "den" })  :  (: GetLong :),
    ({ "throne", "chief's throne", "kobold chief's throne", "old wooden chair",
       "old chair", "wooden chair", "chair" })  :
       "A throne fit only for a kobold chief, it is a small, old wooden chair "
       "with armrests.  It is quite old and rickety, it's stain has been worn "
       "through in several places showing the bare, rotting wood beneath.",
    ({ "plundered loot", "loot" })  :
       "Some coins, shiny metal pieces, and brightly colored cloth make up "
       "the plundered loot that the kobold's have secured from their victims, "
       "most likely wanderers or travellers.",
    ({ "rusty weapons", "rusty weapon", "weapons", "weapon" })  :
       "Lying in a pile some old, rust covered weapons sit.  Some clubs that "
       "are no more than thick branches, spears with the tips coming off, and "
       "short swords that are rusty with a chipped blade are what make up the "
       "pile.  There is nothing of any worth lying in the pile here.",
    ({ "clubs", "club", "thick branches", "thick branch", "branches", "branch",
       "spears", "spear", "short swords", "swords", "short sword", "sword" }) :
       "Some of the weapons lying forgotten in a pile.  They have not been "
       "used in quite some time and are in dire need of repair.",
    ({ "bed", "moss", "moss bed", "blanket" })  :
       "The bed is made from a fresh supply of moss that is piled evenly in a "
       "large enough area for three kobolds to sleep on.  A once luxurious "
       "blanket covers it and makes it look slightly comfortable to lay on. ",
    ({ "luxurious blanket", "blanket" })  :
       "This once luxurious blanket covers the pile of moss that the kobold "
       "chief uses as a bed.  It had an intricate design at one time, but now "
       "the colors have all bled together and is as dirty now as it was once "
       "beautiful.",
    ({ "walls", "wall", "scalp", "scalps" })  :
       "On the walls around the den, scalps from the kobold chief's kills "
       "hang.  Human, elf, gnome, and many others, thought the one that "
       "sticks out the most is the large scalp of a giant which is hung over "
       "the kobold chief's chair, er throne.",
    ({ "large scalp" })  :
       "The scalp of a giant which the kobold chief supposedly killed.",
    ({ "coins", "coin", "shiny metal pieces", "shiny metal piece", "metal",
       "pieces", "piece", "shiny metal", "metal pieces", "metal piece",
       "brightly colored cloth", "colored cloth", "cloth" })  :
       "This is the loot of the kobold chief, pretty pitiful huh?",
    ({ "pile" })  :
       "Are you referring to the weapons or the bed.",
  ]) );

  SetInventory( ([ NPCS + "/koboldchief" : 1,
                   NPCS + "/koboldguard" : 2,
                   NPCS + "/koboldwomen" : 2,
  ]) );
}

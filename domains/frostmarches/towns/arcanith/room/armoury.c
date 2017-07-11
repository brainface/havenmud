/* "the ruined armoury" by Sardonas */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("a decaying armoury");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetExits( ([
    "out"  : ROOM "/ruins7",
  ]) );

  SetLong("The inside of the armoury is covered in a thick layer of dust.  "
          "Suits of armour and shields hang along the walls, as they slowly "
          "give in to the ravages of time.  Everything in this shop is "
          "old-fashioned and finely crafted; if it wasn't for the rust, the "
          "armour would be valuble.");

  SetItems( ([
    ({ "armoury" })  :
       (: GetLong :),
    ({ "thick layer of dust", "dust", "layer of dust" })  :
       "A thick layer of dust covers every surface.  The dust swirls with "
       "the faintest touch.  The layer of dust causes everything to look "
       "grey and bland.",
    ({ "metal items", "metal item", "items", "item" })   :
       "Rust slowly eats its way through the metal armour and shields.",
    ({ "metal shields", "metal shield", "shields", "shield" })  :
       "The shields are old and decaying.  Rust covers the metal shields, "
       "making them weak and pitted.",
    ({ "suits of armour", "suit of armour", "metal armours", "metal armour",
       "armours", "armour" })  :
       "The suits of armour are finely crafted and decorated.  They would "
       "have been very valuble and strong, yet rust has made them weak and "
       "worthless.",
    ({ "red-orange rust", "rust" })  :
       "Red-orange rust covers every metal item in this shop.",
  ]) );

  SetSmell( ([
    "default"  : "The smell of rust fills the air.",
  ]) );
  SetInventory( ([
     NPC "/giant_spider" : 2 ]) );
}

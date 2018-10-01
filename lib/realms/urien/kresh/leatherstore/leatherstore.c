// Urien 110613 - Updated Long
// Town, Domain, Items, Adjectives
// Clone of Leather store on main road 
// Small size player Leather Store
// Made it more 'Goblin'
#include <domains.h>
#include <lib.h>
#include "../goblins.h"

inherit LIB_ROOM;

static void create() {
  ::create();   
  SetShort("Temu's Rags");
  SetDomain("Southern Coast");
  SetTown("Kresh");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetExits( ([
     "out": GOBLIN_ROOM + "m_2",
  ]) );
  SetLong(
     "The inside of this circular leather store despite its size, "
     "is quite simplistic. A small counter divides the inside "
     "in half with leather hide piled high along the eastern "
     "side. Pelts of several animals have been sewn together "
     "and secured along the walls of the tent expose the "
     "wooden frame underneath. A small candle that sits in a "
     "thin metal bowl, burns slowly and provides illumination. A "
     "used leather hide flap slightly covers the exit out.");
  SetItems( ([
   ({ "store", "tent","yurt","inside" }) : (: GetLong :),
   ({ "ground", "floor" }): "The ground is natural dirt in "
      "this tent. The counter that divides the store "
      "seems to have been built on top of it.",
   ({ "counter" }) : "This wooden counter is sturdy and acts "
      "as point of sale for the store. A thin metal bowl "
      "has been placed on the western side to brighten "
      "the inside. Piles of mare hide sit dishevelled on "
      "the eastern wall and stack atop the counter itself.",     
   "piles": "A medium sized pile or conglomerate little piles "
      "of leather hide sits on the eastern side of the yurt. "
      "They have been cut to accommodate smaller sized "
      "pieces of clothing. There is no organization as they "
      "vary in quality and color.",
   "pelts": "Fur pelts have been crudely cut and sewn "
      "together providing a traditional Goblin Interior. "
      "It functions as a makeshift insulation in this "
      "shop and adds a natural border from the elements. "
      "It looks as if the project was rushed due to "
      "the wooden frame pieces being exposed.",
   "frame": "The wooden frame of the yurt is noticeable "
      "along the circular wall. It appears sturdy and "
      "does not look to be damaged in any particular "
      "exposed area in the tent.",
   "candle": "A small wax candle burns softly resting "
      "inside a thin metal bowl. It sits atop the western "
      "edge of the counter providing light.",
   "bowl": "A thin metal bowl has been placed on the "
      "counter with a candle placed inside. It seems "
      "very thin and delicate for which burning candles "
      "is the only function.",
   "ceiling": "The ceiling and the wall are essentially "
      "one. The center peak of the round ceiling is "
      "high and descends to the circular wall below.",
   "wall": "The single circular wall covered in pelts "
      "has been decorated poorly. Small portions of the "
      "tent frame can be seen in certain parts. It "
      "rises up slightly and makes a round ceiling.",
   "exit": "An exit leads out of this crude shop.",
   "flap": "A thick piece of leather covers the exit "
      "out of the store. It seems to have seen much "
      "use from being agitated and used, giving it "
      "a plush quality.",
  ]) );
  SetItemAdjectives( ([
   "store" : ({ "little" }),
   "counter" : ({ "wooden" }),
   "piles": ({ "hide","mare" }),
   "frame": ({ "wooden" }),
   "pelts": ({ "fur" }),
   "candle": ({ "small" }),
   "bowl": ({ "thin","metal" }),
   "wall": ({ "circular" }),
   "ceiling": ({ "round" }),
   "flap": ({ "leather","hide" }),
  ]) );
  SetInventory( ([ 
     STORE_DIR + "temu" : 1,
     STORE_DIR + "ogdai" : 1,
  ]) );
  SetSmell( ([
    "default" : "A strong smell of leather hide lingers "
                "in the air.",
  ]) );
}
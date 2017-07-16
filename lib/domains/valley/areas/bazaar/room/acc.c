/* This is booth where one could buy accessories such as silk scarves, leather wallets and purses, or jewelry. */
#include <lib.h>
#include "../bazaar.h"
  inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("an accessories booth");
  SetLong("This is a small canopy-covered booth filled with "
     "exotic silk scarves, leather wallets and purses, silver "
     "and gold jewelry, and velvet hats. The items for sale "
     "have the artisanship of many distant lands. There is "
     "a wooden table in the corner laden with samplings "
     "of all the finest articles. More shopping areas are visible to "
     "the west, and the ticket booth is back to the north. A "
     "small mysterious tent is just south of here.");
  SetExits( ([
     "north" : BAZAAR_ROOM "booth",
     "west" : BAZAAR_ROOM "trinket",
  ]) );
  SetSmell( ([
     "default" : "Exotic scents eminate from the silks and perfumes."
  ]) );
  SetListen( ([
     "default" : "Sounds of laughter fill the booth."
  ]) );
  SetItems( ([
   ({ "booth" }) : "It is made from a plain, canvas canopy supported by four, long, wooden poles in the ground.",
   ({ "canopy" }) : "The canopy is fashioned from a plain, stiff canvas.",
   ({ "articles" }) : "The articles on the table are all sorts of scarves, wallets and purses, gold "
     "and silver jewelry, and velvet hats.",
   ({ "scarf", "scarves" }) : "The design of each silk scarf is detailed and unique.",
   ({ "wallet", "wallets" }) : "These leather wallets are quite fashionable.",
   ({ "purse", "purses" }) : "The leather purses are small and stylish.",
   ({ "gold jewelry", "silver jewelry", "jewelry" }) :
     "There are rings, necklaces, and bracelets with intricate designs.",
   ({ "hat", "hats" }) : "The velvet hats of all colors are adorned with colorful feathers.",
   ({ "table" }) : "The table is covered in scarves, wallets and purses, gold and silver jewelry, and hats of all sizes.",
   ({ "canvas" }) : "This stiff canvas makes up the roof of the booth.",
   ({ "tent" }) : "A small, plain tent is just south of here.",
  ]) );
  SetItemAdjectives( ([
    "booth" : ({ "small", "canopy-covered" }),
     "tent" : ({ "small", "mysterious" }),
    "canopy" : ({ "plain", "stiff", "canvas" }),
   "canvas" : ({ "plain", "stiff" }),
    "scarf" : ({ "exotic", "silk" }),
    "wallet" : ({ "leather" }),
    "purse" : ({ "leather" }),
    "jewelry" : ({ "gold", "silver" }),
    "hat" : ({ "velvet" }),
    "table" : ({ "wooden" }),
  ]) );
  SetEnters( ([
     "tent" : BAZAAR_ROOM "fortune",
  ]) );
  SetInventory( ([ BAZAAR_NPC + "kelsey" : 1, ]) );
}

#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a halfling village");
    SetDomain("Crystal Reaches");
    SetLong(
      "This is in the heart of the halfling village. Burrows are "
      "all throughout this area. Gardens exist from the aesthetic "
      "to the useful, but most have no real purpose. Halflings "
      "congregate in large numbers and give the area an especially "
      "warm feeling. Fields can barely be seen on the outskirts of "
      "the village."
    );
    SetItems( ([
      "village"  :  (: GetLong :),
      ({"pasture", "pastures"})  :
      "The pastures are green and the grass is kept short by "
      "the presence of various grazing animals.",
      ({"garden", "gardens"})  :
      "The halflings are excellent gardeners and their gardens are "
      "prosperous.",
      "wheat"  :
      "Golden wheat waves gently in the breeze.",
      ({"burrow", "burrows"})  :
      "Halflings have dug burrows here.  Their little round doors "
      "can be seen protruding the hillsides everywhere.",
      ({"fields", "field"})  :
      "Vast fields of wheat wave gently in the breeze and can be seen "
      "expanding out in the distance.",
      ({"animal", "animals"})  :
      "Grazing animals that live in the pastures keep the plant "
      "growth to minimum.",
      ({"fence", "fences"})  :
      "Fences surround the pastures and confine the animals.",
      "grass"  :
      "The grass is kept short by grazing animals.",
      ({"hill", "hills"})  :
      "The halflings have made burrows in the ancient hills.",
    ]) );
    SetInventory(([
       NPCS + "/half" : 5 
    ]));

    SetItemAdjectives( ([
      "wheat"    :  ({"golden", "waving"}),
      "burrow"  :  ({"hillside", "underground"}),
      "field"    :  ({"vast", "wheat"}),
      "pasture"    :  ({"green", "grazing"}),
      "hill"    :  ({"ancient", "steep"}),
      "grass"    :   ({"short", "green"}),
      "animal"    :  ({"grazing"}),
      "garden"  :  ({"aesthetic", "small", "useful", "prospering"}),
    ]) );
    SetSmell( ([
      "default"  :  "The aromas from food float through the air.",
    ]) );
    SetListen( ([
      "default"  :  "Villagers are talking happily.",
    ]) );
    SetExits( ([
      "southeast"  :  ROOMS + "/village.c",
      "south"  :  ROOMS + "/twiddle.c",
    ]) );
}

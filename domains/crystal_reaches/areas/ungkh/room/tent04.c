//Selket@Haven
//2006

#include <lib.h>
#include "../ungkh.h"
#include <domains.h>
inherit LIB_ROOM;

static void create() {

  room::create();
  SetShort("inside a dark tent");
  SetClimate("indoors");
  SetLong(
    "This tent seems to be the haven for home-grown poisons and mushrooms, "
    "which sprout from piles of manure that litter the floor. Rude bottles "
    "made of leather lie about, some full of poisons extracted from "
    "anything the ogres can lay their paws on. The only exit is out."
  );
  SetSmell("The earthy scent of mushrooms and manure stagnates.");
  SetListen("The noise of Ungkh is greatly reduced inside the tent.");
  SetItems( ([
    ({"hides", "tent", "walls"}) :
    "The hides that make this tent are the skins of elves. The veins and "
    "insulating bits of fat still cling to the hides.",
    ({"poisons", "bottles", "poison", "bottle"}) : 
    "The leather canteens of poison ooze from their enclosures and "
    "are unsafe to touch.",
    ({"mushroom", "mushrooms", "pile", "piles", "manure", "floor"}) : 
    "Mushrooms of various sizes and colors sprout from the smelly "
    "manure, and some of them look edible. Or maybe not.",
  ]) );
  SetItemAdjectives( ([
    "poisons" : ({ "home-grown" }),
    "bottle" : ({ "rude", "leather" }),
  ]) );
  SetExits( ([
    "out" : U_ROOM + "road10",
    ]) );
  SetInventory( ([
    U_NPC "projectileogre" : 3,
  ]) );
  }

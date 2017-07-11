//Selket@Haven
//2006

#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside the Chestnut Mare Tavern");
   SetClimate("indoors");
   SetAmbientLight(55);
   SetExits( ([
      "out" : LLORYK + "room/uh3",
   ]) );
   SetInventory( ([
      LLORYK "npc/andie" : 1,
      LLORYK "npc/drunk" : 1,
      LLORYK "npc/vanya" : 1,
      LLORYK "npc/rogue" : 1,
   ]) );
   SetLong("The Chestnut Mare is Lloryk's shabby excuse for a tavern. "
           "Although the trestle tables and long sturdy benches are "
           "clean, and the planked floor is kept swept, the whole "
           "place smells a lot like a stable. A modest bar stretches "
           "along one wall, waxed to shine like a curry-combed stallion. "
            );
   SetItems( ([
      ({ "mare", "tavern" }) :
         (: GetLong :),
      ({ "table", "tables", "bench", "benches" }) : 
         "The wooden tables and benches are low to the floor, built "
         "to accommodate nearly every farmer in the Shire.",
      ({ "floor", "floors" }) : 
         "The floor of the tavern is almost spotless, except for "
         "stray bits of straw and grass here and there.",
      ({ "bar" }) : 
         "The bar runs from one wall to the other, a short wooden "
         "structure with nary a scratch in the shiny surface.",
      ({ "wall", "walls" }) : 
         "The walls seem to be like any others.",
   ]) );
   SetItemAdjectives( ([
      "mare" : ({ "chestnut", "lloryk" }),
      "tavern" : ({ "shabby" }),
      "floor" : ({ "planked", "swept" }),
      "table" : ({ "trestle" }),
      "bench" : ({ "long", "sturdy", "clean" }),
   ]) );
   SetSmell( ([
      "default" : "The stable scent is nearly covered up by the "
                  "smells of wholesome food and good beer. Nearly.",
   ]) );
   SetListen( ([
      "default" : "The cheery din of conversation warms the room.",
   ]) );
}

#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside the blue tent");
  SetExits( ([
       "out" : CAMP_ROOM + "cl3",
       ]) );
  SetObviousExits("out");
  SetLong("This tent is neatly kept, with stacks of tomes and books "
          "lying about with a distinct, if undiscernable, order to them. "
          "There is a sleeping mat lying off to one side of the tent, "
          "and it appears to also be kept up with the greatest of care.");
  SetItems( ([
      "mat" : "This mat is a very well tended sleeping mat.",
   ({ "tome", "tomes", "book", "books" }) : "These seem to be spell books. "
                                              "Only a trained master would "
                                              "go anywhere near them.",
       ]) );
  SetInventory( ([
      CAMP_NPC + "mage" : 1,
      ]) );
 }

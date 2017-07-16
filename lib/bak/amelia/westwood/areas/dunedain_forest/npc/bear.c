#include <lib.h>
#include "../forest.h"
inherit LIB_NPC;

static void create(){
  npc::create();
  SetShort("a brown bear");
  SetLong("This large mound of brown fur is a forest bear with a "
          "very unpleasant disposition.  He scowls and growls and looks "
          "for all the world like he's ready to attack anything "
          "in his path.  He has sharp claws and big teeth "
          "and a lot of mass to him.");
  SetLevel(8);
  SetId( ({ "bear" }) );
  SetKeyName("bear");
  SetRace("bear");
  SetGender("male");
  SetClass("animal");
  SetInventory( ([
                   F_OBJ "claw" : 1
              ]) );
}


/* Approved by Balishae on Thu Sep 11 13:49:39 1997. */

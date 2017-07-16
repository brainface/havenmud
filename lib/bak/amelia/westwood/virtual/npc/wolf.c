#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("grey wolf");
  SetShort("a cunning grey wolf");
  SetId( ({ "wolf", "grey wolf" }) );
  SetAdjectives( ({ "cunning" }) );
  SetRace("dog");
  SetLevel(random(3) + 3);
  SetClass("animal");
  SetLong("This regal animal has a pelt of grey covering a thin yet \n"
         "strong form.  His eyes show the intelligence of a racial \n"
         "history which causes the sentient races to fear his race \n"
         "with universal hatred.");
  SetGender("male");
 }

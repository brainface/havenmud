#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("grey wolf");
  SetId( ({ "wolf", "grey wolf" }) );
  SetAdjectives( ({ "cunning" }) );
  SetShort("a cunning grey wolf");
  SetLong("This regal animal has a pelt of grey covering a thin yet \n"
         "strong form.  His eyes show the intelligence of a racial \n"
         "history which causes the sentient races to fear his race \n"
         "with universal hatred.");
  SetRace("dog"); 
  SetClass("animal");
  SetLevel(random(3) + 3);
  SetGender("male");
 }
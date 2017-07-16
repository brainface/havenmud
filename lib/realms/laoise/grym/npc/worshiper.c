#include <lib.h>
#include "../grymxoria.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worshipper");
  SetId( ({ "worshipper", "nosferatu" }) );
  SetShort("a worshipper of Saahagoth");
  SetLong(
    "A average Nosferatu worshiper of the religion of "
    "Saahagoth."
  );
  SetRace("nosferatu");
  if(random(10) > 5) {
  SetGender("male");
  }
  else {
  SetGender("female");
  }
  SetClass("fighter");
  SetLevel(7);
  SetInventory( ([ 
    G_OBJ + "blood_dagger" : "wield dagger in right hand" 
  ]) );
  SetCurrency("bloodgems", 15);
}

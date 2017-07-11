#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("defender");
  SetId( ({"nosferatu","defender"}) );
  SetAdjectives( ({"big","intimidating","alert"}) );
  SetShort("a nosferatu defender");
  SetLong("This defender is overly sized.  He has big, squared shoulders "
  "that peek out from his vest.  His intimidating eyes search "
  "around while his fine lips hide behind baring fangs that seem "
   "very acute.  His head is tilted upwards, alert, like he's hiding "
  "something."); 
  SetRace("nosferatu");
  SetGender("male");
  SetMorality(-80);
  SetClass("fighter");
  SetLevel(18);
  SetCurrency("crystals",random(10)+1);
  SetAction(9, ({
  "!say I don't see what I'm out here for, there's no one around..",
  "!mutter"
  }) );
  SetCombatAction(11, ({
  "!say Members! Guard the lodge!",
  }) );
  SetInventory( ([
  L_OBJ + "vest" : "wear vest",
  L_OBJ + "pants" : "wear pants",
  L_OBJ + "staff" : "wield staff",
  ]) );
}

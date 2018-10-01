#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  
  SetKeyName("defender");
  SetShort("a nosferatu defender");
  SetId( ({"nosferatu","defender"}) );
  SetAdjectives( ({"big","intimidating","alert"}) );
  SetLong(
     "something."
     ); 
  SetRace("nosferatu"); 
  SetGender("male");
  SetClass("cavalier");
  SetLevel(18+random(8));
  SetInventory( ([
     L_OBJ + "vest" : "wear vest",
     L_OBJ + "pants" : "wear pants",
     L_OBJ + "staff" : "wield staff",
     ]) );
  SetAction(9, ({
     "!say I don't see why I'm out here, there's no one around.",
     "!mutter",
     "!emote paces back and forth.",
     }) );
  SetCombatAction(11, ({
     "!say You'll never get past me!",
     "!emote growls fiercely.",
     }) );

}

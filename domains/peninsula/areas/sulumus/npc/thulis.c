// Proximo@Via Imperialis
// 06/03/2003

#include <lib.h>
#include <std.h>
#include "../sulumus.h"

inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("thulis");
  SetId( ({ "thulis", "enforcer", "we_wander" }) );
  SetAdjectives( ({ "head" }) );
  SetShort("Thulis the Head Enforcer");
  SetLong(
     "This aging, battle-scarred man has seen countless battles and has "
     "done countless acts of both good and evil. He goes where the job "
     "opportunities takes him and his men. It looks as though he has started "
     "to settle down in the trading post, happy with his current arrangement "
     "and slowing of the pace of life. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  SetFriends( ({
     "we_wander", 
  }) );
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetInventory( ([
     S_OBJ + "amulet" : "wear amulet",
     S_OBJ + "spear" : "wield spear",
     S_OBJ + "leather_vest" : "wear vest",
     S_OBJ + "leather_pants" : "wear pants",
     S_OBJ + "leather_boots" : "wear boots",
     S_OBJ + "leather_helmet" : "wear helmet",
     S_OBJ + "e_cloak" : "wear cloak",
     ]) );
  SetTrainingSkills( ({
     "pole combat"
  	 }) );
  SetTown("Sanctum");
  SetClass("fighter");
  SetStat("durability", 1, 2);
  SetStat("strength", 1, 2);
  SetSkill("pierce combat", 1, 1);
  SetSkill("pole combat", 1, 1);
  SetSkill("melee combat", 1, 1);
  SetSkill("slash combat", 1, 1);
  SetSkill("blunt combat", 1, 1);
  SetSkill("knife combat", 1, 1);
  SetSkill("projectile combat", 1, 1);
  SetLevel(30);
  SetLimit(1);
  SetCurrency("imperials", 100 + random(100));
  SetMorality(-75);
}

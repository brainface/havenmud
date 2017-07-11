
#include <lib.h>
#include "../haven.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("arcturus");
  SetRace("elf");
  SetLimit(1);
  SetNoClean(1);
  SetClass("cavalier");
  SetSkill("blunt combat", 200, 1);
  SetSkill("hack combat", 200, 1);
  SetSkill("pierce combat", 200, 1);
  SetSkill("slash combat", 200, 1);
  SetSkill("projectile combat", 200, 1);
  SetSkill("melee combat", 200, 1);
  SetSkill("faith", 200, 1);
  SetSkill("evokation", 200, 1);
  SetSkill("healing", 200, 1);
  SetSkill("enchantment", 200, 1);
  SetSkill("combat rage",200,1);
  SetSkill("accuracy",200,1);
  SetSkill("parry",200,1);
  SetSkill("multi-weapon",600,1);
  SetSkill("chain armour",200,1);
  SetSkill("fire magic",200,2);
  SetLevel(250);
  SetShort("Arcturus the Supreme Paladin of Haven Town (elf)");
  SetId( ({ "arcturus", "paladin", "elf", "haven_wander" }) );
  SetWanderSpeed(10);
  SetTown("Haven");
  SetReligion("Kylin");
  SetAdjectives( ({ "supreme", "elf" }) );
  SetLong("Arcturus has made a life of combat.  His abilities to deflect attacks are legendary.");
  SetInventory( ([
    H_OBJ "guard_armour" : "wear armour",
    H_OBJ "avatarslash" : "wield longsword",
    H_OBJ "avatarpierce" : "wield rapier",
    ]) );
  SetCurrency("imperials",random(15000)+10);
  SetGender("male");
  SetMorality(2000);
  AddFood(25000);
  AddDrink(25000);
  SetSpellBook( ([
    "barrier of faith" : 100,
    "desert banishment" : 100,
    "smite" : 100,
    "wrath" : 100,
    "touch of death" : 100,
    "wall of force" : 100,
    "perfect recovery" : 100,
    "hand of judgement" : 100,
    
  	]) );
  SetAction(5, ({ 
  	"!cast barrier of faith",
    "!cast wall of force",
    "!speak I defend this city from harm.",
     }) );
  SetCombatAction(30, ({
    "!cast barrier of faith",
    "!cast perfect recovery",
    "!cast wrath",
    "!cast desert banishment",
    "!cast smite",
    "!cast hand of judgement",
  	}) );
  if (environment()) call_out( (: eventForce, "cast barrier of faith" :), 0 );
  SetFirstCommands( ({ "cast wall of force", "cast wall of force", "cast wall of force" }) );
}
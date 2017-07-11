/*   Portia  5-14-99
     The guard for the dark order guild.
     /domains/havenwood/areas/darkorderguild/guard
     MODIFIED: Dylanthalus@HAVEN
      hopefully do a little better to protect their nonmagical guild hall.
      the rogue didn't use a knife, nor made use of a combat style.
 */

#include <lib.h>
#include <std.h>
inherit LIB_NPC;

void DoCombatSomething();


static void create() {
  npc::create();
  SetKeyName("guard");
  SetShort("a tall guard");
  SetId( ({"guard"}) );
  SetAdjectives( ({"tall"}) );
  SetGender("male");
  SetRace("dark-elf");
  SetMorality(-250);
  SetClass("rogue");
  SetLevel(30);
  SetLong("This tall guard looks very intimidating. It is clear that "
    "one will not enter this shack while he breathes.");
  SetInventory( ([
    "/domains/havenwood/areas/darkorderguild/elf_tunic" : "wear tunic",
    "/domains/havenwood/areas/darkorderguild/g_pants"   : "wear pants",
    "/domains/havenwood/areas/darkorderguild/g_boots"   : "wear boots",
    STD_KNIFE + "freeknife" : 1,
    STD_KNIFE + "stiletto" : 1,
    ]) );
  SetFirstCommands( ({ "wield all" }) );
  SetCombatStyleLevel("blade dancing", 60);
  SetCombatAction(10, (: DoCombatSomething :) ); 

  }

void DoCombatSomething() {

  if (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) {
    eventForce("set style to blade dancing");
        }
  else
    eventForce("set style to none");
  return;
}

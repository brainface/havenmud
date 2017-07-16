#include <lib.h>
#include <std.h>
#include "../thra.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("thra guardian");
  SetShort("a Guardian of Thra");
  SetId( ({ "gelfling", "guardian" }) );
  SetAdjectives( ({ "thra" }) );
  SetRace("gelfling");
  SetClass("druid");
  SetSkill("ice magic", 1, 1);
  SetLevel(75);
  SetFriends( ({ "gelfling" }) );
  SetMorality(1500);
  SetReligion("Eclat");
  SetSpellBook( ([
    "vermin horde" : 100,
    "wall of wood" : 100,
    "ice storm"    : 100,
    ]) );
  SetFirstCommands( ({ "cast wall of wood", "cast wall of wood", "cast wall of wood", "cast wall of wood", "cast wall of wood", }) );
  SetInventory( ([
    STD_WEAPON "pole/small_halberd" : "wield all",
    ]) );
  SetGender(random(2) ? "male" : "female");
  SetLong(
    "This guardian of the village of Thra seems to take " + possessive(GetGender()) + " job seriously. "
    "The firm look in " + possessive(GetGender()) + " eyes gives the impression that the gelflings will "
    "not be chased from this forest as they were their old."
    );
  SetAction(1, ({
    "!speak Welcome to Thra.",
    "!speak Bring peace with you to Thra.",
    }) );
  SetCombatAction(10, ({ 
    "!cast wall of wood",
    "!cast vermin horde",
    "!cast ice storm",
    }) );
  SetGreet("Greetings to you as well. You can find assistance on the southwest platform of Thra.");
}
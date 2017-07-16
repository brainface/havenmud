//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_SENTIENT;
int CheckInvader();

static void create() {
  ::create();
  SetKeyName("battlemage");
  SetId( ({ "gnoll", "mage", "battlemage" }) );
  SetAdjectives( ({ "battle" }) );
  SetShort("a battlemage");
  SetLong(
    "This mage has dignified himself in battles for the army "
    "of Lisht. His powers are amazing, and he is not one to "
    "be easily trifled with."
  );
  SetRace("gnoll");
  SetClass("evoker");
  SetGender("male");
  SetBaseLanguage("Rehshai");
  SetTown("Lisht");
  SetLevel(random(30) + 50);
  SetReligion("Enniae");
  SetSpellBook( ([
    "psychokinetic impulse" : 100,
    "mesmer barrier" : 100,
    "chain lightning" : 100,
    "paralysis" : 100,
  ]) );
  SetCombatAction(30, ({ 
    "!cast psychokinetic impulse",
    "!cast chain lightning",
    "!cast paralysis",
  }) );
  SetAction(5, ({
    "!emote glares at you as if you have no right to be here.",
    "!cast mesmer barrier",
    "!flex",
    "!emote looks at a map idly.",
  }) );
  SetFirstCommands( ({ 
    "cast mesmer barrier", 
    "cast mesmer barrier", 
    "cast mesmer barrier",
    "cast mesmer barrier",
    "cast mesmer barrier",
  }) );
  SetInventory( ([
    "/std/clothing/body/dgold_robe" : "wear robe",
    "/std/clothing/boot/laced_shoes" : "wear shoes",
    "/std/weapon/knife/stiletto" : "wield knife",
    LISHT_OBJ "snake_armlet" : "wear armlet on left arm and left hand",
    ]) );
  SetCurrency("deben", 1000);
  SetMorality(-300);
  SetLimit(1);
  SetEncounter( (: CheckInvader :) );
 }

int CheckInvader() {
  if (this_player()->GetProperty("invader")) {
    SetAttack(this_player());
    return 1;
  }
  return 0;
 }

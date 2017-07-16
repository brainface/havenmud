/*  A mage to guard the library */
#include <lib.h>
#include "../haven.h"
inherit LIB_SENTIENT;
int CheckInvader();

static void create() {
  ::create();
  SetKeyName("warrior mage");
  SetRace("elf");
  SetId( ({ "elf", "mage", "mage_guard" }) );
  SetAdjectives( ({ "warrior" }) );
  SetClass("evoker");
  SetSkill("fire magic",1,2);
  SetGender("male");
  SetShort("a warrior mage of the Grand Library");
  SetTown("Haven");
  SetReligion("Kylin");
  SetLevel(random(20) + 20);
  SetSpellBook( ([
     "shock"           : 100,
     "sphere"          : 100,
     "fireball"        : 100,
     "chain lightning" : 100,
     "paralysis"       : 100,
     ]) );
  SetCombatAction(60, ({ 
     "!cast sphere",
     "!cast energy field",
     "!cast chain lightning",
     "!cast shock",
     "!cast paralysis",
     "!cast fireball",
     }) );
  SetAction(5, ({
     "!emote looks stoic, as if to ward off foes.",
     "!cast sphere",
     "!cast energy field",
     "!frown thoughtfully",
     }) );
  SetLong("This mage of the Grand Library defends the honor of "
          "the Library against the Haven Town Guard and Templars. "
          "His demeanor suggests someone not at all happy with his "
          "role in the new Haven Town.");
  SetInventory( ([
     "/std/clothing/body/drab_robe" : "wear robe",
     "/std/weapon/pole/staff" : "wield staff",
     ]) );
  SetCurrency("imperials", 400);
  SetMorality(-300);
  SetEncounter( (: CheckInvader :) );
 }

int CheckInvader() {
  if (this_player()->GetProperty("invader")) {
    SetAttack(this_player());
    return 1;
  }
  return 0;
 }

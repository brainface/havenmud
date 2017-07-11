#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

void DoSomething();

static void create() {
  ::create();
  SetKeyName("gerard");
  SetId( ({ "gerard", "magician", "gerard the magician" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetGender("male");
  SetStat("intelligence", 40, 1);
  SetClass("enchanter");
  SetLevel(65);
  SetCurrency("senones", 800);
  SetFriends( ({ "hammat" }) );
  SetTaughtSpheres( ({
    "magical enchantment"
  }) );
  SetSpellBook( ([
    "disintergrate"   : 100,
    "mesmer barrier"  : 100,
    "energy wall"     : 100,
    "chain lightning" : 100,
    ]) );
  SetShort("Gerard the Magician");
  SetLong("A tall, powerfully built Goden is here, his dark brown fur "
          "greying in places due to great age.  Despite his apparent great "
          "age and the fact that he spends most of his time indoors studying "
          "Arcane Arts long forgotten by all but the most wise of wizards, "
          "his body possesses a strength and prowess to it that makes him an "
          "incredibly dangerous foe.  An aura of crackling energy forever "
          "enshrouds this cat-like creature, and random bolts of electricity "
          "crackle from his fiery red eyes.");
  SetCombatAction(70, (: DoSomething :));
  SetInventory( ([ "/std/weapon/pole/baton" : "wield baton" ]) );
  SetMorality(25);
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Magician",
    "mortal" : "the Magician",
    "hm"     : "the Grand Magician of Keryth",
    "legend" : "the Wizard of Enchantment",
    ]) );
}

void DoSomething() {
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast " + (random(3) ? "mesmer barrier" : "energy wall" ));
    return;
  }
  
  if ((!random(5)) && (userp(GetCurrentEnemy()))) {
    eventForce("cast " + (random(3) ? "disintegrate" : "chain lightning"));
    return;
  }

}

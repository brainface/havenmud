#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

void DoSomething();

static void create() {
  ::create();
  SetKeyName("gerard");
  SetId( ({ "gerard", "planar magician", "gerard the planar magician" }) );
  SetRace("goden");
  SetTown("Keryth");
  SetGender("male");
  SetStat("intelligence", 40, 1);
  SetSkill("planar magic", 40, 1);
  SetSkill("pole attack", 40, 1);
  SetLevel(35);
  SetSkill("evokation", 150, 1);
  SetSkill("conjuring", 150, 1);
  SetCurrency("senones", 800);
  SetFriends( ({ "hammat" }) );
  SetTaughtSpheres( ({
    "magical planar magic"
  }) );
  SetSpellBook( ([
    "dimension door" : 100,
    "elemental protection" : 100,
    "energy wall" : 100
  ]) );
  SetNoJoin(1);
  SetShort("Gerard the Planar Magician");
  SetLong("A tall, powerfully built Goden is here, his dark brown fur "
          "greying in places due to great age.  Despite his apparent great "
          "age and the fact that he spends most of his time indoors studying "
          "Arcane Arts long forgotten by all but the most wise of wizards, "
          "his body possesses a strength and prowess to it that makes him an "
          "incredibly dangerous foe.  An aura of crackling energy forever "
          "enshrouds this cat-like creature, and random bolts of electricity "
          "crackle from his fiery red eyes.");
  SetCombatAction(35, (: DoSomething :));
  SetInventory( ([ "/std/weapon/pole/baton" : "wield baton" ]) );
  SetMorality(25);
}

void DoSomething() {
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast " + (random(3) ? "elemental protection" : "energy wall" ));
    return;
  }
  
  if ((!random(5)) && (userp(GetCurrentEnemy()))) {
    eventForce("cast dimension door on " + GetCurrentEnemy()->GetKeyName());
    return;
  }

  if ((!random(3)) &&
      (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/3))) &&
      (sizeof(GetCurrentEnemy()->GetWielded()) != 0)) {
    eventForce("disarm");
    return;
  }
}

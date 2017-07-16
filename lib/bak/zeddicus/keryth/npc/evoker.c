#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_LEADER;

void DoSomething();

static void create() {
  ::create();
  SetFriends( ({ "gerard" }) );
  SetKeyName("hammat");
  SetId( ({ "hammat", "evoker" }) );
  SetRace("goden");
  SetClass("evoker");
  SetTown("Keryth");
  SetGender("male");
  SetTaughtSpheres( ({
    "magical",
    "magical evokation"
  }) );
  SetStat("intelligence", 60, 1);
  SetLevel(40);
  SetCurrency("senones", 900);
  SetSpellBook( ([
    "acid blast" : 100,
    "chain lightning" : 100,
    "channeling" : 100,
    "disintegrate" : 100,
    "enhanced aura" : 100,
    "energy wall" : 100
  ]) );
  SetShort("Hammat the Evoker");
  SetPlayerTitles( ([
    "newbie" : "the Evokation Student of Keryth",
    "mortal" : "the Determined Evoker of Keryth",
    "hm"     : "the Respected Evoker",
    "legend" : "the Expert of Evokation",
    "avatar" : "the Commander of Magical Energies"
  ]) );
  SetFreeEquip( ([
    STD_POLE + "staff" : 1
  ]) );
  SetLong("Hammat is a young evoker in charge of teaching those who want to "
          "learn the art of evokation.  Despite his youth, he is intelligent "
          "and looks rather strong.  His feline eyes denote wisdom and "
          "knowledge.");
  SetCombatAction(50, (: DoSomething :));
  SetInventory( ([
    "/std/weapon/pole/baton" : "wield baton",
    "/std/armour/pants/leggings" : "wear leggings"
  ]) );
  SetMorality(-100);
}

void DoSomething() {
  if ((GetMagicPoints() < (GetMaxMagicPoints()/6)) &&
    (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) &&
    (!random(3))) {
    eventForce("cast channeling");
    return;
  }
  
  if ((sizeof(GetMagicProtection()) < 2) ||
     ((!random(3)) && (sizeof(GetMagicProtection()) < 5))) {
    eventForce("cast " + (random(3) ? "energy wall" : "enhanced aura" ));
    return;
  }
  
  if (random(2)) {
    eventForce("cast " + (random(3) ? "disintegrate" : "chain lightning" ));
    return;
  }

  if ((!random(3)) &&
      (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) &&
      (sizeof(GetCurrentEnemy()->GetWielded()) != 0)) {
    eventForce("disarm");
    return;
  }

  if (random(2) && sizeof(GetCurrentEnemy()->GetWielded()) != 0) {
    eventForce("cast acid blast");
    return;
  }
}

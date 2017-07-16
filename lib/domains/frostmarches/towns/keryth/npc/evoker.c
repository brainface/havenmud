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
    "magical evokation",
    }) );
  SetStat("intelligence", 60, 1);
  SetLevel(40);
  SetCurrency("senones", 900);
  SetSpellBook( ([
    "paraylsis"  : 100,
    "fireball"   : 100,
    "channeling" : 100,
    "ice ball"   : 100,
    "sphere"     : 100,
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
  SetCombatAction(65, (: DoSomething :));
  SetInventory( ([
    "/std/weapon/pole/baton"     : "wield baton",
    "/std/armour/pants/leggings" : "wear leggings"
  ]) );
  SetMorality(-250);
  SetFirstCommands( ({
    "cast sphere",
    "cast sphere",
    "cast sphere",
    "cast sphere",
    }) );
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
    eventForce("cast sphere");
    return;
  }
  
  if (random(2)) {
    eventForce("cast " + (random(3) ? "ice ball" : "paralysis" ));
    return;
  }
  
  if (random(2)) {
    eventForce("cast fireball");
    return;
  }
  

  /*if ((!random(3)) &&
      (GetStaminaPoints() > (to_int(GetMaxStaminaPoints()/2))) &&
      (sizeof(GetCurrentEnemy()->GetWielded()) != 0)) {
    eventForce("disarm");
    return;
  }*/


}

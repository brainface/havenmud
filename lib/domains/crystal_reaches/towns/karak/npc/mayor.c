// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_MAYOR;

static void create() {
  mayor::create();
  SetKeyName("dealer");
  SetShort("Dealer, WarBoss of Karak");
  SetId( ({ "dealer", "warboss", "mayor", "orc"}) );
  SetLong(
    "This enormous creature before you looks like a one orc "
    "army. His massive frame is covered with muscle and scars "
    "as well as a healthly selection of armor and wargear. "
    "All petitions for citizenship are brought before him."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("fighter");
  SetLevel(60);
  SetTown("Karak");
  SetLocalCurrency("orcteef");
  SetTax(5);
  SetFriends( ({ "rommel" }) );
  SetInventory( ([ 
    KARAK_OBJ + "runea" : "wear armour", 
    KARAK_OBJ + "runes" : "wield sword in left hand",
    KARAK_OBJ + "axe"   : "wield axe in right hand",
  	]) );
  SetCombatAction(10, ({
  	"!disarm",
  	"!disorient",
  	}) );
   SetTownRanks( ({
    ({ "Snotling", "Snotling" }),
    ({ "Ork", "Ork" }),
    ({ "Big'un", "Big'un" }),
    ({ "Boss", "Boss" }),
    ({ "Big Boss", "Big Boss" }),
    ({ "WarBoss", "WarBoss" }),
    ({ "Warlord", "Warlord" }),
    }) );
}

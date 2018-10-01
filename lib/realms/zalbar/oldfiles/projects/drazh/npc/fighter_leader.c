// by Dahaka
// Aug 2004


#include <lib.h>
#include "../drazh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gnawk");
  SetShort("Gnawk, Captain of the Drazh Watch");
  SetId( ({"gnawk","skaven","watchman"}) );
  SetLong(
    "Gnawk is a large than normal skaven with dark brown fur. His "
    "large frame supports the muscles of a hulking warrior. He looks "
    "as if he could teach a thing or two to anyone willing to listen." 
    );
  SetRace("skaven");
  SetClass("fighter");
  SetLevel(55);
  SetMorality(-1900);
  SetGender("male");
  SetAction(5, ({
    "!speak Would you like to join the Watchman?",
    "!speak I teach those who wish to become Watchman of Drazh.",
    "!speak Defend Drazh against our enemies!",
    "!speak Enlist and make Drazh strong again.",
    }) );
  SetCombatAction(6, ({
    "!speak Fool!",
    "!speak I'll teach you a thing or two for sure.",
    "!yell We are under attack!",
    "!disorient",
    }) );
  SetCurrency("roni", random(900));
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Watchman Recruit of Drazh",
    "mortal" : "the Watchman of Drazh",
    "hm"     : "the Vile Watchman of Drazh",
    "legend" : "the Master of the Drazh Watch",
    "rogue"  : "the Scoundrel Senteniel of Drazh",
    "priest" : "the Infernal Soldier of Drazh",
       ]) );
  SetTown("Drazh");
  SetReligion("Soirin");
  SetInventory( ([
     V_OBJ + "scale_mail" : "wear armour",
     V_OBJ + "lpants"     : "wear pants",
     V_OBJ + "longsword"  : "wield sword",
     V_OBJ + "axe"        : "wield axe",
     ]) );
  SetFreeEquip( ([
     V_OBJ + "newbie_sword"   : 1,
     V_OBJ + "recruit_armour" : 1,
     V_OBJ + "newbie_axe"     : 1,
     ]) );
  }
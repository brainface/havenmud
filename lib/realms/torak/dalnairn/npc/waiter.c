// Dalnairn
// Aerelus
// edited for dalnairn recode
// torak@haven 2017

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("throk");    
  SetId( ({ "throk", "half-orc", "waiter", "dalnairn_person" }) );
  SetShort("Throk the waiter");
  SetLong(
    "Throk is a burly half-orc, veins popping out of their muscles. "
    "He has short unkempt black hair, black eyes and his dark green "
    "skin is lined with musculature. ", 
  );
  SetFriends("dalnairn_people");
  SetRace("half-orc");
  SetGender("male");
  SetClass("contemplator");
  SetLevel(75);
  SetReligion("Soirin");
  SetMorality(-150);
  SetCurrency("shards", 50);
  SetInventory( ([
    "/std/weapon/melee/brass_knuckles" : "wield knuckles",
  ]) );
  SetMenuItems( ([ 
    "boar steak"       : DAL_MEAL "boar_steak",
    "lobster tail"     : DAL_MEAL "lobster_tail",
    "monkey brain"     : DAL_MEAL "monkey_brain",
    "seagull soup"     : DAL_MEAL "seagull_soup",
    "tune steak"       : DAL_MEAL "tuna_steak",
    "truffle souffle"  : DAL_MEAL "truffle_souffle",
    "orange marmalade" : DAL_MEAL "orange_marmalade",
    "orange juice"     : DAL_MEAL "orange_juice",
    "orange shandy"    : DAL_MEAL "orange_shandy",
  ]) );
  SetLocalCurrency("shards");  
}

// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("jolich");  
  SetId( ({ "jolich", "captain", "dalnairn_people" }) );
  SetShort("Captain Jolich of the Dalnairn guard");
  SetLong(
    "Captain Jolich is the leader of the Dalnairn city guard. He is an "
    "arrogant man, and honestly believes he is superiour to everyone in the "
    "city. His constant smirk shows a small scar, presumably from battle, "
    "on his upper lip. He looks like he knows quite a lot about being a "
    "fighter."    
  );
  SetFriends("dalnairn_people");  
  SetRace("dwarf");
  SetGender("male");
  SetClass("fighter");
  SetLevel(80);
  SetReligion("Soirin");
  SetMorality(-200);
  SetCurrency("shards", random(100));
  SetInventory( ([
         DAL_OBJ + "guardarmour": "wear my suit",
         DAL_OBJ + "sword" : "wield my sword",
         DAL_OBJ + "boots" : "wear my boots",
  ]) ); 
  SetAction(5, ({
    "!speak Got what it takes to join the guard, little man?",
  }) );
  
  SetTown("Dalnairn");  
  SetFreeEquip( ([
    "/std/weapon/hack/hand-axe" : 1,
    "/std/weapon/slash/shortsword" : 1,
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Impotent",
    "mortal" : "the Undestinguished Watchman",
    "hm" : "the Member of the Dalnairn Guard",
    "legend" : "the Commendable Custodian",
    "avatar" : "the Obsidian Blade",
  ]) );
}
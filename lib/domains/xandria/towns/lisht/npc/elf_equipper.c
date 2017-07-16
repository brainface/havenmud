#include <lib.h>
#include <std.h>
#include "../lisht.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("jethro");
  SetGender("male");
  SetRace("elf");
  SetTown("Lisht");
  SetBaseLanguage("Alatherian");
  SetClass("merchant");
  SetLevel(15);
  SetCurrency("deben", 200);
  SetShort("Jethro the Middler");
  SetId( ({ "jethro", "middler" }) );
  SetLong(
    "Jethro the Middler received his nickname as someone who is willing to "
    "share equipment with the various slaves in Lisht. His generous personality "
    "has kept many a slave from being totally without ability to advance "
    "themselves. One could simply <ask jethro for help>"
    );
  SetLevelLimit(8);
  SetLimit(1);
  SetFreeEquipment( ([
    "club" : STD_WEAPON "newbie_club",
    "fishing pole" : STD_FISHING "pole",
    "knife" : STD_WEAPON "/knife/small_knife" ,
    ]) );
  SetAction(10, ({
    "!say Ask me for a club!",
    "!say Ask me for a fishing pole!",
    "!say Ask me for help!",
   }) );
}
  

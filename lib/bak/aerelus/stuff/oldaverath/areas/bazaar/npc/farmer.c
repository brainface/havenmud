/*  A Farming leader
    Coded by Kilik
 */
#include <lib.h>
#include <std.h>
#include "../bazaar.h"
inherit LIB_LEADER;
static void create() {
  leader::create();
  SetKeyName("buma");
  SetId( ({ "buma", "buma faner", "farmer" }) );
  SetRace("human");
  SetGender("male");
  SetClass("merchant");
  SetLevel(30);
  SetTown("Averath");
  SetShort("Buma Faner the farmer");
  SetLong("Buma is a short, and very well built farmer,  with "
          "large hands and a slight limp. He has blonde hair and "
          "well tanned skin.");
  SetPlayerTitles( ([
    "newbie" : "the Farmhand",
    "mortal" : "the Field Runner",
    "hm" : "the Planter of Lands",
    "legend" : "the Harvester",
    "avatar" : "the Farmsteader",
  ]) );
  SetFreeEquipment( ([
    BAZAAR_OBJ + "shovel" : 1,
    STD_FISH   "pole" : 1,
  ]) );
}

#include <lib.h>
#include <std.h>
#include "../averath.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Edmond Brunel");
  SetId( ({ "edmond", "brunel", "farmer", "averath_person" }) );
  SetShort("Edmond Brunel the Farmer");
  SetLong(
    "Edmond is a short, and very well built farmer, with large hands and a "
    "slight limp. He has blonde hair and well tanned skin. Years of working "
    "the land has given him great insight into farming. He seems like he "
    "could probably teach a few methods."
 		);
  
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Avera");
  SetReligion("Aetarin");  
  
  SetMorality(100);
  SetClass("merchant");
  SetLevel(30);
  AddCurrency("ducats", random(100)+25);
  
  SetPlayerTitles( ([
    "newbie" : "the Farmhand",
    "mortal" : "the Field Runner",
    "hm"     : "the Planter of Lands",
    "legend" : "the Harvester",
    "avatar" : "the Farmsteader",
  ]) );
  
  SetFreeEquipment( ([
    AVERATH_OBJ "shovel" : 1,
    STD_FISH    "pole" : 1,
  ]) );
}

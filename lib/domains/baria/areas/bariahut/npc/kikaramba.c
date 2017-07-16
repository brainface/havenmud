//Alex@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../area.h"
inherit LIB_SENTIENT;

static void create(){
  sentient::create();
  SetKeyName("kikaramba");
  SetShort("Kikaramba the Demented");
  SetId( ({ "man", "kikaramba"}) );
  SetAdjectives( ({ "old", "demented"}) );
  SetRace("human");
  SetBaseLanguage("Barian");
  SetClass("fighter");
  SetLevel(20);
  SetLong(
    "Kikaramba is the once-proud father of Mlima. Ku-choka has pushed "
    "him into the cellar, and now he lives out the rest of his days"
    "complaining bitterly and drinking homemade wine. Although elderly,  "
    "he is quite senile and may just prove a fearsome opponent.");
  SetLimit(1);
  SetGender("male");
  SetCurrency("chits", 200);
  SetInventory( ([
    AREA_OBJ "smock" : "wear smock",
    AREA_OBJ "bhat"  : "wear hat",
    AREA_OBJ "kumquat_wine" : 1,
  ]) );
  SetAction(10, ({
    "!say When I was your age, we didn't HAVE a jungle!",
    "Kikaramba drools a little orange liquid down his chest.",
    "Kikaramba shuffles aimlessly.",
    "!say Nobody cares about me.",
  }) );
  SetSmell( "He smells like a sweaty drunk. Yuck." );
  SetMorality(-50);
  SetWander(1);
}
    

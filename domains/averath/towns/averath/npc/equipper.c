#include <lib.h>
#include <std.h>
#include "../averath.h"
inherit LIB_EQUIPPER;

static void create() {
   ::create();
   SetKeyName("Rosette Dufour");
   SetId( ({ "rosette", "defour", "helpful", "averath_person" }) );
   SetShort("Rosette Dufour the Helpful");   
   SetLong(
     "Rosette has been placed in charge of distributing basic clothing and "
     "other simple items to the citizens, should they require them. She seems "
     "very friendly with a pleasant smile, ready to offer aid to anyone who "
     "asks her."     
   );           
   
   SetRace("human");
   SetGender("female");
   SetBaseLanguage("Avera");
   SetReligion("Aetarin");   
   
   SetMorality(125);
   SetClass("rogue");
   SetLevel(20);   
   AddCurrency("ducats", random(100)+10);
   
   SetFreeEquipment( ([
     "mace"  : AVERATH_OBJ + "newbie_mace",
     "sword" : AVERATH_OBJ + "shortsword",
     "knife" : AVERATH_OBJ + "newbie_knife",
     "shirt" : AVERATH_OBJ + "drab_shirt",
     "pants" : AVERATH_OBJ + "drab_pants",
     "staff" : STD_WEAPON    "staff",
     "coat"  : STD_CLOTHING  "coat",
     ]) );
   SetLevelLimit(10);
   
   SetAction(1, ({ "!say Do you need anything? Just ask, I might be able "
    "to help!" }) );   
}

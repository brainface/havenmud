#include <lib.h>
#include <std.h>
#include "../parva.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Alejandro de Sloop");
  SetLimit(1);
  SetShort("Alejandro de Sloop the Equipper of Swabbies");
  SetId( ({ "alejandro", "sloop", "equipper" }) );
  SetAdjectives( ({ "alejandro", "equipper", "de" }) );
  SetRace("human");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "epee"  : STD_PIERCE   "epee",
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "fishing pole"  : PARVA_OBJ "newbie_pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    ]) );
  SetLong("Alejandro de Sloop is a patient, ginger-haired man of middle age. "
    "He attends closely to the racks and shelves with one beady eye while "
    "seeking to equip all those citizens who come to him."
    );
  SetGender("male");
  SetClass("fighter");
  SetLevel(6);
  SetMorality(150);
  SetAction(2, ({
    "!speak Mayhaps you need my assistance?",
    "!speak Mayhaps I can help you?",
    "!speak Ask me, and I could help you.",
    }) );
}

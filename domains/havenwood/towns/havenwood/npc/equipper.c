#include <lib.h>
#include <std.h>
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Laurana");
  SetLimit(1);
  SetShort("Laurana the Friendly");
  SetId( ({ "laurana", }) );
  SetAdjectives( ({ "friendly" }) );
  SetRace("wild-elf");
  SetTown("Havenwood");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "shirt",
    "shoes" : STD_CLOTHING "shoes",
    "pants" : STD_CLOTHING "pants",
    "coat"  : STD_CLOTHING "coat",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    "map"   : STD_OBJ "havenwoodmap",
    ]) );
  SetLong(
    "Laurana is famous in the Havenwood for her open, friendly gestures "
    "and her stockpile of the things the citizens need most. She gives "
    "and expects no payment for her goods. All she requires is that those "
    "in need <ask laurana for help>."
    );
  SetGender("female");
  SetClass("ranger");
  SetLevel(6);
  SetAction(2, ({
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}

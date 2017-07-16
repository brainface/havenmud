#include <lib.h>
#include <std.h>
#include "../underland.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Falcorok");
  SetRace("gnome");
  SetGender("male");
  SetShort("Falcorok the Equipper");
  SetId( ({ "falcorok", "equipper" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Falcorok is an equipper for the young gnomes of the Underland. "
    "Asking him for help is a fine way to get some free stuff."
  );
  SetClass("merchant");
  SetLevel(2);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "small_shirt",
    "shoes" : STD_CLOTHING "small_shoes",
    "pants" : STD_CLOTHING "small_pants",
    "coat"  : STD_CLOTHING "small_coat",
    "fishing pole"  : STD_FISH "pole",
    "sword" : STD_WEAPON "dented_sword",
    "club"  : STD_WEAPON "newbie_club",
    "knife" : STD_WEAPON "small_knife",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    "staff" : STD_WEAPON "staff",
    "epee"  : STD_WEAPON "pierce/epee",
    ]) );
}

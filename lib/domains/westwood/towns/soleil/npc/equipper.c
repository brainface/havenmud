
#include <lib.h>
#include <std.h>
#include "../soleil.h"
inherit LIB_EQUIPPER;

static void create() {
  ::create();
  SetKeyName("Wiccket");
  SetLimit(1);
  SetShort("Wiccket the Daydreamer");
  SetId( ({ "wiccket", "daydreamer", "equipper" }) );
  SetAdjectives( ({ "equipper" }) );
  SetRace("muezzin");
  SetLevelLimit(10);
  SetFreeEquipment( ([
    "shirt" : STD_CLOTHING "small_shirt",
    "shoes" : STD_CLOTHING "small_shoes",
    "pants" : STD_CLOTHING "small_pants",
    "coat"  : STD_CLOTHING "small_coat",
    "knife" : STD_KNIFE "hunting_knife",
    "drum"  : STD_INSTRUMENTS "drum",
    "epee"  : STD_PIERCE "epee",
    "fishing pole" : STD_FISHING "pole",
    "sword" : S_OBJ + "sword_training",
    "club"  : STD_WEAPON "newbie_club",
    "bow"   : STD_WEAPON "projectile/bow_long_newbie",
    "staff" : S_OBJ + "pole_short_newbie",
    "iron fist" : S_OBJ + "ironfist_newbie",
    ]) );
  SetLong("Wiccket is a short muezzin with thin nappy dark brown "
          "fur that covers his entire body. His dark brown eyes "
          "hide very well in with his fur. Wiccket looks preoccupied "
          "but is always willing to help a young muezzin get started "
          "on the the right foot. ");
  SetGender("male");
  SetClass("fighter");
  SetReligion("Eclat");
  SetMorality(1000);
  SetLevel(6);
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(2, ({
    "!speak Perhaps you need my assistance?",
    "!speak Perhaps I can help you?",
    "!speak Ask me, and I will help you.",
    }) );
}

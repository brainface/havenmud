// by Zalbar
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("gazkr");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"gazkr","stormvermin","councilman","skaven"}) );
  SetAdjectives( ({"warlord","lord","commander"}) );
  SetShort("Warlord Gazkr, Stormvermin Commander");
  SetLong( 
   "This large well built skaven has midnight black fur covering his "
   "body except for a white patch in the shape of a skaven claw on "
   "the side of his head. Gazkr tells all that is where Melchezidek has "
   "blessed him. As Commander of the Stormvermin, he tries to recruit "
   "the young skaven of Drazh into his army."
   );
  SetMorality(-2000);
  SetGender("male");
  SetRace("skaven");
  SetClass("cavalier");
  SetLevel(125);
  SetCurrency("roni",random(3000));
  SetInventory( ([
     V_OBJ + "scale_armour" : 
      "wear robe on torso and left arm and left leg and right arm and right leg",
     V_OBJ + "wall_shield"  : "wear shield on left arm and left claw", 
     V_OBJ + "longsword"    : "wield sword",
     ]) );
  SetPlayerTitles( ([
    "newbie"      : "the Stormvermin Recruit of Drazh",
    "mortal"      : "the Stormvermin of Drazh",
    "hm"          : "the Elite Stormvermin of Drazh",
    "legend"      : "the Stormvermin Warlord of Drazh",
    "necromancer" : "the PlagueLord",
  ]) );
  SetFreeEquip( ([
     V_OBJ + "newbie_tuck"  : 1,
     V_OBJ + "scale_mail"   : 1,
     V_OBJ + "newbie_sword" : 1,
     ]) );
  SetFriends( ({
     "skaven","councilman","watchman"
   }) );
  SetAction(1, ({
   "!say Join the armies of Drazh!",
   "!say We need to strengthen our numbers.",
   "!say Melchezidek has blessed me!.",
   }) );
  SetCombatAction(10, ({
     "!yell Enemies! Die!",
     "!growl violently",
     "!say you will die!",
   }) );
}

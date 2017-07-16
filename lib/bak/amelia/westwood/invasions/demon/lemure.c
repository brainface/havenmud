/*  A bottom feeder in the chain of devils */
#include <lib.h>
#include <armour_types.h>
inherit LIB_INVADER;

static void create() {
  invader::create();
  SetKeyName("lemure");
  SetShort("a slimy lemure");
  SetId( ({ "lemure", "devil" }) );
  SetAdjectives( ({ "slimy" }) );
  SetLong("This is a lemure, one of the damned souls stuck for "
          "all eternity in the Lower Planes. Its pitiful body "
          "has only a slimy, muck-like lower half with two "
          "protrusions that pass as arms and a half formed head with "
          "large and unclosing eyes of solid black.");
  SetRace("lemure",1);
  AddLimb("torso", 0, 1);
  AddLimb("right arm", "torso", 2);
  AddLimb("left arm", "torso", 2);
  AddLimb("head", "torso", 1);
  AddLimb("right hand", "right arm", 4, A_WEAPON);
  AddLimb("left hand", "left arm", 4, A_WEAPON);
  SetStat("strength", 15, 2);
  SetStat("durability", 15, 2);
  SetStat("agility", 2, 4);
  SetStat("coordination", 2, 4);
  SetClass("valkyr");
  SetLevel(10);
  SetFriends( ({"barbed devil","bane devil","black abashai",
    "lemure","maralith","pit fiend"}) );
  SetAction(50, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
  }) );
  }

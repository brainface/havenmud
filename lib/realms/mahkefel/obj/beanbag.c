// Mahkefel 2010
// guess what this does.
#include <lib.h>

inherit LIB_ITEM;
inherit LIB_SIT;

static void create() {
  ::create();
  SetShort("a super comfy beanbag chair");
  SetKeyName("chair");
  SetId( ({"beanbag", "chair" }) );
  SetAdjectives( ({ "super","comfy","beanbag" }) );
  SetLong(
    "This is a super awesome comfy beanbag chair stuffed with the finest of "
    "comfy spider corpses killed in the most excruciated and certain ways. "
    "But you'll never tell that because it's actually like I don't know made "
    "of good beanbag stuff whatever that is fuckit it doesn't leak spiders "
    "you just get to recline on their corpses because ahahahahaah that's not "
    "weird."
  );
  SetMass(100);
  SetDamagePoints(250);

  //SetWeaponClass(5); // It's basically a pillow
}


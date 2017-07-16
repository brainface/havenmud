/*  Hand Axe, Koboldish - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("koboldish hand axe");
  SetId( ({ "koboldish hand axe", "hand axe", "axe" }) );
  SetAdjectives( ({ "koboldish", "bloody", "unbalanced", "unwieldy" }) );
  SetShort("a koboldish hand axe");

  SetLong("This is a koboldish hand axe, and a bad imitation of a hand axe at "
          "that.  It is said that a kobold chief made the hand axe and used "
          "it to scalp his victims, which would explain some of the blood.  "
          "Also, because hand axe's head is badly formed and the handle is "
          "slightly crooked the weapon is very unbalanced and unwieldy.");

  SetMass(100);
  SetValue(80);
  SetDamagePoints(400);

  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal", "wood" }) );
  SetRepairSkills( ([ "weapon smithing" : 4,
                      "wood working" : 1,
                      "metal working" : 5,
  ]) );
  SetRepairDifficulty(7);

  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(4);
}



// Torak 2012
// LARGE cloth lacks any kind of warmth armour
// poof, warm large armour
// balance based on mastershozoku.c @ /d/t/a/ninja_tower/obj/store/

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("suit");
  SetShort("a suit of ogre-sized under armour");
  SetId( ({ "suit", "armour" }) );
  SetAdjectives( ({ "ogre", "ogre-sized", "sized", "under", "large" }) );
  SetLong(
    "This ogre-sized suit of under armour is large and "
    "padded for cushioning. It is made from soft fabrics. "
  );
  SetArmourType(A_BODY_ARMOUR);
  SetMass(120);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_LARGE);
  SetValue(1000);
  SetDamagePoints(4500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(30);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
    "armour smithing" : 10,
    "textile working" : 10,
  ]) );   
  SetRepairDifficulty(20);
}

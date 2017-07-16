#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("zills");
  SetShort("a set of golden zills");
  SetId( ({ "zills", "bard_instrument" }) );
  SetAdjectives( ({ "golden" }) );
  SetLong(
    "Zills are small metallic instruments, similiar to castanets used by "
    "flamenco dancers. They are used to keep musical time with belly-"
    "dancing."
    );
  SetDamagePoints(500);
  SetValue(50);
  SetMass(4);
  SetHands(2);
  SetWeaponType("melee");
  SetClass(1);
  SetMaterials( ({ "metal", "natural" }) );
  SetRepairDifficulty(1);
}

 
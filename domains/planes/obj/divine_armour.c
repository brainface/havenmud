/*  Armour for the Haven Town Guard */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int BonusCheck();

static void create() {
  ::create();
  SetKeyName("divine armour");
  SetArmourType(A_ARMOUR);
  SetShort("a suit of pure white platemail");
  SetLong(
    "This pure white armour is a source of defense for the Paladins of the Upper Planes."
    );
  SetValue(4500);
  SetMass(200);
  SetWarmth(0);
  SetDamagePoints(2000);
  SetId( ({ "suit", "platemail", "armour" }) );
  SetAdjectives( ({ "pure", "white", "suit", "of", "divine" }) );
  SetMaterials( ({ "mithril" }) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetProtectionBonus(MAGIC, 20);
  SetProtectionBonus(SLASH, 15);
  SetProtectionBonus(BLUNT, 15);
  SetSize(SIZE_LARGE);
}


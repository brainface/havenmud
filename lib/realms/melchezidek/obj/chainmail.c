/*  Chainmail for small things */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int CheckGuard();
int BonusCheck();

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of battle-scarred and rusted chainmail");
  SetLong("This chainmail has seen better days. Scars and broken links "
          "hint at a long life of service and terrible battles. Rust "
	  "has taken hold of many of the individual links and is "
	  "particularly visible around the various battle scars."); 
  SetValue(4500);
  SetSize(SIZE_SMALL);
  SetMass(75);
  SetWarmth(0);
  SetDamagePoints(2000);
  SetId( ({ "suit", "chainmail" }) );
  SetAdjectives( ({ "rusted", "scarred", "battle-scarred" }) );
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(40);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetProtectionBonus(MAGIC, 20);
  SetProtectionBonus(SLASH, 15);
  SetProtectionBonus(BLUNT, 15);
  SetProperty("magic", "Ancient magics imbue this chainmail with slightly "
		       "greater protections than normal mundane chainmail "
		       "would while being lighter than normal.");
}

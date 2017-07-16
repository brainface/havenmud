#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("necklace");
  SetId(( { "necklace", "amulet" } ));
  SetShort("a necklace");
  SetLong("Along the chain of this necklace is engraved the words, \"To "
          "Alana, from Jord with love.\"");
  SetMass(50);
  SetMaterial("mithril");
  SetRepairDifficulty(20);
  SetWarmth(0);
  SetValue(60);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(140);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}


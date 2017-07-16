#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("obsidian breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "obsidian" }) );
  SetShort("an obsidian breastplate");
  SetLong(
    "This breastplate is carved from pitch black obsidian. Two plates rounded"
    " like a beetle shell protect the front and back like a carapace,"
    " while overlapping cylindrical chunks of the rock protect the arms. A"
    " coarse fabric lines the interior and secures the armour together."
  );
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_ARMOUR);
  SetDamagePoints(3500);
  SetMass(400);
  SetMaterial( ({ "natural" }) );
  SetProperty("history",
    "This armour was crafted by some fell smith of the"
    " plane of fire for the elementals that guard that"
    " realm."
  );
  SetSize(SIZE_MEDIUM);
  SetValue(400);
  SetVendorType(VT_ARMOUR);
  SetWarmth(5);
}


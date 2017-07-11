/*
 * A heavy plate suit for pit fiends
 *
 * It's just a full body heavy plate armour
 * good for horrors, non-conjurer orcs & half-orcs.
 */
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("suit");
  SetId(( {"suit", "platemail"} ));
  SetShort("an adamantine suit of platemail");
  SetAdjectives( ({"adamantine","suit","of","platemail"}) );
  SetLong(
    "Made from some dense black metal, this suit of platemail consists of"
    " large flat slabs of metal protecting the chest, arms, and thighs."
    " Smaller overlapping plates cover the stomach and joints, providing"
    " some flexibility without sacrificing defense."
  );
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetDamagePoints(10000);
  SetMass(1000);
  SetMaterial("metal");
  SetProperty("history",
    "Once used to armour the forces of Order, most of these suits of"
    " adamantine armour were lost in a fierce battle on the lower planes"
    " during the chaos of the godswar; the method of its forging is"
    " long lost. It is rumored they are now used by the vicious pit"
    " fiends that patrol that realm."
  );
  SetRepairDifficulty(200);
  SetSize(SIZE_LARGE);
  SetValue(20000);
  SetVendorType(VT_ARMOUR);
  SetWarmth(0);
  SetWear("The heavy plate suit is unbearably heavy.");
}

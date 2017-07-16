/*  Rags - Kobold - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h> 
#include <size.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;
inherit LIB_SMELL;

static void create() {
  armour::create();
  SetKeyName("rags");
  SetId( ({ "orange rags", "rags" }) );
  SetAdjectives( ({ "orange" }) );
  SetShort("the orange rags");
  SetLong(
    "These are the rags of kobolds. One can tell this from a few "
    "distinct properties that these rags have. First of all, they are "
    "orange - a color that kobolds are known to favor. Also, one can "
    "tell just from the distinct smell that these were worn by a "
    "kobold. hese rags do little to protect one from the elements."
  );
  SetSmell("They smell of wet dog and stagnant water.");
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(20);
  SetValue(0);
  SetDamagePoints(75);
  SetSize(SIZE_SMALL);
  SetMaterial("textile");
  SetWarmth(6);
}
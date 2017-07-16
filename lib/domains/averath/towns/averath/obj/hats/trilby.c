#include <armour_types.h>
#include <vendor_types.h>
#include <lib.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("trilby");
  SetShort("a tweed trilby");
  SetId( ({ "trilby" }) );
  SetAdjectives( ({ "tweed" }) );
  SetLong("This hat, made from tweed, has a narrow brim and a deeply-indented "
  				"crown. It looks rather fashionable, and was obviously hand crafted "
  				"with great care.");  
  SetVendorType(VT_CLOTHING);
  SetMaterial("textile");
  SetRepairDifficulty(10);
  SetArmourType(A_HELMET);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(40);
  SetValue(400);
  SetDamagePoints(250);
  SetSize(SIZE_MEDIUM);
  }

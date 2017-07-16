#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cuirass");
  SetId(( {"cuirass"} ));
  SetShort("a studded leather cuirass");
  SetAdjectives( ({"studded","leather",}) );
  SetLong(
    "This leather cuirass is crafted to provide the most protection "
    "possible without impeding movement or producing a racket of metal. "
    "Long steel plates riveted to the underside "
    "of dyed black leather, while an inner layer of canvas pads the wearer "
    "from grinding plates and dampen noise. "
    "Visible steel plates protect the shoulders and elbows, while the "
    "inner joints are relatively unprotected to provide greater flexibility. "
  );
  SetMass(325);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"leather","metal"}) );
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(3750);
  SetDamagePoints(4000);
  SetArmourType(A_ARMOUR);
  SetWear("The metal weights provide a comforting weight along your torso.");
}


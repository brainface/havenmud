#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("steel armour");
  SetId(( {"armour", "suit"} ));
  SetShort("a suit of fine steel armour");
  SetAdjectives( ({"steel", "fine", "suit of"}) );  
  SetLong(
    "This sturdy suit of armour is crafted of tough steel. The plate covering "
    "the left shoulder of the wearer has a small carving of an anvil, "
    "signifying that this suit was crafted by Kelan, perhaps the finest smith "
    "in the Southern Coast region. The suit covers most of the body, leaving "
    "very little exposed to danger. It is lined with fine silk, providing "
    "comfort to the wearer aswell as superiour protection."    
  );   
  SetMass(350);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("metal");
  SetWarmth(4);
  SetRepairDifficulty(70);
  SetValue(4000);
  SetDamagePoints(4000);
  SetArmourType(A_BODY_ARMOUR);
  SetRestrictLimbs( ({ "right arm", "left arm", "torso" }) );
  SetWear("The suit of steel armour feels very comfortable.");
}
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetId(( {"helmet" } ));
  SetShort("a glimmering mithril helmet");
  SetAdjectives( ({"mithril", "glimmering"}) );
  SetLong(
    "This masterwork helmet is woven of mithril plates that have been "
    "loricated on a mithril chainmail coif to offer a semi-rigid head "
    "protection that is rivaled by few. The inner lining is layers of "
    "a fine pink silk covering stout leather. The nose guard is of a "
    "pure yellow gold which wraps around the eyes and follows the cheeks "
    "and around the chin to the back of the helmet giving the whole piece "
    "a stark border to the silver colored mithril plating. A plume of "
    "emeral green feathers adorns the top."
  );     
  SetMass(115);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(90);
  SetValue(20000);
  SetDamagePoints(50000);
  SetArmourType(A_HELMET);  
  SetWear("The helmet seems to conform to your head.");
}

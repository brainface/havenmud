#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("frost covered platemail");
  SetId(( {"armour", "platemail", "suit"} ));
  SetShort("an ancient suit of frost covered platemail");
  SetAdjectives( ({"ancient", "suit", "of", "frost", "covered"}) );
  SetLong(
    "Crafted for a giant, and by the looks of the scratches and dents long "
    "ago, mostly still interlocking plates of mithril coated in deep layers "
    "of ice protect the chest and limbs of whoever might be large enough "
    "to wear this armour. The joints are guarded by a somewhat less rigid "
    "snow-covered chains that probably were once padded in leather. It's "
    "difficult to say if the ice was some magical part of the forging "
    "process or simply ages of accumulation that have become impossible "
    "to remove."
  );
  SetMass(1000);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_GIANT);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(70);
  SetValue(25000);
  SetDamagePoints(25000);
  SetArmourType(A_BODY_ARMOUR);
  SetWear("The suit of frozen plate is approximately as comfortable as wearing an igloo.");

  SetProperty("history",
    "Definitely forged of mithril, but you oddly can't determine anything of the history. "
    "It's almost as if it were made before recorded tales."
  );
  SetProperty("magic",
    "It seems some really relatively minor enchantment is at work here, preventing the ice "
    "from completely melting or locking the joints enough to prevent delicate spellcasting."
  );
  }


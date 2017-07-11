/*
 * mahkefel 3/10
 * a pretty good bow
 * for angel things
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("mithril bow");
  SetShort("a graceful mithril bow");
  SetLong(
    "This elegantly crafted mithril bow has a reverse "
    "curve on both limbs, to reduce the strain of the "
    "pull. Verses extolling the name and power of Duuk "
    "are scribed along the limbs. The string is fine "
    "tallow, and capable of exerting an impressive amount "
    "of force when used."
  );
  SetId( ({"mithril bow","bow"}) );
  SetAdjectives("mithril","graceful");
  
  SetClass(30);
  SetDamagePoints(4000);
  SetDamageType(HEAT);
  SetHands(2);
  SetMass(45);
  SetMaterial("mithril");
  SetProperty("history",
    "This bow was crafted by a great elven mage before "
    "the godswar. She made many of them, of such quality "
    "they were used to arm the other planar servants of "
    "her god."
  );
  SetProperty("mage",
    "This weapon has been enchanted to imbue its arrows "
    "with flame."
  );
  SetRepairDifficulty(85);
  SetValue(1200);
  SetVendorType(VT_WEAPON);
  SetWeaponType("projectile");
  SetWield(
    "An arrow of flame forms as you draw the bowstring."
  );
}


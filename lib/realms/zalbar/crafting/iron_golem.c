#include <lib.h>
#include <vendor_types.h>
#include <loot.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("iron_golem");
  SetShort("an iron golem body");
  SetId( ({ "iron_golem", "body", "golem", "golem_body" }) );
  SetAdjectives( ({ "iron" }) );
  SetLong(
    "A large eight foot long lifeless humanoid body made of black iron "
	"covered in runes. The head of this body features two fiery diamonds "
	"for the eyes of the golem. ");
  SetMass(64000);
  SetValue(10000);
  SetDamagePoints(20000);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_MAGIC);
}
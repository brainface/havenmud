#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a mithril greatsword");
  SetLong("The finely crafted mithril blade of this "
    "sword gleams in the light.");
  SetId( ({"sword", "greatsword","mithril","mithril greatsword",
    "great"}) );
  SetClass(30);
  SetDamagePoints(3000);
  SetValue(4000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(600);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"mithril"}) );
  SetHands(2);
  SetMaterial("mithril");
  SetRepairSkills( ([ 
  	"weapon smithing" : 20,
    "mithril working" : 20 ]) );
  SetRepairDifficulty(25);
 }

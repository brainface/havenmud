#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() 
{
  item::create();
  SetKeyName("dagger");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 15,
   "weapon smithing" : 10,
     ]) );
  SetShort("a small dagger");
  SetAdjectives( ({ "small" }) );
  SetId( ({ "dagger", "small dagger" }) );
  SetLong("This is a small dagger not much larger "
    "than the palm of a human hand.  It is made of "
    "a fine steel and very well crafted.  The blade"
    " has a full tang running through to the end of the "
    "pommel and ending in a small sphere, counter-balancing "
    "the weight of the dagger.  The handguard is "
    "leather wrapped with a single silver wire "
    "wrapped to hold it into place.");
  SetClass(24);
  SetDamagePoints(1800);
  SetValue(3000);
  SetMass(150);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetProperty("magic", "This dagger seems to be able to draw "
    "energy from opponents.");
}

int eventStrike(object ob) 
{
  int amount = random(15);
  if (amount > 10) 
  {
    ob->AddStaminaPoints(-amount);
    environment()->AddStaminaPoints(amount);
    message("weapon", "%^BLUE%^The dagger seems to pulse as it "
      "hits.%^RESET%^",environment(environment()));
  }
  return item::eventStrike(ob);
}

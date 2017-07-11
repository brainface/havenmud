#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("runed bow");
  SetId( ({ "bow" }) );
  SetAdjectives( ({ "runed" }) );
  SetShort("a runed bow");
  SetLong("This bow is very basic except for"
          " the handle being adorned with ancient"
          " Tai runes. It is a standard bow of"
          " about four feet in height.");
  SetHands(1);
  SetClass(12);
  SetWeaponType("projectile");
  SetDamageType(PIERCE | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(160);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "wood working" : 1,
    "weapon smithing" : 1,
     ]) );
  SetProperty("magic", "This bow has been empowered with"
              " the ability to inflict greater damage on undead"
              " foes.");
 }

int eventStrike(object who) {
  int nolive = who->GetUndead();
  int amount = random(25);

  if (nolive == 1) {
      message("action", "Smoke rises from the wound created by " 
      + environment()->GetCapName() + "'s bow.", 
      environment(environment()) );
      return (item::eventStrike(who) + amount);
   
  }
      return (item::eventStrike(who));
}

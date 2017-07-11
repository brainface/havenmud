#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("runed katana");
  SetId( ({ "katana" }) );
  SetAdjectives( ({ "runed" }) );
  SetShort("a runed katana");
  SetLong("This katana is very basic except for"
          " the handle being adorned with ancient"
          " Tai runes. It is a medium sized single"
          " edged sword.");
  SetHands(1);
  SetClass(12);
  SetWeaponType("slash");
  SetDamageType(SLASH | MAGIC);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(160);
  SetMass(200);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
     ]) );
  SetProperty("magic", "This katana has been empowered with"
              " the ability to inflict greater damage on undead"
              " foes.");
 }

int eventStrike(object who) {
  int nolive = who->GetUndead();
  int amount = random(25);

  if (nolive == 1) {
      message("action", "Smoke rises from the wound created by " 
      + environment()->GetCapName() + "'s katana.", 
      environment(environment()) );
      return (item::eventStrike(who) + amount);
   
  }
      return (item::eventStrike(who));
}


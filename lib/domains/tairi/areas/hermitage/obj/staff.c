#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("runed staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "runed" }) );
  SetShort("a runed staff");
  SetLong("This is a long staff made of a dark wood."
          " Ancient Tairi runes have been enscribed from the"
          " ends of the staff to the leather grip in"
          " the middle."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT | MAGIC);
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
  SetProperty("magic", "This staff has been empowered with"
              " the ability to inflict greater damage on undead"
              " foes.");
 }


int eventStrike(object who) {
  int nolive = who->GetUndead();
  int amount = random(25);

  if (nolive == 1) {
      message("action", "Smoke rises from the wound created by " 
      + environment()->GetCapName() + "'s staff", 
      environment(environment()) );
      return (item::eventStrike(who) + amount);
   
  }
      return (item::eventStrike(who));
}


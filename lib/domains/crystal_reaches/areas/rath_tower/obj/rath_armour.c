/*  Rath Khan's breastplate from hell, etc */
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("ancient breastplate");
  SetShort("an ancient, rune enscripted breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "ancient", "rune enscripted", "enscripted" }) );
  SetDamagePoints(3000);
  SetMaterial( ({  "mithril" }) );
  SetRepairDifficulty(60);
  SetWarmth(0);
  SetValue(8000);
  SetArmourClass(ARMOUR_PLATE);
  SetProperty("laoise_flag", 1);
  SetMass(500);
  SetArmourType(A_ARMOUR);
  SetLong("This ancient breastplate has seen its share of action. It appears "
          "have been enscribed with runes against various forms of magic.");
  SetRead( ({ "runes", "rune", "enscription" }), "The runes are unreadable.");
  // SetProtection(BLUNT, 100);
  // SetProtection(PIERCE, 100);
  // SetProtection(SLASH, 100);
  // SetProtection(HEAT, 100);
  // SetProtection(COLD, 100);
  // SetProtection(ACID, 100);
  SetSize(SIZE_MEDIUM);
}

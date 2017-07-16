/*
 * Conjured ARmour for the frost armour spell
 * frost armour spell declared armour type, class adjectives blahblah
 * this file only contains functions and magic id property

 */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("frost armour");
  // will be overridden
  SetShort("a bit of frost");
  debug("made a new armour piece");
  SetLong("A thick coating of frost and ice. It seems unnaturally flexible "
    "for the material involved, yet it gathers and hardens when struck.");

  SetId( ({ "frost_armour" }) );

  //SetAdjectives( ({ "dragon", "dragonscale", "large", "scale" }) );
  //SetArmourClass(ARMOUR_NATURAL);
  //SetArmourType(A_SHIELD);
  //SetDamagePoints(1500);
  SetMass(500);
  SetMaterial( ({ "natural" }) );
  SetProperty("history",
  "This smells like necromancy, and recent at that. While moderately "
  "uncomfortable it's probably not harmful, nor worth anything.");
  SetProperty("magic",
  "Magically forged by a necromancer directly upon the skin of the wearer, "
  "this conjured armour will face once removed. It will resist frost and "
  "fear fire."
  );
  SetProtectionBonus(COLD,5);
  SetRepairDifficulty(10);
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  // MaxDamagePoints, DamagePoints?
  AddSave( ({"Size" }) );
  
}



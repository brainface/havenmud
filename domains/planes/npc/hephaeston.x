/* A fire elemental for the fire plane with a special attack */
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;


static void create() {
  npc::create();
  SetKeyName("Lord Hephaeston");
  SetId( ({ "lord", "hephaeston", "elemental" }) );
  SetAdjectives( ({ "fire", "lord", "elemental" }) );
  SetShort("Hephaeston the Lord of Elemental Fire");
  SetLong(
    "Hephaeston is the Lord of Elemental Fire. His burning visage is enough to cause terror in "
    "most mortals. His anger is legendary, and his power over the plane of fire unchallenged."
    );
  SetGender("male");
  SetRace("elemental");
  SetClass("evoker");
  SetSkill("fire magic", 1, 1);
  SetLevel(300);
  SetFearType("fiery terror");
  SetResistLevel(220);
  SetFearLength(15);
  SetEncounter(100);
  SetMeleeAttackString("flaming hand");
  SetResistance(MAGIC, "high");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "high");
  SetMeleeDamageType(HEAT);
  SetLimit(1);
  SetSpellBook( ([
    "wards of light" : 100,
    "flamestrike"    : 100,
    "fireburst"      : 100,
    ]) );
  SetCombatAction(85, ({
    "!cast fireburst", 
    "!cast wards of light",
    "!cast flamestrike",
  }) );
  SetFirstCommands( ({
    "cast wards of light",
    "cast wards of light",
    "cast wards of light",
  }) );
}

void init() {
  npc::init();
  fear::init();
}


void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wards of light");
  }
}
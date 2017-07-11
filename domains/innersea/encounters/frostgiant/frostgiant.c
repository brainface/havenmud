/*  A pit fiend */
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <domains.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("frost giant");
  SetId( ({ "giant" }) );
  SetAdjectives( ({ "immense","lumbering","frost" }) );
  SetGender("male");
  SetShort("an immense lumbering frost giant");
  SetLong("A massive titan carves a slow and onerous path through "
    "the endless ice, seemingly oblivious to the layers of frost "
    "and snow accumulating against his giant frame. Watching closely, "
    "he doesn't appear to be breathing, and his grey cloudy eyes "
    "look like they have not held life in a very long time.");
  SetRace("giant");

  SetMorality(0);
  SetClass("cavalier");
  SetClass("necromancer");
  SetLevel(400);
  SetFearType("ancient fear");
  SetResistLevel(35);
  SetFearLength(10);
  SetBaseLanguage("Ancient");
  SetCombatAction(15, ({
    "!cast fimbulwinter",
    "!cast fortress of solitude",
  }) );
  SetAction(5, ({
    "!emote strides forward laborously and unstoppably.",
    "!emote moans, rumbling the ice around.",
    "!say your world dies in darkness and winter.",
  }) );
  SetEncounter(5);

  SetInventory( ([
    INNERSEA_ENCOUNTERS "frostgiant/platemail" : "wear platemail",
    INNERSEA_ENCOUNTERS "frostgiant/scroll" : 1,
    INNERSEA_ENCOUNTERS "viking/longship" : "wield longship",
  ]) );
  SetFirstCommands( ({
    "cast fortress of solitude",
    "cast fortress of solitude",
    "cast fortress of solitude",    
  }) );
  SetMeleeDamageType(BLUNT|COLD);
  SetResistance(ALL_ELEMENTS|ALL_PHYSICAL,"medium");
  SetResistance(COLD|WATER,"immune");
  SetResistance(HEAT,"vulnerable");
  SetUndead(1);
  SetUndeadType("lich");
  }


void init() {
  npc::init();
  fear::init();
}

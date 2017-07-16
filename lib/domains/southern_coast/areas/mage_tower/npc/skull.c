#include <lib.h>
#include <damage_types.h>
#include "../mage_tower.h"

inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("flying skull");
  SetShort("a flying severed head");
  SetId( ({ "head", "skull", "tower_wander" }) );
  SetAdjectives( ({ "flying", "severed" }) );
  SetRace("lamrani head", 1);
  AddLimb("head", 0, 1);
  SetStat("intelligence", 100, 1);
  SetStat("durability", 100000, 1);
  SetStat("wisdom", 100000, 1);
  SetStat("strength", 20, 1);
  SetNoCorpse(1);
  SetDie("%^RED%^The floating head drifts to the floor "
         "where it dissolves.%^RESET%^");
  SetMeleeAttackString("teeth");
  SetMeleeDamageType(PIERCE);
  SetResistance(ALL_DAMAGE, "immune");
  SetResistance(MAGIC, "none");
  SetMorality(-100);
  SetGender( random(2) ? "male" : "female" );
  SetLong("This flying severed lamrani head has seen better days. "
          "The head floats about with no means of support, a toy "
          "used since the days when the lamrani were banished to "
          "the Lower Planes with the aide of the residents of this "
          "tower.");
  SetLanguage("Dasinri", 100, 1);
  SetAction(25, ({
    "!emote floats about listlessly.",
    "!cackle mani",
    "!muah",
    "!speak The Master will avenge me.",
    "!yell The Master Comes!",
    "!speak He will tear this town down around itself.",
    "!emote looks through you.",
    "!emote stares at a wall idly.",
    }) );
  SetCombatAction(10, ({
    "!yell I'll swallow your soul!",
    "!speak Master forsake me not!",
    "!emote closes his eyes and begins chanting.",
    }) );
  SetTalkResponses( ([
    "tower" : "Speak not the accursed word!",
    ({ "key", "keys" }) : "The secret lies in the grove.",
    ({ "elf" }) : "The vile race shall be sent to Hell when "
                  "the Master takes his revenge!",
    ({ "master", "Master" }) : "Long Live the Lamrani Lord!",
    ]) );
  SetWander(10);
}

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../castle.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("muezzin");
  SetGender("female");
  SetClass("fighter");
  SetLevel(90);
  SetTown("Soleil");
  SetKeyName("dark Vagabond");
  SetId( ({ "muezzin","vagabond"}) );
  SetAdjectives( ({ "dark" }) );
  SetShort("a dark muezzin vagabond");
  SetLong("Dark black curly hair drapes this muezzin all around "
          "her body. Her triangle white nose which sticks out appears as "
          "a target on her head. Her light green eyes are briskly "
          "buried under albino fur face. Slight yellow fangs creep "
          "out from her mouth which compliment this muezzins wide "
          "jaw frame. Her overall body appearance is normal and "
          "few scars litter her strong looking arms.");
  SetDie("The dark muezzin staggers before she dies."); 
  SetMorality(150);
  SetInventory( ([
    RUINS_OBJ + "mbo" : "wield bo",
    RUINS_OBJ + "bheadband" : "wear headband",
    RUINS_OBJ + "mbelt"   : "wear belt",
      ]) );

  SetReligion("Eclat","Eclat");
  SetCombatAction(5, ({ 
    "!emote attempts to bite you!",
    "!chuckle",
    }) ); 
  SetAction(3, ({
    "!speak I used to play here as a child.",
    "!speak Few remember the old alliances with the Nosferatu...",
    "!speak The Soleil guard still patrol these halls.",
    "!emote yawns sleepishly.",
    "!emote scratches something.",
     }) );
}
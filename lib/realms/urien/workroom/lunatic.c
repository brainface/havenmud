#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <damage_types.h>

#define WORKROOMDIR "/realms/urien/workroom/"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("lunatic");
  SetId( ({ "lunatic"}) );
  SetShort("Lunatic Godenn the chubby apprentice");
  SetAdjectives( ({  "apprentice","godenn" }) );
  SetLong("Luna is another higher being of Kailie. Being coddled most of his "
          "youth has given him a warm welcoming appearance. His body is "
          "covered with short black hair with a white patch on his chest. "
          "His face looks very young for a goden, particular to one in their "
          "teenage years. He has been rewarded to assist the duties with "
          "his goden brother in this realm. Overall, his body is portly "
          "but that should not be underestimated due to his deadly "
          "claws which creep out from his massive paws.");
  SetMorality(1100);
  SetClass("evoker");
  SetLevel(425); // LOW MAX
  SetRace("goden");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetInventory( ([
        WORKROOMDIR+ "luknife"  : "wield my 1st knife",
        WORKROOMDIR+ "luturban" : "wear turban",
        WORKROOMDIR+ "luneck"   : "wear collar",
  ]) );
 SetFirstCommands( ({
    "emote pulls his knife out of the sign.",
    "say Orders?",
   }) );
 SetSpellBook( ([
    "fireball"             : 100,
    "bolt"                 : 100,
    "energy field"         : 100,
    "chain lightning"      : 100,
    "haste"                : 100,
    "planar durability"    : 100,
    "planar strength"      : 100,
    ]) );
  SetAction(2, ({
    "!cast energy field",
    "!cast haste",
    "!cast planar strength",
    "!cast planar durability",
    }) );
  SetCombatAction(50, ({
    "!cast fireball",
    "!cast chain lightning",
    "!cast bolt",
    "!cast energy field",
    }) );
SetDie("Lunatic takes a few steps back, morphs into a light orb and then "
       "shoots into the sky!");
SetNoCorpse(1);
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 2) {
      eventForce("cast energy field");
 }
}
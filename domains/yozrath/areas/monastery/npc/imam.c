// Monastery
// Aerelus
// 07/05/2006

#include <lib.h>
#include "../monastery.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("husaam");
  SetShort("Husaam the enlightened imam");
  SetId( ({ "imam", "husaam" }) );
  SetAdjectives( ({ "enlightened", "strong" }) );
  SetLong(
    "Husaam is a Kylin imam. He is in charge of everything that happens in "
    "the monastery, including worship and training. He looks very strong, "
    "despite his respectable age. He has an enlightened look about him, "
    "giving the impression that he is entirely at one with his faith. He "
    "appears most capable of defending himself."
  );  
  SetRace("human");
  SetClass("imam");
  SetSkill("fire magic",1,2);
  SetSkill("projectile combat",1,2);
  SetLevel(90);
  SetSpellBook( ([
    "wrath" : 100,
    "wall of force" : 100,
    "purify" : 100,
    "pious obstructions" : 100,
    ]) );
  SetSongBook( ([
    "aria of air" : 100,
    "aria of ice" : 100,
    "aria of fire" : 100,
    ]) );
  SetGender("male");
  SetReligion("Kylin");
  SetBaseLanguage("Padashi");
  SetMorality(1200);
  SetFriends ( ({ "monk", "imam", "warrior_monk", "guard" }) );
  SetInventory( ([
    AREA_OBJ "imam_robe" : "wear robe",
    AREA_OBJ "imam_bow"  : "wield crossbow",
    ]) );
  SetAction(6, ({
    "!emote looks deep in thought.",
    "!cast pious obstructions",
    "!say Through order comes balance.",
    "!say Through balance comes order.",
    "!cast wall of force",
  }) );
  SetCombatAction(40, ({
  	"!cast purify",
  	"!sing aria of ice",
  	"!sing aria of air",
    "!say You are no match against the will of our Lord!",
    "!cast wrath",
    "!sing aria of fire",
    "!cast wall of force",
    }) );
 }

/** Approved by Laoise at Sun May 21 17:03:55 2006. **/
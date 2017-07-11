/*
 * This guy exists solely to
 * carry a truly voluminous backpack
 * of epic porportions.
 */
// mahkefel 2015:
// planeswalker is trademarked, probably not a big deal but
// using a moderately more original name won't hurt.
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <daemons.h>
#include "../planes.h"
inherit LIB_SENTIENT;

static void create() {
  string gender, possessive, pronoun, objective;
  mapping inventory;

  ::create();
  SetKeyName("riftmage");
  SetRace(RACES_D->GetRandomRace());

  // random gender
  gender = random(2) ? "male" : "female";
  possessive = "his";
  pronoun = "he";
  objective = "him";
  if (gender == "female") {
    possessive = "her";
    pronoun = "she";
    objective = "her";
  }
  // descriptive text
  SetGender(gender);

  SetClass("evoker");
  SetShort("a wandering riftmage (" + GetRace() + ")");
  SetId( ({ "riftmage", GetRace() }) );
  SetAdjectives( ({ "wandering", GetRace() }) );
  SetLevel(150 + random(20));
  SetLong(
    "This mage is of some adventurous sort, wandering the planes in search"
    " of fame and arcane power. " + capitalize(possessive) + " eyes glimmer"
    " slightly with eldritch energy, and the surrounding environment"
    " of the plane seems somehow less hostile around " + objective + "."
  );

  SetInventory( ([
    PLANE_OBJ "planeswalker/alpenstock" : "wield alpenstock",
    PLANE_OBJ "planeswalker/haversack" + GetSize() :
      "wear haversack on right arm and torso and left arm",
  ]) );
  SetAction(10, ({
    "!emote scans the horizon.",
    "!say many souls are lost who wander the planes unprepared.",
    "!say do not interfere with my travels.",
    "!say great power is to be found by those willing to brave these realms.",
  }) );
  SetCombatAction(90, ({
    "!say Your death is on your own foolish head!",
    "!cast dimensional rift",
    "!cast lightning blast",
    "!cast avalanche",
  }) );
  SetFirstCommands( ({
    "cast temperature shield",
    "cast temperature shield",
  }) );
  SetWander(3);
}


void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast energy wall");
  }
}


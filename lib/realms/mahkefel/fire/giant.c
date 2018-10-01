/*  A pit fiend */
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("muspelheim");
  SetId( ({ "giant", "muspelheim" }) );
  SetAdjectives( ({ "immense", "fiery" }) );
  SetGender("male");
  SetShort("an immense fiery muspelheim");
  SetLong(""

A pit fiend is a towering giant of a devil with a reddish "
          "body and huge wings jutting from his torso. His large claws "
          "and huge teeth set this creature apart as a viscious killer.");
  SetRace("devil");
  AddSkill("pole combat",GetLevel()*2+2,1); // pitchforkin'
  SetMorality(0);
  SetReligion("Magildan");
  SetClass("mystic");
  SetLevel(220);
  SetCombatAction(15, ({
    "!cast muspelli",
    "!cast muspelli",
    "!cast nature's recovery",
    "!cast aetheric rift",
  }) );
  SetAction(5, ({
    "!emote strides across the ground, shaking the earth with each step.",
    "!emote burns like a bonfire.",
  }) );
  SetFirstCommands( ({
    "!cast temperature shield",
    "!cast aetheric rift",
    "!cast aetheric rift",
  }) );
  //SetEncounter(100);

  SetInventory( ([
    PLANE_OBJ + "muspel_armour" :
      "wear suit on torso and right arm and left arm and right leg and left leg",
    PLANE_OBJ + "muspel_hammer" : "wield hammer",
  ]) );
  SetMeleeDamageType(SLASH);
  }


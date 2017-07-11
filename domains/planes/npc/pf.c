/*  A pit fiend */
#include <lib.h>
#include "../planes.h"
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

static void create() {
  npc::create();
  SetKeyName("pit fiend");
  SetId( ({ "fiend", "devil" }) );
  SetAdjectives( ({ "pit" }) );
  SetGender("male");
  SetShort("a pit fiend");
  SetLong("A pit fiend is a towering giant of a devil with a reddish "
          "body and huge wings jutting from his torso. His large claws "
          "and huge teeth set this creature apart as a viscious killer.");
  SetRace("devil");
  AddLimb("left wing", "torso", 2, ({A_WING}) );
  AddLimb("right wing", "torso", 2, ({A_WING}) );
  //AddLimb("left hoof", "left leg", 3, ({A_SOCK,A_LONG_SOCK}) );
  //AddLimb("right hoof", "right leg", 3, ({A_SOCK,A_LONG_SOCK}) );
  //DestLimb("left foot");
  //DestLimb("right foot");
  AddSkill("pole combat",GetLevel()*2+2,1); // pitchforkin'
  SetMorality(-2000);
  SetClass("cavalier"); // changed from rogue. more armouor skills.
  SetLevel(260);
  SetFearType("devil fear");
  SetResistLevel(35);
  SetFearLength(20);
  SetCombatAction(3, (: eventSpecial :) );
  SetAction(5, ({
    "!emote looks around maniacally.",
  }) );
  SetEncounter(100);

  SetInventory( ([
    PLANE_OBJ + "pit_armour" :
      "wear suit on torso and right arm and left arm and right leg and left leg",
    PLANE_OBJ + "pit_wing" : 2,
    PLANE_OBJ + "pitchfork" : "wield pitchfork",
  ]) );
  SetFirstCommands( ({
    "wear first wingguard on right wing",
    "wear first wingguard on left wing",
  }) );
  SetMeleeDamageType(SLASH);
  }

void eventSpecial() {
  object who = this_object();
  object target = GetCurrentEnemy();

  send_messages("tear",
     "$agent_name%^RED%^ $agent_verb%^RESET%^ at $target_name "
     "with $agent_possessive teeth.", who, target, environment() );
   target->eventReceiveDamage(who, SLASH, random(400), 0,
              target->GetRandomLimb("head") );
     return;
  }

void init() {
  npc::init();
  fear::init();
  }


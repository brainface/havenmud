// hilarity ensues?


#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

void eventSpecial();

int eventCheckPlayer();


static void create() {
  npc::create();
  SetKeyName("slag fiend");
  SetId( ({ "fiend" }) );
  SetAdjectives( ({ "slag" }) );
  SetGender("male");
  SetShort("a slag fiend");
  SetLong("A towering, slag-skinned demon with coal black wings and "
          "and ferrous claws and teeth. No creature of Taigis, this "
          "monstrosity is the rage of ruined mountains made manifest.");
  SetRace("devil");
  SetBaseLanguage("Ancient");
  AddLimb("left wing", "torso", 2, ({A_WING}) );
  AddLimb("right wing", "torso", 2, ({A_WING}) );
  //AddLimb("left hoof", "left leg", 3, ({A_SOCK,A_LONG_SOCK}) );
  //AddLimb("right hoof", "right leg", 3, ({A_SOCK,A_LONG_SOCK}) );
  //DestLimb("left foot");
  //DestLimb("right foot");
  //AddSkill("pole combat",GetLevel()*2+2,1); // pitchforkin'
  SetMorality(0);
  SetReligion("Magildan");
  AddSkill("natural magic",1,1);
  AddSkill("evokation",1,1);
  SetClass("cavalier");
  SetStat("wisdom",500);
  SetLevel(180);
  SetFearType("claustrophobia");
  SetResistLevel(35);
  SetFearLength(10);
  SetCombatAction(15, ({
    "!cast slag",
    "!cast slag",
    "!cast wall of iron",
    "!disorient",
    "!emote stomps violently, shaking the ground.",
  }) );
 
  SetAction(5, ({
    "!emote rumbles furiously.",
  }) );

  SetEncounter( (:eventCheckPlayer:) );

  SetInventory( ([
    DIR_STD "balrog/obj/fire_whip" : "wield whip",
  ]) );
  SetFirstCommands( ({
    "cast wall of iron",
    "cast wall of iron",
    "kill all",
  }) );
  SetMeleeDamageType(SLASH);
  }

void init() {
  npc::init();
  fear::init();
  }

int eventCheckPlayer() {
  object who = this_player();
  if( who->GetSkillLevel("mining") > 100 && who->GetLevel() > 150) {
    return 1;
  }
  return 0;
}


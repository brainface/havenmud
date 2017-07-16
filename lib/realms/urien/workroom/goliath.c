// Basic NPC to assume, for generic bug 
// testing fun.

#include <lib.h>
#include <std.h>
#include <dirs.h>
#include <damage_types.h>

#define WORKROOMDIR "/realms/urien/workroom/"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("goliath");
  SetId( ({ "goliath"}) );
  SetShort("Goliath Godenn the lord of portals");
  SetAdjectives( ({  "lord","godenn" }) );
  SetLong("Goliath is one of the higher beings of Kailie. Surviving cold "
          "weather and numerous battles has made him hardier than any mortal "
          "existing. His fur coat has numerous colours consisting of yellow "
          "ochre, white and black. His torso has longer hair which contains a "
          "cheetah pattern of black rings on it. His face shows of sorrow and "
          "despair, thus he has been rewarded to maintain this upper realm. His "
          "lower right humerous shows an old wound, as does his split jaw. "
          "Occasionally, his tail twitches when he shifts his weight.");
  SetMorality(1000);
  SetClass("fighter");
  AddSkill("multi-weapon",1);
  AddSkill("accuracy",1);
  AddSkill("dodge",1);
  SetLevel(500); // MAX PLAYER LEVEL
  SetRace("goden");
  SetGender("male");
  SetBaseLanguage("Eltherian");
  SetCurrency("imperials", 250);
  SetInventory( ([
        WORKROOMDIR+ "gosword"  : "wield 1st sword",
        WORKROOMDIR+ "goswordd" : "wield 1st sword",
        WORKROOMDIR+ "goneck"   : "wear collar",
        WORKROOMDIR+ "goturban" : "wear turban",
  ]) );
 SetFirstCommands( ({
    "emote stands at attention and sharply salutes.",
    "say Your bidding, sire?",
   }) );
SetDie("Goliath takes a few steps back, morphs into a light orb and then "
       "shoots into the sky!");
SetNoCorpse(1);
}
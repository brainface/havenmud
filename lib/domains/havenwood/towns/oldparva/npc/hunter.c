#include <lib.h>
#include "parva.h"
inherit LIB_TRAINER;

static void create() 
{
  trainer::create();
  SetTown("Parva");
  SetProperty("parvanoleave",1);
  SetMorality(150);
  SetKeyName("Inimicii");
  SetShort("Inimicii, the hunter");
  SetId( ({ "inimicii","hunter" }) );
  SetAdjectives( ({ "old" }) );
  SetLong("Inimicii has spent his life defending his home town "
    "until the lizardmen ran it over; he is now determined "
    "to raise the youth of Parva so that it might be "
    "protected better.  Unlike most halflings, he did not "
    "venture to Soleil with the rest; he was tired of moving "
    "and had just set up here in Parva at that time.  "
    "He is a strong fighter and a "
    "great hunter.  He trains those who have ranger skills.");
  SetClass("ranger");
  SetGender("male");
  SetRace("halfling");
  RemoveLanguage("Eltherian");
  SetLanguage("Enlan",100,1);
  SetLevel(29);
  SetInventory( ([
    P_OBJ + "/pants_ini" : "wear pants",
    P_OBJ + "/boots_ini" : "wear boots",
    P_OBJ + "/shirt_ini" : "wear shirt",
    P_OBJ + "/shortsword" : "wield shortsword",
    P_OBJ + "/longsword" : "wield longsword",
  ]) );
  SetAction(1,({ "!say I train rangers, that I do.",
    "!say I was a hunter for many years, "
      "using my bow and arrow to get food.",
    "!say Hunting and being a ranger are "
      "two things that go together like bread "
      "and butter, or happiness and an Eclat, or "
      "maybe greed and a Soirin.",
    "!say I train rangers, mostly, but anyone "
      "who has any one of the skills I teach, I'll "
      "train them too!"  
  }) );
  SetCombatAction(2,({ "!say Stop that!","!say Get away!",
    "!slice","!shout Help!  Help me!",
    "!say Someone help me!","!slice","!say Get this "
    "cretin out of here!","!say Where are the "
    "other Parvans?  Don't let us die again!","!slice" }) );
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("natural magic");
  AddTrainingSkills("slash combat");
  AddTrainingSkills("projectile combat");
  AddTrainingSkills("metal working");
  AddTrainingSkills("wood working");
  AddTrainingSkills("leather working");
  AddTrainingSkills("textile working");
  AddTrainingSkills("natural working");
  AddTrainingSkills("armour smithing");
  AddTrainingSkills("weapon smithing");
  AddTrainingSkills("multi-weapon");
  AddTrainingSkills("melee combat");
  AddTrainingSkills("melee combat");
  
  SetCombatStyle("sword slinging");
  SetCombatStyleLevel("sword slinging",100);
}

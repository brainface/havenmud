#include <lib.h>
#include "../drazh.h"

inherit LIB_LEADER;

void DoCombatSomething();

static void create() {
  leader::create();
  SetKeyName("varrk");
  SetId( ({"skaven","seer"}) );
  SetAdjectives( ({"lord","of","decay"}) );
  SetShort("Varrk, Lord of Decay");
  SetLong(
     "The grey filthy matted fur of this medium sized skaven covers "
     "Varrk's torso only. Varrk's arms and legs are completely shaven "
     "and scarred covered. Varrk waits patiently for his next student. "
     );
  SetRace("skaven");
  SetGender("male");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetClass("necromancer");
  AddSkill("ice magic",1,2);
  SetMorality(-1000);
  SetLevel(85);
    SetPlayerTitles( ([
     "newbie"   : "the Tyro of Pestilence",
     "mortal"   : "the Acolyte of Pestilence",
     "hm"       : "the Disciple of Decay",
     "legend"   : "the Seer of Decay",
     "cavalier" : "the Warlock of Pestilence",
     ]) );
  SetSpellBook( ([
     "umbral shield" : 100,
     "wither"        : 100,
     "soultap"       : 100,
     "avalanche"     : 100,
     ]) );
  SetAction(5, ({ 
     "!say do you wish to learn the ways of pestilence?",
     "!cast umbral shield",
       }) );
  SetCombatAction(50, (: DoCombatSomething :) );
  SetInventory( ([
     V_OBJ + "necro_staff" : "wield staff",
     V_OBJ + "grey_robe"   : 
       "wear robe on torso and left arm and left leg and right arm and right leg",
       ]) );
 SetFirstCommands( ({
    "cast umbral shield",
    "cast umbral shield",
    }) );
}

void DoCombatSomething(object who){
  if (!random(10)) {
    int randnum = random(2);
    if (randnum == 0) { eventForce("speak this is not a wise choice.");}
    else { eventForce("speak as the Lord of Decay, you will die.");}
  }

  switch(random(6)) {
    case 0..2:
      eventForce("cast wither");
      break;
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast umbral shield");
      break;
    case 4:
      eventForce("cast soultap");
      break; 
    default:
      eventForce("cast avalanche");
      break;
}
  return;
}
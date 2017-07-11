// Coded by Zeratul
// Head Priest of Skadar
// March 07, 2000

#include <lib.h>
#include "../vacazar.h"
#include <std.h>
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("sarakar");
  SetTown("Vacazar");
  SetReligion("Skadar");
  SetId( ({"sarakar","priest","head priest"}) );
  SetAdjectives( ({"faithful"}) );
  SetShort("Sarakar the Head Priest of Skadar");
  SetLong(
     "Sarakar is a skaven of many words. He is one whom openly preaches "
     "about the faith of Skadar, all in praise of his lord Zeratul. He is the "
     "head priest of Skadar, chosen of Zeratul, messager to the people. "
  );
  SetGender("male");
  SetRace("skaven");
  SetClass("priest");
  SetTaughtSpheres( ({"religion skadar","clerical","clerical necromancy",
  "clerical enchantment","clerical planar magic"}) );
  SetLevel(70);
  SetSpellBook( ([
     "ice skin" : 100,
     "wards of darkness" : 100,
     "energy blade" : 100,
     "silent running" : 100,
     "harm body" : 100,
     "pain touch" : 100,
     "pious obstructions" : 100,
  ]) );
  SetUniqueSkills( ([
  ]) );
  SetPlayerTitles( ([
     "newbie" : "the Faithful of Skadar",
     "mortal" : "the Priest of Skadar",
     "hm" : "the Silent Priest of Skadar",
     "legend" : "the Assassin-Priest of Skadar",
     "avatar" : "the Godly Assassin-Priest of Skadar",
  ]) );
  SetFreeEquip( ([
     "/std/weapon/knife/freeknife" : 1,
  ]) );
  SetAction(8, ({
     "!say Zeratul's faith is the pillar that supports us",
     "!say My lord's will is the foundation of this town.",
     "!nods solem",
     "!say My Lord has blanketed us from the darkness!",
     "!say Zeratul has saved us from the horror of kailie and has given us a purpose!",
  }) );
  SetCombatAction(9, ({
     "!cast cold bolt",
     "!yell My Lord will smite you down!",
     "!cast harm body",
     "!yell Help me!",
     "!cast pain touch",
     "!say You fool!",
     "!cast wards of darkness",
     "!cast ice skin",
  }) );
  SetInventory( ([
     V_OBJ + "double_knife" : "wield knife",
     V_OBJ + "vest" : "wear vest",
  ]) );
  }

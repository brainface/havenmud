//   Modified by Dahaka
//  7-2004

#include <lib.h>
#include "../drazh.h"
inherit LIB_NPC;

int type = random(2);
string CheckSetShort();

int CheckWanted();
#include "../wanted.h"

static void create() {
  npc::create();
  SetKeyName("watchman");
  SetId( ({"watchman","skaven","drunk"}) );
  SetShort("a drunken skaven watchman");
  SetRace("skaven");
  SetClass("fighter");
  SetLevel(35 + random(10)); 
  SetGender("male");
  SetAction(3, ({
     "!yawn",
     "!emote drools.",
     }) );
  SetCombatAction(4, ({
     "!say Die!",
     "!yell Die!!",
     "!emote vomits.",
     }) );
  SetEncounter( (: CheckWanted :) );
  SetFriends( ({
     "skaven","watchman",
   }) );
  AddAlcohol(120);
  SetMorality(-1000);

  if (type == 0) {
    SetAdjectives( ({"strong","skaven","drunken"}) );
    SetLong(
       "This strong looking skaven is one of the watchmen of the city. He guards "
       "the streets, enforcing the law to all of those who live in and visit "
       "the town. "
       );
    SetInventory( ([
       V_OBJ + "buckler"    : "wear buckler on left arm",
       V_OBJ + "scimitar"   : "wield scimitar",
       V_OBJ + "scale_mail" : "wear armour",
       V_OBJ + "lpants"     : "wear pants",
       ]) );
    }

  else if (type == 1) {
    SetAdjectives( ({"agile","skaven","drunken"}) );
    SetLong(
       "This agile looking skaven is one of the watchmen of the city. He guards "
       "the streets, enforcing the law to all of those who live in and visit "
       "the town. "
       );
    SetInventory( ([
       V_OBJ + "axe"        : "wield axe",
       V_OBJ + "scale_mail" : "wear armour",
       V_OBJ + "lpants"     : "wear pants",
       ]) );
    }
}

int CheckWanted() {
  if(this_player()->GetInvis()) return 0;
  if(!userp(this_player())) return 0;
  if(member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
     eventForce("follow " + this_player()->GetKeyName());
     eventForce("yell Suffer, Criminal!");
     SetAttack(this_player());
     return 1;
  }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
  }
}


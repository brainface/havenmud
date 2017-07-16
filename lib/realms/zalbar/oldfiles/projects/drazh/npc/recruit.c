//  Modified by Dahaka
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
  SetKeyName("recruit");
  SetId( ({"watchman","skaven","recruit"}) );
  
  SetRace("skaven");
  
  SetClass("fighter");
  SetLevel(5 + random(5));
  SetGender("male");
  SetAction(3, ({
     "!emote stands at parade rest.",
     "!emote stands at attention.",
   }) );
  SetCombatAction(4, ({
     "!say Die!",
     "!yell Die!!",
   }) );
  SetFriends( ({
     "skaven","watchman","recruit",
   }) );
  SetMorality(-1000);

  if (type == 0) {
  SetAdjectives( ({"strong","skaven"}) );
  SetShort("a strong skaven recruit");
  SetLong(
     "This strong looking skaven is training to be a member of the watch. His "
     "dirty matted fur shows signs of dried blood which must be from training"
     );
  RemoveSkill("hack attack");
  SetInventory( ([
     V_OBJ + "glaive"         : "wield glaive",
     V_OBJ + "recruit_armour" : "wear breastplate",
     V_OBJ + "lpants"         : "wear pants",
     ]) );
  }

  else {
  SetAdjectives( ({"agile","skaven"}) );
  SetShort("an agile skaven recruit");
  SetLong(
     "This agile looking skaven is training to be a member of the watch. His "
     "dirty matted fur shows signs of dried blood which must be from training."
     );
  SetInventory( ([
     V_OBJ + "scimitar"       : "wield scimitar",
     V_OBJ + "buckler"        : "wear on left arm",
     V_OBJ + "recruit_armour" : "wear breastplate",
     V_OBJ + "lpants"         : "wear pants",
     ]) );
  }
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
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


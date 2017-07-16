#include <lib.h>
#include "../../towns/soleil/soleil.h"
inherit LIB_SENTIENT;

int CheckEvil();

static void create() {
  sentient::create();
  SetKeyName("knight");
  SetShort("a knight of the forest");
  SetId( ({ "knight" }) );
  SetLong("This knight looks very powerful as he stands "
    "guard over his friends who reside in Soleil.  He "
    "appears to be quite legendary from whatever lands he "
    "comes from.  He is one of the chosen of the good god "
    "Gabriel and will defend Soleil to the death.");
  SetProperty("soleilnoleave",1);
  SetRace("human");
  SetGender("male");
  SetClass("cavalier");
  SetClass("cleric");
  SetLevel(random(30)+90);
  SetMorality(1000);
  SetReligion("Eclat");
  SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
    "Soleil citizen","Oppugno","shaggy dog","Sorgan",
    "entrance guard","Iuvo","Fossis","Kiee","Miserum","knight","guard",
  }) );
  SetStat("strength",150,1);
  SetStat("durability",150,1);
  SetStat("intelligence",150,1);
  SetStat("wisdom",150,1);
  SetStat("speed",100);
  SetStat("agility",100);
  SetSkill("pierce defense",175,1);
  SetSkill("slash defense",175,1);
  SetSkill("blunt defense",175,1);
  SetSkill("melee defense",175,1);
  SetSkill("pierce attack",175,1);
  SetSkill("slash attack",200,1);
  SetSkill("melee attack",175,1);
  SetSkill("faith",175,1);
  SetSkill("enchantment",175,1);
  SetSkill("healing",175,1);
  SetSkill("multi hand",200,1);
  SetAction(10, ({ "!go west","!go east","!go north","!go south",
    "!go northeast","!go northwest","!go southeast","!go southwest",
    "!go up","!go down",
  }) );
  SetCombatStyle("sword slinging");
  SetCombatStyleLevel("sword slinging",100);
  SetInventory( ([ 
    S_OBJ + "armour_gauntlet1" : "wear first gauntlet on right hand",
    S_OBJ + "sword" : "wield sword",
    S_OBJ + "armour_helmet" : "wear helmet",
    S_OBJ + "armour_body" : "wear breastplate",
    S_OBJ + "armour_cuisse" : "wear cuisse",
    S_OBJ + "armour_solleret" : "wear solleret",
    S_OBJ + "armour_gauntlet2" : "wear first gauntlet on left hand",
  ]) );
  SetEncounter( (: CheckEvil :) );
}

int CheckEvil() {
  if ((this_player()->GetMorality() < -350) && 
    (this_player()->GetLevel() > 25)) {
      eventForce("speak You are not welcome here!");
      return 1;
    }
  return 0;
}

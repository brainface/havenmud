#include <lib.h>
#include "../soleil.h"
inherit LIB_TOWNGUARD;

int CheckEvil();

static void create() {
  ::create();
  SetKeyName("knight");
  SetShort("a knight of the forest");
  SetId( ({ "knight" }) );
  SetLong("This knight looks very powerful as he stands "
    "guard over his friends who reside in Soleil.  He "
    "appears to be quite legendary from whatever lands he "
    "comes from.  He is one of the chosen of the joyful Goddess "
    "Amelia and will defend Soleil to the death.");
  SetProperty("soleilnoleave",1);
  SetRace("muezzin");
  SetTown("Soleil");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(random(30)+150);
  SetMorality(1000);
  SetReligion("Eclat","Eclat");
  SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
    "Soleil citizen","Oppugno","shaggy dog","Sorgan",
    "entrance guard","Iuvo","Fossis","Kiee","Miserum","knight","guard",
    "Acclima","Trill","Kiee","Miserum","Fossis","Aegri","Melody",
  }) );
  SetSkill("faith", 175);
  SetSkill("enchantment",175,1);
  SetSkill("healing",175,1);
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
  
}

int CheckEvil() {
  if ((this_player()->GetMorality() < -350) && 
    (this_player()->GetLevel() > 25)) {
      eventForce("speak You are not welcome here!");
      return 1;
    }
  return 0;
}

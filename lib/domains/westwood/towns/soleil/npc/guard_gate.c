#include <lib.h>
inherit LIB_TOWNGUARD;
#include "../soleil.h"

int CheckWanted();
#include "../wanted.h"


static void create() {
   ::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("entrance guard");
   SetShort("an entrance guard");
   SetId( ({ "guard","muezzin","male","soleil_cit" }) );
   SetAdjectives( ({ "entrance" }) );
   SetLong("A jovial look characterizes the entrance guard who attempts "
           "to prevent the entrance of the 'wrong' people into Soleil.  "
           "Light fur covers his whole body, what can be seen of the "
           "body at any rate.  He stands firmly, at attention, but "
           "seems more relaxed than most in such a position.");
   SetGender("male");
   SetRace("muezzin");
  SetTown("Soleil");
   SetClass("cavalier");
   SetMorality(100);
   SetLevel(43+random(5));
   SetInventory( ([
                    S_OBJ + "spear_long" : "wield spear in right hand",
                    //S_OBJ + "spear_long" : "wield spear in left hand",	
               ]) );
   SetReligion("Eclat","Eclat");
   SetFriends( ({ "Dulcae","Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum","soleil_cit" }) );
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell " + this_player()->GetCapName() + "!  A criminal!  "
			"Soleil, come to me and fight!");
     SetAttack(this_player());
    return 1;
   }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
   }
  return 0;
 }

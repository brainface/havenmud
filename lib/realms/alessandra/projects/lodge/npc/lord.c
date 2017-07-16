#include <lib.h>
#include "../lodge.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();

  call_out( (: eventForce, "put key in pouch" :), 0);

  SetKeyName("Sh'zar");
  SetShort("Lord Sh'zar the cult high priest");
  SetId( ({"lord","high priest","priest","sh'zar","lord sh'zar","nosferatu"}) );
  SetAdjectives( ({"unkept", "nosferatu"}) );
  SetLong(
     "This unkept figure is reverently known as Lord Sh'zar "
     "by his royal throng of subjects.  His bald head is "
     "covered with several large scars that bare the mark "
     "of untreated infections.  His malformed jaw juts several"
     "yellowed pointed fangs and his lips are stained red with  "
     "fresh blood.  He is not the neighborly type.  The "
     "expression on his face shows a state of no tolerance."
     );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("rogue");
  SetLevel(40);
  SetInventory( ([
     L_OBJ + "boots" : "wear boots",
     L_OBJ + "pouch" : "wear pouch",
     L_OBJ + "hide" : "wear hide",
     L_OBJ + "pants" : "wear pants",
     L_OBJ + "dagger" : "wield dagger",
     L_OBJ + "chainmail" : "wear chainmail",
     L_OBJ "icekey" : 1,
     ]) );
  SetAction(16, ({
     "!grunt",
     "!say who dares enter my shrine and disturb me?",
     "!emote takes a gulp from a chalice.",
     "!say what does it take to get some peace around here?",
     "!emote slams his fist on the arm of his chair.",
     "!breathe",     
     }) );
  SetCombatAction(15, ({
     "!yell Guards!",
     "!say Fool, do you actually think you stand a chance against me?",
     }) );
}




#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../lodge.h"

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Sh'zar");
  SetRace("nosferatu");
  SetShort("Lord Sh'zar the cult high priest");
  SetId( ({"lord","high priest","priest","sh'zar","lord sh'zar","nosferatu"}) );
  SetAdjectives( ({"unkept", "nosferatu"}) );
  SetClass("priest");
  SetSkill("knife combat", 1, 1);
  SetSkill("fire magic", 1, 2);
  SetLevel(40);
  SetMorality(-1100);
  SetReligion("Saahagoth","Saahagoth");
  SetSpellBook( ([
        "bless"                 : 100,
        "aegis of the faithful" : 100,
        "harm body"             : 50,
        "pain touch"            : 50,
        "hellfire"              : 100,
      	]) );
  SetLong("This unkept figure is reverently known as Lord Sh'zar "
  "by his royal throng of subjects.  His bald head is "
  "covered with several large scars that bare the mark "
  "of untreated infections.  His malformed jaw juts several "
  "yellowed pointed fangs and his lips are stained red with  "
  "fresh blood.  He is not the neighborly type.  The "
  "expression on his face shows a state of no tolerance.");
  SetGender("male");
  SetAction(16, ({
  "!grunt",
  "!cast bless on me",
  "!cast shield of faith",
  "!say who dares enter my shrine and disturb me?",
  "!say what does it take to get some peace around here?",
  "!emote slams his fist on the arm of his chair.",
  "!breathe",     
  }) );
  SetCombatAction(60, ({
  "!cast hellfire",
  "!cast pain touch",
  "!cast harm body",
  "!cast shield of faith",
  "!yell Guards!",
  "!say Fool, do you actually think you stand a chance against me?",
  }) );
  SetInventory( ([
  L_OBJ + "boots"     : "wear boots",
  L_OBJ + "pouch"     : "wear pouch",
  L_OBJ + "hide"      : "wear hide",
  L_OBJ + "pants"     : "wear pants",
  L_OBJ + "dagger"    : "wield dagger",
  L_OBJ + "chainmail" : "wear chainmail",
  L_OBJ "icekey" : 1,
  ]) );

  SetFirstCommands( ({
  	"cast aegis of the faithful",
  	"cast aegis of the faithful",
  	"put key in pouch",
    }) );
}


/* Approved by Duuktsaryth on Sat Feb 19 16:34:04 2000. */

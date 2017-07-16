//  Gypsy in dead forest near Gothic Manor
//  Alessandra 2009

#include <lib.h>
#include "../vamp.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  
  SetKeyName("woman");
  SetId( ({ "chick", "gypsy", "woman", "dark-elf" }) );
  SetAdjectives( ({"chick", "something"}) );
  SetShort("a gypsy woman");
  SetLong(
     "This is a gypsy chick."     
     );
  SetRace("dark-elf");
  SetGender("female");
  SetClass("enchanter");
  SetSkill("multi-weapon", 200, 1);
  SetSkill("knife combat",200, 1);
  SetSkill("dodge",200, 1);
  SetSkill("stealing",200, 1);
  SetSkill("cloth armour", 200, 1);
  SetSkill("accuracy", 200, 1);
  SetSkill("slash combat", 200, 2);
  SetSkill("projectile combat", 200, 2);
  SetSkill("melee combat", 200, 2);
  SetSkill("disarm", 200, 2);
  SetSkill("parry",200, 1);
  SetSkill("pierce combat",600, 2);
  SetSkill("poison magic",200, 2);
  SetSkill("fire magic",200, 2);
  SetLevel(250);
  SetReligion("Soirin");
  SetMorality(-500);
  SetInventory( ([ 
     ]) );
  SetCurrency("roni",random(1500)+10);
  SetSpellBook( ([
     ]) );
  SetAction(5, ({ 
     }) );
  SetCombatAction(30, ({
     }) );
//  if (environment()) call_out( (: eventForce, "cast barrier of faith" :), 0 );
//  SetFirstCommands( ({ "cast wall of force", "cast wall of force", "cast wall of force" }) );

  SetDie("As the druid dies, her blood mingles with the earth.")

  SetTalkResponses( ([
        ({ "kara", "druid" })  :
        "Greetings Traveller.  I am Kara the protector of the last Aster.",
        ({ "aster", "tree", "sapling" })  :
        "The Aster or Star-fruit Tree is the last of its kind.  I don't know "
        "why they died out, but I have sworn to protect and tend to this tree "
        "with my life.",
        ({ "fruit" })  : 
        "The fruit of the Aster is quite amazing and unique.  It is very soft "
        "and juicy, and not well suited for travelling.  The amazing aspect of "
        "the fruit is the light bearing qualities it has.  Whenever two "
        "seeds collide, a flash of light is given off by the fruit.  This "
        "makes it twinkle.",
        ({ "ruins", "city", "arcanith" }) :
        "I know very little about these ruins.  I know that it was " 
        "once a great city, known as Arcanith, City of Light.  The real "
        "expert is Vartus Timlin, he has told me all I know about the city.",
        ({ "vartus", "timlin" }) :
        "Vartus is a kindly old scholar, who knows a little of everything.  "
        "The last I saw him he was heading to the cathedral.  If you have "
        "questions about the town ask him.",
        ({ "cathedral" }) :
        "The cathedral is to the north.  The path there is blocked by weeds.  "
        "Once I clear them you may go there.",
    	]) )

}

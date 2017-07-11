/*  The druid of the Tree */

#include <lib.h>
#include "../ruins.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("kara");
  SetId( ({ "kara", "druid", "druid of the tree" }) );
  SetAdjectives( ({ "young" }) );
  SetShort("Kara, Druid of the Tree");
  SetLong(
  			"A young druid tends to this grove.  She is fairly tall with long "
        "wheat colored hair.  Pointed ears stick out from between her "
        "long tresses.  Her green eyes speak of meadows and forests.");
  
  SetRace("half-elf");
  SetClass("druid");
  SetLevel(8);
  SetReligion("Eclat","Eclat");
  SetGender("female");
  SetMorality(1000);
  SetAction(5, ({ 
  		"The druid lovingly tends to the odd looking sapling.",
      "As the wind blows through her hair, Kara smiles." }) );
  SetSpellBook( ([
    	"tangle"   : 40,
    	"barkskin" : 80,
    	]) );
  SetCombatAction(60, ({ 
  		"!cast tangle",
      "!cast barkskin",
      }) );
  SetInventory( ([ 
  		OBJ "/leather_vest" : "wear vest",
      OBJ "/carved_staff" : "wield staff" 
      ]) );
  SetDie("As the druid dies, her blood mingles with the earth.");
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
    	]) );
}

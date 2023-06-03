// Originally going to be a cleric, but Eclat clerics 
// cannot harness the power of Amelia. Kept the file 
// name, changed the class

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../castle.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetRace("muezzin");
  SetGender("female");
  SetClass("druid");
  SetLevel(120);
  SetTown("Soleil");
  SetKeyName("Druid");
  SetId( ({"druid"}) );
  SetAdjectives( ({ "eclat","muezzin" }) );
  SetShort("a muezzin Eclat Druid");
  SetLong("This specific Muezzin appears very aware of her "
          "surroundings. She is covered by a light brown fur "
          "that is very straight and well groomed. Her yellow "
          "eyes beam outside of her furrowed brows and light "
          "coloured snout. Her arms are unusually massive "
          "but her intellect appears unrivalled. She looks to "
          "be a high master in her religious order.");
  SetDie("The Druid twitches slightly after her death.");
  SetLimit(1);  
  SetMorality(1000);
  SetCurrency("senones", 35 );
  SetReligion("Eclat");
  SetInventory( ([
        RUINS_OBJ "clepole"  : 1,
  ]) );
  SetFirstCommands( ({
    "wield my pole",
    "yell Welcome to Lake Pokenay!",
    "go north",
    "sit down",
   }) );
  SetSpellBook( ([
    "bloom" : 100,
    "reveal rainbow" : 100,
    "joyful rain" : 100,
    "forest banishment" : 100,
    "harmony hand" : 100,
    "enhance joy" : 100,
    "create rose" : 100,
    ]) );
  SetCombatAction(5, ({ 
    "!emote mutters a quick prayer and ebbs a green essence.",
    "!yell Amelia, help me in this dark hour!!!",
    "!cast forest banishment",
    "!cast harmony hand",
    "!cast joyful rain",
    }) ); 
  SetAction(2, ({
    "!emote curtsies gracefully.",
    "!speak The waterfall here is a lovely place to relax.",
    "!speak Amelia shines down on us from above.",
    "!speak Rest traveller and partake on the blessings of Amelia with me?",    
    "!speak Sometimes I sit close to the lake and enjoy the mist from the waterfall.",
    "!cast bloom",
    "!cast reveal rainbow",
    "!emote hums a joyful tune.",
    "!emote quickly runs to a tree and hugs it firmly",
    "!fish with my first pole",
    "!cast enhance joy",
    "!cast create rose",
    "!drop all roses",
   }) );
  SetTalkResponses( ([
        ({ "hello", "hi" })  :
        "The lake is much more relaxing, especially with the "
        "waterfall above.",
        ({ "waterfall", "lake" }) :
        "This waterfall and lake is of value to us in Soleil. "
        "No doubt a blessing from Amelia herself. Feel free to "
        "drink or leisure here friend.",
        ({ "soleil", "Soleil" }) :
        "Soleil is our one true home.",
        ({ "amelia" })  : 
        "Amelia be praised! The Lady of Mercy shines on us!",
    ]) );
}
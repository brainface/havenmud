#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../castle.h"

inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetRace("muezzin");
  SetGender("male");
  SetClass("viking");
  SetLevel(105);
  SetTown("Soleil");
  SetKeyName("tan Vagabond");
  SetId( ({ "muezzin","vagabond"}) );
  SetAdjectives( ({ "tan" }) );
  SetShort("a tan muezzin vagabond");
  SetLong("This male muezzin is covered with a light tan "
          "colored fur throughout his body. Beady dark yellow "
          "eyes hide slightly behind his brown mustache and "
          "neckbeard combination. Dirt and madded fur have clumped up "
          "around his calves and back hair. His overall "
          "appearance is fat, as if he knows where all the good"
          "food is located in the trees of the Westwood.");
  SetDie("The tan muezzin collapses to the ground."); 
  SetMorality(150);
  SetCurrency("senones",15 );
  SetReligion("Eclat","Eclat");
  SetInventory( ([
    RUINS_OBJ + "mhatchet"   : "wield my first hatchet",
    RUINS_OBJ + "mstocking": 2,
      ]) );
//Must do this to wear stockings, the wear func is weird with long socks
  SetFirstCommands( ({ "wear first stocking on right foot and right leg",
                       "wear first stocking on left foot and left leg",
                       }) );
  SetCombatAction(5, ({ 
    "!emote slashes about!",
    "!yell Finally a battle!!!",
    }) ); 
  SetAction(3, ({
    "!emote twirls his hatchet.",
    "!speak We are many hidden in the trees.",
    "!speak These ruins have been here a very long time.",
    "!speak Soleil still watches this place.",
    "!speak My father refuses to come back here, he claims there "
           "is ghosts!",
     }) );
  SetTalkResponses( ([
        ({ "hello", "hi" })  :
        "Hmm? Do you seek the knowledge of these halls?",
        ({ "ghosts", "father" })  :
        "My father spent some time here but left in a great "
        "hurry, mentioning something of tainted spirits of "
        "forgotten soldiers. I've searched everywhere, to be "
        "honest I have no clue what I am looking for. If you "
        "see them, ensure they have rest.",
        ({ "spirits", "spirit", "soldiers" })  :
        "The spirits would most likely be soldiers of the "
        "survivors of these forgotten, after my ancestors fled "
        "from the Orcish incursion and lived here briefly. They "
        "should rest, knowing we still shine in Amelia's light. ",
        ({ "orcs", "orc" })  :
        "Nasty things. They should be dispatched.",
        ({ "ruins", "castle","ivory castle" })  :
        "My people built the Ivory Castle ages ago before "
        "Soleil was established as our real home. When the elders "
        "decreed we must live in the wood, this place "
        "was abandoned, but not forgotten. Guards still "
        "patrol these halls bound shining in Amelia's Blessing. ",
        ({ "halls" })  : 
        "The ruins here, have been here ages ago after Amelia "
        "helped us escape the first Godswar in the Westwood. We "
        "abandoned mock elvish structures like these ages ago.",
        ({ "godswar" })  : 
        "Timelines vary dependant on who you ask. All I know "
        "for certain is the end result was us sentient beings "
        "with our own mothers. Ours is to Amelia, her happiness "
        "is endless!.",
        ({ "westwood", "west wood" }) :
        "The Westwood is beautiful at times, but can be "
        "devastating to live in, if you are not much of "
        "a survivalist it would benefit you to shelter in "
        "the ruins. As we chanter of the world past.",
        ({ "soleil", "Soleil" }) :
        "Amelia lead us into the woods away from the "
        "conflict of the Karakians, where we consolidated to "
        "dedicating our lives to the world. The Westwood "
        "would be our new home.",
        ({ "amelia" })  : 
        "Amelia be praised! We shine in her forest. Dire "
        "traveller, rest here if you so desire!",
    ]) );
}
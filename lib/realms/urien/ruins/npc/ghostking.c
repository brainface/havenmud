#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../castle.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("muezzin");
  SetGender("male");
  SetClass("fighter");
  SetLevel(94);
  SetKeyName("Spirit");
  SetId( ({ "spirit","king"}) );
  SetAdjectives( ({ "wispy" }) );
  SetShort("a wispy king spirit");
  SetLong("This spirit glows slightly with a hue of soft green "
          "colour. An earthen crown rests on top of his small "
          "Muezzin head. His eyes are milky white and barely "
          "hide behind his thick long body hair. A rather large "
          "sash rests on his shoulder which has been tied around "
          "his waist. He emits a light fog from his very being."); 
  SetMorality(200);
  SetReligion("Eclat","Eclat");
  SetDie("The spirit turns into mist."); 
  SetNoCorpse(1);
  SetInventory( ([
    RUINS_OBJ + "kkris" : "wield kris in left hand",
    ]) );
  SetCombatAction(5, ({ 
    "!speak Another agent of Taigis I see, Begone!",
    "!yell May Amelia have pity on you, dark one!",
    "!emote flickers in and out of existence.",
    }) ); 
  SetAction(2, ({
    "!emote emits a slight green fog into the environment.",
    "!moan sadly",
    "!emote ebbs in and out of existence.",
     }) );
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(5, ({
    "!speak Have you also come seeking my treasure?",
    "!speak The only losers of the GodsWar was us, the mortal beings "
           "of Kailie. We went without food while they squabbled over "
           "control.",
    "!speak The soldiers of Soleil served this castle honorably.",
    "!speak Amelia lead us to the Westwood, we used this Ivory "
           "castle for joy and peace. ",
    "!speak The drawbridge closes at night for your security.",
    "!emote looks weary as if holding his mortal form causes pain.",
  }) );
}
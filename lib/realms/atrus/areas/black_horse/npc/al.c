/* al.c for Black Horse Inn
   Atrus@Haven
   19MAY2013
*/

#include <lib.h> 
#include "../bhi.h"
inherit LIB_NPC;

void CheckPlayer();

void eventKitchen();
void eventHallway();
void eventWander();
void eventDining();


static void create() {
    npc::create();
    SetKeyName("alvare");
    SetShort("Alvare the owner of the Black Horse Inn");
    SetId( ( "alvare", "owner", "al" ) );
    SetAdjectives( ({ "al", "alvare", "owner" }) );
    SetLong(
       "Alvare, or 'Al', to his friends is a bright and sunny dispositioned "
       "human with wrinkled eyes and a bald head. He is tall and heavy with "
       "thick shoulders and knotted hands. His face is deeply lined on his cheeks "
       "and forehead, signs he smiles more often than not. Al's lot in life has "
       "brought him to being the humble owner of the Black Horse Inn which he "
       "loves even more than his wife."
       );
    SetRace("human");
    SetGender("male");
    SetClass("merchant");
    SetLevel(random(15) + 40);
    SetCurrency("imperials", random(100) + 25);
    SetCurrency("shrydes", random(1000) + 250);
    SetCurrency("bloodgems", random(400) + 75);
    SetInventory( ([
        BHI_OBJ "apron" : "wear apron",
        BHI_OBJ "shirt" : "wear shirt",
        BHI_OBJ "spatula" : "wield spatula",
        BHI_OBJ "shoes" : "weare shoes",
      ]) ); 
    SetMorality(200);
    SetSkill("brawling", random(20) + 80, 1);
    SetSkill("melee combat", random(20) + 80, 1);
    SetAction(random(10)+3, ({ "!yell Gimme a minute!",
            "!emote sighs.",
            "!smile",
            "!emote flips a steak.",
            "!emote cleans the griddle.",
            "!emote looks through his spice rack before selecting a jar.",
            "!emote mumbles under his breath.",
            "!emote carefully smells a boiling pot.",
            "!speak welcome to the Black Horse Inn, please see the bartender "
            "at the bar to place your order!",
            (: eventKitchen :),
            (: eventHallway :),
            (: eventWander :),
            (: eventDining :),
            }) );
    SetCombatAction(2, ({ "!scream", }) );
}

/*
void eventKitchen() {
    if (environment() = BHI_ROOM + "kitchen") {
    return("!emote cleans griddle.");
    }
 }


void eventHallway() {
    if (environment() = BHI_ROOM + "hallway") { 
    return("!emote inspects the hallway for damages.");
    }
 }
*/
void eventDining() {
    if (environment() = BHI_ROOM + "bar") {
    int CheckPlayer() {
       string tp_rel = this_player()->GetReligion();
       string tp_race = this_player()->GetRace();
       string tp_town = this_player()->GetTown();

    if(creatorp(this_player())) return 0;
  
    if ( (tp_race == "human") )
      return("!speak nice to see fellow humans in the Black Horse Inn");
    else
      if ( (tp_town == "Grymxoria") )
        return("!speak no sucking on the guests while your here");
      }
   }
}

void eventWander() {
return;
}

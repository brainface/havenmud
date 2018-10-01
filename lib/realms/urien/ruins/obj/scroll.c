//Scroll of Town Portal...
//Must have investment of Oisaeu for it to work.
//Special thanks to Mahkefel and Melchezidek
//Urien@Haven 01.03.13

#include <lib.h>
string BlahRead();
//void HurtMe(object who);

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("scroll");
  SetId( ({ "scroll" }) );
  SetAdjectives( ({ "papyrus","lengthy" }) );
  SetShort( "a lengthy papyrus scroll" );
  SetLong( "This scroll appears ancient. Long slips of papyrus "
           "have been pressed together to form a single sheet "
           "of paper which has cracked from time and neglect. "
           "The words written on the surface appear to be in "
           "Oisaeu text.");
  SetProperty("magic", "This scroll will take you to a place "
                       "in the heavens."); 
  SetMaterial( ({ "natural" }) );
  SetMass(5);
  SetValue(400);
  SetRead( (: BlahRead :) );
}

int BlahRead() {
  object who = this_player();
  string town = who->GetNationality();
    int lang = who->GetLanguageLevel("Oiseau");
    int rand = 70 + random(20);
//    debug("lang: " + lang + " rand: " + rand);    
    if (lang < rand) {
    send_messages( ({ "read" }), "$agent_name $agent_verb the scroll and "+
                                 "nothing happens.",
    who, 0, environment(who));
    return 1;
  }
  if (who->GetInCombat()) {
    who->eventPrint("You're too busy right now.");
    return 1;
  }
  if (sizeof(who->GetEnemies())) {
    who->eventPrint("It is too difficult to read this in combat!");
    return 1;
  }
  who->eventPrint("You read the scroll....\n\n"
                  "It burns up in your hands!\n"
                  "Your environment turns into a blinding brightness.\n"
                  "When you open your eyes you seem to appear somewhere "+
                  "familiar...");
  who->eventMoveLiving("/domains/staff/room/setup", 
       "$N reads an incantation from the scroll, then disappears!",
       "$N appears in a quick puff of smoke!");
  eventDestruct();
  return 1;
}
/*  
//  Original intention was to harm the user
//  with random damage to hands. There is 
//  a price with using old magicks. Had this 
//  going but never got it right. Ok and  
//  balanced to have or not have.

int eventRead(object who) { 
    call_out((: HurtMe, who :), 0);
    return 1;
}

void HurtMe(object who) {
    who->eventPrint("The scroll harms you!");
    environment(who)->eventPrint("The scroll harms " + (string)who->GetName() +
                                 " before it burns to ash!", who);
    who->eventReceiveDamage(this_object(), HEAT, random(100), 0,
                            (string)who->GetRandomLimb("right hand"));
}*/
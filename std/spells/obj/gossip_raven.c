/*             
 * gossipy raven thing
 * Mahkefel 2011               
 */              

#include <lib.h>
#include <std.h>
#include <domains.h>
#include <std.h>    
inherit LIB_NPC;

//goes away
void flyOff(string nothing);

static void create() {
  string gender;      
  string possessive;  
  string pronoun;     

  ::create();
  SetKeyName("raven");
  SetShort("a suspiciously intelligent raven");
  SetClass("rogue");
  // random gender
  gender = random(2) ? "male" : "female";
  possessive = "his";                    
  pronoun = "he";                        
  if (gender == "female") {              
    possessive = "her";                                       
    pronoun = "she";                     
  }                                      

  // descriptive text
  SetGender(gender); 

  SetLong(
    "This small, sleek bird is covered in coal-black feathers "
    "that seem to draw in the light. Its eyes look around it "
    "with suspicious amounts of intelligence, and it a slight "
    "aura of magic seems to surround it."                                 
  );                                                               
  SetId( ({ "raven" }) );
  SetAdjectives( ({ "suspiciously","intelligent", "coal-black" }) );

  // base statistics
  SetRace("bird");
  SetClass("animal");
  SetLevel(25);

  SetStat("intelligence",100);
  SetAction(30, ({
    "!emote resettles on "+possessive+" perch.",
    "!emote looks at you a bit too curiously.",
  }) );
  SetMorality(-10);
}

void flyOff(string nothing) {
  send_messages("leap",
    "$agent_name $agent_verb from $agent_possessive perch and flaps merrily away.",
    this_object(), 0, environment(this_object())
  );
  eventForce("yell CAWWW");
  eventDestruct();
}

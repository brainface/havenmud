/* ----------------------------------------------------------------------- */
// Filename: clairvoyance.c                                                  
// Author: Derek Noble                                                       
// Immortal: dylanthalus@haven                                               
// Creation Date: Dec 18th, 1998                                             
// Abstract: Basically, an advanced discern location spell.                  
// Revision History: Note of thanks to Vanyel, Morgoth and Zeddicus for      
//                     various roles in the creation of this spell.          
// MAHKEFEL STEALS THIS                                                      
// FUCK THAT DYLANTHUS, W'ere gonna make a bird. and we're gonna give it     
//   SERKITS. And it's gonna share those Sekrits with the caster!            
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <magic.h>
#include <std.h>  
inherit LIB_SPELL;

static void create() {
  spell::create();    
  SetSpell("unkind gossip");
  SetDifficulty(50);        
  SetRules("LIV", "STR");   
  SetGlobalSpell(1);        
  SetRequiredMagic(100);    
  SetMagicCost(25, 25);     
  SetSpellType(SPELL_OTHER);
  SetSkills( ([             
     "practical magic" : 150,      
  ]) );                            
  SetHelp(                         
    "Most practiced witches have learned that knowledge is power, "
    "and can use this rite to bargain for others' "                
    "well-kept secrets.");                                         
                                                                   
  }                                                                   

/* CanCast is from discern location, originally 
   coded by Vanyel@Haven */                     

int CanCast(object who, int level, mixed limb, object *targets) {
  if (!playerp(targets[0])) {                                    
      message("system", "Cast it on whom?", who);                
      return 0;                                                  
     }                                                           
  return spell::CanCast(who, level, limb, targets);              
}                                                                

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];
  string story = target->GetStory();
  string *tidbits = ({});
  string tidbit;
  object crow;

  //YOU SAW THAT RIGTH IT'S A FUCKIN' GOSSIP RAVEN. CUASE IT'S 'UNKIND GOSSIP', GET IT? EH? EH?
  crow = new(STD_SPELLS "obj/gossip_raven");

  if (!story) {
    tidbit = "Never was a more boring person born.";
  } else {
    tidbits = explode(story,".");
    tidbit = tidbits[ random(sizeof(tidbits)) ];
  }

  crow->SetBaseLanguage( who->GetNativeLanguage() );
  crow->eventMove(environment(who));

  if( environment(who)->GetClimate("indoors") ) {
    send_messages("fly",
      "A coal-black raven suddenly %^BOLD%^CYAN%^soars%^RESET%^ into the room and perches on $agent_possessive_noun shoulder!",
      who, crow, environment(who) );
  } else {
    send_messages("glide", "A coal-black raven suddenly%^BOLD%^CYAN%^glide%^RESET%^ down and perches on $agent_possessive_noun shoulder!",
      who, crow, environment(who) );
  }

  call_out( (: call_other, crow, "eventForce", "speak I know all about " +target->GetName() + "!" :), 5 );
  call_out( (: call_other, crow, "eventForce", "say They say, you know... " + tidbit :), 15 );
  call_out( (: call_other, crow, "flyOff", "into the wild blue yonder" :), 20 );
  return 1;
}


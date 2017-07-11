#include <lib.h>  
#include <std.h>  
#include <daemons.h>
inherit LIB_VERB;   

static void create() {
    verb::create();   
    SetVerb("marry"); 
    SetRules("LIV to LIV");
    SetErrorMessage("Marry whom to whom?");
    SetHelp("Syntax: <marry PLAYER to PLAYER>\n\n"
            "Allows people of great faith to join to souls in marriage.  "
            "In order to marry to people, you must however be in a place "
            "which you find holy.\n\n"                                    
            "See also: divorce");                                         
}                                                                         

mixed can_marry_liv_to_liv() {
  object who = this_player(); 
  int classcheck;             
  if (who->GetSleeping()) return "You cannot do that while sleeping!";  
  if (who->GetParalyzed()) return "You are unable to move.";            
  if (who->ClassMember("cleric") || who->ClassMember("mystic") || who->ClassMember("druid") 
      || who->ClassMember("contemplator") || who->ClassMember("shaman") || who->ClassMember("imam")
      ) return 1;                                                                                  
  if (who->GetSkillLevel("faith") > 10) return 1;
  return "You lack faith and are not of a class that can perform marriages.";
}

mixed do_marry_liv_to_liv(object spouse1, object spouse2) {
  mixed tmp;
  object ring;
  if( this_player() == spouse1 || this_player() == spouse2 ) {
    this_player()->eventPrint("You may not perform a marriage on yourself.");
    return "You may not perform a marriage on yourself.";
  }
  // Mahkefel sept 2011
  // prevent bjorn from marrying his damned effigy
  if( !playerp(spouse1) || !playerp(spouse2) ) {
    send_messages("","An onlooker speaks up, and rudely denounces the marriage!",
      this_player(),0,environment(this_player()) );
      return "You may only marry important people!";
  }
  spouse1->eventMarry(this_player(), spouse2);
  spouse2->eventMarry(this_player(), spouse1);
  ring = new(STD_OBJ "wed_ring");
        ring->SetSpouse((string)spouse2->GetCapName());
        ring->eventMove(spouse1);
  ring = new(STD_OBJ "wed_ring");
        ring->SetSpouse((string)spouse1->GetCapName());
        ring->eventMove(spouse2);
        send_messages( ({ "join" }),
          "$agent_name $agent_verb " + capitalize(spouse1->GetKeyName()) + " and " + capitalize(spouse2->GetKeyName())
          + " in marriage.", this_player(), 0, environment(this_player()) );
        CHAT_D->eventSendChannel("Wedding!", "ooc", capitalize(spouse1->GetKeyName()) + " and " + capitalize(spouse2->GetKeyName())
          + " have been joined in marriage!", 1);
        users()->eventPrint("%^BOLD%^BLUE%^Wedding bells ring across the land!%^RESET%^");
        return 1;
}

